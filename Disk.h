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
		
		//Queues for keeping track of occupied and free pages
		std::queue <int> occupied;
		std::queue <int> free;

	public:
		
		int diskspace[1000000];

		//Page management functions
		Page request_page(int pid);
		void update_occupied(int pid);
		std::queue<int> get_occupied();
		
		


};

