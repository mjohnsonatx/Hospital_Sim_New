#pragma once

#include <vector>
#include "Patient.h"
#include "File.h"

class GenerateDataBase
{
public:
	std::vector<Patient> initialize_patient_vector(const int & );
	void generate_names( const std::vector<std::string>& , std::vector<Patient>& , const int &);
	void generate_meds(const std::vector<std::string>& , std::vector<Patient>& , const int&);
	void generate_allergies(const std::vector<std::string>&, const std::vector<std::string> &, std::vector<Patient>& , const int&);
	void generate_dob(std::vector<Patient>&, const int &);
	void generate_weight(std::vector<Patient>&, const int &);
};

