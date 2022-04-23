#include "File.h"
#include <iostream>
#include <string>
#include <vector>
#include "Patient.h"
#include <fstream>


void File::fileIO(std::string path, std::vector<Patient>& input ) {
    std::ifstream fin;
    fin.open(path);

    if (!fin)
        std::cout << "********INPUT FILE FAILED TO OPEN********";
    else {

        std::string j, k, m, n, name; // for file input.

        int id = 0,
            p = 0;

        double o = 0.0;

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
            input.push_back(newPatient);
        }
    }
    fin.close();
}