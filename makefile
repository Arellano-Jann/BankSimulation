bank: main.o event.o
	g++ -o main.o bank

main.o: main.cpp aQueue.h pQueue.h
	g++ -c main.cpp

event.o: event.cpp event.h
	g++ -c event.cpp

clean:
	rm *.o bank