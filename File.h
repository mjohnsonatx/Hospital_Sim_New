#pragma once

#include "Patient.h"
#include "File.h"
#include <iostream>
#include <fstream>
#include "string"
#include <vector>


class File
{
public:
	void file_input(std::ifstream& fin, std::string str, std::vector<std::string>& vec);
	void fileIO(std::string, std::vector<Patient>&);
	std::vector<std::string> getNames(const std::string &path);
	std::vector<std::string> getMeds(const std::string &path);
	std::vector<std::string> get_Allergic_Reactions(const std::string& path);
};

