#include "phonelist.h"

/*
	Course: COMP 333 - C++
	Student: Brigitte Demers
	Assignment: Lab 10
	Implementation file for the directory.
*/

PhoneList::PhoneList(string initialTitle)
{
	/*
		This ensures there is nothing in the list.
		Thus the list starts with no nodes.
	*/
	firstPtr = NULL;
	/*
		Ensures the title of phone list is initialized with the
		argument passed to the constructor. 
		title from class is initialized to initialTitle in
		the constructor.
	*/
	title = initialTitle;
	/*
		Total number of directories. Since there are non yet
		it is set to zero.
	*/
	noDir = 0;
}

void PhoneList::showList(ostream& output)const
{
	if (firstPtr == NULL)
	{
		output << "No node was found." << endl;
	}
	else
	{
		/*
			This is the 'walker' it will 'walk' down the list and display
			the name, area code, and phone number in each node.
			To start, it is sets walker to point at the same location as 
			firstPtr.
		*/
		Directory* walker = firstPtr;
		while (walker != NULL)
		{
			/*
				This should format PhoneNo as: XXX-XXXX
				I used Chat GPT to help me figure out how
				to format the number.
			*/
			int iPhoneNo = walker->phoneNo;
			string formatPhoneNo = to_string(iPhoneNo / 10000)  // First three digits.
				+ "-" + to_string(iPhoneNo % 10000); // Last four digits.

			output << fixed << setprecision(2);
			output << "My Black Book:" << endl;
			output << "Name:" << setw(25) << "Area Code:"
				<< setw(25) << "Phone Number:" << endl << endl;

			output << walker->name 
				<< setw(25) << walker->areaCode
				<< setw(25) << formatPhoneNo << endl;

			walker = walker->link;
		}

		output << "Number of Directories: " << getNoDirectories() << endl;
	}
}