/*
Tree class functions definitions file
*/

#include <iostream>
#include <stack>
#include <queue>
#include "Tree.h"
#include "Node.h"

using namespace std;

//Construction
/*
Tree constructor
*/
Tree::Tree()
{	
	//Set root ID
	root_pid = 0;
	
	//Populate free queue with all page IDs
	for (int i = 0; i < 2000; i++)
	{
		free.push(i);
	}

} //end constructor

//Getters and Setters

/*
Function Name: get_root
Description: Returns the current page ID the Tree instance root is set to
Arguments: None
Returns: The ID of the page the root resides in
*/
int Tree::get_root()
{
	return root_pid;
} //end get_root

/*
Function Name: set_root
Description: Sets the root page ID used by the Tree instance
Arguments: pid, the integer page ID to set the root to
Returns: None
*/
void Tree::set_root(int pid)
{
	root_pid = pid;
} //end set_root

/*
Function Name: search
Description: Search for a record by key
Arguments: k, the search key; memspace, the memory space to search
Returns: The record ID associated with the search key as an integer
*/
int Tree::search(int k, string memspace[2000][500])
{
	return tree_search(k, root_pid, memspace);
} //end search

/*
Function Name: tree_search
Description: Searches the index for the requested key value
Arguments: k, the integer value of the search key; pid, the page ID to start
	searching from; memspace, the memory space array.
Returns: The record ID of the associated key value
*/
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

/*
Function Name: insert_record
Description: Inserts a new record into the database and updates the search index
Arguments: k, an integer that is the key value (SSN) to insert; record_id, an 
	integer containing the record ID value to be inserted;
	memspace, the memory space used by the system
Returns: None
*/
void Tree::insert_record(int k, int record_id, string memspace[2000][500])
{
	stack<int> parents; /*Keeps track of parent node page IDs for 
					  recursive calls*/
	Node current_node = Node();

	//Check for empty memory, write first record to first page if so
	if (used.empty())
	{
		current_node.set_SSN(1, k);
		current_node.set_rid(1, record_id);
		current_node.write_to_page(root_pid, memspace);
		used.push(root_pid);
		free.pop();
		return;
	}
	
	//Load root node to memory	
	current_node.load_from_page(root_pid, memspace);
	used.push(root_pid);
	free.pop();

	
	//Insertion algorithm
	while (current_node.get_n_type() == 0)
	{
		int node_addr = current_node.get_addr();

		parents.push(node_addr);
		
		int pointer_count = 0;
		
		for (int i = 0; i < 3; i++)
		{
			if (current_node.get_tp(i) != 9999)
			{
				pointer_count++;
			}
		}

		if (k <= current_node.get_SSN(1))
		{
			node_addr = current_node.get_tp(0);
			current_node.clear();
			current_node.load_from_page(node_addr, memspace);
		}
		else if (k > current_node.get_SSN(2))
		{
			node_addr = current_node.get_tp(1);
			current_node.clear();
			current_node.load_from_page(node_addr, memspace);
		}

	} //end while

} //end insert_record

/*
Function Name: delete_record
Description: Deletes a record from the database and updates the search index
Arguments:  k, an integer that is the key value (SSN) to delete; 
	memspace, the memory space used by the system
Returns: None
*/
void delete_record(int k, string memspace[2000][500])
{

}//end delete_record
