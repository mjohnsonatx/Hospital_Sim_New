#pragma once

#include "patient.h"
#include <iostream>
#include <vector>
#include <string>

class Menu {
private: 
    
    vector<Patient> patient;
    int new_patients;


public:
	Void AddNewPatient() {
        std::cout << "How many patients need to be registered?\n";
        std::cin >> new_patients;

        for (int i = 0; i < new_patients; i++) {

            Patient newPatient;

            std::cout << "Enter the patients name: \n";
            getline(std::cin >> std::ws, n);

            std::cout << "Enter the patient's age: \n";
            std::cin >> std::ws >> l;

            std::cout << "Does the patient have any allergies? Y or N \n";
            std::cin >> std::ws >> answer;

            std::cout << "Does the patient have any allergies? \n";
            std::cin >> answer;

            if (answer == "Yes" || answer == "yes") {
                do {
                    answer = "no";

                    std::cout << "Please enter the allergy: ";
                    getline(std::cin >> std::ws, a);

                    std::cout << "Please enter the reaction: ";
                    getline(std::cin >> std::ws, b);

                    reported_allergy.substance = a;
                    reported_allergy.reaction = b;

                    newPatient.setAllergies(a, b, num_allergies);

                    std::cout << "Is there more: ";
                    getline(std::cin >> std::ws, answer);

                    if (answer == "yes" || answer == "Yes")
                        more = true;
                    else
                        more = false;
                } while (more);
            }
            newPatient.setWeight(h);
            newPatient.setAge(l);
            newPatient.setName(n);
            newPatient.setId(i);

            patientDataBase.push_back(newPatient);
        }

	}
};
