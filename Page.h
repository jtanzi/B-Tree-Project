/*
Page class
This is an abstract representation of a page in disk space for
holding information about the page location and bitmap and
does not store any records
*/

#ifndef PAGE_H
#define PAGE_H

class Page
{
	private:
		
		char* pid;  //Page ID
		char bitmap[100]; //Page bitmap; stored in last 100 bytes of Page

	public:

		Page(char* pid);
		char* getpid();
		char* getbitmap();

};

#endif
