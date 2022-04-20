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
   
    
public:
    
    std::vector<Allergies> allergy_list;
    std::vector<DailyMeds> dailyMeds;
    
    Patient();
    Patient(std::string, int, double, int);
    void setName(std::string);
    void setWeight(double);
    void setAge(int);
    void setId(int);
    void setAllergies(std::string allergy, std::string reaction, int &counter); // get rid of counter
    void setDailyMeds(std::string dailymed, std::string, int &counter); // get rid of counter
    void displayAllergies(std::ostream& out);// needs to be converted to a while loop
    void displayPatientDemo(std::ostream& out); //not defined
    void displayDailyMeds(std::ostream& out); // needs to be converted to a while loop
    void printName();

    std::string getName()const;
    double getWeight()const;
    int getAge()const;
    std::string* getAllergies()const; // idk if these have utility, as the display functions work
    std::string* getDailyMeds()const;// what I said above, I think they need to be
    int getId() const;              // pointers because they should at least return
                                //the address of the first iteration of their respective structs.
};