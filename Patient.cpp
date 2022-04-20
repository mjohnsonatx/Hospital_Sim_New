#include <iomanip>
#include "patient.h"
#include <iostream>
#include <vector>

Patient::Patient() {
    name = "Jane Doe";
    age = 0;
    weight_lbs = 220.0;
    iD = 000;
    std::vector<Allergies> allergy_list{};
    std::vector<DailyMeds> dailyMeds{};
}
Patient::Patient(std::string n, int a, double w, int d) {
    n = name;
    a = age;
    w = weight_lbs;
    d = iD;
    std::vector<Allergies> allergy_list;
    std::vector<DailyMeds> dailyMeds;
}
void Patient::setWeight(double w) {
    weight_lbs = w;
}
void Patient::setName(std::string n) {
    name = n;
}
void Patient::setAge(int a) {
    age = a;
}
void Patient::setId(int i) {
    iD = i;
}
void Patient::setAllergies(std::string allergies, std::string reaction, int &num_allergies) {
    if (num_allergies == 0) {
        Allergies allergy;
        allergy.substance = allergies;
        allergy.reaction = reaction;
        allergy_list.push_back(allergy);
        num_allergies++;
    }
    else {
        Allergies a;
        a.substance = allergies;
        a.reaction = reaction;
        allergy_list.push_back(a);    
    }

}
void Patient::setDailyMeds(std::string dailymeds, std::string dose, int& num_meds) {
    if (!dailymeds.empty()) {
        DailyMeds d;
        d.med = dailymeds;
        d.dose = dose;
        dailyMeds.push_back(d);
        num_meds++;
    }
    else {
        DailyMeds d;
        d.med = dailymeds;
        d.dose = dose;
        dailyMeds.push_back(d);
        num_meds++;
    }
}

void Patient::displayAllergies(std::ostream& out) {  //should make prettier with setFill

    if (allergy_list.size() == 0)
        out << "The patient does not report allergies." << std::endl;

    else if (allergy_list.size() == 1)
        out << "The patient has one allergy: " << allergy_list[0].substance
        << " which causes " << allergy_list[0].reaction << std::endl;
    else {
         /// make better, not the vector way.
         out << "The patient has " << allergy_list.size() << " allergies." << std::endl;
         out << "Allergy:" << std::setw(15) << "Reaction:" << std::endl;
         for(int i = 0; i < allergy_list.size(); ++i)
         {
             out << allergy_list[i].substance << std::setw(15)
                 << allergy_list[i].reaction << std::endl;
         }


    }
}


    void Patient::displayDailyMeds(std::ostream & out) {   //should make prettier with setFill
        if (dailyMeds.size() == 0)
            out << "No meds reported." << std::endl;
        else {
            out << "Daily Medication: " << std::setw(10) << "Dose: " << std::endl;
            for (int i = 0; i < dailyMeds.size(); i++)
                out << dailyMeds[i].med << std::setw(10) << dailyMeds[i].dose << std::endl;
        }
    }

    void Patient::printName() { std::cout << name << std::endl; }
    void Patient::displayPatientDemo(std::ostream & out) {}

    double Patient::getWeight() const { return weight_lbs; }

    std::string Patient::getName() const { return name; }

    int Patient::getAge() const { return age; }

    int Patient::getId() const { return iD; }