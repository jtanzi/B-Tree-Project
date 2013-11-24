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
	//cout << "root_pid: " << root_pid << endl;
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
	//cout << "pid: " << pid << endl;
	//cout << "Search node: " << endl << current_node;
	//cout << "Page: ";
	//for (int i = 0; i < 40; i++)
	//{
	//	cout << memspace[pid][i];
	//}
	//cout << endl;

	if (current_node.get_n_type() == 1)  //node is a leaf
	{
		if (current_node.get_SSN(1) == k)
		{
			n_pid = pid;
			cout << "n_pid: " << n_pid << endl;
			cout << "current_node:" << current_node;
			return current_node.get_rid(1);
		}
		else if (current_node.get_SSN(2) == k)
		{
			n_pid = pid;
			cout << "n_pid: " << n_pid << endl;
			cout << "current_node:" << current_node;
			return current_node.get_rid(2);
		}
		else if (current_node.get_SSN(3) == k)
		{
			n_pid = pid;
			cout << "n_pid: " << n_pid << endl;
			cout << "current_node:" << current_node;
			return current_node.get_rid(3);
		}
		else
		{
			n_pid = pid;
			cout << "n_pid: " << n_pid << endl;
			cout << "current_node:" << current_node;
			return -1;
		}
	}
	else  //node is internal
	{
		int k0 = current_node.get_SSN(1);
		int k1 = current_node.get_SSN(2);
		parents.push(pid);
		
		if (k <= k0)
		{
			cout << "k <= k0";
			cout << "n_pid: " << n_pid << endl;
			cout << "current_node:" << current_node;
			return tree_search(k, current_node.get_tp(0), memspace);
		}
		else if (k0 < k && k <= k1)
		{
			cout << "k0 < k && k < k1";
			cout << "n_pid: " << n_pid << endl;
			cout << "current_node:" << current_node;
			return tree_search(k, current_node.get_tp(1), memspace);
		}
		else
		{
			cout << "k > k1";
			cout << "n_pid: " << n_pid << endl;
			cout << "current_node:" << current_node;
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
		//cout << "Insert result: " << n_pid << " " << result << endl;
		n.load_from_page(n_pid, memspace);

		if (used.empty())
		{
			//cout << "F1\n";
			n.clear();
			used.push(n_pid);
			free.pop();
		}
		//cout << n;

		//Check if any SSN slots are free
		int full_slot_count = 0;

		for (int i = 1; i < 4; i++)
		{
			if (n.get_SSN(i) != 999999999)
			{
				full_slot_count = full_slot_count + 1;
			}
		}
	
		//cout << "full_slot_count = " << full_slot_count << endl;

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
			
			cout << "Towards end of Insert: " << endl;
			cout << "n: " << n << endl;
			n.write_to_page(n_pid, memspace);
		}
		else  //Need to split
		{
			Node ns = Node(1);  //Create new sibling leaf node

			if (k < n.get_SSN(1))
			{
				ns.set_SSN(1, n.get_SSN(2));
				ns.set_rid(1, n.get_rid(2));
				ns.set_SSN(2, n.get_SSN(3));
				ns.set_rid(2, n.get_rid(3));
				ns.set_sib_p(n.get_sib_p());

				n.set_SSN(3, 999999999);
				n.set_rid(3, 999999);
				n.set_SSN(2, n.get_SSN(1));
				n.set_rid(2, n.get_rid(1));
				n.set_SSN(1, k);
				n.set_rid(1, record_id);
				n.set_sib_p(free.front());

				//Push to parent node
				push_parent(n.get_SSN(2), n, memspace);
			}
			else if (k < n.get_SSN(2))
			{
				ns.set_SSN(1, n.get_SSN(2));
				ns.set_rid(1, n.get_rid(2));
				ns.set_SSN(2, n.get_SSN(3));
				ns.set_rid(2, n.get_rid(3));
				ns.set_sib_p(n.get_sib_p());

				n.set_SSN(3, 999999999);
				n.set_rid(3, 999999);
				n.set_SSN(2, k);
				n.set_rid(2, record_id);
				n.set_sib_p(free.front());

				//Push to parent node
				push_parent(n.get_SSN(2), n, memspace);
			}
			else if (k < n.get_SSN(3))
			{
				ns.set_SSN(1, k);
				ns.set_rid(1, record_id);
				ns.set_SSN(2, n.get_SSN(3));
				ns.set_rid(2, n.get_rid(3));
				ns.set_sib_p(n.get_sib_p());

				n.set_SSN(3, 999999999);
				n.set_rid(3, 999999);
				n.set_sib_p(free.front());

				//Push to parent node
				push_parent(n.get_SSN(2), n, memspace);
			}
			else  //k > SSN3
			{
				ns.set_SSN(1, n.get_SSN(3));
				ns.set_rid(1, n.get_rid(3));
				ns.set_SSN(2, k);
				ns.set_rid(2, record_id);
				ns.set_sib_p(n.get_sib_p());

				n.set_SSN(3, 999999999);
				n.set_rid(3, 999999);
				n.set_sib_p(free.front());

				//Push to parent node
				push_parent(n.get_SSN(2), n, memspace);
			}
			
			cout << "Towards end of Insert: " << endl;
			cout << "n: " << n << endl << "ns: " << ns;
	
			//Update pages and page management queues
			n.write_to_page(n_pid, memspace);
			ns.write_to_page(n.get_sib_p(), memspace);
			used.push(n.get_sib_p());
			free.pop();			
		} 
	
	}

	//Clear parents stack for next insert or delete
	while (!(parents.empty()))
	{
		parents.pop();
	}

} //end insert_record


/*
Function Name: push_parent
Description: Pushes the appropriate index key from the child node to the parent
	node during a split
Arguments:  k, an integer that is the key value (SSN) to push; 
	n, the Node containing the key value; memspace, the memory space used by 
	the system
Returns: None
*/
void Tree::push_parent(int k, Node n, string memspace[2000][500])
{
	Node p = Node(0);  //Create an internal node
	//cout << "F2\n";
	if (parents.empty()) //Tree empty except for leaf
	{
		//cout << "F8\n";
		p.set_tp(0, n_pid);
		p.set_tp(1, n.get_sib_p());
		p.set_SSN(1, k);
		free.pop();
		//cout << "p: " << p << "page id: " << free.front() << endl;
		p.write_to_page(free.front(), memspace);
		root_pid = free.front();
		used.push(root_pid);
	}
	else  //
	{
		p.load_from_page(parents.top(), memspace);
		//p.set_n_type(0);

		if (p.get_SSN(2) == 999999999)
		{
			//cout << "F7\n";
			p.set_SSN(2, k);
			p.set_tp(2, n.get_sib_p());
			p.write_to_page(parents.top(), memspace);
			//cout << "p: " << p << "page id: " << parents.top() << endl;
		}
		else  //Slots full
		{
			//Store key to push and pointer value
			int SSN_temp = p.get_SSN(1);
			
			//Create a new node for the split potion
			Node ps = Node(0);
			int ps_pid = free.front();
			
			p.set_sib_p(ps_pid);
			
			ps.set_SSN(1, p.get_SSN(2));
			ps.set_tp(0, p.get_tp(1));
			ps.set_tp(1, p.get_tp(2));
			p.set_SSN(1, k);
			p.set_tp(1, n.get_sib_p());

			//cout << "p: " << p << "ps: " << ps;
			
			//Update page information and management queues
			p.write_to_page(parents.top(), memspace);
			ps.write_to_page(ps_pid, memspace);
			used.push(free.front());
			free.pop();

			//Push up to parent	
			parents.pop();
			push_parent(SSN_temp, p, memspace);		
		}	
	}
} //end push_parent


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
