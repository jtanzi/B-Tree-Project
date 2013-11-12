/*
Page class functions definitions file
*/

#include <iostream>
#include "Page.h"

using namespace std;


/*
Constructor for Page instance
Arguments: pid (Page ID for Page to create)
Returns: Page with the Page ID requested
*/
Page::Page(int pid)
{
	Page::pid = pid;
}

int Page::getpid()
{
	return pid;
}

int* Page::getbitmap()
{
	return bitmap;
}
