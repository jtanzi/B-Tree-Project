/*
Tree class functions definitions file
*/

#include <iostream>
#include "Tree.h"
#include "Node.h"

using namespace std;

//Construction
/*
Tree constructor
*/
Tree::Tree()
{
	root_pid = 0;
}

//Getters and Setters
int Tree::get_root()
{
	return root_pid;
}

void Tree::set_root(int pid)
{
	root_pid = pid;
}

int Tree::search(int k, string memspace[2000][500])
{
	return tree_search(k, root_pid, memspace);
}

int Tree::tree_search(int k, int pid, string memspace[2000][500])
{
	Node current_node = Node();
	current_node.load_from_page(pid, memspace);
	//cout << "F1\n";

	if (current_node.get_n_type() == 1)  //node is a leaf
	{
		if (current_node.get_SSN(1) == k)
		{
			//cout << "F6\n";
			return current_node.get_rid(1);
		}
		else if (current_node.get_SSN(2) == k)
		{
			//cout << "F7\n";
			return current_node.get_rid(2);
		}
		else if (current_node.get_SSN(3) == k)
		{
			//cout << "F8\n";
			return current_node.get_rid(3);
		}
		else
		{
			//cout << "F9\n";
			return -1;
		}
	}
	else  //node is internal
	{
		int k0 = current_node.get_SSN(1);
		int k1 = current_node.get_SSN(2);
		
		//cout << "F2\n";

		if (k < k0)
		{
			//cout << "F3\n";
			return tree_search(k, current_node.get_tp(0), memspace);
		}
		else if (k0 <= k && k < k1)
		{
			//cout << "F4\n";
			return tree_search(k, current_node.get_tp(1), memspace);
		}
		else
		{
			//cout << "F5\n";
			return tree_search(k, current_node.get_tp(2), memspace);
		}
	}
} //end tree_search
