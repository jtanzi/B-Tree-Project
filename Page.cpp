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
Page::Page(char* pid)
{
	pid = pid;
}

char* Page::getpid()
{
	return pid;
}

char* Page::getbitmap()
{
	return bitmap;
}
