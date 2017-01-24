#include "PKW.h"
#include "FzgParken.h"
#include "FzgFahren.h"


//Standardkonstruktor
PKW::PKW() : Fahrzeug()
{
}

//Konstruktor mit allen Attributen
PKW::PKW(string sName, double dMaxGeschwindigkeit, double dVerbrauch, double dTankvolumen):Fahrzeug(sName, dMaxGeschwindigkeit)
{
	p_dVerbrauch = dVerbrauch/100;
	p_dTankvolumen = dTankvolumen;
	p_dTankinhalt = p_dTankvolumen / 2;
}

//Selbstdefinierter Copyconstructor
PKW::PKW(const PKW& pkw):Fahrzeug(pkw)
{
	p_dVerbrauch = pkw.p_dVerbrauch;
	p_dTankvolumen = pkw.p_dTankvolumen;
	p_dTankinhalt = pkw.p_dTankinhalt;
}

//Destruktor (virtuell)
PKW::~PKW()
{
}

//Gibt den Gesamtverbrauch zurück
double PKW::dVerbrauch()
{
	return p_dVerbrauch*p_dGesamtStrecke;
}

/*
Funktion zum betanken des PKWs. Defaultparameter ist auf 666 gesetzt als genügend große Zahl zum volltanken
egal wie groß der Tank ist.
Es wird die tatsächlich getankte Menge zurückgegeben.
*/
double PKW::dTanken(double dMenge)
{
	double dTankDif = p_dTankvolumen - p_dTankinhalt;

	if (dMenge < 0)
	{
		p_dTankinhalt = p_dTankvolumen;
		cout << "Das Fahrzeug " << p_sName << " wurde mit " << dTankDif << "l voll getankt!" << endl;
		p_dTankinhalt = p_dTankvolumen;

		return dTankDif;
	}
	else
	{
		p_dTankinhalt += dMenge;
		cout << "Das Fahrzeug " << p_sName << " wurde mit " << dMenge << "l auf " << p_dTankinhalt << "l aufgefüllt!" << endl;
		
		return dMenge;
	}

	return 0;
}

/*
Funktion zur speziellen Abfertigung von PKW. Erst wird geschaut, ob der PKW überhaupt noch Tankinhalt hat,
danach wird erst die allgemeine Abfertigung aufgerufen, wobei der alte Streckenstand gespeichert wird zur
Berechnung der nur im letzten Schritt abgelegten Strecke
*/
void PKW::vAbfertigung()
{
	if (p_dTankinhalt > 0)
	{
		double dGesamtstreckeAlt = p_dGesamtStrecke;
		
		Fahrzeug::vAbfertigung();

		p_dTankinhalt -= (p_dVerbrauch) *(p_dGesamtStrecke - dGesamtstreckeAlt);

		if (p_dTankinhalt < 0)
		{
			p_dTankinhalt = 0;
		}
	}
}

void PKW::vZeichnen(Weg* pWeg)
{
	double dRelPos = p_dAbschnittStrecke / (pWeg->dGetLaenge());
	
	bZeichnePKW(p_sName, pWeg->getName(), dRelPos, dGeschwindigkeit(), p_dTankinhalt);
}


//Ausgabe der maximalen Gechwindigkeit als aktuelle Geschwindigkeit
double PKW::dGeschwindigkeit()
{
	double d_StreckenGeschwindigkeit = p_pVerhalten->getSpeed();

	if ((d_StreckenGeschwindigkeit > p_dMaxGeschwindigkeit  || d_StreckenGeschwindigkeit < 0) && p_dTankinhalt > 0)
	{
		return p_dMaxGeschwindigkeit;
	}
	else if (p_dTankinhalt <= 0)
	{
		return 0;
	}
	else
	{
		return d_StreckenGeschwindigkeit;
	}
}

//Ergänzung der ostream Ausgabe für PKWs
ostream& PKW::ostreamAusgabe(ostream& daten)
{
	Fahrzeug::ostreamAusgabe(daten) << setw(17) << setfill(' ') << dVerbrauch() << setw(15) << setfill(' ') << p_dTankinhalt;

	return daten;
}

//Überladung des = Operators für PKWs
PKW& PKW::operator =(PKW& fahrzeug)
{
	
		return PKW::PKW(fahrzeug); 
}

//zeichnen
//bZeichnen(Namen, relativPos., 