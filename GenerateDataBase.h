#pragma once

#include <vector>
#include "Patient.h"
#include "File.h"

class GenerateDataBase
{
public:
	std::vector<Patient> generate_names(std::vector<std::string>& names);
	std::vector<Patient> generate_meds(std::vector<std::string>& names);
	std::vector<Patient> generate_allergies(std::vector<std::string>& names);
	std::vector<Patient> generate_dob(std::vector<std::string>& names);
	std::vector<Patient> generate_weight(std::vector<std::string>& names);
};

