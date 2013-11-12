/*
Disk class functions definitions file
*/

#include <iostream>
#include "Disk.h"

using namespace std;

//Construction
/*
Disk constructor
*/
/*Disk::Disk()
{
	
}*/

//Page management functions
/*
request_page function
Arguments: pid (Page ID of the page to request)
Returns a Page with the ID requested
*/
Page Disk::request_page(int pid)
{
	Page new_Page = Page(pid);
	update_occupied(pid);

	return new_Page;
}


void Disk::update_occupied(int pid)
{
	occupied.push(pid);
	free.pop();
}	

std::queue<int> Disk::get_occupied()
{
	return occupied;
}	
		



