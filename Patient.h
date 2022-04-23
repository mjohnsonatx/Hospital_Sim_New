#pragma once
#include <iostream>
#include <vector>

struct Allergies {
    Allergies() : substance(" "), reaction(" ") {};
    //Allergies (std::string substance, std::string reaction);
    std::string substance;
    std::string reaction;
};

struct DailyMeds {
    DailyMeds() : med(" "), dose(" ") {};
    DailyMeds ( std::string med, std::string dose);
    std::string med;
    std::string dose;
};

class Patient {

private:
    static const int MAX_SIZE = 100;
    std::string name;
    int age, iD;
    double weight_lbs;
    int allergies_counter = 0;
    int num_meds = 0;
   
    
public:
    
    std::vector<Allergies> allergy_list;
    std::vector<DailyMeds> dailyMeds;
    
    Patient();
    Patient(std::string, int, double, int);
    void setName(std::string);
    void setWeight(double);
    void setAge(int);
    void setId(int);
    void setAllergies(std::string allergy, std::string reaction); // get rid of counter
    void setDailyMeds(std::string dailymed, std::string); // get rid of counter
    void displayAllergies();
    void displayPatientDemo(std::ostream& out) ; //not defined
    void displayDailyMeds(); // needs to be converted to a while loop
    void printName();
    void removeAllergy(int);

    std::string getName()const { return name; }
    double getWeight()const { return weight_lbs; }
    int getAge()const { return age; }
    int getAllergies_counter()const { return allergies_counter;} 
    int getDailyMeds()const { return num_meds; }
    int getId() const { return iD; }
};