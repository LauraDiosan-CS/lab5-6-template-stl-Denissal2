#pragma once
#pragma once
#include "Repo.h"
#include "Rezervare.h"
#include "Cost.h"
#include <vector>
#include <list>
using namespace std;
class Service
{
private: 
	
	Repo<Rezervare> repo;
	Repo<Cost> res;
public:
	  Service();
	  Service(const Repo<Rezervare>&);
	  void setRepo(const Repo<Rezervare>&);
	  //void setRepos(const Repo<Cost>&);
	  void addRezervare(Rezervare&);
	  void delRezervare(Rezervare&);
	  list<Rezervare> getAll();
	  vector<Rezervare> getAll2();
	 // Rezervare update(Rezervare, const char*, int,int);
	  Rezervare update(Rezervare,Rezervare);
	  __int64 findOne(Rezervare);
	  __int64 getSize();
	  list<Rezervare> filtreazaDupaNumeSiNr1(const char*, int);
	  list<Rezervare> sortByNrZbor();
	  list<Rezervare> sortByNrLoc();
	  vector<Rezervare> sorteazaDupaLoc();
	  list<Rezervare> sortByNameCresc();
	  list<Rezervare> sortByNameDescrs();
	  list<Rezervare> Avanseaza(const char*);
	  list<Rezervare> NrZborEgalCuPozLista(const char*);
	//  vector<Rezervare> RezervareLoc(int, int);
	  Service(const Repo<Cost>&);
	  void addCost(Cost&);
	  void delCost(Cost&);
	  list<Cost> getAlls();
	  Cost updateCost(Cost, Cost);
	  __int64 findOneCost(Cost);
	  __int64 getSizeCost();
	  ~Service();
};

