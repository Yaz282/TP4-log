CXX=g++
CPPFLAGS= -ansi -pedantic -Wall -std=c++11 -g

analog: main.o Ligne.o Lecture.o Statistique.o
	$(CXX) -o $@ $^

%.o : %.cpp %.h
	$(CXX) -c $< $(CPPFLAGS)


clean : 
	rm *.o

run :
	./analog