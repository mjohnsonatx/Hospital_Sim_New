//Thus far, this is a simple program that contains a class Patient that holds
// the individuals name, age, weight, home medicine, and allergies.

// The program will be able to sort and search the patients by ID number and name.

#include "Patient.h"
#include "menu.h"
#include "File.h"
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
    File file;

    bool more = false;

    int l,
        choice;
    double h;

    std::string path = "patients.txt";

    file.fileIO(path, patientDataBase);

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
                
                /// <summary>
                /// NOT COMPLETED
                /// </summary>
                /// <returns></returns>
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
    
    return 0;
    }