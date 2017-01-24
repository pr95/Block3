#include "FzgParken.h"
#include "Weg.h"
#include "Losfahren.h"



FzgParken::FzgParken(Weg* Weg):FzgVerhalten(Weg)
{
}

FzgParken::FzgParken(Weg* Weg, double dStartzeit) : FzgVerhalten(Weg)
{
	p_dStartzeit = dStartzeit;
}

FzgParken::~FzgParken()
{
}

//Lässt das Fahrzeug erst abfahren, wenn die Startzeit erreicht wurde
double FzgParken::dStrecke(Fahrzeug* fFahrzeug, double Zeitraum)
{
	//Wenn Startzeit erreicht wird, springt es in die exception
	if (p_dStartzeit-dGlobaleZeit>epsilon)
	{
		return 0.0;
	}
	else
	{
		throw new Losfahren(fFahrzeug, p_pWeg);
	}
}

//Gibt 0 als aktuelle Geschwindigkeit zurück
int FzgParken::getSpeed() const
{
	return 0;
}