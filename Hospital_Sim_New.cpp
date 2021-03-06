//***************************
//****  THIS IS MAIN  *******
//***************************

// This is a simple program that contains a class Patient that holds
// an individuals name, age, weight, home medicine, and allergies.

// The program will be able to sort and search the patients by ID number and name.

#include "Patient.h"
#include "menu.h"
#include "GenerateDataBase.h"
#include "File.h"
#include <unordered_map>
#include <vector>
#include <iostream>
#include "string"

int main()
{
    auto const NUM_PATIENTS{ 100 };

    auto index{ 0 },
        choice{ 0 };

    Menu menu;
    File file;
    GenerateDataBase generate;

    std::vector<Patient> patientDataBase;
    std::unordered_map<std::string, Patient> hashtable;

    // file names for name generators.
    const std::string NAMES_PATH{ "names.txt" };
    const std::string MEDS_PATH {"medications.txt"};
    const std::string ALLERGIES_PATH{ "allergic_reaction.txt" };
    
     //create list of names, meds, and allergic reactions.
    std::vector<std::string>not_random_names_list { file.getNames(NAMES_PATH) };
    std::vector<std::string>not_random_meds_list { file.getMeds(MEDS_PATH) };
    std::vector<std::string>allergies_reactions { file.get_Allergic_Reactions(ALLERGIES_PATH) };
    
    patientDataBase = generate.initialize_patient_vector(not_random_names_list,
        not_random_meds_list, allergies_reactions, NUM_PATIENTS) ;

    
    // put patient db in hashtable.
    for (auto& i : patientDataBase) {
        std::string key = std::to_string(i.getAge());
        key = key + i.getName() + i.getDOB();

        Patient p = i;
        hashtable.insert(std::make_pair(key, p));
    }

   

    do {
        std::cout << "Please make a selection: \n"
            << "1.) Search for patient.\n"
            << "2.) Enter new patient demographics.\n"
            << "3.) Add or amend patient allergies.\n"
            << "4.) Add or amend daily medications.\n"
            << "5.) Display patient demographics. \n"
            << "6.) Display patient allergies.\n"
            << "7.) Display home medication(s).\n"
            << "8.) Print everything.\n"
            << "9.) Exit the program.\n";
        std::cin >> choice;

        while (choice < 1 || choice > 8)
        {
            std::cout << "Please enter 1, 2, 3, 4, 5, 6, 7, or 8: \n";
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
