#pragma once
#include "AktivesVO.h"
#include "LazyListe.h"

class Fahrzeug;
class Kreuzung;
typedef list<Fahrzeug*> ListFahrzeug;
enum Begrenzung { Innerorts = 50, Landstraﬂe = 100, Autobahn = -1 }; //Innerorts, Landstraﬂe, Autobahn

class Weg :
	public AktivesVO	

{
//Anlegung von Aufz‰hlung Begrenzung zur Nutzung im Konstruktor
public:
	Weg();
	Weg(string sName, double dLaenge, Begrenzung eLimit = Innerorts, bool bUeberholverbot = true);
	~Weg();


	void vAbfertigung();
	void vAnnahme(Fahrzeug*);
	void vAnnahme(Fahrzeug*, double);
	void vAbgabe(Fahrzeug*);

	//Getter
	double dGetLaenge();
	double dGetSchranke();
	int iGetLimit();
	Kreuzung* vGetKreuzung();
	Weg* vGetRueckweg();

	//Setter
	void vSetSchranke(double dStrecke);
	void vSetRueckweg(Weg* pWeg);
	void vSetKreuzung(Kreuzung* pKreuz);

	ostream& ostreamAusgabe(ostream&);

private:
	double p_dLaenge;
	LazyListe<Fahrzeug*> p_pFahrzeuge;
	Begrenzung p_eLimit;
	bool p_bUeberholverbot;
	double p_dSchranke;

	Weg* p_pRueckweg;
	Kreuzung* p_pKreuzung;	//Kreuzung am Ende der Strasse
};

