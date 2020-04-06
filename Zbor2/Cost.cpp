#include "Cost.h"
#include <string.h>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <sstream>
#include <stdlib.h>

using namespace std;
Cost::Cost() {
	// initializare,constructor implicit
	this->clasa = NULL;
	this->pret = 0;
	
}
Cost::Cost(const char* clasa, int pret) {
	
	this->clasa = new char[strlen(clasa) + 1];
	strcpy_s(this->clasa, 1 + strlen(clasa), clasa);
	this->pret = pret;
	
}
Cost::Cost(const Cost& e) {
	// Constructorul de copiere , primele 2 linii de cod identice cu cele de la  constructorul cu parametrii
	// doar ca aici avem un Examen e  si this->nume va vrea sa-i ia numele acestuia si de aceea acolo avem e.nume*
	// this->data = e.data (data examenului e *)
	//cout << "copy constructor" << endl;
	this->clasa = new char[strlen(e.clasa) + 1];
	strcpy_s(this->clasa, 1 + strlen(e.clasa), e.clasa);
	this->pret = e.pret;
	
}

Cost::Cost(string linie)
{
	std::istringstream iss(linie);
	string tok1, tok2;
	iss >> tok1 >> tok2;
	clasa = new char[tok1.length() + 1];
	strcpy_s(clasa, tok1.length() + 1, tok1.c_str());
	pret = stoi(tok2);

}

//Geteri
//   Voi explica la teste importanta lor *!


char* Cost::getClasa() {
	return this->clasa;
}

int Cost::getPret() {
	return this->pret;
}



//Seteri


void Cost::setClasa(const char* clasa) {
	// Dezalocare(pentru ca s-ar putea sa existe un nume(in general exista)
	if (this->clasa != NULL) {
		delete[] this->clasa;
	}
	// realocare si copierea noului nume in this->nume
	this->clasa = new char[strlen(clasa) + 1];
	strcpy_s(this->clasa, strlen(clasa) + 1, clasa);

}

void Cost::setPret(int pret) {
	this->pret = pret;
}





Cost& Cost::operator=(const Cost& e) {
	// Aici daca nu gresesc totusi nu e vorba de egalitate si de operatorul de atribuire!(lui this ii se atribuie ceva nou(cu ajutorul Seterilor)!
	this->setClasa(e.clasa);
	this->setPret(e.pret);
	// return *this ->valoarea adresei respective
	return *this;
}


Cost::~Cost() {
	//Destructor (Dupa ce folosim Examenul la ce trebuie , facem putin loc in memorie)
	if (this->clasa != NULL) {
		delete[] this->clasa;
		this->clasa = NULL;
	}
	this->pret = 0;
	
}
// Compararea ( verificarea egalitatii dintre Examenul curenta si o a doua Examenul)
bool  Cost::compare(Cost& e) {
	// verificarea data this->examen este egal cu examenul e 
	return ((this->pret == e.pret) && (strcmp(this->clasa, e.clasa) == 0) );
}

bool Cost::operator<(const Cost& e)
{
	return ((strcmp(this->clasa, e.clasa) < 0) && (this->pret < e.pret));

}

bool Cost::operator>(const Cost& e)
{
	return ((strcmp(this->clasa, e.clasa) > 0) && (this->pret > e.pret));
}



bool Cost:: operator==(const Cost& e) {
	// la fel ca mai sus * (egalitate)
	return strcmp(this->clasa, e.clasa) == 0 && this->pret == e.pret ;
}



ostream& operator<<(ostream& os, Cost& e) {
	//os << "[nume:" << e.nume << "-nr.zbor:" << e.nr_zbor << "-nr.loc:" << e.nr_loc << "]";
	os << e.clasa << " " << e.pret << " "  << endl;
	return os;

}

istream& operator>>(istream& is,Cost& e)
{
	cout << "Dati Clasa: ";
	char* clasa = new char[20];
	cin >> clasa;
	cout << "Dati pretul: ";
	int pret;
	cin >> pret;
	e.setClasa(clasa);
	e.setPret(pret);
	delete[] clasa;
	return is;
}
