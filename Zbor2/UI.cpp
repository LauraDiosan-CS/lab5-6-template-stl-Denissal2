#include "UI.h"
#include <iostream>
using namespace std;

void addRez(Service& serv) {
	Rezervare re;
	cout << "Dati Rezervarea:";
	cin >> re;
	serv.addRezervare(re);
	cout << "Rezervarea a fost adaugata cu succes!" << endl;
}


void findStud(Service& serv) {
	Rezervare re;
	cout << "Dati Rezervarea:";
	cin >> re;
	__int64 rez = serv.findOne(re);
	cout << "Pozitia rezervarii este:" << rez;
}
	


void delRez(Service& serv) {
	Rezervare re;
	cout << "Dati Rezervarea:" << endl;
	cin >> re;
	serv.delRezervare(re);
	cout << "Rezervare stearsa" << endl;
}

void showAll(Service& serv) {
	list<Rezervare> re = serv.getAll();
	for (Rezervare r : re)
		cout << r;
}

void UpdateRezervare(Service& serv) {
	Rezervare re;
	cout << "Dati Rezervarea de modificat:" << endl;
	cin >> re;
	char* newnume = new char[25];
	cout << "Noul nume:" << endl;
	cin >> newnume;
	int newnr1;
	cout << "Noul numar de zbor:" << endl;
	cin >> newnr1;
	int newnr2;
	cout << "Noua numar al locului:" << endl;
	cin >> newnr2;
	Rezervare rex =serv.update(re,Rezervare(newnume,newnr1,newnr2));
	cout << "Rezervarea in cazul existentei acesteia a fost modificata!" << endl;


}


void Proprietate1(Service& serv) {
	char* n = new char[10];
	int v;
	cout << "Dati subsirul cautat in nume: ";
	cin >> n;
	cout << "Dati nr de zbor minimal:";
	cin >> v;

	list<Rezervare> re = serv.filtreazaDupaNumeSiNr1(n, v);
	for (Rezervare r : re)
		cout << r;
	delete[] n;

}


void Proprietate2(Service& serv) {

	list<Rezervare> rez = serv.sortByNrZbor();
	for (Rezervare r : rez)
		cout << r;

}

void Proprietate3(Service& serv) {

	list<Rezervare> rez = serv.sortByNrLoc();
	for (Rezervare r : rez)
		cout << r;

}


void Proprietate4(Service& serv) {
	char* nume_zbor = new char[25];
	cout << " Introduceti numele:";
	cin >> nume_zbor;
	int bonus = 0;
	list<Rezervare> re = serv.Avanseaza(nume_zbor);
	for (Rezervare r : re)
		cout << r;
	delete[] nume_zbor;
}

void Proprietate5(Service& serv) {
	char* nume_zbor = new char[25];
	cout << " Introduceti numele:";
	cin >> nume_zbor;
	int bonus = 0;
	list<Rezervare> re = serv.NrZborEgalCuPozLista(nume_zbor);
	for (Rezervare r : re)
		cout << r;
	delete[] nume_zbor;
}

void Proprietate6(Service& serv) {
	list<Rezervare> rez = serv.sortByNameCresc();
	for (Rezervare r : rez)
		cout << r;
}

void Proprietate7(Service& serv) {
	list<Rezervare> rez = serv.sortByNameDescrs();
	for (Rezervare r : rez)
		cout << r;
}

void addCost(Service& serv) {
	Cost cost;
	cout << "Dati Costul:";
	cin >> cost;
	serv.addCost(cost);
	cout << "Plata cu succes!" << endl;

}
void ShowAlls(Service& serv) {
	list<Cost> costuri = serv.getAlls();
	for (Cost c : costuri)
		cout << c;
}

void delCost(Service& serv) {
	Cost cost;
	cout << "Dati costul de sters";
	cin >> cost;
	serv.delCost(cost);
	cout << "Stergere efectuata cu succes in cazul in care isi are rostul!" << endl;
}

void findCost(Service& serv) {
	Cost re;
	cout << "Dati Costul:";
	cin >> re;
	__int64 rez = serv.findOneCost(re);
	cout << "Pozitia costului este:" << rez;
}

void UpdateCost(Service& serv) {
	Cost re;
	cout << "Dati Costul de modificat:" << endl;
	cin >> re;
	char* newclasa = new char[25];
	cout << "Noul nume:" << endl;
	cin >> newclasa;
	int newpret1;
	cout << "Noul pret:" << endl;
	cin >> newpret1;
	Cost rex = serv.updateCost(re, Cost(newclasa, newpret1));
	cout << "Rezervarea in cazul existentei acesteia a fost modificata!" << endl;


}

void NumarDeRezervari(Service& serv) {
	list<Rezervare> re = serv.getAll();
	cout <<"Numarul de rezervari:"<< re.size();
	list<Cost> cost = serv.getAlls();
	cout << endl;
	cout <<"Numarul de costuri:"<< cost.size();
}


void AfisareRezervariPret(Service& serv) {

	list<Rezervare> re = serv.getAll();
	for (Rezervare r : re)
		cout << r;
	cout << endl << endl << endl;
	list<Cost> costuri = serv.getAlls();
	for (Cost c : costuri)
		cout << c;

}



void showUI(Service& serv)
{
	bool gata = false;
	while (!gata) {
		cout << endl;
		cout << "OPTIUNI: " << endl;
		cout << "	1. Adauga rezervare " << endl;
		cout << "	2. Cauta rezervare " << endl;
		cout << "	3. Sterge rezervare " << endl;
		cout << "	4. Afiseaza toate rezervariile " << endl;
		cout << "	5. Modifica rezervare " << endl;
		cout << "	6. Proprietate  1 " << endl;
		cout << "	7. Proprietate  2 " << endl;
		cout << "	8. Proprietate  3 " << endl;
		cout << "	9. Proprietate  4 " << endl;
		cout << "	10. Proprietate 5 " << endl;
		cout << "	11. Proprietate 6" << endl;
		cout << "	12. Proprietate 7" << endl;
		cout << "	13. Adauga cost" << endl;
		cout << "	14. Afiseaza costuri" << endl;
		cout << "	15. Sterge cost" << endl;
		cout << "	16. Cauta cost" << endl;
		cout << "	17. Modifica cost" << endl;
		cout << "	18. Numarul de Rezervari/Costuri" << endl;
		cout << "   19.Afisare tot" << endl;
		cout << "	0. EXIT!" << endl;
		cout << "Introduceti optiunea (prin numarul ei): " ;
		int opt;
		cin >> opt;
		switch (opt) {
		case 1: {addRez(serv); break; }
		case 2: {findStud(serv); break; }
		case 3: {delRez(serv); break; }
		case 4: {showAll(serv); break; }
		case 5: {UpdateRezervare(serv);break;}
		case 6: {Proprietate1(serv);break;}
		case 7: {Proprietate2(serv);break;}
		case 8: {Proprietate3(serv);break;}
		case 9: {Proprietate4(serv);break;}
		case 10:{Proprietate5(serv);break;}
		case 11: {Proprietate6(serv);break;}
		case 12: {Proprietate7(serv);break;}
		case 13: {addCost(serv);break;}
		case 14: {ShowAlls(serv);break;}
		case 15: {delCost(serv);break;}
		case 16: {findCost(serv);break;}
		case 17: {UpdateCost(serv);break;}
		case 18: {NumarDeRezervari(serv);break;}
		case 19: {AfisareRezervariPret(serv);break;}
		case 0: {gata = true; cout << "LA REVEDERE!" << endl; }
		}
	}
}