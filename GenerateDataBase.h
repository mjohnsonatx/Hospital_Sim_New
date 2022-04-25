#pragma once

#include <vector>
#include "Patient.h"
#include "File.h"

class GenerateDataBase
{
public:
	std::vector<Patient> initialize_patient_vector(const int & );
	void generate_names( const std::vector<std::string>& names, std::vector<Patient>& input, const int &);
	void generate_meds(const std::vector<std::string>& names, std::vector<Patient>& input, const int&);
	std::vector<Patient> generate_allergies(std::vector<std::string>& names);
	std::vector<Patient> generate_dob(std::vector<std::string>& names);
	std::vector<Patient> generate_weight(std::vector<std::string>& names);
};

