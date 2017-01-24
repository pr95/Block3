#include "FzgFahren.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include "Streckenende.h"


FzgFahren::FzgFahren(Weg* Weg):FzgVerhalten(Weg)
{
}


FzgFahren::~FzgFahren()
{
}


//
double FzgFahren::dStrecke(Fahrzeug* pFzg, double dZeitraum)
{
	double dFahrbareStrecke = pFzg->dGeschwindigkeit() * dZeitraum;
	double dUebrigeStrecke = this->p_pWeg->dGetSchranke() - pFzg->getAbschnittStrecke();
	
	
	if (this->p_pWeg->dGetLaenge() == pFzg->getAbschnittStrecke())
	{
		throw new Streckenende(pFzg, p_pWeg);
	}
	else if (dFahrbareStrecke > (dUebrigeStrecke))
	{
		return dUebrigeStrecke;
	}
	else
	{
		p_pWeg->vSetSchranke(dFahrbareStrecke + pFzg->getAbschnittStrecke());
		return dFahrbareStrecke;
	}

	return 0.0;
}

//Gibt das Geschwindigkeitslimit des Weges zurück
int FzgFahren::getSpeed() const
{
	return p_pWeg->iGetLimit();
}
