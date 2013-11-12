#include <iostream>
#include <cstdlib>
#include "Disk.h"
#include "Page.h"

using namespace std;

int main()
{

	Disk disk = Disk();
	char* pid = "0001";
	Page new_page = disk.request_page(pid);

	cout << new_page.getpid() << new_page.getbitmap() << endl;
	

}
