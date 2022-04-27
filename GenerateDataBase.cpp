#include "GenerateDataBase.h"
#include <vector>
#include "Patient.h"
#include "File.h"
#include <random>
#include <string.h>
#include <iomanip>



std::vector<Patient> GenerateDataBase::initialize_patient_vector(const std::vector<std::string> &not_random_names_list, 
    const std::vector<std::string> &not_random_meds_list, const std::vector<std::string> &allergies_reactions, const int &NUM_PATIENTS, std::unordered_map<std::string, Patient> &hashtable) {
 
    //initialize NUM_PATIENTS with default constructor
    std::vector<Patient> input;
    for (int i = 0; i < NUM_PATIENTS; ++i) {
        Patient patient;
        input.push_back(patient);
    }
    
    generate_names(not_random_names_list, input, NUM_PATIENTS);
    generate_meds(not_random_meds_list, input, NUM_PATIENTS);
    generate_allergies(not_random_meds_list, allergies_reactions, input, NUM_PATIENTS);
    generate_dob(input, NUM_PATIENTS);
    generate_weight(input, NUM_PATIENTS);

    /*
    for (auto &i : input) {
        std::string key = i.getDOB(),
            key2 = i.getName();
        key = key + key2; 
        hashtable.insert(key, input[i]);
    }
    */
    return input;
}

void GenerateDataBase::generate_names(const std::vector<std::string>& names, std::vector<Patient>&input, const int& NUM_PATIENTS) {

    int min = 0,
        max = 1000;

    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(min, max);
    int counter = 0;

    while (counter < NUM_PATIENTS) {

        auto random_int = uni(rng);
        std::string space = " ";
        std::string newName_first = names[random_int];

        random_int = uni(rng);
        std::string newName_last = names[random_int];
        //std::string newName = newName_first + space + newName_last;
        //std::cout << newName << "  ";

        input[counter].setName(newName_first, newName_last);
        ++counter;
    }
}

void GenerateDataBase::generate_meds(const std::vector<std::string>& meds_list, std::vector<Patient>& input, const int& NUM_PATIENTS){
    
    int min = 0, max = 4;

    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(min, max);
    int counter = 0;

    while (counter < NUM_PATIENTS) {

        // make random number of meds per patient
        std::uniform_int_distribution<int> uni(min, max);
        auto random_num_meds = uni(rng);

        while (random_num_meds != 0) {

            int max3 = 30;
            std::uniform_int_distribution<int> uni(min, max3);
            auto random_med = uni(rng);

            std::string patient_meds = meds_list[random_med];

           input[counter].setDailyMeds(patient_meds, "");
            --random_num_meds;
        }
        ++counter;
    }
}

void GenerateDataBase::generate_allergies(const std::vector<std::string>& meds_list, const std::vector<std::string>& allergic_reactions, 
    
    std::vector<Patient>& input, const int& NUM_PATIENTS){
    
    int min = 0, max = 4,
        counter = 0,
        max2 = 9,
        max3 = 30;

    std::random_device rd;
    std::mt19937 rng(rd());

    while (counter < NUM_PATIENTS) {
            
        // make random number of meds per patient
        
        std::uniform_int_distribution<int> uni(min, max);
        auto random_num_meds = uni(rng);

        while (random_num_meds != 0) { 

            std::uniform_int_distribution<int> uni(min, max3);
            auto random_med = uni(rng);

            std::string patient_allergy = meds_list[random_med];
            
            std::uniform_int_distribution<int> uni2(min, max2);
            auto random_allergy = uni2(rng);
            std::string reaction = allergic_reactions[random_allergy];

            input[counter].setAllergies(patient_allergy, reaction);
            --random_num_meds;
        }
        ++counter;
    }
}

void GenerateDataBase::generate_dob(std::vector<Patient> & input, const int &NUM_PATIENTS ){
    
    int months[12]{ 1,2,3,4,5,6,7,8,9,10,11,12 },
        days[30],
        years[110],
        counter = 0;

    // initialze day array. 
    for (int i = 0; i < 30; ++i)
        days[i] = i + 1;

    // initialize year array
    for (int i = 0; i < 109; ++i) {
        years[i] = 1910+i;
    }
    
    int min_month = 1, max_month = 12,
        days_min = 0, days_max = 30,
        years_min = 0, years_max = 109;

    std::random_device rd;
    std::mt19937 rng(rd());

    while (counter != NUM_PATIENTS) {

        //generate random month
        std::uniform_int_distribution<int> uni1(min_month, max_month);
        auto randomMonth = uni1(rng);
        std::string month = std::to_string(months[randomMonth]);
        
        if (randomMonth < 9) { month = '0' + month; }

        //generate random day
        std::uniform_int_distribution<int> uni2(days_min, days_max);
        auto randomDay = uni2(rng);
        std::string day = std::to_string(days[randomDay]);

        if (randomDay < 9 ) {day = '0' + day;}

        //generate random year
        std::uniform_int_distribution<int> uni3(years_min, years_max);
        auto randomYear = uni3(rng);
        std::string year = std::to_string(years[randomYear]);

        std::string dob = month + "/" + day + "/" + year;

        input[counter].setDOB(dob);

        ++counter;
    }
}

void GenerateDataBase::generate_weight(std::vector<Patient>& input, const int & NUM_PATIENTS){
       
    auto counter = 0; 
    std::random_device rd;
    std::mt19937 rng(rd());
    
    auto young_min = 25, young_max = 55,
         small_human_min = 50, small_human_max = 140,
         adult_min = 100, adult_max = 450;

    while ( counter != NUM_PATIENTS) {
       
        
        
        std::string original = input[counter].getDOB();

        std::string s2 = original.substr(6, 9);
        int year = atoi(s2.c_str());

        int age = 2022 - year;
        input[counter].setAge(age);

        if (age <= 10) {

            std::uniform_int_distribution<int> uni(young_min, young_max);
            auto random_young_weight = uni(rng);
            input[counter].setWeight(random_young_weight);
        }
        else if (age <= 20 && age >= 10 ) {

            std::uniform_int_distribution<int> uni(small_human_min, small_human_max);
            auto random_small_human_weight = uni(rng);
            input[counter].setWeight(random_small_human_weight);
        }

        else {
            
            std::uniform_int_distribution<int> uni(adult_min, adult_max);
            auto random_human_weight = uni(rng);
            input[counter].setWeight(random_human_weight);
        }
        ++counter;
    }
}
