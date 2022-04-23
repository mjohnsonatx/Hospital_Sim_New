#include <iomanip>
#include "patient.h"
#include <iostream>
#include <vector>

Patient::Patient() {
    name = "Jane Doe";
    age = 0;
    weight_lbs = 220.0;
    iD = 000;
    std::vector<Allergies> allergy_list;
    std::vector<DailyMeds> dailyMeds;
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
void Patient::setAllergies(std::string allergies, std::string reaction) {
    
        Allergies allergy;
        allergy.substance = allergies;
        allergy.reaction = reaction;
        allergy_list.push_back(allergy);
        ++allergies_counter;
}
void Patient::setDailyMeds(std::string dailymeds, std::string dose) {

        DailyMeds d;
        d.med = dailymeds;
        d.dose = dose;
        dailyMeds.push_back(d);
        ++num_meds;
}

void Patient::displayAllergies() {  //should make prettier with setFill

    if (allergy_list.size() == 0)
        std::cout << "The patient does not report allergies." << std::endl;

    else if (allergy_list.size() == 1)
        std::cout << "The patient has one allergy: " << allergy_list[0].substance
        << " which causes " << allergy_list[0].reaction << std::endl;
    else {
         /// make better, not the vector way.
         std::cout << "The patient has " << allergy_list.size() << " allergies." << std::endl;
         std::cout << "Allergy:" << std::setw(15) << "Reaction:" << std::endl;
         for(size_t i = 0; i < allergy_list.size(); ++i)
         {
             std::cout << "Allergy " << i+1 << " " << allergy_list[i].substance << std::setw(15)
                 << allergy_list[i].reaction << std::endl;
         }
    }
}

    void Patient::displayDailyMeds() {   //should make prettier with setFill
        if (dailyMeds.size() == 0)
            std::cout << "No meds reported." << std::endl;
        else {
            std::cout << "Daily Medication: " << std::setw(10) << "Dose: " << std::endl;
            for (size_t i = 0; i < dailyMeds.size(); i++)
                std::cout << dailyMeds[i].med << std::setw(10) << dailyMeds[i].dose << std::endl;
        }
    }

    void Patient::removeAllergy(int a ) { 
       
        allergy_list.erase(allergy_list.begin() + a-1);
    }
    void Patient::printName() { std::cout << name << std::endl; }
    void Patient::displayPatientDemo(std::ostream & out) {}

    //double Patient::getWeight() const { return weight_lbs; }

    //std::string Patient::getName() const { return name; }

    //int Patient::getAge() const { return age; }

    //int Patient::getId() const { return iD; }