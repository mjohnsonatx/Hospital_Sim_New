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

//std::vector<Patient> GenerateDataBase::generate_dob(std::vector<std::string>& names, const int& NUM_PATIENTS){}
//std::vector<Patient> GenerateDataBase::generate_weight(std::vector<std::string>& names){}
