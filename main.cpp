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

	Node n = Node(1);

	for (int i = 0; i < 2000; i++)
	{
		n.write_to_page(i, memspace);
	}


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



