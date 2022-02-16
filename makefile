output: main.o base.o persistance.o
	g++ main.o base.o persistance.o -o output

main.o: main.cpp headers.h
	g++ -c main.cpp

base.o: base.cpp base.h
	g++ -c base.cpp

persistance.o: persistance.cpp persistance.h
	g++ -c persistance.cpp

clean:
	rm *.o output