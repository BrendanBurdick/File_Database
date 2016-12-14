/* Name: Brendan Burdick
 * Class: Object Oriented Programming Using C++
 * Professor: Andrew Jung
 * Date Produced: December 10th, 2016
 * 
 * Purpose of this (.cpp) file:
 * 
 * This (.cpp) file provides function definitions for function prototypes within the newstudent.h header file. All of the computation for the main file is executed here, starting with 'bulkofProg()'.
 * I have 2 constructors (one for no correct input, and one for correct input). In the enhanced constructor, all of the new student's attributes are set, and the averages are calculated using the 
 * corresponding functions (calcExamAverage, calcHWAverage, calcOverallGrade, calcLetterGrade). The headerDesign() function designs the header of the database, while the writeTo() function transfers 
 * the user's attributes to the file. The bulkOfProg() function is the main meat of the program. When it's called, it askes for a filename, and depending on whether it exists or not, it is created, and
 * data can be added to / searched from it. The createNewStudent() function takes in all of a new student's data, then utilizes the writeTo() function to write that new data to the file. The 
 * displayDatabase function displays all of the contents within a file, neatly. The makeASearch() function repeatedly searched for data within a file. Finally, there is a destructor as well.
 * 
 * */
#include "newStudent.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

//Default Constructor Definition. Used when no data is inputted for a student. Defaults all values to 0 or "NaN".
newStudent::newStudent()
{
	fullName = "NaN", schID = "NaN", schoolYear = "NaN", Department = "NaN";
	Midterm = 0, FinalExam = 0, HW1 = 0, HW2 = 0, HW3 = 0, Attendance = 0, Project = 0;
}

//Enhanced Constructor Definition. Assigns inputted data to the corresponding student attributes. Calculates the rest using functions below.
newStudent::newStudent(string Name, string ID, string schYear, string dept, double midtermEx, double finalEx, double firstHW, double secHW, double thirHW, double attend, double proj)
{
	fullName=Name;
	schID=ID;
	schoolYear=schYear;
	Department=dept;
	Midterm=midtermEx;
	FinalExam=finalEx;
	HW1=firstHW;
	HW2=secHW;
	HW3=thirHW;
	Attendance=attend;
	Project=proj;
}


//This function takes in the student's midterm and final grades, and calculates the student's exam average.
double newStudent::calcExamAverage(double grade1, double grade2)
{
	double average = (Midterm+FinalExam)/2;
	return average;
}


//This function akes in HW1, HW2, and HW3 grades, and calculates the student's homework average.
double newStudent::calcHWAverage(double gr1, double gr2, double gr3)
{
	double average = (HW1+HW2+HW3)/3;
	return average;
}


/* This function takes in the student's Exam Average, HW Average, Project, and Attendance Grade, and calculates overall grade.
 * It calculates the student's final grade based on the following breakdown:
 * 
 * Exams are worth 50%, Homework is worth 20%, Project is worth 20%, and Attendance is worth 10%.
 * */
double newStudent::calcOverallGrade(double exams, double homework, double projGrade, double attGrade)
{
	double calc1 = (exams*0.5); //Calculates exam weight grade for student.
	double calc2 = (homework*0.2); //Calculates homework weight grade for student.
	double calc3 = (projGrade*0.2); //Calculates project weight grade for student.
	double calc4 = (attGrade*0.1); //Calculates attendance weight grade for student.
	double finalGrade = calc1+calc2+calc3+calc4;
	
	return finalGrade;
}


//This function takes in the overall grade and translates it into a letter grade.
string newStudent::calcLetterGrade(double gradeToTranslate)
{
	if (gradeToTranslate <= 100 && gradeToTranslate >=97) //Criteria for A+ Grade.
		return "A+";
	else if (gradeToTranslate < 97 && gradeToTranslate >= 94) //Criteria for A Grade.
		return "A";
	else if (gradeToTranslate < 94 && gradeToTranslate >= 90) //Criteria for A- Grade.
		return "A-";
	else if (gradeToTranslate < 90 && gradeToTranslate >= 87) //Criteria for B+ Grade.
		return "B+";
	else if (gradeToTranslate < 87 && gradeToTranslate >= 84) //Criteria for B Grade.
		return "B";
	else if (gradeToTranslate < 84 && gradeToTranslate >= 80) //Criteria for B- Grade.
		return "B-";
	else if (gradeToTranslate < 80 && gradeToTranslate >= 77) //Criteria for C+ Grade.
		return "C+";
	else if (gradeToTranslate < 77 && gradeToTranslate >= 74) //Criteria for C Grade.
		return "C";
	else if (gradeToTranslate < 74 && gradeToTranslate >= 70) //Criteria for C- Grade.
		return "C-";
	else if (gradeToTranslate < 70 && gradeToTranslate >= 67) //Criteria for D+ Grade.
		return "D+";
	else if (gradeToTranslate < 67 && gradeToTranslate >= 64) //Criteria for D Grade.
		return "D";
	else if (gradeToTranslate < 64 && gradeToTranslate >= 60) //Criteria for D- Grade.
		return "D-";
	else
		return "F"; //Anything lower than a 60 is an F grade.
}


/* This function takes in the address of an output filestream and the calculated grades for a new student. Upon receiving the filestream, 
 * the attributes of the student are stored directly within a file. All decimal values are rounded to 2 decimal places.
 * */
void newStudent::writeTo(ofstream &fileStream, double ExamAverage, double HWAverage, double overallGrade, string letterGrade)
{
	fileStream << fullName << endl << schID << endl << schoolYear << endl << Department << endl << fixed << setprecision(2) <<  Midterm << endl << fixed << setprecision(2) << FinalExam << endl << fixed << setprecision(2) << ExamAverage << endl << fixed << setprecision(2) << HW1 << endl << fixed << setprecision(2) << HW2 << endl << fixed << setprecision(2) << HW3 << endl << fixed << setprecision(2) << HWAverage << endl << fixed << setprecision(2) << Attendance << endl << Project << endl << fixed << setprecision(2) << overallGrade << endl << letterGrade <<endl; 
}


/* This function is designed specifically for creating the header for the formatted database. I created this function as a way to design the 
 * top of the file database. The top of the file is formatted specifically for each attribute that a student will have.
 * */
void newStudent::headerDesign()
{
	cout << left << setw(20) << "Student Name:"  << left << setw(13) << "School ID:" << left << setw(19) << "Year In School:"  << left << setw(18) << "Department:"  << left << setw(20) << "Mid-Term Exam:"  << left << setw(16) << "Final Exam:"  << left << setw(18) << "Exam Average:"  << left << setw(11) << "H.W.1:"  << left << setw(11) << "H.W.2:"  << left << setw(11) << "H.W.3:"  << left << setw(20) << "Homework Average:"  << left << setw(16) << "Attendance:" << left << setw(13) << "Project:" << left << setw(19) << "Overall Grade:" << left << setw(13) << "Letter Grade:" << endl; //Neatly writes header, aligned left.
	
	cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl; //Line to separate header from data.
}


/* This function is what will be called by the student object in main. To start, it asks the user for a filename. If it exists, then it asks a user whether he/she wants to add information to the file,
 * display all of the information within a file, search the file for specific students, or close the file. If the file does not exist, then the file is created, and the user is asked whether h/she
 * would like to add information to the file. When the user is done adding information to the file, they are asked whether they would like to search through the data. If they do not, then the file closes.
 * 
 * 
 * */
void newStudent::bulkOfProg()
{
	int addInfo = 1, userInput, searchAgain = 1; //Variables to track loops.
	string file; //String to hold inputted filename.
	char Trash[2]; //To grab excess characters upon data type swaps.
	
	cout << "\nPlease enter the name of the file you want to view / create: ";
	getline (cin, file); //Takes in file name.
	
	ifstream fileExists(file); //Input file stream to test if a file exists.
	if (fileExists.is_open()) //If the file is open, then it exists. Asks user if they want to add/search for information, or close file.
	{
		cout<<"\nOpening existing file! Would you like to add information, search for information, or close file?"<<endl;
		cout<<"1. Add information to the file."<<endl;
		cout<<"2. Display all information."<<endl;
		cout<<"3. Search for a specific student."<<endl;
		cout<<"4. Close the file."<<endl;
		cout<<"--> ";
		cin>>userInput;
		
		if (userInput==1) //If user enters '1', creates new student.
		{
			while (addInfo != 0)
			{
				cin.getline(Trash, 2); //Trashes the extra characters.
				createNewStudent(file); //Calls method to create new student object.
				cout<<"Would you like to add more information? (0 for no, 1 for yes.) ";
				cin>>addInfo; //Updates the addInfo varibale, determining whether to loop or not.
			}
			cout << "\nFile content addition completed. Would you like to make a search for information? (0 for no, 1 for yes.)";
			cin >> userInput; //Once the new data is added, the user is asked if they want to search for student's within the file.
			
			while (userInput != 0) //Loop to make searches for information, until sentinel value '0' is entered.
				userInput = makeASearch(file);
		}
		
		else if (userInput==2) //If user enters '2', shows entire database. Program closes after.
		{
			cout << "\n";
			displayDatabase(fileExists);
		}
			
		else if (userInput==3) //If user enters '3', searches for information.
		{
			while (searchAgain != 0) //Loop to make searches for information, until sentinel value '0' is entered. Initial 'searchAgain' value initialized at top.
				searchAgain = makeASearch(file); //searchAgain value is the return value from the makeASearch function.
		}
		
		else
		{
			fileExists.close();
			cout<<"File Closed.\n";
		}
	}
		
	else //If the file is not opened with ifstream then it does not exist, and it is created with an ofstream the file. Then it asks the user if they want to add info to it.
	{
		ofstream newFile(file); //Create new file.
		newFile.close(); //Close file stream.
		cout<<"\nNew file created! Would you like to add information to it? (0 for no, 1 for yes.) ";
		cin>>addInfo;
		
		while (addInfo != 0) //Loop to create new students, and add their data to the file created above.
		{
			cin.getline(Trash, 2); //Trash variable to get the newLine characters.
			createNewStudent(file);
			cout<<"Would you like to add more information? (0 for no, 1 for yes.) ";
			cin>>addInfo;
		}
		
		cout << "\nFile content addition completed. Would you like to make a search for information? (0 for no, 1 for yes.)";
		cin >> userInput; //Once the new data is added, the user is asked if they want to search for student's within the file.
		
		while (userInput != 0) //Loop to make searches for information, until sentinel value '0' is entered.
		{
			userInput = makeASearch(file);
		}
	}
}


/* This function adds new data to a file. The function prompts the user to input the attributes of a new student. The terminal asks the user for the new student's Name, ID, 
 * School Year, Department, Midterm Grade, Final Grade, Homework Grades, Attendance Grades, and Project Grade. The averages for each student are calculated within the student 
 * object itself. Note that the filename is passed and used to create an output filestream. The filestream is set to append to the file, so it doesn't overwrite the existing 
 * data (ios::app command). The address of this output filestream is then passed to a function within the new student object's definition, which is designed to print the new 
 * student's information within the specified file.
 * */
void newStudent::createNewStudent(string filename)
{
	string Name, ID, Year, Dept, letterGr; //Variables to get all of the new student's information.
	double mid, fin, hw1, hw2, hw3, att, proj, examAver, HWAver, overallGr;
	ofstream writeToFile(filename, ios::app); //Output file stream appends to bottom of the file.
	
	cout<<"Name: ";
	getline (cin, Name);
	
	cout<<"ID: ";
	getline (cin, ID);
	
	cout<<"Year: ";
	getline (cin, Year);
	
	cout<<"Department: ";
	getline (cin, Dept);
	
	cout<<"Midterm: ";
	cin>>mid;
	
	cout<<"Final: ";
	cin>>fin;
	
	cout<<"HW1: ";
	cin>>hw1;
	
	cout<<"HW2: ";
	cin>>hw2;
	
	cout<<"HW3: ";
	cin>>hw3;
	
	cout<<"Attendance: ";
	cin>>att;
	
	cout<<"Project: ";
	cin>>proj;
	
	cout<<"\nNew Student Created!\n"<<endl;
	
	newStudent newStu(Name, ID, Year, Dept, mid, fin, hw1, hw2, hw3, att, proj); //Creates new student with inputted data.
	examAver = newStu.calcExamAverage(mid, fin); //Calculates exam average using function within the newStu object. Stores in variable.
	HWAver = newStu.calcHWAverage(hw1, hw2, hw3); //Calculates homework average using function within the newStu object. Stores in variable.
	overallGr = newStu.calcOverallGrade(examAver, HWAver, proj, att); //Calculates overall grade using function within the newStu object. Stores in variable.
	letterGr = newStu.calcLetterGrade(overallGr); //Calculates letter grade using function within the newStu object. Stores in variable.
	newStu.writeTo(writeToFile, examAver, HWAver, overallGr, letterGr); //Writes all data to file using function within newStu object.
}


/* This function takes an input file stream and uses it to display an entire database. It uses the input filestream to load all of a student's values into temporary variables,
 * and then neatly displays them on the screen.
 * */
void newStudent::displayDatabase(ifstream &fileToReadFrom)
{
	string Name, ID, Year, Dept, letterGr, outputLine, mid, fin, hw1, hw2, hw3, att, proj, examAver, HWAver, overallGr, extra; //Variables for student values.
	headerDesign(); //Designs header.
	while (1)
	{
		getline(fileToReadFrom, Name); //The getlines retrieve and display the values of the current student we're printing.
		getline(fileToReadFrom, ID);
		getline(fileToReadFrom, Year);
		getline(fileToReadFrom, Dept);
		fileToReadFrom >> mid >> fin >> hw1 >> hw2 >> hw3 >> att >> proj >> examAver >> HWAver >> overallGr >> letterGr; 
		getline(fileToReadFrom, extra); //This getline kills the extra whitespace in the file. For organization.
		
		if (fileToReadFrom.eof()) //Breaks out of loop if end of file is reached.
			break;
			
		//Takes the stored data and formats it, under the header, to the terminal for display purposes.
		cout << left << setw(20) << Name << left << setw(13) << ID << left << setw(19) << Year << left << setw(18) << Dept << left << setw(20) << mid << left << setw(16) << fin << left << setw(18) << examAver << left << setw(11) << hw1 << left << setw(11) << hw2 << left << setw(11) << hw3 << left << setw(20) <<  HWAver << left << setw(16) << att << left << setw(13) << proj << left << setw(19) <<  overallGr << left << setw(13) << letterGr <<endl; 
	}
	fileToReadFrom.close();
	cout<<"\nFile Closed.\n\n";
}


/* This function's purpose is to take a filename as a parameter, open it with an ifstream, and search the file for certain keywords. It does this by taking in a search word to look for,
 * assigning each of a student's attributes to a temporary variable, and every time the search word is matched, it prints all of the currently stored variables. A worthwile note is
 * that the 'search' only takes the Name, ID, School Year, and Department category into account. If a search term is found within a certain category, it breaks out of the while loop
 * and qualifies to be prined since the matchFlag value gets changed to true. If it finds no matches, it still breaks out of the loop, but it doesn't print that student. A header is
 * printed regardless of finding a student or not, therefor, if a student is not found within the file, it will just have an empty database. 
 * 
 * The search continues until the user enter decides that they don't want to search anymore (when they hit 0).
 */
int newStudent::makeASearch(string filename)
{
	string Name, ID, Year, Dept, letterGr, searchTerm, extra; //Variables to hold student values while traversing files. Additional values "search-term" and
	double mid, fin, hw1, hw2, hw3, att, proj, examAver, HWAver, overallGr; // "extra, for the search term and extra white space.
	char Trash[2]; //Kills new lines.
	int loopVal; //Return value. This is the user's decision to keep looping or not.
	bool matchFlag; //Marks whether a search has been successful or not.
	ifstream searchStream(filename); //Input stream. This stream opens, traverses, and assigns values from the file.
	
	cout << "\nEnter Keywords (Searching the Name, ID, Year in School, and Department Categories.)"<<endl;
	cout << "Example search words: Computer Science, Brendan Burdick, Junior, etc...\n"<<endl;
	cout << "Search Words: ";
	
	cin.getline(Trash, 2); //Trashes extra characters upon changing from numeric input to string.
	getline(cin, searchTerm); //Gets search term.
	cout << endl;
	
	int lookingForMatch = -1; //Value to evaluate whether a match has been found.
	
	headerDesign(); //Designs header.
	
	while(1)
	{
		matchFlag = false; //Sets initial flag value to false, since we haven't found a match yet.
		getline(searchStream, Name); //The getlines retrieve and store the values of the current student we're evaluating.
		getline(searchStream, ID);
		getline(searchStream, Year);
		getline(searchStream, Dept);
		searchStream >> mid >> fin >> hw1 >> hw2 >> hw3 >> att >> proj >> examAver >> HWAver >> overallGr >> letterGr; 
		getline(searchStream, extra); //This getline kills the extra whitespace in the file. For organization.
		
		if (searchStream.eof())
			break;
		
		while (!matchFlag) //While no match has been found.
		{
			//lookingForMatch = Name.find(searchTerm, lookingForMatch+1);
			if ((lookingForMatch = Name.find(searchTerm, lookingForMatch+1)) == 0) //If the name matches the search term, break the loop.
			{
				matchFlag = true; //Adjust flag to true after a match is found.
				break;
			}
			
			else if ((lookingForMatch = ID.find(searchTerm, lookingForMatch+1)) == 0) //If the ID matches the search term, break the loop.
			{
					matchFlag = true; //Adjust flag to true after a match is found.
					break;
			}
			
			else if ((lookingForMatch = Year.find(searchTerm, lookingForMatch+1)) == 0) //If the school year matches the search term, break the loop.
			{
					matchFlag = true; //Adjust flag to true after a match is found.
					break;
			}
			
			else if ((lookingForMatch = Dept.find(searchTerm, lookingForMatch+1)) == 0) //If the department matches the search term, break the loop.
			{
					matchFlag = true; //Adjust flag to true after a match is found.
					break;
			}
			
			else
				break;
		}
		
		if (matchFlag == true) //If match is found, display that student's information with under the header.
		{
			//Takes the stored data and formats it, under the header, to the terminal for display purposes. (Only if there is a data match)
			cout << left << setw(20) << Name << left << setw(13) << ID << left << setw(19) << Year << left << setw(18) << Dept << left << setw(20) << mid << left << setw(16) << fin << left << setw(18) << examAver << left << setw(11) << hw1 << left << setw(11) << hw2 << left << setw(11) << hw3 << left << setw(20) <<  HWAver << left << setw(16) << att << left << setw(13) << proj << left << setw(19) <<  overallGr << left << setw(13) << letterGr << left << endl;
		}
	}
	
	cout << "\nWould you like to make another search for information? (0 for no, 1 for yes.)";
	cin >> loopVal; //Value returns to function caller, telling whether or not to continue searching for info.
	return loopVal;
}

/* This destructor unitializes all variables.
 * */
newStudent::~newStudent()
{
	fullName = "NaN", schID = "NaN", schoolYear = "NaN", Department = "NaN";
	Midterm = 0, FinalExam = 0, HW1 = 0, HW2 = 0, HW3 = 0, Attendance = 0, Project = 0;
}
