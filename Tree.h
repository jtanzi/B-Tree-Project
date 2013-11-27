/*
Tree class header file
*/
#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <queue>
#include <stack>
#include "Node.h"

using namespace std;

class Tree

{
	private:
		
		//root node pointer
		int root_pid;
		stack<int> parents;
		int n_pid;

	public:

		//Constructor
		Tree();

		//Getters and Setters
		int get_root();
		void set_root(int pid);	

		//Tree operations
		int search(int k, string memspace[2000][500]);
		int tree_search(int k, int root_pid, string memspace[2000][500]);
		void insert_record(int k, int record_id, string memspace[2000][500]);
		void push_parent(int k, Node n, string memspace[2000][500]);
		void delete_record(int k, string memspace[2000][500]);	
		void delete_parent(int k, Node n, string memspace[2000][500]);
		void output(string memspace[2000][500]);	

		//Page availability tracking
		queue<int> free;
		queue<int> used;

		

};

#endif
