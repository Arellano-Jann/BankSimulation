all: bank

bank: main.o Event.o
	g++ -o bank main.o Event.o

main.o: main.cpp AQueue.h PQueue.h
	g++ -c main.cpp

Event.o: Event.cpp Event.h
	g++ -c Event.cpp

clean:
	rm *.o bank