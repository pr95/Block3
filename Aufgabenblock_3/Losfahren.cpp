#include "Losfahren.h"
#include "Weg.h"
#include "Fahrzeug.h"



Losfahren::Losfahren(Fahrzeug* fFahrzeug, Weg* wWeg):FahrAusnahme(fFahrzeug, wWeg)
{
	
}


Losfahren::~Losfahren()
{
}

void Losfahren::vBearbeiten()
{
	p_pWeg->vAbgabe(p_pFahrzeug);
	p_pWeg->vAnnahme(p_pFahrzeug);

	cout << "Ausnahme: Losfahren; Fahrzeug, Startzeit und Name: " << p_pFahrzeug->getName() << " " << dGlobaleZeit << " " << p_pWeg->getName() << endl << endl;
}