#include "Hospital.h"
#include <iostream>
#include <fstream> // for file handling
#include <string>

using namespace std;

void patientList() // reading from patient file.
{
	fstream patientFile; // file object of patients.
	patientFile.open("pList.txt", fstream::in); // opening file only for read.
	try
	{
		if (patientFile.is_open()) // checks if the file is associated.
		{
			cout << "\n\t->The Patient List Shown Below" << endl;
			string str; // string to hold lines of txt file.
			while (!patientFile.eof()) // reads until end of the file.
			{
				getline(patientFile, str); // gets the text line by line.
				cout << str << endl; // printing to the console.
			}
		}
		else 
			throw 10; // integer number for the error.
	}
	catch (int a)
	{
		cout << "ERROR: File Could Not Opened. Error no:" << a << endl;
		// if the file is not associated with the target file sends an error.
	}
	patientFile.close(); // closing the file.
}

void doctorList() // reading from doctor file.
{
	fstream doctorFile; // file object of doctors.
	doctorFile.open("dList.txt", fstream::in); // opening file only for read.
	try
	{
		if (doctorFile.is_open()) // checks if the file is associated.
		{
			cout << "\n\t->The Doctor List Shown Below" << endl;
			string str; // string to hold lines of txt file.
			while (!doctorFile.eof()) // reads until end of the file.
			{
				getline(doctorFile, str); // gets the text line by line.
				cout << str << endl; // printing to the console.
			}
		}
		else
			throw 20; // integer number for the error.
	}
	catch (int a)
	{
		cout << "ERROR: File Could Not Opened. Error no:" << a << endl;
		// if the file is not associated with the target file sends an error.
	}
	doctorFile.close(); // closing the file.
}

Doc askDoc() // getting the information of the doctor.
{
	int age;
	string name, surname, start, retire = "Retiring date undefined.";
	cout << "Please enter the information in this order:" << endl;
	cout << "\t Name, Surname, Age, Starting Date (DD.MM.YYYY)." << endl;
	cin >> name >> surname >> age >> start;
	char c;
	cout << "Do you also want to enter Retiring Date? (y/n)" << endl;
	cin >> c;
	if (c == 'y')
	{
		cout << "Please enter Retiring Date:" << endl;
		cin >> retire;
		Doc A(name, surname, age, start, retire); // creating doctor object.
		return A;
	}
	else if (c == 'n')
	{
		Doc B(name, surname, age, start, retire); // creating doctor object.
		return B;
	}
}

Patient askPatient() // getting the information of the patient.
{
	int age;
	string name, surname, enter, exit = "Exit date undefined.", illness = "Illness undefined.";
	cout << "Please enter the information in this order:" << endl;
	cout << "\t Name, Surname, Age, Date of Entrance (DD.MM.YYYY)" << endl;
	cin >> name >> surname >> age >> enter;
	char c;
	cout << "Do you also want to enter Exit Date and Illness? (y/n)" << endl;
	cin >> c;
	if (c == 'y')
	{
		cout << "Please enter Exit Date (DD.MM.YYYY) and Illness:" << endl;
		cin >> exit >> illness;
		Patient A(name, surname, age, enter, exit, illness); // creating patient object.
		return A;
	}
	else if (c == 'n')
	{
		Patient B(name, surname, age, enter, exit, illness); // creating patient object.
		return B;
	}
}

void patientSearchName()
{
	string search; // key word for search.
	cout << "Please enter the name you want to search:" << endl;
	cin >> search;
	fstream patientFile; // file object of patients.
	patientFile.open("pList.txt", fstream::in); // opening file only for read.
	int match = 0;
	try
	{
		if (patientFile.is_open())
		{
			cout << "\n\t->The Result Is Shown Below" << endl;
			string str;
			while (!patientFile.eof())
			{
				getline(patientFile, str); // gets the text line by line.
				if (str == search)
				{
					match++;
					for (int i = 0; i < 6; i++)
					{
						cout << str << endl;
						getline(patientFile, str); // gets the text line by line.
					}
					cout << "------------" << endl;
				}
			}
			cout << endl;
			if (match == 0)
			{
				cout << "No matches found." << endl;
			}
			else
			{
				cout << "Match count: " << match << endl;
			}
		}
		else
			throw 50; // integer number for the error.
	}
	catch (int a)
	{
		cout << "ERROR: File Could Not Opened. Error no:" << a << endl;
		// if the file is not associated with the target file sends an error.
	}
	patientFile.close(); // closing the file.
}

void doctorSearchName()
{
	string search; // key word for search.
	cout << "Please enter the name you want to search:" << endl;
	cin >> search;
	fstream doctorFile; // file object of patients.
	doctorFile.open("dList.txt", fstream::in); // opening file only for read.
	int match = 0;
	try
	{
		if (doctorFile.is_open())
		{
			cout << "\n\t->The Result Is Shown Below" << endl;
			string str;
			while (!doctorFile.eof())
			{
				getline(doctorFile, str); // gets the text line by line.
				if (str == search)
				{
					match++;
					for (int i = 0; i < 5; i++)
					{
						cout << str << endl;
						getline(doctorFile, str); // gets the text line by line.
					}
					cout << "------------" << endl;
				}
			}
			cout << endl;
			if (match == 0)
			{
				cout << "No matches found." << endl;
			}
			else
			{
				cout << "Match count: " << match << endl;
			}
		}
		else
			throw 60; // integer number for the error.
	}
	catch (int a)
	{
		cout << "ERROR: File Could Not Opened. Error no:" << a << endl;
		// if the file is not associated with the target file sends an error.
	}
	doctorFile.close(); // closing the file.
}

int main() // DON'T FORGET TO WRITE INHERITANCE.
{
	char rp;
	do
	{
		cout << "\t\t\t ________________________________________" << endl;
		cout << "\t\t\t|           HOSPITAL DATA BASE           |" << endl;
		cout << "\t\t\t|                                        |" << endl;
		cout << "\t\t\t|PRESS (1) TO SEE THE PATIENT LIST.      |" << endl;
		cout << "\t\t\t|PRESS (2) TO SEE THE DOCTOR LIST.       |" << endl;
		cout << "\t\t\t|PRESS (3) TO REGISTER A PATIENT.        |" << endl;
		cout << "\t\t\t|PRESS (4) TO REGISTER A DOCTOR.         |" << endl;
		cout << "\t\t\t|PRESS (5) TO SEARCH PATIENTS BY NAME.   |" << endl;
		cout << "\t\t\t|PRESS (6) TO SEARCH DOCTORS BY NAME.    |" << endl;
		cout << "\t\t\t|PRESS (7) TO EXIT.                      |" << endl;
		cout << "\t\t\t|________________________________________|" << endl;
		cout << endl << endl; // MENU.

		int choose;
		cin >> choose;
		switch (choose)
		{
		case 1: // LIST PATIENT
			patientList();
			break;
		case 2: // LIST DOC
			doctorList();
			break;
		case 3: // REGISTER PATIENT
			askPatient().printInfo();
			break;
		case 4: // REGISTER DOC
			askDoc().printInfo();
			break;
		case 5: // SEARCH PATIENTS BY NAME
			patientSearchName();
			break;
		case 6: // SEARCH DOCTORS BY NAME
			doctorSearchName();
			break;
		case 7: // EXIT
			return 0;
			break;
		default:
			cout << "Please enter a valid number." << endl;
			break;
		}
		cout << "Do you want to continue? (y/n)." << endl;
		cin >> rp;
	} while (rp == 'y');
	return 0;
}