/*
Tree class functions definitions file
*/

#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <vector>
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
	cout << "Search node: " << endl << current_node;

	if (current_node.get_n_type() == 1)  //node is a leaf
	{
		if (current_node.get_SSN(1) == k)
		{
			n_pid = pid;
			return current_node.get_rid(1);
		}
		else if (current_node.get_SSN(2) == k)
		{
			n_pid = pid;
			return current_node.get_rid(2);
		}
		else if (current_node.get_SSN(3) == k)
		{
			n_pid = pid;
			return current_node.get_rid(3);
		}
		else
		{
			n_pid = pid;
			return -1;
		}
	}
	else  //node is internal
	{
		int k0 = current_node.get_SSN(1);
		int k1 = current_node.get_SSN(2);
		parents.push(pid);
		
		if (k < k0)
		{
			return tree_search(k, current_node.get_tp(0), memspace);
		}
		else if (k0 <= k && k < k1)
		{
			return tree_search(k, current_node.get_tp(1), memspace);
		}
		else
		{
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
	
	Node n = Node();
	//cout << "From in insert: " << k << endl;
	int result = search(k, memspace);
	//cout << "Insert: " << result << endl;

	if (result == record_id)
	{
		return;
	}
	
	if (result == -1)
	{
		//cout << "Insert result: " << n_pid << " " << result << " " 
			//<< parents.top() << endl;
		n.load_from_page(n_pid, memspace);

		if (used.empty())
		{
			cout << "F1\n";
			n.clear();
			used.push(n_pid);
			free.pop();
		}
		cout << n;

		//Check if any SSN slots are free
		int full_slot_count = 0;

		for (int i = 1; i < 4; i++)
		{
			if (n.get_SSN(i) != 999999999)
			{
				full_slot_count = full_slot_count + 1;
			}
		}
	
		cout << "full_slot_count = " << full_slot_count << endl;

		//Check for available slots and update page records
		if (full_slot_count < 3) //record slots available on page
		{
			if (k < n.get_SSN(1))
			{
				n.set_SSN(3, n.get_SSN(2));
				n.set_rid(3, n.get_rid(2));
				n.set_SSN(2, n.get_SSN(1));
				n.set_rid(2, n.get_rid(1));
				n.set_SSN(1, k);
				n.set_rid(1, record_id);
			}
			else if (k > n.get_SSN(1) && k < n.get_SSN(2))
			{
				n.set_SSN(3, n.get_SSN(2));
				n.set_rid(3, n.get_rid(2));
				n.set_SSN(2, k);
				n.set_rid(2, record_id);				
			}
			else if (k > n.get_SSN(2))
			{
				n.set_SSN(3, k);
				n.set_rid(3, record_id);				
			}
		}
		
		cout << n;
		//Update page	
		n.write_to_page(n_pid, memspace);
		
	}	

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
