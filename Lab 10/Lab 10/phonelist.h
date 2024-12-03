#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

/*
	Course: COMP 333 - C++
	Student: Brigitte Demers
	Assignment: Lab 10
	Specification file for the directory.
*/

struct Directory
{
	string name; // Name of Person/Company.
	int areaCode; // Area code for the phone number.
	int phoneNo; // The phone number.
	Directory* link; // Pointer to the next node in the list.
};

class PhoneList
{
private:
	Directory* firstPtr; // Pointer to the first directory object.
	string title; // Phone list title
	int noDir; // Total number of directories in the list.
public:
	// Constructors:
	PhoneList(string/*title*/);
	~PhoneList();
	void showList(ostream&/*file or cout*/) const;
	void addDirectory(string/*name*/, int/*area code*/, int/*phone number*/);
	void removeDirectory(string/*title*/);
	int getNoDirectories() const;
	string getTitle() const;
};