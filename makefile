hw5: main.o Tree.o
	g++ -g -o hw5 main.o Tree.o 

main.o: main.cpp 
	g++ -g -c main.cpp 

Tree.o: Tree.cpp
	g++ -g -c Tree.cpp

clean:
	rm -f main Tree *.o *.~
	find ./ -name '*~' | xargs rm
