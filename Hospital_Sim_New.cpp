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
#include <random>

int main()
{
    std::vector<std::string> names_list;
    std::vector<std::string>meds_list;
    std::vector<Patient> patientDataBase;
    
    Menu menu;
    File file;
    
    auto index = 0,
         choice = 0;

/*
    const std::string NAMES_PATH = "names.txt";
    const std::string MEDS_PATH = "medications.txt";

    //create list of names and meds
    names_list=file.getNames(NAMES_PATH);
    meds_list = file.getMeds(MEDS_PATH);

    //generate random names and push them into the patientDataBase
    int min = 0, max = 1000, max2 = 4;

    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(min, max);
    int counter = 0;
    
    while (counter < 5000) {
        
        auto random_int = uni(rng);
        std::string space = " ";
        std::string newName_first = names_list[random_int];

        random_int = uni(rng);
        std::string newName_last = names_list[random_int];
        std::string newName = newName_first + space + newName_last;
        //std::cout << newName << "  ";

        Patient patient;
        patient.setName(newName);

        // make random number of meds per patient
        std::uniform_int_distribution<int> uni(min, max2);
        auto random_num_meds = uni(rng);
        
        while (random_num_meds != 0) {
            
            int max3 = 30;
            std::uniform_int_distribution<int> uni(min, max3);
            auto random_med = uni(rng);
            
            std::string patient_meds = meds_list[random_med];
            
            patient.setDailyMeds(patient_meds, "");
            --random_num_meds;
        }
        patientDataBase.push_back(patient);
        ++counter;  
    } 
  */  
    // create short list of test patients
    const std::string PATH = "patients.txt";
    file.fileIO(PATH, patientDataBase);

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