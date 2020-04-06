#include "Service.h"
#include <algorithm> 

Service::Service()
{
}

Service::Service(const Repo<Rezervare>& r)
{
	repo = r;
}

void Service::setRepo(const Repo<Rezervare>& r)
{
	repo = r;
}



void Service::addRezervare(Rezervare& r)
{
	repo.addElem(r);
}

void Service::delRezervare(Rezervare& r)
{
	repo.del(r);
}

list<Rezervare> Service::getAll()
{
	return repo.GetAll();
}

vector<Rezervare> Service::getAll2()
{
	list<Rezervare> rez = repo.GetAll();
	vector<Rezervare> v(rez.begin(), rez.end());
	return v;
}

Rezervare Service::update(Rezervare r, Rezervare r1)
{
	repo.updateElem(r, r1);
	return r;
}


__int64 Service::findOne(Rezervare r)
{
	return repo.findElem(r);
}

__int64 Service::getSize()
{
	return this->repo.getSize();
}

list<Rezervare>Service::filtreazaDupaNumeSiNr1(const char* n, int a) {

	list<Rezervare> rez;
	for (__int64 i = 0;i < repo.getSize();i++)
	{
		Rezervare crt = repo.get(i) ;
		if (strstr(crt.getNume(), n) && crt.getNrZbor() >= a) {
			rez.push_back(crt);
		}
	}
	return rez;
}




	
bool myNrZborCompare(Rezervare x, Rezervare y){
if (x.getNrZbor() == y.getNrZbor()) {
	return x < y;
}
	return x.getNrZbor() < y.getNrZbor();

}


list<Rezervare> Service::sortByNrZbor()
{

	list<Rezervare> all = repo.GetAll();
	all.sort(myNrZborCompare);
	// Daca nu se pune nimic in loc de myGradeCompare -> Sortare dupa nume ?!
	return all;
}

bool myNrLocCompare(Rezervare x, Rezervare y) {
	if (x.getNrLoc() == y.getNrLoc()) {
		return x > y;
	}
	return x.getNrZbor() > y.getNrZbor();

}

list<Rezervare> Service::sortByNrLoc()
{
	list<Rezervare> all = repo.GetAll();
	all.sort(myNrLocCompare);
	// Daca nu se pune nimic in loc de myGradeCompare -> Sortare dupa nume ?!
	return all;
}

vector<Rezervare> Service::sorteazaDupaLoc()
{
	list<Rezervare> all = repo.GetAll();
	//sort(all.begin(), all.end(), myNrLocCompare);
	all.sort(myNrLocCompare);
	vector<Rezervare> rez(all.begin(), all.end());
	return rez;
}

bool myNameCompareCresc(Rezervare x, Rezervare y) {

	
	if (strcmp(x.getNume(),y.getNume()) == 0) {
		// daca puneam < 0 ..Se contrazicea cu urmatorul return si se afisa lista initiala..
		return x < y;
	}
	return strcmp(x.getNume(), y.getNume()) < 0;

}

list<Rezervare> Service::sortByNameCresc()
{
	list<Rezervare> all = repo.GetAll();
	all.sort(myNameCompareCresc);
	// Daca nu se pune nimic in loc de myGradeCompare -> Sortare dupa nume ?! , se pare ca trebe (Testat!!!)
	return all;
}
bool myNameCompareDescresc(Rezervare x, Rezervare y) {


	if (strcmp(x.getNume(), y.getNume()) == 0) {
		// daca puneam < 0 ..Se contrazicea cu urmatorul return si se afisa lista initiala..
		return x > y;
	}
	return strcmp(x.getNume(), y.getNume()) > 0;

}


list<Rezervare> Service::sortByNameDescrs()
{
	list<Rezervare> all = repo.GetAll();
	all.sort(myNameCompareDescresc);
	return all;
}

list<Rezervare> Service::Avanseaza(const char* name)
{
	// Vedem care dintre clienti au numele x si dupa in functie de ordinea lor li se atribuie nrzbor (Primul =1 ,al doilea = 2...)
	list<Rezervare> RezervareFilter;
	int first = 0;
	for (__int64 i = 0; i < repo.getSize(); i++) {
		Rezervare& re = repo.get(i);
		
		// Daca nu pui &  - se creeaza un nou student si nu se modifica valoarea notei
		if (strcmp(re.getNume(), name) == 0) {
			first++; 
			re.setNrZbor(first);
			RezervareFilter.push_back(re);
			
		}
		
	}

	return RezervareFilter;

}

list<Rezervare> Service::NrZborEgalCuPozLista(const char* name)
{
	list<Rezervare> RezervareFilter;
	int first = 0;
	for (__int64 i = 0; i < repo.getSize(); i++) {
		Rezervare& re = repo.get(i);
		first++;
		// Daca nu pui &  - se creeaza un nou student si nu se modifica valoarea notei
		if (strcmp(re.getNume(), name) == 0) {
			re.setNrZbor(first);
			RezervareFilter.push_back(re);

		}

	}

	return RezervareFilter;
}
/*
vector<Rezervare> Service::RezervareLoc(int x, int y)
{
	vector<Rezervare> studFilter;
	for (int i = 0; i < repo.getSize(); i++) {
		Rezervare crtRezervare = repo.get(i);
		if (((crtRezervare.getNrLoc() < x) && (crtRezervare.getNrLoc() != y))) {
			studFilter.push_back(crtRezervare);
		}
	}
	return studFilter;
}

*/



Service::Service(const Repo<Cost>& c)
{
	res = c;

}

void Service::addCost(Cost& c)
{
	res.addElem(c);
}

void Service::delCost(Cost& c)
{
	res.del(c);
}

list<Cost> Service::getAlls()
{
	return res.GetAll();
}

Cost Service::updateCost(Cost c1, Cost c2)
{
	res.updateElem(c1, c2);
	return c1;
}

__int64 Service::findOneCost(Cost c)
{
	return res.findElem(c);
}

__int64 Service::getSizeCost()
{
	return this->res.getSize();
}



Service::~Service()
{
}
