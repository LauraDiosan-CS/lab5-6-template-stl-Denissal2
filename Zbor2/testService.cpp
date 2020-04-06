
#include "testService.h"
#include <assert.h>
#include <iostream>
using namespace std;



void TestService::test1()
{
	Service r;
	assert(r.getSize() == 0);
	Rezervare r1("Darius", 20, 30);
	r.addRezervare(r1);
	assert(r.getSize() == 1);
	Rezervare r2("Maria", 32, 10);
	r.addRezervare(r2);
	assert(r.getSize() == 2);
	Rezervare r3("Marcel", 40, 50);
	r.addRezervare(r3);
	assert(r.getSize() == 3);
	assert(r.findOne(Rezervare("Darius", 20, 30)) == 0);
	assert(r.findOne(Rezervare("Maria", 32, 10)) == 1);
	assert(r.findOne(Rezervare("Marcel", 40, 50)) == 2);
	char* x = new char[7];
	strcpy_s(x, 7, "Marcel");
	Rezervare rx = r.update(r2,Rezervare(x,32,40));
	assert(r.findOne(Rezervare(x, 32, 40)) == 1 );
	assert(r.findOne(Rezervare("Maria", 32, 10)) == 1323);
	assert(r.getSize() == 3);
	r.delRezervare(r1);
	assert(r.getSize() == 2);
	r.addRezervare(r1);
	Rezervare px = r.update(r1, Rezervare("Marius",20,30));
	assert(r.findOne(Rezervare("Darius", 20, 30)) == 1323);
	assert(r.findOne(Rezervare("Marius", 20, 30)) == 2);
	assert(r.getSize() == 3);
	list<Rezervare> rev;
	rev = r.getAll();
	assert(rev.size() == 3);
	Rezervare s1("Ana", 21, 23);
	Rezervare s2("Maria", 19, 4);
	Rezervare s3("Florina", 20, 15);
	Rezervare s4("Marian", 18, 99);

	
	
	
	



	cout << "Testele Service!" << endl;
}

void TestService::test2()
{


	Service r;
	assert(r.getSize() == 0);
	Rezervare r1("Darius", 20, 30);
	r.addRezervare(r1);
	assert(r.getSize() == 1);
	Rezervare r2("Maria", 32, 10);
	r.addRezervare(r2);
	Rezervare r3("Denis", 20, 30);
	r.addRezervare(r3);
	list<Rezervare> re = r.filtreazaDupaNumeSiNr1("u", 10);
	assert(re.size() == 1);
	list<Rezervare> rex = r.filtreazaDupaNumeSiNr1("a", 12);
	assert(rex.size() == 2);
	list<Rezervare> rez = r.filtreazaDupaNumeSiNr1("i", 15);
	assert(rez.size() == 3);
	list<Rezervare> rey = r.filtreazaDupaNumeSiNr1("sersx", 10);
	assert(rey.size() == 0);

	
	cout << "Testele Service2!" << endl;

}
void TestService::test3() {
	Rezervare s1("Ana", 21, 23);
	Rezervare s2("Maria", 19, 4);
	Rezervare s3("Florina", 20, 15);
	Rezervare s4("Marian", 18, 99);
	Repo<Rezervare> rep;
	Service serv;
	assert(rep.getSize() == 0);
	rep.addElem(s1);
	rep.addElem(s2);
	rep.addElem(s3);
	rep.addElem(s4);
	assert(rep.getSize() == 4);
	serv.addRezervare(s1);
	serv.addRezervare(s2);
	serv.addRezervare(s3);
	serv.addRezervare(s4);
	vector<Rezervare> locSort = serv.sorteazaDupaLoc();
	assert(locSort[1] == s3);
	assert(locSort[3] == s4);
	cout << "Testele Service3!";
}


TestService::TestService()
{
}

void TestService::runTests()
{
	test1();
	test2();
	test3();
}

TestService::~TestService()
{
}
