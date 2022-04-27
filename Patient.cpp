#include <iomanip>
#include "patient.h"
#include <iostream>
#include <vector>

Patient::Patient() {
    first_name = "Jane";
    last_name = "Doe"; 
    age = 0;
    weight_lbs = 220.0;
    iD = 000;
    DOB = 01/ 01/2000;
    std::vector<Allergies> allergy_list;
    std::vector<DailyMeds> dailyMeds;
}

Patient::Patient(std::string first, std::string last, int a, double w, int d, std::string x){
    first_name = first;
    last_name = last;
    age = a;
    weight_lbs = w;
    iD = d;
    DOB = x;
    std::vector<Allergies> allergy_list;
    std::vector<DailyMeds> dailyMeds;
}

void Patient::setWeight(double w) {
    weight_lbs = w;
}

void Patient::setName(std::string first, std::string last ) {
    first_name = first;
    last_name = last;
}

void Patient::setAge(int a) {
    age = a;
}

void Patient::setId(int i) {
    iD = i;
}

void Patient::setDOB(std::string s) {
    DOB = s;
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

    auto counter = 0;

    if (allergy_list.size() == 0)
        std::cout << "The patient does not report allergies." << std::endl;

    else if (allergy_list.size() == 1)
        std::cout << "The patient has one allergy: " << allergy_list[0].substance
        << " which causes " << allergy_list[0].reaction << std::endl;
    else {
         std::cout << "The patient has " << allergy_list.size() << " allergies." << std::endl;
         
         for(auto& i : allergy_list)
         {
             std::cout << "\nAllergy " << counter+1 << ": " << i.substance << "\n" << 
                          "Reaction: " << i.reaction << "\n\n";
             ++counter;
         }
         std::cout << "\n";
    }
}

void Patient::displayDailyMeds() {   //should make prettier with setFill
    if (dailyMeds.size() == 0)
        std::cout << "No meds reported." << std::endl;
    else {
        std::cout << "Daily Medication: " << std::setw(10) << "Dose: " << std::endl;
            for(auto& i : dailyMeds)
            std::cout << i.med << std::setw(10) << i.dose << std::endl;
    }
}

void Patient::removeAllergy(int a ) { 
       
    allergy_list.erase(allergy_list.begin() + a);
}

void Patient::amend_allergy(int itr, std::string substance, std::string reaction) {
        
    
    if(substance != "no change")
        allergy_list[itr].substance == substance;
    if(reaction != "no change")
        allergy_list[itr].reaction == reaction;
    
    removeAllergy(itr);
    setAllergies(substance, reaction);

    displayAllergies();
}

void Patient::removeDailyMed(int a) {

    dailyMeds.erase(dailyMeds.begin() + a);
}


    
void Patient::displayPatientDemo() {
      
        std::cout 
            << "Patient Name: " << getName()
            << "\nPatient DOB:" << getDOB()
            << "\nPatient Age: " << getAge()
            << "\nPatient Weight: " << getWeight()
            << "\nPatient ID number: " << getId()
            << "\n\n";
}


   