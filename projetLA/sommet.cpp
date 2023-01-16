#include "sommet.hpp"
Sommet::Sommet():s(0) , est_lettre(false), car('\0'){};

Sommet::Sommet(int x): s(x) , est_lettre(false) {};

Sommet::Sommet(int x,char c): s(x) , est_lettre(true) , car(c){};
	
void Sommet::setl(bool m){
	est_lettre=m;
	}
void Sommet::set(int m){
		s=m;
	}
bool Sommet::estlettre(){
	return est_lettre;
	}
char Sommet::getcara(){
	return car;}
int Sommet::get(){
		return s;
		}
Sommet& Sommet::operator=(Sommet x){
		s=x.s;
		est_lettre=x.est_lettre;
		car=x.car;
		return *this;
		}
