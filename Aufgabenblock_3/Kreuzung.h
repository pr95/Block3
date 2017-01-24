#pragma once
#include "Weg.h"

class Kreuzung :
	public AktivesVO
{
public:
	//Konstruktor und Destruktor
	Kreuzung(string sName, double dTankstelle = 0);
	~Kreuzung();

	//Methoden
	void vVerbinde(string sWegHin, string sWegZurueck, double dLaenge, Kreuzung *pKreuzung,
		Begrenzung enumBegrenzung = Innerorts, bool bUeberholverbot = true);
	void vTanken(Fahrzeug* pFzg);
	void vAnnahme(Fahrzeug* pFzg, Weg* pWeg);							//Fahrend
	void vAnnahme(Fahrzeug* pFzg, double dStartzeit);		//Parkend
	void vAbfertigung();
	Weg* ptZufaelligerWeg(Weg*);

	//Getter, Setter, Adder
	void vAddWeg(Weg*);

	ostream& ostreamAusgabe(ostream&);

private:
	list<Weg*> p_pWege;		//Speichert abgehende Wege
	double p_dTankstelle;	//Tankinhalt der Tankstelle
};

