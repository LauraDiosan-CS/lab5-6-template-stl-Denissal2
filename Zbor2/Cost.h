#include <ostream>
#include <string>
#include <stdlib.h>
#include <istream>
#include <iostream>
using namespace std;
#ifndef COST_H
#define COST_H
class Cost {
private:
	// Ceea din ce este constituit examenul (tip sir de caractere ->nume,tip int data si nota*)
	char* clasa;
	int pret;
	

public:
	// constructor fara parametrii(explicit se mai numeste daca nu gresesc)
	Cost();
	// constructor cu parametrii
	Cost(const char*, int);
	// constructor de copiere
	Cost(const Cost&);
	Cost(string);
	//Rezervare(string);//constructor de conversie
	char* getClasa();
	int getPret();
	// Setteri 
	void setClasa(const char*);
	void setPret(int);
	// Destructorul (Dupa ce te folosesti de ceva si numai ai absolut nevoie de el ->se va sterge ,cam asta e traducerea)
	~Cost();
	// operator de atribuire
	Cost& operator=(const Cost&);
	// Compara 2 examene!(Intr-un fel si asta poate fi ca cei de mai sus!)
	bool operator==(const Cost& e);
	// Compara 2 examene!(Intr-un fel si asta poate fi ca cei de mai sus!)
	bool compare(Cost& e);
	bool operator<(const Cost&);
	bool operator>(const Cost&);
	friend ostream& operator<<(ostream&, Cost&);
	friend istream& operator>>(istream&, Cost&);
};

#endif

