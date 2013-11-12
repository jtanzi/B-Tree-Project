/*
Disk class header file
*/

#include <iostream>
#include <queue>
#include "Page.h"

using namespace std;

class Disk

{
	private:

		char diskspace[1000000];
		
		//Queues for keeping track of occupied and free pages
		std::queue <char*> occupied;
		std::queue <char*> free;

	public:
		
		//Page management functions
		Page request_page(char* pid);
		void update_occupied(char* pid);
		
		


};

