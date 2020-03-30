#include "Rezervare.h"
#include <string.h>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <sstream>
#include <stdlib.h>
#include "Rezervare.h"


using namespace std;
Rezervare::Rezervare() {
	// initializare,constructor implicit
	this->nume = NULL;
	this->nr_zbor = 0;
	this->nr_loc = 0;
}
Rezervare::Rezervare(char* nume, int nr_zbor, int nr_loc) {
	// contructor cu parametri
	//  new char[strlen(nume)+1 ...Acel new apare din cauza ca dupa cum vedem avem un pointer,strlen(nume)+1 ->lungimea numelui +1 (adica abc -> str(len)+1=4 acel "+1" ->backslash*"
	// Dupa ce scriem prima linie de cod din interior trebuie sa aplicam strcpy_s -> si doar asa reusim sa specificam ca this->nume = nume*
	// strcpy(destinatie,lungime,ceea ce trebuie sa ajunga la destinatie(sa fie aceasta daca e sa o luam asa!)
	// strcpy se aplica aici pentru ca avem un sir de caractere ca parametru 
	//Ca la vectori dinamici ,alocam spatiu care ulterior daca nu gresesc se va dealoca in destructor*
	//Alocarea are loc prin prima linie de cod * ,iar strcpy ->copiem nume in this->nume*
	// la int nu se aplica acelas rationament!
	this->nume = new char[strlen(nume) + 1];
	strcpy_s(this->nume, 1 + strlen(nume), nume);
	this->nr_zbor = nr_zbor;
	this->nr_loc = nr_loc;
}
Rezervare::Rezervare(const Rezervare& e) {
	// Constructorul de copiere , primele 2 linii de cod identice cu cele de la  constructorul cu parametrii
	// doar ca aici avem un Examen e  si this->nume va vrea sa-i ia numele acestuia si de aceea acolo avem e.nume*
	// this->data = e.data (data examenului e *)
	//cout << "copy constructor" << endl;
	this->nume = new char[strlen(e.nume) + 1];
	strcpy_s(this->nume, 1 + strlen(e.nume), e.nume);
	this->nr_zbor = e.nr_zbor;
	this->nr_loc = e.nr_loc;
}

//Geteri
//   Voi explica la teste importanta lor *!


char* Rezervare::getNume() {
	return this->nume;
}

int Rezervare::getNrZbor() {
	return this->nr_zbor;
}

int Rezervare::getNrLoc() {
	return this->nr_loc;
}

//Seteri


void Rezervare::setNume(char* nume) {
	// Dezalocare(pentru ca s-ar putea sa existe un nume(in general exista)
	if (this->nume != NULL) {
		delete[] this->nume;
	}
	// realocare si copierea noului nume in this->nume
	this->nume = new char[strlen(nume) + 1];
	strcpy_s(this->nume, strlen(nume) + 1, nume);

}

void Rezervare::setNrZbor(int nr_zbor) {
	this->nr_zbor = nr_zbor;
}

void Rezervare::setNrLoc(int nr_loc) {
	this->nr_loc = nr_loc;
}
char* Rezervare::toString() {
	if (this->nume != NULL) {
		int noChars = strlen(this->nume) + 13;
		char* s = new char[noChars];
		char* aux = new char[5];
		char* aux2 = new char[5];
		strcpy_s(s, noChars, this->nume);
		strcat_s(s, noChars, " ");
		_itoa_s(this->nr_zbor, aux2, 5, 10);
		_itoa_s(this->nr_loc, aux, 5, 10);
		strcat_s(s, noChars, aux2);
		strcat_s(s, noChars, " ");
		strcat_s(s, noChars, aux);
		if (aux) {
			delete[] aux;
			aux = NULL;
		}
		strcat_s(s, noChars, " ");
		return s;
	}
	else
	{
		char* x = new char[1];
		strcpy_s(x, 1, "");
		return x;
	}
}


Rezervare& Rezervare::operator=(const Rezervare& e) {
	// Aici daca nu gresesc totusi nu e vorba de egalitate si de operatorul de atribuire!(lui this ii se atribuie ceva nou(cu ajutorul Seterilor)!
	this->setNume(e.nume);
	this->setNrZbor(e.nr_zbor);
	this->setNrLoc(e.nr_loc);
	// return *this ->valoarea adresei respective
	return *this;
}


Rezervare::~Rezervare() {
	//Destructor (Dupa ce folosim Examenul la ce trebuie , facem putin loc in memorie)
	if (this->nume != NULL) {
		delete[] this->nume;
		this->nume = NULL;
	}
	this->nr_zbor = 0;
	this->nr_loc = 0;
}
// Compararea ( verificarea egalitatii dintre Examenul curenta si o a doua Examenul)
bool  Rezervare::compare(Rezervare& e) {
	// verificarea data this->examen este egal cu examenul e 
	return ((this->nr_zbor == e.nr_zbor) && (strcmp(this->nume, e.nume) == 0) && (this->nr_loc == e.nr_loc));
}

bool Rezervare::operator<(const Rezervare& e)
{
	return ((strcmp(this->nume, e.nume) < 0) && (this->nr_zbor < e.nr_zbor) && (this->nr_loc < e.nr_loc));

}


bool Rezervare:: operator==(const Rezervare& e) {
	// la fel ca mai sus * (egalitate)
	return strcmp(this->nume, e.nume) == 0 && this->nr_zbor == e.nr_zbor && this->nr_loc == e.nr_loc;
}

bool Rezervare:: operator!=(const Rezervare& e) {

	return strcmp(this->nume, e.nume) == 0 && this->nr_zbor == e.nr_zbor && this->nr_loc != e.nr_loc;

}

ostream& operator<<(ostream& os, Rezervare& e) {
	os << "[nume:" << e.nume << "-nr.zbor:" << e.nr_zbor << "-nr.loc:" << e.nr_loc << "]";

	return os;
}

istream& operator>>(istream& is, Rezervare& e)
{
	cout << "Dati numele: ";
	char* nume = new char[20];
	//char nume[20];
	//is.get(nume,20);
	//cin.get(nume,19);
	cin >> nume;
	cout << "Dati nr_zbor: ";
	int nr_zbor;
	cin >> nr_zbor;
	cout << "Dati nr_loc:";
	int nr_loc;
	cin >> nr_loc;
	e.setNume(nume);
	e.setNrZbor(nr_zbor);
	e.setNrLoc(nr_loc);
	delete[] nume;
	return is;
}
