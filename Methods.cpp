#include "Hospital.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// HUMAN CLASS METHODS
Human::Human(string n, string s, int a):
	name(n), surname(s), age(a) {}

// PATIENT CLASS METHODS
Patient::Patient(string n, string s, int a, string en, string ex, string i):
	Human(n, s, a), enter(en), exit(ex), illness(i) {}

void Patient::printInfo()
{
	fstream patientFile;
	patientFile.open("pList.txt", fstream::out | fstream::app);
	// opening file only for write at the end of the file.
	try
	{
		if (patientFile.is_open()) // checks if the file is associated.
		{
			patientFile << Human::name << endl;
			patientFile << Human::surname << endl;
			patientFile << Human::age << endl;
			patientFile << Patient::enter << endl;
			patientFile << Patient::exit << endl;
			patientFile << Patient::illness << endl;
			patientFile << endl;
		}
		else
			throw 30; // integer number for the error.
	}
	catch (int e)
	{
		cout << "ERROR: File Could Not Opened. Error no:" << e << endl;
		// if the file is not associated with the target file sends an error.
	}
}

// DOC CLASS METHODS
Doc::Doc(string n, string s, int a, string st, string re):
	Human(n, s, a), start(st), retire(re) {}

void Doc::printInfo()
{
	fstream doctorFile;
	doctorFile.open("dList.txt", fstream::out | fstream::app);
	// opening file only for write at the end of the file.
	try
	{
		if (doctorFile.is_open()) // checks if the file is associated.
		{
			doctorFile << Human::name << endl;
			doctorFile << Human::surname << endl;
			doctorFile << Human::age << endl;
			doctorFile << Doc::start << endl; 
			doctorFile << Doc::retire << endl;
			doctorFile << endl;
		}
		else
			throw 40; // integer number for the error.
	}
	catch (int e)
	{
		cout << "ERROR: File Could Not Opened. Error no:" << e << endl;
		// if the file is not associated with the target file sends an error.
	}
}