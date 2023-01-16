#include "Arbre.hpp"
#include <string>
#include <vector>
#include <fstream>

class Lecture{
	private:
		int freq[27];// tableau d'entier de frequences
		Arbre Hauffman; // l'arbre finale de hauffman
	public:
	Arbre man();
	Lecture(std::string txt);// constructeur par une chaine de caractere
	Lecture(std::string nomfic,bool isfic);//constructeur par un fichier
	~Lecture(){};// destructeur
	int* getfreq();
	void  Man(); // construire l'arbre hauffman
 
	void cryptage(char* c[27]); // fct de cryptage

	string code(string cr,int f);// mets le code correspendant au code entré dans un string
	string decryptage(string crypt); //fct de decryptage

};
