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
};