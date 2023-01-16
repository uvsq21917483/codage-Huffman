#include "Lecture.hpp"
#include <vector>
#include <string>
#include <cstring>
using namespace std;
int main(int a,char ** b)
{ 
	cout << "\n voir le README \n\n\n";
	Lecture *hauff;
	if (a == 3)	 hauff=new Lecture(b[1],true);	 //si on veut coder un fichier
	else hauff=new Lecture(b[1]);// si on veut coder un string
			
	hauff->Man(); //appel fonction Man pour construire l'arbre de hauffman
	string code;
	cout <<"la chaine:"<<endl;
	
	cout <<b[1]<<endl<<"son code :"<<endl;
	
	if (a==2) code=hauff->code(b[1],0);// recuperation du code de hauffman correspendant au chaine codée
	if ( a==3 ) code=hauff->code(b[1],1);//  à partir d'un fichier ou d'un string
	
	cout <<"son cryptage :"<<endl;
	cout <<code<<endl;

	cout <<"son decryptage :"<<endl;
	
	cout << hauff->decryptage(code); // affichage du decryptage du code qui va etre la chaine initiale
	
	
	string a_decrypter;
	cout << " introduizez la chaine a decrypter \n";
	cin >> a_decrypter;	
	
	cout << hauff->decryptage(a_decrypter); // decryptage de la chaine entrée

	delete hauff;	

    return 0;
}
