/* Name: Brendan Burdick
 * Class: Object Oriented Programming Using C++
 * Professor: Andrew Jung
 * Date Produced: December 10th, 2016
 * 
 * FINAL EXAM
 * 
 * Purpose of Program:
 * 
 * This purpose of this program is to make simple database to store and retrieve student’s information including name, id, mid-term and final exam, homework, project, and attendance. 
 * To store student’s information, the program allows creating a file and saving student’s information in it with table structure.
 * 
 * First, the program asks a user to input student’s information that includes name of the student, his/her mid-term and final exam score, each homework score, attendance score, 
 * project score.  Then it calculates exam average, homework average, overall numeric grade, and letter grade.  All information must be saved into the file.
 * 
 * The program will allow searching student’s information when the instructor wants information for a specific student. When the program is executed, it will ask you first to enter a
 * file name. If the file is exists, then the program will ask you whether you want to add info or search info.. If the file is not existed, then the program will create automatically
 * the file you request and ask you whether you want to add info to the file or not. Once the instructor wants to find information from saved data, the program will ask the words to be
 * searched. Program will display whole information regarding the search term. For example, the user enters “Computer Science” as a searching word, then the program finds matching words
 * in the file. Once the program found words matched, it will display whole information related to the term “Computer Science” such as name of the student, his/her mid-term and final
 * exam score, exam average, each homework score, homework average, attendance score, project score, overall numeric grade, and letter grade. The program will display information with
 * nicely designed format.
 * 
 * The weight average of the grade is based on following:
 * Exam: 50%
 * Homework: 20%
 * Project: 20%
 * Attendance: 10%
 * 
 * */
#include <iostream>
#include "newStudent.h"
using namespace std;

int main()
{
	newStudent startProgram; //Create Student Object.
	startProgram.bulkOfProg(); //Call first function.
}
