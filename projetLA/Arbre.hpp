#include "sommet.hpp"
#include <string>
#include <cstring>
#include <vector>

class Arbre  { 
	private:
	
		Sommet s{Sommet()};// un attribut sommet 
	
	public:
		Arbre* gauche; // acces aux fils 
		Arbre* droit; //  gauches et droit
		Arbre();// constructeur par defaut
		Arbre(Sommet& c);//  constructeur par un sommet
		~Arbre(){
		}	
		Sommet getso();
		
		void fusion(Arbre* b,Arbre* a); // fusionne deux arbres
		
		void add(Sommet &a); // ajout l'element a
		
		void printList();// affichage d'un arbre
		
		Arbre operator=(Arbre& a); // copie d'un arbre
		
		void decomposition(Arbre& a,Arbre& b) ; // decomposition de deux arbre
		
	//	void supp(Sommet& a);
		
		void pcryptage(string s,int g,char* c[27]);// pre cryptage
		
		void pdecryptage(std::string x,Arbre &a,std::string & decrypt,bool& b); // pre decryptage

};
