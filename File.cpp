#include "File.h"
#include <iostream>
#include <string>
#include <vector>
#include "Patient.h"
#include <fstream>


std::vector<std::string> File::getMeds(const std::string& path) {
    
    std::vector<std::string> meds;

    std::ifstream fin;
    fin.open(path);

    if (!fin)
        std::cout << "********INPUT FILE FAILED TO OPEN********";
    else {

        std::string med;

        while (fin >> med) {  
            getline(fin >> std::ws, med);
            meds.push_back(med);
        }
    }
    fin.close();

    return meds;
}

std::vector<std::string> File::getNames(const std::string& path) {
    
    std::vector<std::string> names_list;

    std::ifstream fin;
    fin.open(path);

    if (!fin)
        std::cout << "********INPUT FILE FAILED TO OPEN********";
    else {
        
        std::string name;

        while (fin >> name) {
            getline(fin >> std::ws, name);
            names_list.push_back(name);
        }
    }
    fin.close();

    return names_list;
}

std::vector<std::string> get_Allregic_Reactions(const std::string& path) {

    std::vector<std::string> allergic_reaction_list;

    std::ifstream fin;
    fin.open(path);

    if (!fin)
        std::cout << "********INPUT FILE FAILED TO OPEN********";
    else {

        std::string allergy;

        while (fin >> allergy) {
            getline(fin >> std::ws, allergy);
            allergic_reaction_list.push_back(allergy);
        }
    }
    fin.close();

    return allergic_reaction_list;
}


void File::fileIO(std::string path, std::vector<Patient>& input ) {
    std::ifstream fin;
    fin.open(path);

    if (!fin)
        std::cout << "********INPUT FILE FAILED TO OPEN********";
    else {

        // variables for file input.
        
        Patient newPatient;
        
        std::string 
            allergy, 
            reaction, 
            medication, 
            dosage, 
            first_name,
            last_name,
            name;

        int id = 0,
            age = 0;

        double weight = 0.0;

        
        
        while (fin >> id) {

            getline(fin >> std::ws, name);
            
            // parse the name into first and last name
            auto pos = 0;
            std::string delimiter = " ";
            pos = name.find(delimiter);
            first_name = name.substr(0, pos);
            last_name = name.substr((pos + 1), name.size());
            
            fin >> std::ws >> age;
            fin >> std::ws >> weight;    
            }

            newPatient.setName(first_name, last_name);
            newPatient.setId(id);
            newPatient.setAge(age);
            newPatient.setWeight(weight);


            for (int i = 0; i < 2; i++) {

                std::getline(fin >> std::ws, allergy);
                std::getline(fin >> std::ws, reaction);

                newPatient.setAllergies(allergy, reaction);
            }
            for (int i = 0; i < 2; i++) {

                getline(fin >> std::ws, medication);
                getline(fin >> std::ws, dosage);

                newPatient.setDailyMeds(medication, dosage);
            }
            input.push_back(newPatient);
        }
    fin.close();
}