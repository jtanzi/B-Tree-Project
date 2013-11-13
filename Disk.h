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
		Disk();
		string diskspace[1000000];

		void disk_write(int start, int end, int value, int length);
		string pad_value(int value, int length);

		//Page management functions
		Page request_page(int pid);
		void update_occupied(int pid);
		std::queue<int> get_occupied();
		
		


};

