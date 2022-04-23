#include <iostream>
#include <string>
#include <vector>
#include "Patient.h"


class Menu {
private:
	int index;
public:
	int patient_Search( std::vector<Patient>& input);
	void add_Patient(std::vector<Patient>& input);
	void add_amend_allergies(std::vector<Patient>& input);
	void add_amend_medications(std::vector<Patient>& input);
	void print_patient(std::vector<Patient>& input);
	void print_patient_allegies(std::vector<Patient>& input);
	void print_patient_medications(std::vector<Patient>& input);
	void print_everything(std::vector<Patient>& input);
};