#include "FahrAusnahme.h"



FahrAusnahme::FahrAusnahme()
{
}

FahrAusnahme::FahrAusnahme(Fahrzeug* fahr, Weg* abschnitt)
{
	p_pFahrzeug = fahr;
	p_pWeg = abschnitt;
}

FahrAusnahme::~FahrAusnahme()
{
}
