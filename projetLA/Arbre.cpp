#include "Arbre.hpp"
#include <string>
#include <cstring>
#include <vector>
using namespace std;
 
	Arbre::Arbre():s(),gauche(NULL),droit(NULL){};

	Arbre Arbre::operator=(Arbre& a){
	s=a.s;
	gauche=a.gauche;
	droit=a.droit;
	return *this;
	}	
	
	Arbre::Arbre(Sommet& c){
		s=c;
		gauche=NULL;
		droit=NULL;
		}
	
		
		
Sommet	Arbre::getso(){
	return s;
	};
	
void 	Arbre::fusion(Arbre* b,Arbre* a){
			s.set(a->getso().get()+b->getso().get()); // mettre la valeur du sommet resultant
			s.setl(false); // indiquer que ce n'est pas une lettre
			gauche=a;
		    droit=b;
		   }

	
void 	Arbre::add(Sommet &a){
	Arbre *p;
	p=this;
	while (p->droit){ // on avance tant que la droite n'est pas null
		p=p->droit;
		}
	Arbre *k=new Arbre(a);
	p->droit=k;
	}	

void Arbre::printList() 
{ 		
    if  ( this->gauche ){
	
		 gauche->printList();}
	
	cout << this->s.get() << " "; 
	if( s.estlettre() ) cout << ":("<< s.getcara() <<")   ";

	if  ( this->droit ) {	
		droit->printList(); 		
		} 
}

void Arbre::pdecryptage(std::string x,Arbre &a,std::string &decrypt,bool& b){
	
	if(s.estlettre()) { // si le noeud est une lettre on garde le caractere correspendant 
		 decrypt.push_back(s.getcara());
		if (x.length() > 0) a.pdecryptage(x,a,decrypt,b);
		else b=true; // si on est à la fin de la chaine et on est sur une feuille le codage est bon
	}
	else { // sinon on avnce
		if (x.length() > 0){// vers la gauche si on lis un 0
				if (x.front()=='0') {
					if (gauche)
						gauche->pdecryptage(x.substr(1),a,decrypt,b);
						}
			else { 
					if (x.front()=='1') {//vers la droite si on lis un 1
						if (droit) droit->pdecryptage(x .substr(1),a,decrypt,b);
					}
				}
		}
	}
}
void Arbre::pcryptage(std::string x,int g,char* c[27]){
	
	if (s.estlettre()){// si on est sur une feuille on garde le code  correspendant au caractere
		while(x[(x.length())-1]=='X'){
			x.pop_back(); 
			}
		if (s.getcara()==' '){
			c[26]=new char[x.length()+1];
			strcpy(c[26], x.c_str());	
			}
		else {
			if (s.getcara()=='\n'){
			c[27]=new char[x.length()+1];
			strcpy(c[27], x.c_str());	
			}
		else {	
			c[int(s.getcara()-'a')]=new char[x.length()+1];
			strcpy(c[int(s.getcara()-'a')], x.c_str());
			}
		}
		}
	else{
	if(gauche) { // si on parcours la gauche de l'arbre 
		x[g]='0';// on ajoute un 0
		gauche->pcryptage(x,g+1,c);
		}
	if(droit) {// si on parcours la droite de l'arbre 
		x[g]='1';// on ajoute un 1
		droit->pcryptage(x,g+1,c);
		}
	}
}
