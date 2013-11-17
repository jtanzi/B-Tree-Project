hw5: main.o Tree.o Node.o
	g++ -g -o hw5 main.o Tree.o Node.o

main.o: main.cpp 
	g++ -g -c main.cpp 

Tree.o: Tree.cpp
	g++ -g -c Tree.cpp

Node.o: Node.cpp
	g++ -g -c Node.cpp

clean:
	rm -f main Tree Node *.o *.~
	find ./ -name '*~' | xargs rm
