#include <iostream>
#include <sstream>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include "Tree.h"
#include "Node.h"

using namespace std;


//Function Declaration



//Main Program
int main()
{
	char input1[8];
	string op;
	int key;
	int rid;


	string memspace[2000][500];
	Tree tree = Tree();
	/*
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

	for (int i = 0; i < 3; i++)
	{
		tree.used.push(i);
		tree.free.pop();	
	}

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

	cout << "Search test:" << tree.search(3, memspace) << endl
		<< tree.search(5, memspace) << endl
		<< tree.search(300, memspace) << endl
		<< tree.search(20, memspace) << endl;

	cout <<"Start Insert Test\n";
	tree.insert_record(20, 250, memspace);

	nodeA.load_from_page(0, memspace);
	nodeB.load_from_page(1, memspace);
	nodeC.load_from_page(2, memspace);

	cout << "nodeA: " << nodeA;
	cout << "nodeB: " << nodeB;
	cout << "nodeC: " << nodeC;
	*/
	cout << "$";
	cin >> input1 >> key >> rid;
	while(true)
	{
		cout << input1 << " " << key << " " << rid << endl;
		
		if (strcmp(input1, "Insert") == 0)
		{
			tree.insert_record(key, rid, memspace);
		}
		else if (strcmp(input1, "Search") == 0)
		{
			cout << tree.search(key, memspace) << endl;
		}
		else if (strcmp(input1, "Output") == 0)
		{
			break;
		}
		cout << "$";
		cin >> input1 >> key >> rid;

	}

return 0;

} //end main



