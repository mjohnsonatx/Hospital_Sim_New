#include "File.h"
#include <iostream>
#include <string>
#include <vector>
#include "Patient.h"
#include <fstream>


void File::fileIO(std::string path, std::vector<Patient>& input ) {
    std::ifstream fin;
    fin.open(path);

    if (!fin)
        std::cout << "********INPUT FILE FAILED TO OPEN********";
    else {

        // variables for file input.
        std::string 
            allergy, 
            reaction, 
            medication, 
            dosage, 
            name;

        int id = 0,
            age = 0;

        double weight = 0.0;

        while (fin >> id) {

            Patient newPatient;

            getline(fin >> std::ws, name);
            fin >> std::ws >> age;
            fin >> std::ws >> weight;

            newPatient.setName(name);
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
    }
    fin.close();
}