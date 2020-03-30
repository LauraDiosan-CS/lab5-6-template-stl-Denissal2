#include "Repo.h"
#include <iostream>
#include "Rezervare.h"
#include <vector>
#include <list>
using namespace std;
template<class Elem>
Repo<Elem>::Repo()
{

}
template<class Elem>
Repo<Elem>::~Repo()
{
}
template<class Elem>
void Repo<Elem>::addElem(Elem& elem)
{
	elemente.push_back(elem);
}

template<class Elem>
list<Elem> Repo<Elem>::GetAll()
{
	return elemente;
}

