#include "Streckenende.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include "Kreuzung.h"


Streckenende::Streckenende(Fahrzeug* fFahrzeug, Weg* wWeg):FahrAusnahme(fFahrzeug, wWeg)
{
}


Streckenende::~Streckenende()
{
}

void Streckenende::vBearbeiten()
{
	p_pWeg->vAbgabe(p_pFahrzeug);
	Kreuzung* kr = p_pWeg->vGetKreuzung();
	kr->vAnnahme(p_pFahrzeug, p_pWeg);
	cout << "Ausnahme: Streckenende, Weg und Fahrzeug: " << p_pWeg->getName() << " " << p_pFahrzeug->getName() << endl << endl;
}