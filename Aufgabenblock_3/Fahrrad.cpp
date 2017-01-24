#include "Fahrrad.h"
#include "FzgParken.h"
#include "FzgFahren.h"


//Standard-Konstruktor
Fahrrad::Fahrrad()
{
}

//Konstruktor mit Parametern
Fahrrad::Fahrrad(string sName, double dMaxGeschwindigkeit) :Fahrzeug(sName, dMaxGeschwindigkeit)
{
}

//Copykonstruktor
Fahrrad::Fahrrad(const Fahrrad& fahrrad) : Fahrzeug(fahrrad)
{
}

//Destruktor
Fahrrad::~Fahrrad()
{
}

/*
Funktion zur Ausgabe der aktuellen Geschwindigkeit.
Geschwindigkeit nimmt alle 20km um 10% ab, bleibt bei minimal 12km/h
*/
double Fahrrad::dGeschwindigkeit()
{
	int iAnzahl_20km = (int)(p_dGesamtStrecke / 20);

	double dAktuelleGeschwindigkeit = p_dMaxGeschwindigkeit * pow(0.9, iAnzahl_20km);

	if (dAktuelleGeschwindigkeit < 12)
	{
		dAktuelleGeschwindigkeit = 12;
	}

	return dAktuelleGeschwindigkeit;
}

void Fahrrad::vZeichnen(Weg* pWeg)
{
	double dRelPos = p_dAbschnittStrecke / (pWeg->dGetLaenge());

	bZeichneFahrrad(p_sName, pWeg->getName(), dRelPos, dGeschwindigkeit());
}