btree: main.o Disk.o Page.o
	g++ -g -o btree main.o Disk.o Page.o

main.o: main.cpp 
	g++ -g -c main.cpp 

Disk.o: Disk.cpp
	g++ -g -c Disk.cpp

Page.o: Page.cpp
	g++ -g -c Page.cpp

clean:
	rm -f main Disk Page *.o *.~
	find ./ -name '*~' | xargs rm
