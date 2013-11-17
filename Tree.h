/*
Tree class header file
*/

#include <iostream>

using namespace std;

class Tree

{
	private:
		
		//root node pointer
		int root_pid;		

	public:

		//Constructor
		Tree();

		//Getters and Setters
		int get_root();
		void set_root(int pid);	

		//Tree operations
		int search(int k, string memspace[2000][500]);
		int tree_search(int k, int root_pid, string memspace[2000][500]);

};

