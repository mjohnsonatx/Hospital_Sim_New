#include "File.h"
#include <iostream>
#include <string>
#include <vector>
#include "Patient.h"
#include <fstream>



void File::file_input(std::ifstream& fin, std::string str, std::vector<std::string>& vec) {

    while (fin >> str) {
        getline(fin >> std::ws, str);
        vec.push_back(str);
    }
}

std::vector<std::string> File::getMeds(const std::string& path) {
    
    std::vector<std::string> meds;

    std::ifstream fin;
    fin.open(path);

    if (!fin)
        std::cout << "********MEDS INPUT FILE FAILED TO OPEN********";
    else {

        std::string med;

        file_input(fin, med, meds);

    }
    
    fin.close();

    return meds;
}

std::vector<std::string> File::getNames(const std::string& path) {
    
    std::vector<std::string> names_list;

    std::ifstream fin;
    fin.open(path);

    if (!fin)
        std::cout << "********NAMES INPUT FILE FAILED TO OPEN********";
    else {
        
        std::string name;

        file_input(fin, name, names_list);
    }
    fin.close();

    return names_list;
}

std::vector<std::string> File::get_Allergic_Reactions(const std::string& path) {

    std::vector<std::string> allergic_reaction_list;

    std::ifstream fin;
    fin.open(path);

    if (!fin)
        std::cout << "********ALLERGIC REACTIONS INPUT FILE FAILED TO OPEN********";
    else {

        std::string allergy;

        file_input(fin, allergy, allergic_reaction_list);
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