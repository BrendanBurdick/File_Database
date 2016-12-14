/* Name: Brendan Burdick
 * Class: Object Oriented Programming Using C++
 * Professor: Andrew Jung
 * Date Produced: December 10th, 2016
 * 
 * Purpose of this (.h) file:
 * 
 * This header file defines all class prototypes.
 * */
#include <string>
#include <fstream>
using namespace std;
class newStudent
{
	private:
		string fullName, schID, schoolYear, Department;
		double Midterm, FinalExam, HW1, HW2, HW3, Attendance, Project;
	
	public:
		newStudent(); //Default Constructor.
		newStudent(string Name, string ID, string schYear, string dept, double midtermEx, double finalEx, double firstHW, double secHW, double thirHW, double attend, double proj); //Enhanced Constructor. Used for actual inputted data when creating new students.
		double calcExamAverage(double grade1, double grade2); //Takes in midterm and final grades, and calculates the student's exam average.
		double calcHWAverage(double gr1, double gr2, double gr3); //Takes in HW1, HW2, and HW3 grades, and calculates the student's homework average.
		double calcOverallGrade(double exams, double homework, double projGrade, double attGrade); //Takes in Exam Average, HW Average, Project, and Attendance Grade, and calculates overall grade.
		string calcLetterGrade(double gradeToTranslate); //Takes in the overall grade and translates it into a letter grade.
		void headerDesign(); //Creates a new file. Key note is the header is added.
		void writeTo(ofstream &fileStream, double ExamAverage, double HWAverage, double overallGrade, string letterGrade); //Writes data new student to a file.
		void bulkOfProg(); //Function prototype for function that runs a bulk of the program. (Including file creation)
		void createNewStudent(string filename); //Function that creates a new student and adds data to the file.
		void displayDatabase(ifstream &fileToReadFrom); //Displays all contents of a file.
		int makeASearch(string filename); //Uses serch terms to locate users based on matched values.
		~newStudent(); //Destructor.
};
