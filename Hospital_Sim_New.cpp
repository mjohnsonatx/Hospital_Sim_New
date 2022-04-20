//    Thus far, this is a simple program that contains a class Patient that holds
// the individuals name, age, weight, home medicine, and allergies.

// The program will be able to sort and search the patients by ID number and name.

// To do:
// make Patient into a vector array. 

#include "Patient.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include "string"
#include <vector>
#include <algorithm>

int main()
{
    int num_patients = 0, size, new_patients, limit;
    std::vector<Patient> patientDataBase;
    Allergies reported_allergy; // instant of allergies
    DailyMeds daily_meds; // instant of daily meds struct to pass to instant of patient
    bool more = false;

    std::string a, b, c, d, e, f, answer, name;
    int l, num_meds = 0, num_allergies = 0, choice, id, p, q = 0; // q is a counter for file input
    double h, o;

    std::string g,//
        j, // allergy
        k, // reaction
        m, // med
        n; // dose

    std::ifstream fin;
    fin.open("patients.txt");

    if (!fin)
        std::cout << "********INPUT FILE FAILED TO OPEN********";
    else {
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
                
                reported_allergy.substance = j;
                reported_allergy.reaction = k;
                newPatient.setAllergies(j, k , num_allergies);
            }
            for (int i = 0; i < 2; i++) {
                
                getline(fin >> std::ws, m);
                getline(fin >> std::ws, n);

                daily_meds.med = m;
                daily_meds.dose = n;
                newPatient.setDailyMeds(m,n, num_meds);

                patientDataBase.push_back(newPatient);
            }
            num_patients++;
        }
    }
    do {
        std::cout << "Please make a selection: \n"
            << "1. Enter new patient demographics.\n"
            << "2. Add or amend patient allergies.\n"
            << "3. Add or amend daily medications.\n"
            << "4. Display patient demographics. \n"
            << "5. Display patient allergies.\n"
            << "6. Display home medication(s).\n"
            << "7. Exit the program.\n";
        std::cin >> choice;

        while (choice < 1 || choice > 7)
        {
            std::cout << "Please enter 1, 2, 3, 4, 5, 6, or 7: \n";
            std::cin >> choice;
        }

        switch (choice) {
        case 1:
            do
            {
                Patient newPatient;

                std::cout << "Enter the patients name: \n";
                getline(std::cin >> std::ws, n);

                std::cout << "Enter the patient's age: \n";
                std::cin >> std::ws >> l;

                std::cout << "Does the patient have any allergies? Yes or No \n";
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
                //newPatient.setId(i);

                patientDataBase.push_back(newPatient);
                
                more = false;
                
                std::cout << "Is there another patient? ";
                getline(std::cin >> std::ws, answer);

                if (answer == "yes" || answer == "Yes")
                    more = true;
                else
                    more = false;
            } while (more);
            break;
        
        case 2:

            std::cout << "Enter the first and last name of the patient:/n";
            std::cin >> std::ws >> name;

            std::vector<Patient>::iterator it = std::find(patientDataBase.begin(), patientDataBase.end(), name);
            int index = std::distance(patientDataBase.begin(), it);

            if (it != patientDataBase.end())
                std::cout << "Patient: " << patientDataBase[index].getName() << std::endl;
            else {
                std::cout << "Patient not found. Would you like to retry /n";
                getline(std::cin >> std::ws, answer);
                //// FINISH //////
            }
    
            patientDataBase[index].displayAllergies(std::cout);
            /// <summary>
            /// Need to add functionality that allows the user to parse through the list of allergies of allergies and ammend them.
            /// 1.)first view allergies
            /// 2.)identify index
            /// 3.)delete or ammend
            /// 4.)add?
            /// </summary>
            /// <returns></returns>
            break;
        case 3:
            more = false; // reset the flag
        
            
                std::cout << "Does the patient take any medications? ";
                std::cin >> answer;

                if (answer == "Yes" || answer == "yes") {
                    do {
                        answer = "no"; // reset answer
                        std::cout << "Medication: ";
                        std::cin >> std::ws >> d;

                        std::cout << "What is the dose? ";
                        getline(std::cin >> std::ws, e);

                        daily_meds.med = d;
                        daily_meds.dose = e;

                        patient[i].setDailyMeds(d, e, num_meds);

                        std::cout << "Is there more? ";
                        getline(std::cin >> std::ws, answer);

                        if (answer == "yes" || answer == "Yes")
                            more = true;
                        else
                            more = false;
                    } while (more);
                }
            }
            break;
        case 4:
            std::cout << "Number of patient counter: " << num_patients << std::endl << std::endl;
            for (int i = 0; patientDataBase.size(); i++) {
                std::cout << "Patient Name: " << patientDatabase[i].getName()
                    << "\nPatient Age: " << patient[i].getAge()
                    << "\nPatient Weight: " << patient[i].getWeight()
                    << "\nPatient ID number: " << patient[i].getId()
                    << "\n\n";
            }
            break;
        case 5:
            for (int i = 0; i < num_patients; ++i) {
                patient[i].displayAllergies(std::cout, num_allergies);
                std::cout << "\n";
            }
            break;
        case 6:
            for (int i = 0; i < num_patients; ++i) {
                patient[i].displayDailyMeds(std::cout, num_meds);
            }
            break;
        }
    } while (choice != 7);

    if (choice == 7)
    {
        std::cout << "Program Termninated." << std::endl;
        return 0;
    }
    fin.close();
    return 0;
}