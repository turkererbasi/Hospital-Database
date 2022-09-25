#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Human // base class.
{
protected:
	string name, surname;
	int age;
public:
	Human(string, string, int);
};

class Patient : public Human // Derived patient class.
{
protected:
	string enter, exit, illness;
public:
	Patient(string, string, int, string, string, string);
	void printInfo();
};

class Doc : public Human // Derived doctor class.
{
protected:
	string start, retire;
public:
	Doc(string, string, int, string, string);
	void printInfo();
};