//Thus far, this is a simple program that contains a class Patient that holds
// the individuals name, age, weight, home medicine, and allergies.

// The program will be able to sort and search the patients by ID number and name.

#include "Patient.h"
#include "menu.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include "string"
#include <vector>
#include <algorithm>

int main()
{
    int num_patients = 0, 
        index = 0;
    
    std::vector<Patient> patientDataBase;
    Menu menu;

    bool more = false;

    int l, 
        num_meds = 0, 
        num_allergies = 0, 
        choice, 
        q = 0; // q is a counter for file input

    double h;

    

    std::ifstream fin;
    fin.open("patients.txt");

    if (!fin)
        std::cout << "********INPUT FILE FAILED TO OPEN********";
    else {
        
        std::string j, k, m, n, name; // for file input.
            
        int id = 0,
            p = 0;
           
        double o = 0.0;

        while (fin >> id) {

            

            Patient newPatient;

            getline(fin >> std::ws, name);
            fin >> std::ws >> p;
            fin >> std::ws >> o;

            newPatient.setName(name);
            newPatient.setId(id);
            newPatient.setAge(p);
            newPatient.setWeight(o);


            for (int i = 0; i < 2; i++) {

                std::getline(fin >> std::ws, j);
                std::getline(fin >> std::ws, k);

                newPatient.setAllergies(j, k);
            }
            for (int i = 0; i < 2; i++) {

                getline(fin >> std::ws, m);
                getline(fin >> std::ws, n);

                newPatient.setDailyMeds(m, n);
            }
            patientDataBase.push_back(newPatient);
            ++num_patients;
        }
    }
    do {
        std::cout << "Please make a selection: \n"
            << "1. Search for patient.\n"
            << "2. Enter new patient demographics.\n"
            << "3. Add or amend patient allergies.\n"
            << "4. Add or amend daily medications.\n"
            << "5. Display patient demographics. \n"
            << "6. Display patient allergies.\n"
            << "7. Display home medication(s).\n"
            << "8. Exit the program.\n";
        std::cin >> choice;

        while (choice < 1 || choice > 8)
        {
            std::cout << "Please enter 1, 2, 3, 4, 5, 6, or 7: \n";
            std::cin >> choice;
        }

        switch (choice) {
            case 1:
            {
                index = menu.patient_Search(patientDataBase);

                break;
            }

            case 2:
            {
                menu.add_Patient(patientDataBase);

                break;
            }
            case 3:
            {

                menu.add_amend_allergies(patientDataBase);

                break;
            }
            
            case 4: //// add functionality for removing meds and ammending meds.
            {
                

                break;
            }

            case 5:
            {
                std::cout << "Number of patient counter: " << num_patients << std::endl << std::endl;
                for (auto& i:patientDataBase) {
                    std::cout << "Patient Name: " << i.getName()
                        << "\nPatient Age: " << i.getAge()
                        << "\nPatient Weight: " << i.getWeight()
                        << "\nPatient ID number: " << i.getId()
                        << "\n\n";
                }
                break;
            }
            case 6:
            {
                for (auto& i:patientDataBase) {
                    std::cout << i.getName() << std::endl;
                    i.displayAllergies();
                }
                break;
            }
            case 7:
            {
                for (auto& i:patientDataBase) {
                    std::cout << i.getName() << std::endl;
                    i.displayDailyMeds();
                }
                break;
            }

        }

    }while (choice != 8);

    if (choice == 7)
    {
        std::cout << "Program Termninated." << std::endl;
        return 0;
    }
    fin.close();
    return 0;
    }