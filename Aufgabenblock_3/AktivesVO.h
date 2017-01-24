#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <list>
#include <math.h>
#include "SimuClient.h"
#define gZeitschritt 0.01
#define epsilon 0.0001

using namespace std;
class Weg;

extern double dGlobaleZeit;

class AktivesVO
{
public:
	AktivesVO();
	AktivesVO(string sName);
	~AktivesVO();


	//Gemeinsam genutzte Methoden von Fahrzeug und Weg
	virtual void vAbfertigung()=0;

	//Überladung der Operatoren
	virtual ostream& ostreamAusgabe(ostream&);

	//Getter
	virtual string getName() const;

private:
	static int p_iMaxID;
	void vInitialisierung();

protected:
	int p_iID;
	string p_sName;
	double p_dZeit;
};

ostream& operator << (ostream& daten, AktivesVO& fahrzeug);