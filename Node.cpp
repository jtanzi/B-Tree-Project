/*
Node class functions definitions file
*/

#include <iostream>
#include <sstream>
#include "Node.h"

using namespace std;

//Construction
/*
Node constructors
*/
Node::Node()
{	
	tp0 = 9999;
	tp1 = 9999;
	tp2 = 9999;
	n_type = 1;
	SSN1 = 999999999;
	SSN2 = 999999999;
	SSN3 = 999999999;
	rid1 = 999999;
	rid2 = 999999;
	rid3 = 999999;
	sib_p = 9999;
}

Node::Node(int type)
{
	n_type = type;	
	tp0 = 9999;
	tp1 = 9999;
	tp2 = 9999;
	SSN1 = 999999999;
	SSN2 = 999999999;
	SSN3 = 999999999;
	rid1 = 999999;
	rid2 = 999999;
	rid3 = 999999;
	sib_p = 9999;
}

/*
Function Name: clear
Description: Clears node values (resets to original new state)
Arguments: None
Returns: None
*/
void Node::clear()
{
	tp0 = 9999;
	tp1 = 9999;
	tp2 = 9999;
	int n_type = 1;
	SSN1 = 999999999;
	SSN2 = 999999999;
	SSN3 = 999999999;
	rid1 = 999999;
	rid2 = 999999;
	rid3 = 999999;
	sib_p = 9999;
}

/*
Function Name: load_from_page
Description: Loads page contents to an instance of a Node
Arguments: pid, the page ID to load from; memspace, the memory space
Returns: None
*/
void Node::load_from_page(int pid, string memspace[2000][500])
{
	//Load the page into memory
	
	string a[8];

	if (pid == 9999)  //Check for null pointer and exit early if found
	{
		return;
	}
	else 
	{
		addr = pid;
	}

	for (int i = 0; i < 8; i++)
	{
		a[i] = memspace[pid][i];
	}

	//Parse the page records according to node type
	
	int node_type = unpad_value(a[0]);


	if (node_type == 0) //Internal node detected
	{
		n_type = 0;
		tp0 = unpad_value(a[1]);  
		SSN1 = unpad_value(a[2]);
		tp1 = unpad_value(a[3]);
		SSN2 = unpad_value(a[4]);
		tp2 = unpad_value(a[5]);
		sib_p = unpad_value(a[7]);
	}
	else  //Leaf node detected
	{
		n_type = 1;
		SSN1 = unpad_value(a[1]);
		rid1 = unpad_value(a[2]);
		SSN2 = unpad_value(a[3]);
		rid2 = unpad_value(a[4]);
		SSN3 = unpad_value(a[5]);
		rid3 = unpad_value(a[6]);
		sib_p = unpad_value(a[7]);
	}
}

/*
Function Name: write_to_page
Description: Writes contents of a Node instance to a page
Arguments: pid, the page ID to write to; memspace, the memory space
Returns: None
*/
void Node::write_to_page(int pid, string memspace[2000][500])
{
	//Parse and write to page according to node type

	if (n_type == 0) //Internal node format
	{
		memspace[pid][0] = pad_value(n_type, 1);
		memspace[pid][1] = pad_value(tp0, 4);
		memspace[pid][2] = pad_value(SSN1, 9);
		memspace[pid][3] = pad_value(tp1, 4);
		memspace[pid][4] = pad_value(SSN2, 9);
		memspace[pid][5] = pad_value(tp2, 4);
	}
	else  //Leaf node format
	{
		memspace[pid][0] = pad_value(n_type, 1);
		memspace[pid][1] = pad_value(SSN1, 9);
		memspace[pid][2] = pad_value(rid1, 6);
		memspace[pid][3] = pad_value(SSN2, 9);
		memspace[pid][4] = pad_value(rid2, 6);
		memspace[pid][5] = pad_value(SSN3, 9);
		memspace[pid][6] = pad_value(rid3, 6);
		memspace[pid][7] = pad_value(sib_p, 4);
	}
	
}

/*
Function Name: pad_value
Description: Takes a integer value and returns a string of a given
	length padded with 0's where needed in front
Arguments: value, the integer value to convert; length, the length of the
	final string
*/
string Node::pad_value(int value, int length)
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
int Node::unpad_value(string value)
{
	int int_value;
	istringstream (value) >> int_value;
	return int_value;
}

//***Getters***

/*
Function Name: 
Description: 
Arguments: 
Returns: 
*/
int Node::get_n_type()
{
	return n_type;	
}

/*
Function Name: 
Description: 
Arguments: 
Returns: 
*/
int Node::get_tp(int tp_num)
{
	switch (tp_num)
	{
		case 0:
			return tp0;
	
		case 1:
			return tp1;

		case 2:
			return tp2;
	}		
}


/*
Function Name: 
Description: 
Arguments: 
Returns: 
*/
int Node::get_SSN(int ssn_num)
{
	switch (ssn_num)
	{
		case 1:
			return SSN1;
	
		case 2:
			return SSN2;

		case 3:
			return SSN3;
	}	
}

/*
Function Name: 
Description: 
Arguments: 
Returns: 
*/
int Node::get_rid(int rid_num)
{
	switch (rid_num)
	{
		case 1:
			return rid1;
	
		case 2:
			return rid2;

		case 3:
			return rid3;
	}
}

/*
Function Name: 
Description: 
Arguments: 
Returns: 
*/
int Node::get_sib_p()
{
	return sib_p;
}

/*
Function Name: 
Description: 
Arguments: 
Returns: 
*/
int Node::get_addr()
{
	return addr;
}

//Setters

/*
Function Name: 
Description: 
Arguments: 
Returns: 
*/
void Node::set_n_type(int value)
{
	n_type = value;	
}

/*
Function Name: 
Description: 
Arguments: 
Returns: 
*/
void Node::set_tp(int tp_num, int value)
{
	switch (tp_num)
	{
		case 0:
			tp0 = value;
			break;

		case 1:
			tp1 = value;
			break;

		case 2:
			tp2 = value;
			break;
	}		
}


/*
Function Name: 
Description: 
Arguments: 
Returns: 
*/
void Node::set_SSN(int ssn_num, int value)
{
	switch (ssn_num)
	{
		case 1:
			SSN1 = value;
			break;

		case 2:
		 	SSN2 = value;
			break;

		case 3:
			SSN3 = value;
			break;
	}	
}

/*
Function Name: 
Description: 
Arguments: 
Returns: 
*/
void Node::set_rid(int rid_num, int value)
{
	switch (rid_num)
	{
		case 1:
			rid1 = value;
			break;

		case 2:
			rid2 = value;
			break;

		case 3:
			rid3 = value;
			break;
	}
}

/*
Function Name: 
Description: 
Arguments: 
Returns: 
*/
void Node::set_sib_p(int value)
{
	sib_p = value;
}

//Operator overloading
ostream &operator<<(ostream &out, Node a) 
{

	if (a.get_n_type() == 0)
	{
		out << a.get_tp(0) << " " << a.get_SSN(1) << " "
			<< a.get_tp(1) << " " << a.get_SSN(2)  << " "
			<< a.get_tp(2) << endl;
	}
	else
	{
		out << a.get_SSN(1) << " (" << a.get_rid(1) << ") "
			<< a.get_SSN(2) << " (" << a.get_rid(2) << ") "
			<< a.get_SSN(3) << " (" << a.get_rid(3) << ") " << endl;
	}

     return out;
}

