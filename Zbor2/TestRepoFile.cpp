#include "TestRepoFile.h"
#include <assert.h>
#include <iostream>
using namespace std;

TestRepoFile::TestRepoFile()
{
	assert(repo.getSize() == 0);
	
}

void TestRepoFile::testLoadFromFile()
{
	
	repo.loadFromFile("PentruTeste.txt");
	assert(repo.getSize() == 4 );
	//repo.saveToFile();
	//repo.loadFromFile("PentruTeste.txt");
	//repo.add(Rezervare("Ions", 19, 20));
	//assert(repo.getSize() == 5);
	//repo.saveToFile();
	// Problema cu saveToFile
	//repo.loadFromFile("PentruTeste.txt");
	//size_t n = repo.getSize();
	//repo.add(Rezervare("Ionica", 19, 22));
	//repo.saveToFile();
	//repo.loadFromFile("PentruTeste.txt");
	//assert(repo.GetAll().size() == n+1 );
	//repo.loadFromFile("PentruTeste.txt");
	//repo.del2(Rezervare("Ionica", 19, 22));
	//repo.del2(Rezervare("Ions", 19, 20));
	//repo.saveToFile();
	cout << "Au trecut testele RepoFile!" << endl;
	
}




TestRepoFile::~TestRepoFile()
{
	cout << "Au trecut testele2 RepoFile!" << endl;
}




