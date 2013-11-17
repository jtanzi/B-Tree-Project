#include <iostream>
#include <sstream>
#include <cstdlib>
#include "Tree.h"
#include "Node.h"

using namespace std;


//Function Declaration



//Main Program
int main()
{

	string memspace[2000][500];
	Tree tree = Tree();
	Node nodeA = Node();
	Node nodeB = Node();
	Node nodeC = Node();
	nodeA.set_tp(0, 1);
	nodeA.set_SSN(1, 10);
	nodeA.set_tp(1, 2);
	nodeB.set_n_type(1);
	nodeB.set_SSN(1, 3);
	nodeB.set_rid(1, 1);
	nodeB.set_SSN(2, 5);
	nodeB.set_rid(2, 2);
	nodeB.set_sib_p(2);
	nodeC.set_n_type(1);
	nodeC.set_SSN(1, 25);
	nodeC.set_rid(1, 3);
	nodeC.set_SSN(2, 36);
	nodeC.set_rid(2, 4);
	
	nodeA.write_to_page(0, memspace);
	nodeB.write_to_page(1, memspace);
	nodeC.write_to_page(2, memspace);

	cout << "nodeA: " << nodeA;
	cout << "nodeB: " << nodeB;
	cout << "nodeC: " << nodeC;
	cout << "------------------" << endl;

	nodeA.load_from_page(0, memspace);
	nodeB.load_from_page(1, memspace);
	nodeC.load_from_page(2, memspace);

	cout << "nodeA: " << nodeA;
	cout << "nodeB: " << nodeB;
	cout << "nodeC: " << nodeC;

	cout << "Search test:" << tree.search(25, memspace) << endl;

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

