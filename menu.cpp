#include <iostream>
#include <vector>
#include <string>
#include "menu.h"
#include "Patient.h"



int Menu::patient_Search( std::vector<Patient>& input) {
	auto choice = 0;
	auto index = 0;
	
	std::cout << "How would you like to search for the patient?\n"
		<< "1.) Search by name.\n"
		<< "2.) Search by DOB.\n"
		<< "3.) Search by ID number.\n"
		<< "4.) Search by display selection.\n";
	std::cin >> choice;

	switch (choice) {

		// search by name
		case 1:
		{
			std::string name;
			std::string answer;

			// get name of patient to search
			std::cout << "Please enter the first and last name of the patient:" << std::endl;
			std::getline(std::cin >> std::ws, name);

			auto it = std::find_if(std::begin(input), std::end(input) - 1, [&](Patient& const p) {
				return p.getName() == name; });

			//auto it = std::find_if(input.begin(), input.end() - 1, [&name](const Patient& input) {
				//return input.getName() == name; });

			// converting the iterator object to an index
			if (it != input.end()) {
				index = std::distance(input.begin(), it);
				std::cout << "Patient: " << input[index].getName() << std::endl;
			}

			else {
				std::cout << "Patient not found. Would you like to retry /n";
				getline(std::cin >> std::ws, answer);
				//// FINISH //////
			}

			break;
		}

		//search by DOB
		case 2:
		{
			std::string date_of_birth;
			std::string answer;

			std::cout << "Please enter the patients date of birth if format MM/DD/YYYY: \n";
			getline(std::cin >> std::ws, date_of_birth);

			auto it = std::find_if(std::begin(input), std::end(input) - 1, [&](Patient& const p) {
				return p.getDOB() == date_of_birth; });

			// converting the iterator object to an index
			if (it != input.end()) {
				index = std::distance(input.begin(), it);
				std::cout << "Patient: " << input[index].getName() << std::endl;
			}

			else {
				std::cout << "Patient not found. Would you like to retry /n";
				getline(std::cin >> std::ws, answer);
				//// FINISH //////
			}

			break;

		}

		//search by menu selection
		case 3:
		{
			for (auto& i : input) {
				std::cout
					<< "Patient number:" << index
					<< "\n Name: " << i.getName()
					<< "\n Age: " << i.getAge()
					<< "\n Weight: " << i.getWeight()
					<< "\n ID number: " << i.getId()
					<< "\n\n";
				++index;
			}

			break;
		}
	}
	return index;
}

void Menu::add_Patient(std::vector<Patient>& input) {
	
	std::string n, answer, dob, a, b;
	double h = 0;
	int l = 0, i = 0;
	bool more = false;
	do
	{
		Patient newPatient;

		std::cout << "Enter the patients name: \n";
		getline(std::cin >> std::ws, n);

		std::cout << "Enter the patient's age: \n";
		std::cin >> std::ws >> l;

		std::cout << "What is the patients weight in pounds? \n";
		std::cin >> std::ws >> h;

		std::cout << "What is the patient's date of birth, please enter "
				  << "in mm/dd/yyyy format\n";
		getline(std::cin >> std::ws, dob);

		std::cout << "Does the patient have any allergies? Yes or No \n";
		std::cin >> answer;

		if (answer == "Yes" || answer == "yes") {
			do {
				answer = "no";

				std::cout << "Please enter the allergy: ";
				getline(std::cin >> std::ws, a);

				std::cout << "Please enter the reaction: ";
				getline(std::cin >> std::ws, b);

				newPatient.setAllergies(a, b);

				std::cout << "Are there more patients? (y or n) ";
				getline(std::cin >> std::ws, answer);

				if (answer == "y" || answer == "Y")
					more = true;
				else
					more = false;
			} while (more);
		}

		newPatient.setWeight(h);
		newPatient.setAge(l);
		newPatient.setName(n);
		newPatient.setId(i);
		newPatient.setDOB(dob);

		input.push_back(newPatient);
		
		more = false;

		std::cout << "Is there another patient? ";
		getline(std::cin >> std::ws, answer);

		if (answer == "yes" || answer == "Yes")
			more = true;
		else
			more = false;
	} while (more);
}

void Menu::add_amend_allergies(std::vector<Patient>& input) {

	index=patient_Search(input);

	std::cout << 
		"1) Remove an allergy.\n" <<
		"2) Add an allergy.\n" <<
		"3) Ammend an allergy.\n";
	
	int choice2 = 0;
	std::cin >> std::ws >> choice2;

	switch (choice2) {

		// removing allergies
		case 1:
		{

			bool flag = false; // for do-while loop

			do {
				int choice3 = 0;
				flag = false;
				char a; // for bool flag answer choice

				std::cout << "Select the allergy to be removed: /n";
				input[index].displayAllergies();
				std::cin >> choice3;

				input[index].removeAllergy(choice3);
				input[index].displayAllergies();

				std::cout << "Would you like to remove another allergy? (Y or N) /n";
				std::cin >> a;

				if (a == 'y') flag = true;

			} while (flag);
			break;
		}

		//adding allergies
		case 2:
		{
			bool flag = false;

			do {
				std::string a, b;

				char d;
				flag = false;

				std::cout << "Please enter the allergy: ";
				getline(std::cin >> std::ws, a);

				std::cout << "Please enter the reaction: ";
				getline(std::cin >> std::ws, b);

				input[index].setAllergies(a, b);

				std::cout << "Would you like to add another allergy? (Y or N) /n";
				std::cin >> d;

				if (d == 'y') flag = true;
			} while (flag);

			break;
		}

		//amending allergies ****BROKEN****
		case 3:
		{
			bool flag = false;

			do {
				std::string a, b;
				char d;
				int amend = 0;
				flag = false;

				std::cout << "Please select the allergy to be amended: ";
				input[index].displayAllergies();
				std::cin >> amend;

				std::cout << "Please enter the substance (if no change write 'no change'): ";
				getline(std::cin >> std::ws, a);

				std::cout << "Please enter the reaction (if no change write 'no change'): ";
				getline(std::cin >> std::ws, b);

				input[index].amend_allergy(index, a, b);

				std::cout << "Would you like to amend another allergy? (Y or N) /n";
				std::cin >> d;

				if (d == 'y') flag = true;
			} while (flag);

			break;
		}

	}

}

void Menu::add_amend_medications(std::vector<Patient>& input) {

	index = patient_Search(input);

	bool more = false; // reset the flag

	auto choice = 0;

	std::string
		medication,
		dosage,
		name,
		answer;

	std::cout
		<< "1.) Would you like to add medications to a patients med list?\n"
		<< "2.) Amend a patient's med list?\n"
		<< "3.) Or, remove meds from a patient's med list?\n";
	std::cin >> choice;

	switch (choice) {
		case 1:
		{
			do {
				answer = ""; // reset answer
				std::cout << "Medication: ";
				std::cin >> std::ws >> medication;

				std::cout << "What is the dose? ";
				getline(std::cin >> std::ws, dosage);

				input[index].setDailyMeds(medication, dosage);

				std::cout << "Are there more medications that need to be added to the list? ";
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
			bool flag = false; 

			do {
				int choice3 = 0;
				flag = false;
				char a; 

				std::cout << "Select the medication to be removed: /n";
				input[index].displayDailyMeds();
				std::cin >> choice3;

				input[index].removeDailyMed(choice3);
				input[index].displayDailyMeds();

				std::cout << "Would you like to remove another medication? (Y or N) /n";
				std::cin >> a;

				if (a == 'y') flag = true;

			} while (flag);

			break;
		}
	}
}

void Menu::print_patient(std::vector<Patient>& input) {
	
	index = patient_Search(input);
	input[index].displayPatientDemo();
}

void Menu::print_patient_allegies(std::vector<Patient>& input) {
	index = patient_Search(input);
	input[index].displayAllergies();
}

void Menu::print_patient_medications(std::vector<Patient>& input) {
	index = patient_Search(input);
	input[index].displayDailyMeds();
}

void Menu::print_everything(std::vector<Patient>& input) {
	for (auto& i : input) {
		i.displayPatientDemo();
		i.displayAllergies();
		i.displayDailyMeds();
		std::cout << "\n\n";
	}

}

