#include <iostream>
#include <string>

using namespace std;

class Sommet{
	protected :

	int s{0};
	bool est_lettre{false};
	char car{'\0'};

	public:
	
	Sommet();
	~Sommet(){};
	Sommet(int x);	
	Sommet(int x,char c);			
	bool estlettre();	 
	void set(int m);	
	void setl(bool m);	
	int get();
	char getcara();
	Sommet& operator=(Sommet x);
	
};
