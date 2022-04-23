#pragma once
#include <iostream>
#include <vector>

struct Allergies {
    Allergies() : substance(" "), reaction(" ") {};
    std::string substance;
    std::string reaction;
};

struct DailyMeds {
    DailyMeds() : med(" "), dose(" ") {};
    std::string med;
    std::string dose;
};

class Patient {

private:
    std::string name;
    std::string DOB;
    
    int age = 0,
        iD = 0,
        allergies_counter = 0,
        num_meds = 0;
    
    double weight_lbs=0;
   
    
public:
    
    std::vector<Allergies> allergy_list;
    std::vector<DailyMeds> dailyMeds;
    
    Patient();
    Patient(std::string, int, double, int, std::string);
    void setName(std::string);
    void setWeight(double);
    void setAge(int);
    void setId(int);
    void setDOB(std::string);
    void setAllergies(std::string allergy, std::string reaction); 
    void setDailyMeds(std::string dailymed, std::string); 
    void displayAllergies();
    void displayPatientDemo(std::ostream& out) ; //not defined
    void displayDailyMeds(); 
    void printName();
    void removeAllergy(int);
    void removeDailyMed(int);
    void amend_allergy(int, std::string sub, std::string reaction);

    std::string getName()const { return name; }
    std::string getDOB()const { return DOB; }
    double getWeight()const { return weight_lbs; }
    int getAge()const { return age; }
    int getAllergies_counter()const { return allergies_counter;} 
    int getDailyMeds()const { return num_meds; }
    int getId() const { return iD; }
    
};