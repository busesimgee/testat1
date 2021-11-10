#include"Fahrzeug.h"
#include"PKW.h"
#include"Fahrrad.h"
#include<iostream>
#include<iomanip>

#include <map>
#include<memory>
#include<vector>
#include<cmath>
#include<string>

double dGlobaleZeit = 0.0;

using namespace std;


//Testfunktion Aufgabe 1
void vAufgabe1()
{
	Fahrzeug f1("F1");
	Fahrzeug f2("Hans");
	Fahrzeug* f3 = new Fahrzeug("Pointerfahrzeug");
	Fahrzeug* f4 = new Fahrzeug();
	delete f3;
	delete f4;
	auto f5 = make_unique<Fahrzeug>();
	auto f6 = make_unique<Fahrzeug>("Smart");
	shared_ptr<Fahrzeug> f7 = make_shared<Fahrzeug>();
	auto f8 = make_shared<Fahrzeug>("Geteilter Smart");
	cout << f8.use_count() << endl;
	shared_ptr<Fahrzeug> f8_2 = f8;
	cout << f8.use_count() << endl;
	//auto f9 = make_unique<Fahrzeug>("Geteilter Smart");
	//cout << f9.use_count() << endl;
	//unique_ptr<Fahrzeug> f9_2 = f9;
	//cout << f9.use_count() << endl;
	vector<unique_ptr<Fahrzeug>> fVec;
	fVec.push_back(move(f5));
	fVec.push_back(move(f6));
	fVec.clear();
	//Vektor mit sharedPtr
	auto f10 = make_shared<Fahrzeug>("Shared 2");
	vector<shared_ptr<Fahrzeug>> fVecShared;
	fVecShared.push_back(f8);
	cout << fVecShared.back().use_count();
	fVecShared.push_back(move(f10));
	cout << fVecShared.back().use_count();
	cout << endl << endl;
	f1.vKopf();
	cout << endl;
	f1.vAusgeben();
	cout << endl;
	f2.vAusgeben();
	cout << endl;
	f6->vAusgeben();
}
void vAufgabe1a()
{
	vector<unique_ptr<Fahrzeug>> vec1a;
	for (int i = 1; i < 4; i++)
	{
		string sName;
		double dMaxGeschwindigkeit;
		cout << "Bitte Name und max. Geschwindigkeit des " << i << ". Fahrzeugs eingeben:"
			<< endl;
		cin >> sName;
		cin >> dMaxGeschwindigkeit;
		vec1a.push_back(make_unique<Fahrzeug>(sName, dMaxGeschwindigkeit));
	}
	for (; dGlobaleZeit < 1; dGlobaleZeit += .1)
	{
		cout << endl;
		vec1a[0]->vKopf();
		cout << endl;
		for (int i = 0; i < 3; i++)
		{
			vec1a[i]->vSimulieren();
			vec1a[i]->vAusgeben();
			cout << endl;
		}
	}
}
void vAufgabe_2()
{
	vector<unique_ptr<Fahrzeug>> vec_2;
	cout << "Anzahl der zu erstellenden PKWs: ";
	int iAnzahl;
	cin >> iAnzahl;
	for (int i = 0; i < iAnzahl; i++)
	{
		cout << "Name, max. Geschwindigkeit, Verbrauch in l/100km und Tankvolumen des " << i
			<< ". Autos angeben: " << endl;
		string sName;
		double dMaxGeschwindigkeit, dVerbrauch, dTankvolumen;
		cin >> sName;
		cin >> dMaxGeschwindigkeit;
		cin >> dVerbrauch;
		cout << "Tankvolumen angeben? (j/n) \n";
		string sEingabe;
		cin >> sEingabe;
		if (sEingabe == "j")
		{
			cin >> dTankvolumen;
			vec_2.push_back(make_unique<PKW>(sName, dMaxGeschwindigkeit, dVerbrauch,
				dTankvolumen));
		}
		else
		{
			vec_2.push_back(make_unique<PKW>(sName, dMaxGeschwindigkeit, dVerbrauch));
		}
	}
	cout << "Anzahl der zu erstellenden Fahrräder: ";
	cin >> iAnzahl;
	for (int i = 0; i < iAnzahl; i++)
	{
		cout << "Name und max. Geschwindigkeit des " << i << ". Fahrrads eingeben: " << endl;
		string sName;
		double dMaxGeschwindigkeit;
		cin >> sName;
		cin >> dMaxGeschwindigkeit;
		vec_2.push_back(make_unique<Fahrrad>(sName, dMaxGeschwindigkeit));
	}
	bool bSchonGetankt = false;
	for (; dGlobaleZeit < 12; dGlobaleZeit += .5)
	{
		cout << endl;
		cout << "Aktuelle Zeit: " << dGlobaleZeit << endl;
		vec_2[0]->vKopf();
		cout << endl;
		for (unsigned int i = 0; i < vec_2.size(); i++)
		{
			vec_2[i]->vSimulieren();
			if (dGlobaleZeit >= 2.97 && bSchonGetankt == false)
			{
				vec_2[i]->dTanken();
			}
			vec_2[i]->vAusgeben(cout);
			cout << endl;
		}
		if (dGlobaleZeit >= 2.97) { bSchonGetankt = true; }
	}
}
void vAufgabe3()
{
	PKW a1("Hans", 100, 10);
	PKW a2("Otto", 200, 10);
	Fahrrad f1("dumm", 30);
	dGlobaleZeit = 2;
	a1.vSimulieren();
	a2.vSimulieren();
	f1.vSimulieren();
	(a1 > f1) ? cout << "> funktioniert." : cout << "Fehler bei >-Operator";
	cout << endl;
	(a1 < a2) ? cout << "< funktioniert." : cout << "Fehler bei <-Operator";
	cout << endl;
	a1.vKopf();
	cout << endl;
	cout << "Ausgabe von a1: " << a1 << endl;
	a2 = a1;
	cout << "Kopie von a1: " << a2 << endl;
}
int main()
{
	vAufgabe3();
	return 0;
}