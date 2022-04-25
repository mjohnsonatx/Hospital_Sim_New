//Thus far, this is a simple program that contains a class Patient that holds
// the individuals name, age, weight, home medicine, and allergies.

// The program will be able to sort and search the patients by ID number and name.

#include "Patient.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include "string"
#include <vector>
#include <algorithm>
#include <random>
#include "menu.h"
#include "File.h"
#include "GenerateDataBase.h"

int main()
{
    auto const NUM_PATIENTS = 5000;
    
    auto index = 0,
         choice = 0;
    
    Menu menu;
    File file;
    GenerateDataBase generate;
    
    std::vector<std::string> not_random_names_list;
    std::vector<std::string>not_random_meds_list;
    std::vector<std::string>allergies_reactions;
    std::vector<Patient> patientDataBase;

    const std::string NAMES_PATH = "names.txt";
    const std::string MEDS_PATH = "medications.txt";
    const std::string ALLERGIES_PATH = "allergic_reaction.txt";
    
     //create list of names and meds
    not_random_names_list=file.getNames(NAMES_PATH);
    not_random_meds_list = file.getMeds(MEDS_PATH);
    allergies_reactions = file.get_Allergic_Reactions(ALLERGIES_PATH);
    
   

    patientDataBase = generate.initialize_patient_vector(NUM_PATIENTS);

    generate.generate_names(not_random_names_list, patientDataBase, NUM_PATIENTS);
    generate.generate_meds(not_random_meds_list, patientDataBase, NUM_PATIENTS);
    generate.generate_allergies(not_random_meds_list, allergies_reactions, patientDataBase, NUM_PATIENTS);
    generate.generate_dob(patientDataBase, NUM_PATIENTS);
    generate.generate_weight(patientDataBase, NUM_PATIENTS);

   

    //generate random names and push them into the patientDataBase
    
  
    ////// create short list of test patients
    //const std::string PATH = "patients.txt";
    //file.fileIO(PATH, patientDataBase);

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