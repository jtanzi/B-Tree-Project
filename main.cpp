#include <iostream>
#include <cstdlib>
#include "Disk.h"
#include "Page.h"

using namespace std;

int main()
{

	Disk disk = Disk();
	int pid = 1;
	Page new_page = disk.request_page(pid);
	cout << "new_page.pid: " << new_page.getpid() << endl;
	disk.disk_write(new_page.getpid() * 500, new_page.getpid() * 500 + 3, 1, 4);
	cout << "disk addr: " << new_page.getpid() * 500 << endl;
	
	cout << "[";
	for (int i = 490; i < 510; i++)
	{
		cout << disk.diskspace[i];
	}
	cout << "]" << endl;
	
	

}
