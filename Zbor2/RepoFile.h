#pragma once
#include "Repo.h"
#include "Rezervare.h"
#include <fstream>
#include <iostream>
using namespace std;

template <class Elem> class RepoFile:public Repo<Elem>
{ 
private: 
	//list<Elem> elemente;
	const char* fis;
public:
	
	RepoFile();
	RepoFile(const char* filenamex);
	void loadFromFile(const char* fileName);
	
	~RepoFile();
};

template<class Elem>
RepoFile<Elem>::RepoFile()
{
	this->fis = new char[40];

}

template<class Elem>
 RepoFile<Elem>::RepoFile(const char* fileName)
{
	 fis = fileName;
	 //this->filename = filenamex;
	 
	 ifstream f(fileName);
	 string linie;
	 char* nume = new char[10];
	 int nr_zbor;
	int nr_loc;
	 //Elem& el;
	 while (!f.eof()) {
		 f >> nume >> nr_zbor >> nr_loc ;
		// f >> el;
		 if (nume != "") {
			 Rezervare s(nume, nr_zbor, nr_loc);
			 this->elemente.push_back(s);
		 }
	 }
	//delete[] nume;
	 f.close();
	 //*/
	
}




 template<class Elem>
  void RepoFile<Elem>::loadFromFile(const char* fileName)
 {
	  
	  this->elemente.clear();
	  fis = fileName;
	  ifstream f(fileName);
	  
	  char* nume = new char[10];
	  int nr_zbor;
	  int nr_loc;

	  
	  //Elem& elem;
	  while (!f.eof()) {
		 f >> nume >> nr_zbor >> nr_loc;
		 // f >> elem;
		 if (strcmp(nume, "") != 0) {
			 Rezervare r(nume, nr_zbor, nr_loc);
			 this->addElem(r);
		 }
	  }
	  delete[] nume;
	  f.close();

	  
 }



 template<class Elem>
 RepoFile<Elem>::~RepoFile()
 {
 }
