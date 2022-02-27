bank: main.o
	g++ -o main.o

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o bank