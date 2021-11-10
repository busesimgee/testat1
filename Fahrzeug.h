#pragma once
#include<string>
#include<iostream>
#include<iomanip>
#include<cmath>

extern double dGlobaleZeit;

using namespace std;

class Fahrzeug
{
private:
	//Statische Variable: Maximal vergebene ID
	static int p_iMaxID;
protected:
	//Name des Fahrzeugs
	string p_sName = "";
	//Eindeutige ID
	const int p_iID = 0; //Maximalgeschwindigkeit
	double p_dMaxGeschwindigkeit = 0;
	//bisher zurueckgelegte Gesamtstrecke
	double p_dGesamtStrecke = 0;
	//gesamte Fahrzeit
	double p_dGesamtZeit = 0;
	//letzte Simulationszeit
	double p_dZeit = 0;
public:
	//Standardkonstruktor
	Fahrzeug();
	//Konstruktor, Name als Eingabe, hochzählende ID
	Fahrzeug(string);
	//Konstruktor, Name als Eingabe, hochzählende ID, Maximalgeschwindigkeit
	Fahrzeug(string, double);
	//Destruktor
	virtual ~Fahrzeug();
	//Ausgabefunktion
	virtual void vAusgeben(ostream& o = cout) const;
	//Static Ausgabefunktion Tabellenkopf
	static void vKopf();
	//Simulationsfkt
	virtual void vSimulieren();
	//Tanken. Falls kein PKW, wird nichts getankt
	virtual double dTanken(double dMenge = numeric_limits<double>::infinity());
	//gibt aktuelle Geschwindigkeit an
	virtual double dGeschwindigkeit() const;
	//Kleiner-Operator fuer Fahrzeuge. True falls Gesamtstrecke kleiner ist
	bool operator<(Fahrzeug& f2) const;
	//Groesser-Operator fuer Fahrzeuge. True falls Gesamtstrecke groesser ist
	bool operator>(Fahrzeug& f2) const;
	//Copy-Konstruktor verbieten
	Fahrzeug(const Fahrzeug&) = delete;
	//Zuweisungsoperator fuer Fahrzeuge. Uebertraegt nur Stammdaten (Name, Maximalgeschwindigkeit)
	virtual void operator=(const Fahrzeug& f2);
};
//Ueberladung des <<-Operators fuer Fahrzeuge
ostream& operator<<(ostream& o, const Fahrzeug&);
