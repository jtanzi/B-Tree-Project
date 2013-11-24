/*
Node class header file
*/

#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

class Node

{
	private:
		
		int tp0, tp1, tp2;  //Internal node pointers
		int n_type;  //Node type
		int SSN1, SSN2, SSN3;  //Keys
		int rid1, rid2, rid3;  //Record IDs
		int sib_p;  //Sibling pointer
		int addr;  //Page ID of node (address)
	

	public:

		//Constructor
		Node();
		Node(int type);

		void clear();

		//Page Management
		void load_from_page(int pid, string memspace[2000][500]);
		void write_to_page(int pid, string memspace[2000][500]);
		string pad_value(int value, int length);
		int unpad_value(string value);

		//Getters and Setters
		int get_n_type();
		int get_tp(int tp_num);
		int get_SSN(int ssn_num);
		int get_rid(int rid_num);
		int get_sib_p();
		int get_addr();
		
		void set_n_type(int value);
		void set_tp(int tp_num, int value);
		void set_SSN(int ssn_num, int value);
		void set_rid(int rid_num, int value);
		void set_sib_p(int value);
		
		//Operator overloading
		friend ostream &operator<<(ostream &out, Node a);
};

#endif
