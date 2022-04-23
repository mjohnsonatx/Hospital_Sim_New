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
            << "8. Print everything.\n"
            << "9.) Exit the program.\n";
        std::cin >> choice;

        while (choice < 1 || choice > 8)
        {
            std::cout << "Please enter 1, 2, 3, 4, 5, 6, or 7: \n";
            std::cin >> choice;
        }

        switch (choice) {
            
            //search for patients
            case 1:
            {
                index = menu.patient_Search(patientDataBase);

                break;
            }

            //add patient(s)
            case 2:
            {
                menu.add_Patient(patientDataBase);

                break;
            }
            
            //amend patient allergies
            case 3:
            {

                menu.add_amend_allergies(patientDataBase);

                break;
            }
            
            // amend patient medications
            case 4: 
            {
                
                menu.add_amend_medications(patientDataBase);

                break;
            }

            // list patient demographics
            case 5:
            {
                menu.print_patient(patientDataBase);
                
                break;
            }

            // print patient allergies
            case 6:
            {
                menu.print_patient_allegies(patientDataBase);

                break;
            }

            //print patient medications
            case 7:
            {
                menu.print_patient_medications(patientDataBase);

                break;
            }

            //print everything
            case 8:
                menu.print_everything(patientDataBase);

                break;
        }

    }while (choice != 9);

    if (choice == 9)
    {
        std::cout << "Program Termninated." << std::endl;
        return 0;
    }
    
    return 0;
    }