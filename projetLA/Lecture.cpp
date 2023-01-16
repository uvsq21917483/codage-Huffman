#include "Lecture.hpp"
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

Lecture::Lecture(std::string txt){
	unsigned int i;
	for(int j=0;j<28;j++){		// initialisation des frequences
			 freq[j]=0;
			 }

	for(i=0;i < txt.length();i++){ // remplissage des frequences
		if( (txt[i] >= 'a') & (txt[i] <= 'z')){
			freq[int(txt[i])-'a']+= 1;
			}	
		if( txt[i] >= 'A' && txt[i] <= 'Z'){
			freq[int(txt[i])-'A']+= 1;
			}
		if (txt[i]==' ') freq[26]+=1;	
		if (txt[i]=='\n') freq[27]+=1;	
		}
		
	
	}
Lecture::Lecture(std::string nomfic,bool isfic){
	fstream fic;
	fic.open(nomfic); 
	for(int j=0;j<28;j++){		
			 freq[j]=0;
			 }
	char z;
	while( not fic.eof() ){
		fic.get(z);
		if( z >= 'a' && z <= 'z'){
			freq[int(z)-'a']+= 1;
		}	
		if( z >= 'A' && z <= 'Z'){
			freq[int(z)-'A']+= 1;
		}
		if (z==' ') freq[26]+=1;	
		if (z=='\n') freq[27]+=1;	
	
	}
	fic.close(); // remplissage des frequences mais à partir d'un fichier
}

Arbre Lecture:: man(){
	return Hauffman;
	}
	
	
int* Lecture::getfreq(){
		return freq;
		}
		

bool comparArbre(Arbre* a,Arbre* b){
	return a->getso().get() > b->getso().get(); // un attribut pour la fonction sort qui tri un vecteur
	}
		
void Lecture::Man(){	
	std::vector<Arbre*> man{};
	
	for(int j=0;j<26;j++){		// mettre un arbre
			if (freq[j]>0){// pour chaque frequences
				Sommet T(freq[j],char(j+'a'));// avec la lettre correspendante
				Arbre *r=new Arbre(T);// et sa frequences
				man.push_back(r);// dans un vecteur
			}
		}
	
	if (freq[26]>0)	{
		Sommet T(freq[26],' ');// remplissage des espaces
		Arbre *r=new Arbre(T);
		man.push_back(r);
		}
	if (freq[27]>0)	{
		Sommet T(freq[26],'\n');// et de sauts de lignes
		Arbre *r=new Arbre(T);
		man.push_back(r);
		}
	
	while (man.size() > 1){// tant que taille du vecteur > 1
		sort(man.begin(),man.end(),comparArbre);// tri du vecteur
		Arbre *a=new Arbre();
		Arbre *b=new Arbre();
		int m=0;
		for(size_t i = 0; i < man.size(); i++) {// soustraire
			if (man[i]->getso().get() < man[m]->getso().get()) {// l'arbre
				m=i;// qui a la plus petite frequences en sommet
			}
		}				
		*a=*man[m];
		man.erase(man.begin()+m);
		m=0;
		for(size_t i = 0; i < man.size(); i++) {
			if (man[i]->getso().get() < man[m]->getso().get()) {
				m=i; // le deuxieme plus petit arbre du vecteur
			}
		}
		*b=*man[m];
		man.erase(man.begin()+m);
				
		Arbre* fus=new Arbre();//fusion des dux arbres
		fus->fusion(a,b);// et
		man.push_back(fus);// les pusher dans le vecteur
		}
	Hauffman=*man[0]; // stocker le seul arbre restant dans hauffman
}


void  Lecture::cryptage(char* c[27]){
	std::string s="XXXXXXXXXXXXXX"; //appel
	Hauffman.pcryptage(s,0,c);//a la fonction de cryptage
	}

string Lecture:: code(string cr,int f){
	char* c[28];
	for(int i=0;i<28;i++){
		c[i]=new char[1]; // initialisation du tableau de chaine de caractere contenant les codes
		c[i][0]= 'X';
		}
	cryptage(c); 
	std::string code;
	if (f==1){ // si on a affaire à un fichier
		fstream fich; 
		fich.open(cr);// on l'ouvre 
		char z;
		while( not fich.eof() ){
		fich.get(z);
		if( z >= 'a' && z <= 'z') code+=c[int(z)-'a']; //on rempli
		
		if( z >= 'A' && z <= 'Z') code+=c[int(z)-'A'];//le string code
		
		if (z==' ') code+=c[26];// avec le code correspendant
		if (z=='\n') code+=c[27];// qui se trouves dans le tableau de chaine de caractere rempli dans cryptage
		
	}
	fich.close();	
	}
	if (f==0){// la meme chose la dessus mais en ayant un string pas un fichier 
		for(unsigned int i=0;i<cr.length();i++){
			if(cr[i] >='a' && cr[i] <= 'z')  code+=c[int(cr[i])-'a'];
			if(cr[i] >='A' && cr[i] <= 'Z')  code+=c[int(cr[i])-'A'];
			if (cr[i] ==' ') code += c[26];
			if (cr[i] =='\n') code += c[27];
		}
	}
	for(int y=0;y<26;y++){
		if (c[y][0] != 'X') cout << "le code de "<< char(y+'a')<< " est: " <<c[y] << endl ; // affichage du code des lettres correspendantes
		}
	for(int y=0;y<26;y++){
		delete[] c[y];
		}
	return code;
}

string Lecture::decryptage(string crypt){
	string decrypt;
	bool b=false;// booleen qui teste la validité du decryptage
	Hauffman.pdecryptage(crypt,Hauffman,decrypt,b); //appel du fonction de decryptage
	if(! b) decrypt ="\n\n attention le decryptage s'est mal passé ! \n LE CODE BINAIRE INTRODUI NE CORRESPEND\n PAS ÀU ARBRE DU DEPART \n"; // travail du booleen
	return decrypt;
}
