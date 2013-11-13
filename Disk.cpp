/*
Disk class functions definitions file
*/

#include <iostream>
#include <sstream>
#include "Disk.h"

using namespace std;

//Construction
/*
Disk constructor
*/
Disk::Disk()
{
	for (int i = 0; i < 1000000; i++)
	{
		diskspace[i] = '0';
	}
}


/*
disk_write function
Arguments: start, an int representing the start index; end, an int representing
the end index; value, the integer value being written
Returns: None
*/
void Disk::disk_write(int start, int end, int value, int length)
{
	//Convert value to a string
	string writeval = pad_value(value, length);
	
	//Loop through string to write to the diskspace
	for (int i = start; i <= end; i++)
	{
		diskspace[i] = writeval[i - start];
	}
}

/*
disk_write function
Arguments: start, an int representing the start index; end, an int representing
the end index; value, the integer value being written
Returns: None
*/
string Disk::pad_value(int value, int length)
{
	//Convert value to a string
	ostringstream intstring;
	intstring << value;
	string initial_str = intstring.str();
	cout << "initial_str: " << initial_str << endl;

	//Pad string with the appropriate number of zeros in front
	string padded_str;
	for (int i = 0; i < (length - initial_str.length()); i++)
	{
		padded_str.append("0");
		cout << padded_str << endl;
	}
	padded_str.append(initial_str);
	cout << "padded_str: " << padded_str << endl;

	return padded_str;
}

//Page management functions
/*
request_page function
Arguments: pid (Page ID of the page to request)
Returns a Page with the ID requested
*/
Page Disk::request_page(int pid)
{
	Page new_Page = Page(pid);
	update_occupied(pid);

	return new_Page;
}


void Disk::update_occupied(int pid)
{
	occupied.push(pid);
	free.pop();
}	

std::queue<int> Disk::get_occupied()
{
	return occupied;
}	




