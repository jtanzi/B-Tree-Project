#include <iostream>
#include <sstream>
#include <cstdlib>
#include "Tree.h"
#include "Node.h"

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
	Tree tree = Tree();
	Node nodeA = Node();
	nodeA.set_n_type(0);

	/*
	Node node1 = Node();
	cout << "node1: " << node1.get_tp(0) << " " << node1.get_tp(1) << " "
		<< node1.get_tp(2) << " "  << node1.get_SSN(1) << " "
		<< node1.get_SSN(2) << " " << node1.get_SSN(3) << endl
		<< node1.get_rid(1) << " " << node1.get_rid(2) << " "
		<< node1.get_rid(3) << endl << node1.get_sib_p() << endl;

	string str = pad_value(5, 4);
	int tp_num = unpad_value(str);
	node1.set_tp(1, tp_num);
	node1.set_SSN(1, "100");
	node1.set_rid(2, 50);
	node1.set_sib_p(3);

	cout << "node1: " << node1.get_tp(0) << " " << node1.get_tp(1) << " "
		<< node1.get_tp(2) << " "  << node1.get_SSN(1) << " "
		<< node1.get_SSN(2) << " " << node1.get_SSN(3) << endl
		<< node1.get_rid(1) << " " << node1.get_rid(2) << " "
		<< node1.get_rid(3) << endl << node1.get_sib_p() << endl;
	*/


} //end main

