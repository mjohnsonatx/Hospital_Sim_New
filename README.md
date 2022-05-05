# Hospital_Sim_New
This repo is intended to simulate a rudimentary hospital database that stores patient objects. Each patient object has a name, age, weight, date of birth, home meds, allergies, and their respective setters and getters.   

Hello, welcome, thanks for stopping by.

First things first:
•	***Hospital_Sim_New.cpp is MAIN.
•	***If you download and unzip all the files into the same folder and then build Hospital_Sim_New from it, it should compile and run to console without error.
•	***All of the files, headers, cpp implementation files, and txt files are necessary for a successful build and they must be in the same root directory. 
•	*****I have only compiled in MSVS******

Goal: the goal of this project was to put together many of the C++ topics and tools that I learned in school. Specifically, I wanted to be more fluent in class/object manipulation, design, and organization. I also wanted with to work with multiple files and practice organizing data in the most expeditious or C++ way. Additionally, I wanted to learn modern, proper, c++ code, and make use of STL Templates and built-in algorithms. 

Currently there are 4 classes each with their respective header and implementation file:
1.	Patient – this class implements the patient object, which is the central focus of the program.
2.	Menu – this class provides the menu functions.
3.	Generate Database – this class generates a unique patient database.
4.	File – this class allows you to bring in patients from a file

About the code:
	Currently, when you build, a database of 100 randomly generated patients will be allocated to a vector of patients. In main, this is vector named patientDataBase. I was initially testing with 5,000 and there weren’t any issues, so I decreased it to make things easier.
Under vector<Patient>patientDataBase is an unordered map, this is broken. I was thinking a unordered map would be easier to lookup patients (o(1)) since one can just access the object with a key. I was going have the key be a concatenation of name and date of birth since ascii have numerical values. 

Menu?
    totes broken

    I think most of the code is broken and that my menu loops have to be re-organized. A lot of the functionality works, setAllergies, amendAllergies, setMeds, amendMeds… But accessing those functions through the switches and do-whiles is not expeditious and often not possible. I have to go back to the drawing board and ask myself “What do I want from the menu, and what is the point of the database.” Since a lot of the backend works correctly, it shouldn’t take too long.

Vectors?  

    Are vectors god’s gift to Bjarne Stroustrup? Or is there a better way to implement the database. The one absolute precondition that I know of is that the structure has to have dynamic memory allocation. From there it needs to be something that is easily searchable for quick patient lookup, and sortable for when the user does not know who they are looking for. To implement a search function of a user defined vector of objects will require manually overloading of the operator (   ==  <  >  !=   [ ] ).  
    
    For example, to search alphabetically by patient name with the less than operator, the ‘<’ would be overloaded in the class implementation file like this: 
		
        bool Patient::operator < (const Patient& x, const Patient& y)
		{
		Return x.name < y.name;
		} 
	
	The overloading of the less than operator allows for the STL algo sort to be called:
		
        sort ( patientDataBase.begin(), patientDataBase.end()-1 )  


    Those are some of the thoughts I'm pondering before starting the next branch.
            
Other than the mentioned issues there are little bugs floating around, I know the user will get an out of bounds error when iterating through either the allergies or meds list. Also, a lot of the randomly generated data is non-sensical, and I think the Patient class needs a copy constructure since they have dynamic memory allocation through their built-in med_list and allergy list vectors.
            
Thank for reading! If you’re into C++, this style prog, this style in-general, or have anything you would like to share, please let me know!


  
