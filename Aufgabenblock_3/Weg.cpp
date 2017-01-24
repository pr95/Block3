#include "Weg.h"
#include "Fahrzeug.h"
#include "FahrAusnahme.h"

//Standardkonstruktor
Weg::Weg()
{
}

//Konstruktor mi Name, Länge und Begrenzung
Weg::Weg(string sName, double dLaenge, Begrenzung eLimit, bool bUeberholverbot) :AktivesVO(sName)
{
	p_dLaenge = dLaenge;
	p_eLimit = eLimit;
	p_bUeberholverbot = bUeberholverbot;
	p_dSchranke = p_dLaenge;
} 

//Destruktor
Weg::~Weg()
{
}

//Gibt die Länge des Weges aus
double Weg::dGetLaenge() { return p_dLaenge; }

//Gibt die Schranke des Weges aus
double Weg::dGetSchranke() 
{
	if (p_bUeberholverbot)
	{
		return p_dSchranke;
	}
	
	return p_dLaenge;
}

//Gibt das Limit des Weges aus
int Weg::iGetLimit() { return p_eLimit; }

//Setzt die neue Schranke
void Weg::vSetSchranke(double dStrecke) { p_dSchranke = dStrecke; }

//Setzt den Rueckweg
void Weg::vSetRueckweg(Weg* pWeg) { p_pRueckweg = pWeg; }

//Gibt den Rueckweg aus
Weg* Weg::vGetRueckweg() { return p_pRueckweg; }

//Setzt die Kreuzung auf die die Strasse fuehrt
void Weg::vSetKreuzung(Kreuzung* pKreuz) { p_pKreuzung = pKreuz; }

//Getter für Kreuzung auf die Straße führt
Kreuzung* Weg::vGetKreuzung() { return p_pKreuzung; }

//Fertigt die Fahrzeuge auf dem Weg ab
void Weg::vAbfertigung()
{
	LazyListe<Fahrzeug*>::iterator itL;
	itL = p_pFahrzeuge.begin();

	p_dSchranke = p_dLaenge;

	while (p_pFahrzeuge.end() != itL)
	{
		try
		{
			(*itL)->vAbfertigung();
			(*itL)->vZeichnen(this);
			
		}
		catch (FahrAusnahme *pAusnahme)
		{
			pAusnahme->vBearbeiten();
		}

		itL++;
	}

	p_pFahrzeuge.vAktualisieren();

}

//Nimmt neue FAHRENDE Fahrzeuge auf den Weg auf
void Weg::vAnnahme(Fahrzeug* pFzg)
{
	p_pFahrzeuge.push_back(pFzg);
	pFzg->vNeueStrecke(this);
}

//Nimmt neue PARKENDE Fahrzeuge auf den Weg auf
void Weg::vAnnahme(Fahrzeug* pFzg, double dStartzeit)
{
	p_pFahrzeuge.push_front(pFzg);
	pFzg->vNeueStrecke(this, dStartzeit);
}


//Entfernt ein Fahrzeug aus der Liste
void Weg::vAbgabe(Fahrzeug* pFzg)
{
	LazyListe<Fahrzeug*>::iterator itL;
	itL = p_pFahrzeuge.begin();
	int i = 0;
	
	while (p_pFahrzeuge.end() != itL)
	{
		if ((*itL) == pFzg)
		{
			p_pFahrzeuge.erase(itL);
		}
		itL++;
	}

}

//Ausgabe des Weges und der darauf befindlichen Fahrzeuge
ostream& Weg::ostreamAusgabe(ostream& daten)
{
	AktivesVO::ostreamAusgabe(daten) << p_dLaenge << "     ( ";

	LazyListe<Fahrzeug*>::iterator itL;
	itL = p_pFahrzeuge.begin();

	while (p_pFahrzeuge.end() != itL)
	{
		daten << (*itL)->getName() << " ";
		itL++;
	}

	daten << ")";

	return daten;
}



