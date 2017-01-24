#pragma once
#include "Fahrzeug.h"

/*
PKW Klasse
Erbt von Fahrzeug
*/
class PKW :
	public Fahrzeug
{

public:
	//Konstruktoren
	PKW();
	PKW(string sName, double dMaxKmh, double dVerbrauch, double dTankvolumen = 55);
	
	//Copykonstruktor
	PKW(const PKW&); 

	//Destruktor
	~PKW();

	//Methoden
	void vAbfertigung();
	void vZeichnen(Weg*);

	//Überladung
	ostream& ostreamAusgabe(ostream&);
	PKW& operator =(PKW&);

private:
	//Attribute
	double p_dVerbrauch;	//Verbrauch/100km
	double p_dTankinhalt;	//In Liter
	double p_dTankvolumen;	//Standard 55l
	
	//Methoden
	double dVerbrauch();
	double dTanken(double dMenge = -1);
	double dGeschwindigkeit();
};

