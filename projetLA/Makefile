Run: compil
	./hello	"le code de hauffman"   

compil:	 Sommet.o Arbre.o Lecture.o main.o
	g++ -Wall sommet.cpp Arbre.cpp Lecture.cpp main.cpp -o hello

Sommet.o:  sommet.cpp sommet.hpp
	g++ -c sommet.hpp sommet.cpp  -Wall -g

Arbre.o:  sommet.hpp Arbre.hpp Arbre.cpp 
	g++  -c sommet.hpp Arbre.hpp Arbre.cpp -Wall -g
	
Lecture.o: Lecture.cpp sommet.hpp Arbre.hpp Lecture.hpp 
	g++ -c Lecture.cpp -Wall -g
	
clear:
	rm -r *.o
	rm -r *.gch
	rm hello
	
	
 nauty > nauty shreier

shreier > nauty naurng

naurng > naututil 
 naututil > nauty nausparse naurng

