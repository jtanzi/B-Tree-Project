/*
Tree class functions definitions file
*/

#include <iostream>
#include "Tree.h"

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
