#include "GenerateDataBase.h"
#include <vector>
#include "Patient.h"
#include "File.h"
#include <random>

std::vector<Patient> GenerateDataBase::generate_names(std::vector<std::string>& names) {

    std::vector<Patient> names_vector;

    int min = 0, max = 1000, max2 = 4;

    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(min, max);
    int counter = 0;

    while (counter < 5000) {

        auto random_int = uni(rng);
        std::string space = " ";
        std::string newName_first = names[random_int];

        random_int = uni(rng);
        std::string newName_last = names[random_int];
        //std::string newName = newName_first + space + newName_last;
        //std::cout << newName << "  ";

        Patient patient;
        patient.setName(newName_first, newName_last);
        names_vector.push_back(patient);
    }
    return names_vector;
}
//std::vector<Patient> GenerateDataBase::generate_meds(std::vector<std::string>& names){}
//std::vector<Patient> GenerateDataBase::generate_allergies(std::vector<std::string>& names){}
//std::vector<Patient> GenerateDataBase::generate_dob(std::vector<std::string>& names){}
//std::vector<Patient> GenerateDataBase::generate_weight(std::vector<std::string>& names){}
