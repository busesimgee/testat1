#include "PKW.h"
#include "Fahrzeug.h"

#include <iomanip>
#include <iostream>

PKW::PKW(string sName, double dMaxGeschwindigkeit, double dVerbrauch, double dTankvolumen) :
	Fahrzeug(sName, dMaxGeschwindigkeit), p_dVerbrauch(dVerbrauch),
	p_dTankvolumen(dTankvolumen), p_dTankinhalt(dTankvolumen / 2)
{}
double PKW::dTanken(double dMenge)
{
	double dFreierTank = p_dTankvolumen - p_dTankinhalt;
	if (dMenge < 0)
	{
		return 0;
	}else if (dFreierTank > dMenge)
	{
		p_dTankinhalt += dMenge;
		return dMenge;
	}else
	{
	p_dTankinhalt = p_dTankvolumen;
	return dFreierTank;
	}
}
void PKW::vSimulieren()
{
	double dTankverbrauch = (dGlobaleZeit - p_dZeit) * dGeschwindigkeit() * p_dVerbrauch /
		100;
	//Wenn der Tank nicht leer ist
	if (p_dTankinhalt > 0)
	{
		Fahrzeug::vSimulieren();
		p_dTankinhalt -= dTankverbrauch;
		if (p_dTankinhalt < 0) { p_dTankinhalt = 0; }
	}else
	{
	p_dZeit = dGlobaleZeit;
	}
}
void PKW::vAusgeben(ostream& o) const
{
	Fahrzeug::vAusgeben(o);
	o.flags(ios::right);
	o.setf(ios::fixed, ios::floatfield);
	o.precision(2);
	o << setw(20) << p_dGesamtStrecke * p_dVerbrauch / 100 << setw(20) << p_dTankinhalt;
}
void PKW::operator=(const PKW& a2)
{
	p_sName = a2.p_sName;
	p_dMaxGeschwindigkeit = a2.p_dMaxGeschwindigkeit;
	p_dVerbrauch = a2.p_dVerbrauch;
	p_dTankvolumen = a2.p_dTankvolumen;
	p_dTankinhalt = p_dTankvolumen / 2;
}
