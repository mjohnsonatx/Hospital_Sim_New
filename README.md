# Hospital_Sim_New

Hello, welcome, thanks for stopping by.

This repo is intended to simulate a rudimentary hospital database that stores a collection of patient objects. Each patient object has the attributes name, age, weight, date of birth, home meds, allergies, and their respective setters and getters.   

First things first:
• ***Hospital_Sim_New.cpp is MAIN.
• ***If you download and unzip all the files into the same folder and then build Hospital_Sim_New from it, it should compile and run to the console without error.
• ***All of the files, headers, cpp implementation files, and txt files are necessary for a successful build and they must be in the same root directory. 
• *****I have only compiled in MSVS******

Goal: 
	The goal of this project is to explore many of the C++ topics and tools that I learned in school. Specifically, I wanted to be more fluent in class/object manipulation, design, and organization. I also wanted to work with multiple files and practice organizing data in the most expeditious or C++ way. Additionally, I wanted to learn modern, proper, c++ code, and make use of STL Templates and built-in algorithms. 

Currently, there are 4 classes each with their respective header and implementation file:
1.	Patient – this class implements the patient object, which is the central focus of the program.
2.	Menu – this class provides the menu functions.
3.	Generate Database – this class generates a unique patient database.
4.	File – this class allows you to bring in patients from a file

About the code:
	
	Currently, when you build, a database of 100 randomly generated patients will be allocated to a vector of patients. In main, this is vector named patientDataBase. I was initially testing with 5,000 and there weren’t any issues, so I decreased it to make things easier. Located under vector<Patient>patientDataBase is an unordered map, this is broken. I was thinking an unordered map would be easier to look up patients (o(1)) since one can just access the object with a key. I was going to have the key be a concatenation of name and date of birth to take advantage of their ASCII values.

Menu Class:
	
	Some loops are broken, and some operations will throw an out-of-range exception when iterating through patients and/or their meds and allergies.
The find algorithm in Patient Search needs to be redesigned, the iterator is returning the correct location, but that value is not being used correctly.
I think most of the menu loops have to be re-designed at a conceptual level and there needs to be redefinition and reassessment of what the menu is for. 

The Container - Vector

	Is a vector the best solution? Is there a better way to implement the database? The one absolute precondition that I know of is that the structure must have dynamic memory allocation because hospitals don’t know how many patients they will see. Following this, the container needs to be something that is easily searchable for quick patient lookup, and sortable for when the user does not know who they are looking for 

Patient Class: 
	
	A lot of the functionality works, setAllergies, amendAllergies, setMeds, amendMeds… But accessing those methods through switches and do-whiles is not expeditious and often not possible. I have to go back to the drawing board and ask myself “Is this the correct way to utilize this container and its associated algorithms.” Since a lot of the backend works correctly, it shouldn’t take too long.

	Future considerations:
	
	What type of container should hold this class? Does this class follow the rule of 5 and need additional constructors? Should I implement threading or parrallel design? Should the operators be overloaded for built-in searching and sorting?

For example, to search alphabetically by patient name with the less than operator, the ‘<’ would be overloaded in the class implementation file like this: 		
        bool Patient::operator < (const Patient& x, const Patient& y)
		{
		Return x.name < y.name;
		} 	
	The overloading of the less than operator allows for the STL algo sort to be called:		
        sort ( patientDataBase.begin(), patientDataBase.end()-1 )  
    
Conclusion:    
Those are some of the thoughts I'm pondering before starting the next branch.
            
Other than the mentioned issues there are little bugs floating around. Like the patientGenerator creating non-sensical data.            
Thank for reading! If you know the answers to my questions, wanna collab, are into C++ and this style in general or have anything you would like to share, please let me know!



  
