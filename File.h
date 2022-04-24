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
	void fileIO(std::string, std::vector<Patient>&);
	std::vector<std::string> getNames(const std::string &path);
	std::vector<std::string> getMeds(const std::string &path);
};

