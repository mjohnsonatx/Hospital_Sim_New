//Thus far, this is a simple program that contains a class Patient that holds
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
    //Allergies reported_allergy; // instant of allergies
    //DailyMeds daily_meds; // instant of daily meds struct to pass to instant of patient
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
        {
            do
            {
                Patient newPatient;

                std::cout << "Enter the patients name: \n";
                getline(std::cin >> std::ws, n);

                std::cout << "Enter the patient's age: \n";
                std::cin >> std::ws >> l;

                std::cout << "What is the patients weight in pounds? \n";
                std::cin >> std::ws >> h;

                std::cout << "Does the patient have any allergies? Yes or No \n";
                std::cin >> answer;

                if (answer == "Yes" || answer == "yes") {
                    do {
                        answer = "no";

                        std::cout << "Please enter the allergy: ";
                        getline(std::cin >> std::ws, a);

                        std::cout << "Please enter the reaction: ";
                        getline(std::cin >> std::ws, b);

                        //reported_allergy.substance = a;
                        //reported_allergy.reaction = b;

                        newPatient.setAllergies(a, b);

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
                ++num_patients;

                more = false;

                std::cout << "Is there another patient? ";
                getline(std::cin >> std::ws, answer);

                if (answer == "yes" || answer == "Yes")
                    more = true;
                else
                    more = false;
            } while (more);

            break;
        }
        case 2:
        {
            // get name of patient to search// should switch to a list on the console.
            std::cout << "Enter the first and last name of the patient:" << std::endl;
            getline(std::cin >> std::ws, name);

            // parsing the vector array, searching for name.
            //auto it = std::find_if(patientDataBase.begin(), patientDataBase.end()-1, [&name](const Patient& patientDataBase) {
            //    return patientDataBase.getName() == name; });

            auto it = std::find_if(std::begin(patientDataBase), std::end(patientDataBase)-1, [&](Patient& const p) {
                return p.getName() == name; });

            // converting the iterator object to an index
            //if (it != patientDataBase.end()) {
                auto index = std::distance(patientDataBase.begin(), it); // was initially auto
                //std::cout << "Patient: " << patientDataBase[index].getName() << std::endl;
            //}

            //else {
                //std::cout << "Patient not found. Would you like to retry /n";
                //getline(std::cin >> std::ws, answer);
                //// FINISH //////
            //}

            //int index = std::distance(patientDataBase.begin(), it);
            //std::cout << "Patient " << patientDataBase[index].getName() << " has these allergies: ";
            patientDataBase[index].displayAllergies();

            

            std::cout << "1) Remove an allergy.\n" <<
                "2) Add an allergy.\n" <<
                "3) Ammend an allergy.\n";
            int choice2 = 0;
            std::cin >> std::ws >> choice2;
            /// <summary>
            /// Need to add functionality that allows the user to parse through the list of allergies of allergies and ammend them.
            /// 1.)first view allergies
            /// 2.)identify index
            /// 3.)delete or ammend
            /// 4.)add?
            /// </summary>
            /// <returns></returns>
            switch (choice2) {
            case 1:
            {

                bool flag = false; // for do-while loop

                do {
                    int choice3 = 0;
                    flag = false;
                    char a; // for bool flag answer choice


                    std::cout << "Select the allergy to be removed: /n";
                    patientDataBase[index].displayAllergies();
                    std::cin >> choice3;

                    patientDataBase[index].removeAllergy(choice3);
                    patientDataBase[index].displayAllergies();
                    //patientDataBase

                    std::cout << "Would you like to remove another allergy? (Y or N) /n";
                    std::cin >> a;

                    if (a == 'y') flag = true;

                } while (flag);
                break;
            }
            case 2:
            {
                bool flag = false;

                do {
                    char d;
                    flag = false;

                    std::cout << "Please enter the allergy: ";
                    getline(std::cin >> std::ws, a);

                    std::cout << "Please enter the reaction: ";
                    getline(std::cin >> std::ws, b);

                    patientDataBase[index].setAllergies(a, b);

                    std::cout << "Would you like to add another allergy? (Y or N) /n";
                    std::cin >> d;

                    if (d == 'y') flag = true;
                } while (flag);

                break;
            }

            ///******add case for amending an allergy******* 

            }
        }
        case 3: //// add functionality for removing meds and ammending meds.
        {
            more = false; // reset the flag

            std::cout << "Enter the first and last name of the patient:/n";
            std::cin >> std::ws >> name;

            ////use code from find_it lambda here


            std::cout << "Do medications need to be added to the medication list? ";
            std::cin >> answer;

            if (answer == "Yes" || answer == "yes") {
                do {
                    answer = ""; // reset answer
                    std::cout << "Medication: ";
                    std::cin >> std::ws >> d;

                    std::cout << "What is the dose? ";
                    getline(std::cin >> std::ws, e);

                    //daily_meds.med = d;
                    //daily_meds.dose = e;

                    //patientDataBase[index].setDailyMeds(d, e, num_meds);

                    std::cout << "Are there more medications that need to be added to the list? ";
                    getline(std::cin >> std::ws, answer);

                    if (answer == "yes" || answer == "Yes")
                        more = true;
                    else
                        more = false;
                } while (more);
            }

            break;
        }

        case 4:
        {
            std::cout << "Number of patient counter: " << num_patients << std::endl << std::endl;
            for (size_t i = 0; i < patientDataBase.size(); ++i) {
                std::cout << "Patient Name: " << patientDataBase[i].getName()
                    << "\nPatient Age: " << patientDataBase[i].getAge()
                    << "\nPatient Weight: " << patientDataBase[i].getWeight()
                    << "\nPatient ID number: " << patientDataBase[i].getId()
                    << "\n\n";
            }
            break;
        }
        case 5:
        {
            for (size_t i = 0; i < patientDataBase.size(); ++i) {
                std::cout << patientDataBase[i].getName() << std::endl;
                patientDataBase[i].displayAllergies();
            }
            break;
        }
        case 6:
        {
            for (size_t i = 0; i < patientDataBase.size(); ++i) {
                std::cout << patientDataBase[i].getName() << std::endl;
                patientDataBase[i].displayDailyMeds();
            }
            break;
        }

        }

        }while (choice != 7);

        if (choice == 7)
        {
            std::cout << "Program Termninated." << std::endl;
            return 0;
        }
        fin.close();
        return 0;
    }