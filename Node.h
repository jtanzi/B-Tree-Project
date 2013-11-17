/*
Node class header file
*/

#include <iostream>

using namespace std;

class Node

{
	private:
		
		int tp0, tp1, tp2;  //Internal node pointers
		int n_type;  //Node type
		string SSN1, SSN2, SSN3;  //Keys
		int rid1, rid2, rid3;  //Record IDs
		int sib_p;  //Sibling pointer
	

	public:

		//Constructor
		Node();

		//Page Management
		void load_from_page(int pid, string memspace[2000][500]);
		void write_to_page(int pid, string memspace[2000][500]);

		//setters and Setters
		int get_n_type();
		int get_tp(int tp_num);
		string get_SSN(int ssn_num);
		int get_rid(int rid_num);
		int get_sib_p();
		
		void set_n_type(int value);
		void set_tp(int tp_num, int value);
		void set_SSN(int ssn_num, string value);
		void set_rid(int rid_num, int value);
		void set_sib_p(int value);

};
