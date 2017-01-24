#pragma once
#include "FahrAusnahme.h"
class Losfahren :
	public FahrAusnahme
{
public:
	Losfahren(Fahrzeug* pFahrzeug, Weg* pWeg);
	~Losfahren();
	void vBearbeiten();
};

