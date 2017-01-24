#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include "AktivesVO.h"

class FzgVerhalten;
using namespace std;


class Fahrzeug : 
	public AktivesVO
{
public:
	//Konstruktoren
	Fahrzeug();
	Fahrzeug(string sName);			
	Fahrzeug(string sName, double dMaxKmh);
	
	//Copyconstruktor
	Fahrzeug(const Fahrzeug&);

	//Destructor
	virtual ~Fahrzeug();
	
	//Methoden
	virtual void vAbfertigung();
	virtual double dTanken(double dMenge = -1);
	virtual double dGeschwindigkeit();
	virtual void vNeueStrecke(Weg*);				//Fahrendes Fahrzeug
	virtual void vNeueStrecke(Weg*, double);		//Parkendes Fahrzeug
	virtual void vZeichnen(Weg*);
	
	//Überladung von Operatoren
	virtual ostream& ostreamAusgabe(ostream&);
	bool operator <(Fahrzeug&);
	virtual Fahrzeug& operator =(Fahrzeug&);

	//Getter
	virtual FzgVerhalten* getVerhalten() const;
	virtual double getAbschnittStrecke() const;


private:
	void vInitialisierung();

//Attribute zum Vererben	
protected:
	int p_iID;
	double p_dMaxGeschwindigkeit;
	double p_dGesamtStrecke;
	double p_dGesamtZeit;
	double p_dZeit;
	double p_dAbschnittStrecke;
	FzgVerhalten* p_pVerhalten;

};

ostream& operator << (ostream& daten, Fahrzeug& fahrzeug); 
