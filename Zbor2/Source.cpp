#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include "Rezervare.h"
#include "testZbor.h"
#include "stdlib.h"
#include "Repo.h"
#include "testRepo.h"
#include "Service.h"
#include <conio.h>
#include "testService.h"
#include "UI.h"
#include "RepoFile.h"
#include "TestRepoFile.h"
using namespace std;

void initService(Service& ) {
	RepoFile<Rezervare> re;
	re.loadFromFile("Text.txt");
	//s.setRepo(re);
	
}

int main() {
	//cout << " start main ..." << endl;cout << "Trec testele?" << endl;
	//cout << "au trecut testele!" << endl;
	//cout << "Succes!" << endl;
	teste2();
	testRepo();
	testRepo2();
	testRepo3();
	TestRepoFile t;
	t.testLoadFromFile();
	t.~TestRepoFile();
	TestService ts;
	ts.runTests();
	//Repo<Rezervare> r;
	// Nu e necesar sa pastrez aceest repo
	Service serv;
	initService(serv);
	showUI(serv);
	cout << "succes";
	return 0;

	
	
}