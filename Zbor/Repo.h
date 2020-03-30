#pragma once
#include <list>
#include <iostream>
using namespace std;
template <class Elem>
class Repo
{
protected:
	list<Elem> elemente;
public:
	Repo();
	~Repo();
	void addElem(Elem&);
	list<Elem> GetAll();


};

