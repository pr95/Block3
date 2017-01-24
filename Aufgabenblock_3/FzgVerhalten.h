#pragma once
#include "Weg.h"

class FzgVerhalten
{
public:
	//Konstruktor und Destruktor
	FzgVerhalten(Weg* pWeg);
	~FzgVerhalten();

	virtual double dStrecke(Fahrzeug*, double)=0;
	virtual int getSpeed() const = 0;

protected:
	Weg* p_pWeg;


};

