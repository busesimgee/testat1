#include "Fahrzeug.h"


int Fahrzeug::p_iMaxID = 0;

Fahrzeug::Fahrzeug()
{
	cout << "Standardkonstruktor." << endl << "Name des Fahrzeugs: " << p_sName << endl <<
		"ID: " << p_iID << endl << endl;
}
Fahrzeug::Fahrzeug(string sName) : p_sName(sName), p_iID(p_iMaxID)
{
	p_iMaxID++;
	cout << "Konstruktor." << endl << "Name des Fahrzeugs: " << p_sName << endl << "ID: " <<
		p_iID << endl << endl;
}
Fahrzeug::Fahrzeug(string sName, double dMaxGeschwindigkeit) : p_sName(sName),
p_dMaxGeschwindigkeit((dMaxGeschwindigkeit > 0) ? dMaxGeschwindigkeit : 0), p_iID(p_iMaxID)
{
	p_iMaxID++;
	cout << "Konstruktor." << endl << "Name des Fahrzeugs: " << p_sName << endl << "ID: " <<
		p_iID << endl << endl;
}
Fahrzeug::~Fahrzeug()
{
	cout << "Destruktor." << endl << "Name des Fahrzeugs: " << p_sName << endl << "ID: " <<
		p_iID << endl << endl;
}
void Fahrzeug::vAusgeben(ostream& o) const
{
	o.flags(ios::right);
	o.setf(ios::fixed, ios::floatfield);
	o.precision(2);
	o << setw(5) << p_iID << setw(20) << p_sName << setw(25) << p_dMaxGeschwindigkeit <<
		setw(20) << p_dGesamtStrecke << setw(30) << dGeschwindigkeit();
}
void Fahrzeug::vKopf()
{
	cout << setw(10) << "ID" << setw(20) << "Name" << setw(30) << "Max. Geschwindigkeit" <<
		setw(25) << "Gesamtstrecke" << setw(35) << "akt. Geschwindigkeit" << setw(25)
		<< "Gesamtverbrauch" << setw(25) << "akt. Tankinhalt" << endl;
	cout <<
		"---------------------------------------------------------------------------------------------------------------------------------------------";
}
void Fahrzeug::vSimulieren()
{
	if (dGlobaleZeit > p_dZeit)
	{
		double dZeitdifferenz = dGlobaleZeit - p_dZeit;
		p_dGesamtStrecke += dZeitdifferenz * dGeschwindigkeit();
		p_dGesamtZeit += dZeitdifferenz;
		p_dZeit = dGlobaleZeit;
	}
}
double Fahrzeug::dTanken(double dMenge)
{
	return 0.0;
}
double Fahrzeug::dGeschwindigkeit() const
{
	return p_dMaxGeschwindigkeit;
}
bool Fahrzeug::operator<(Fahrzeug& f2) const
{
	return (this->p_dGesamtStrecke < f2.p_dGesamtStrecke) ? true : false;
}
bool Fahrzeug::operator>(Fahrzeug& f2) const
{
	return (this->p_dGesamtStrecke > f2.p_dGesamtStrecke) ? true : false;
}
void Fahrzeug::operator=(const Fahrzeug& f2)
{
	p_sName = f2.p_sName;
	p_dMaxGeschwindigkeit = f2.p_dMaxGeschwindigkeit;
}
//Ueberladung des <<-Operators fuer Fahrzeuge
ostream& operator<<(ostream& o, const Fahrzeug& fahrzeug)
{
	fahrzeug.vAusgeben(o);
	return o;
}
