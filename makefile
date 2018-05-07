CC = g++ -std=c++11 -O3

all: chromatic_index.o chromatic_number.o hamiltonian.o

chromatic_index.o: chromatic_index.cpp
	$(CC) chromatic_index.cpp -o chromatic_index.o

chromatic_number.o: chromatic_number.cpp
	$(CC) chromatic_number.cpp -o chromatic_number.o

hamiltonian.o: hamiltonian.cpp
	$(CC) hamiltonian.cpp -o hamiltonian.o

clean:
	rm *.o
