#include <iostream>
#include <sstream>
#include <cstdlib>
#include "Tree.h"

using namespace std;


//Function Declaration

/*
Function Name: pad_value
Description: Takes a integer value and returns a string of a given
	length padded with 0's where needed in front
Arguments: value, the integer value to convert; length, the length of the
	final string
*/
string pad_value(int value, int length)
{
	//Convert value to a string
	ostringstream intstring;
	intstring << value;
	string initial_str = intstring.str();

	//Pad string with the appropriate number of zeros in front
	string padded_str;
	for (int i = 0; i < (length - initial_str.length()); i++)
	{
		padded_str.append("0");
	}
	padded_str.append(initial_str);

	return padded_str;
}

/*
Function Name: unpad_value
Description: Takes a string and returns an integer representation of it
Arguments: value, the string to convert
*/
int unpad_value(string value)
{
	int int_value;
	istringstream (value) >> int_value;
	return int_value;
}


//Main Program
int main()
{

	string memspace[2000][500];
	for (int i = 0; i < 2000; i++)
	{
		string pid = pad_value(i, 4);
		memspace[i][0] = pid;
	}

	cout << memspace[50][0] << endl;


} //end main

