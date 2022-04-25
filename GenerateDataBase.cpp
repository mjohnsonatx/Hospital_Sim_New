#include "GenerateDataBase.h"
#include <vector>
#include "Patient.h"
#include "File.h"
#include <random>



std::vector<Patient> GenerateDataBase::initialize_patient_vector(const int &NUM_PATIENTS) {
    std::vector<Patient> patient_data_base;
 
    for (int i = 0; i < NUM_PATIENTS; ++i) {
        Patient patient;
        patient_data_base.push_back(patient);
    }

    return patient_data_base;
}

void GenerateDataBase::generate_names(const std::vector<std::string>& names, std::vector<Patient>&input, const int& NUM_PATIENTS) {

    std::vector<std::string> names_vector;

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
    //return names_vector;
}

void GenerateDataBase::generate_meds(const std::vector<std::string>& meds_list, std::vector<Patient>& input, const int& NUM_PATIENTS){

    std::vector<Patient> meds_vector;
    
    //generate random names and push them into the patientDataBase
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

void GenerateDataBase::generate_allergies(const std::vector<std::string>& meds_list, const std::vector<std::string>& allergic_reactions, std::vector<Patient>& input, const int& NUM_PATIENTS){
    
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

            int max2 = 9;
            int max3 = 30;

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

void GenerateDataBase::generate_dob(std::vector<Patient> & input, const int NUM_PATIENTS ){
    
    int months[12]{ 1,2,3,4,5,6,7,8,9,10,11,12 },
        days[31],
        years[110],
        counter = 0;

     
    for (int i = 0; i < 30; ++i)
        days[i] = i + 1;

    for (int i = 1; i < 109; ++i) {
        years[i] = 1910;
        years[i] = years[i] + 1;
    }
    
    int min_month = 1, max_month = 12;
    int days_min = 0, days_max = 30;
    int years_min = 0, years_max = 109;

    std::random_device rd;
    std::mt19937 rng(rd());
    
    while (counter != NUM_PATIENTS) {
        //generate random month
        std::uniform_int_distribution<int> uni1(min_month, max_month);
        auto randomMonth = uni1(rng);
        std::string month = std::to_string(months[randomMonth]);

        //generate random day
        std::uniform_int_distribution<int> uni2(days_min, days_max);
        auto randomDay = uni2(rng);
        std::string day = std::to_string(days[randomDay]);

        //generate random year
        std::uniform_int_distribution<int> uni3(years_min, years_max);
        auto randomYear = uni3(rng);
        std::string year = std::to_string(days[randomYear]);

        std::string dob = month + "/" + day + "/" + year;

        input[counter].setDOB(dob);

        ++counter;
    }
    




}
//std::vector<Patient> GenerateDataBase::generate_weight(std::vector<std::string>& names){}
