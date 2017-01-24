#include "PKW.h"
#include "Fahrrad.h"
#include "Weg.h"
#include "Kreuzung.h"
#include <vector>
#include "SimuClient.h"
#include <stdlib.h>
#include "LazyListe.h"


//Uhr initialisieren (global)
double dGlobaleZeit = 0.0;

void vWegTabellenkopf()
{
	cout << setw(4) << resetiosflags(ios::right) << setiosflags(ios::left) << setfill(' ')
		<< "ID" << setw(9) << setfill(' ') << "Name" << "Laenge  Fahrzeuge" << endl;
}


void vAufgabe_5()
{
	Weg* WegHin = new Weg("A", 500, Autobahn);
	Weg* WegRueck = new Weg("B", 500, Autobahn);

	PKW* Audi = new PKW("Audi", 200, 5);
	PKW* Parki = new PKW("Parki", 50, 5, 60);

	WegHin->vAnnahme(Audi);
	WegRueck->vAnnahme(Parki, 1.0);

	int Koordinaten[4] = { 700, 250, 100, 250 };
	
	bInitialisiereGrafik(800, 500);

	bZeichneStrasse("A", "B", 500, 2, Koordinaten);
	bZeichnePKW("Audi", "A", epsilon, 200, 50);
	bZeichnePKW("Parki", "B", 0.5, 0, 60);

	while (dGlobaleZeit < 4)
	{
		vSetzeZeit(dGlobaleZeit);
		cout << "Nach " << dGlobaleZeit << "h" << endl;
		WegHin->vAbfertigung();
		WegRueck->vAbfertigung();

		dGlobaleZeit += gZeitschritt;
		vSleep(500);
	}
}

void vAufgabe_6a()
{
	LazyListe<int> Liste;
	LazyListe<int>::iterator itL;

	//Initialisieren der Liste mti Random Integers
	for (int i = 0; i < 20; i++)
	{
		int zahl = rand() % 10 + 1;
		Liste.push_back(zahl);
	}
	
	//Aktualisieren der Liste
	Liste.vAktualisieren();
	
	cout << "Liste wurde Initialisiert:" << endl;
	
	//Erste Ausgabe der Liste
	itL = Liste.begin();
	while (itL != Liste.end())
	{
		cout << *itL << endl;
		itL++;
	}

	cout << endl << "Löschen der Elemente >5" << endl;

	//Löschen der Elemente >5
	itL = Liste.begin();
	while (itL != Liste.end())
	{
		if (*itL > 5)
		{
			Liste.erase(itL);
		}
		itL++;
	}
	
	cout << "Die Liste ohne Aktualisierung:" << endl;

	//Ausgabe der Liste ohne Aktualisierung
	itL = Liste.begin();
	while (itL != Liste.end())
	{
		cout << *itL << endl;
		itL++;
	}

	Liste.vAktualisieren();

	cout << endl << "Die Liste mit Aktualisierung:" << endl;

	//Ausgabe der Liste mit Aktualisierung
	itL = Liste.begin();
	while (itL != Liste.end())
	{
		cout << *itL << endl;
		itL++;
	}

}

void vAufgabe_7()
{
	Weg* WegHin = new Weg("Hin", 500);
	Weg* WegRueck = new Weg("Rueck", 500);

	PKW* PKW1 = new PKW("PKW1", 200, 5);
	PKW* PKW2 = new PKW("PKW2", 50, 5, 60);
	PKW* Leer = new PKW("Leer", 50, 20, 20);
	Fahrrad* Fahrrad1 = new Fahrrad("Fahrrad1", 30);

	WegHin->vAnnahme(PKW1, 0.7);
	WegHin->vAnnahme(Leer);
	WegHin->vAnnahme(Fahrrad1, 1.2);

	int Koordinaten[4] = { 700, 250, 100, 250 };

	//Zeichnen
	bInitialisiereGrafik(800, 500);

	bZeichneStrasse("Hin", "Rueck", 500, 2, Koordinaten);
	bZeichnePKW("PKW1", "Hin", epsilon, 0, 50);
	bZeichnePKW("Leer", "Hin", epsilon, 0, 50);
	bZeichneFahrrad("Fahrrad1", "Hin", epsilon, 20);

	while (dGlobaleZeit < 20)
	{
		vSetzeZeit(dGlobaleZeit);
		cout << "Nach " << dGlobaleZeit << "h" << endl;
		WegHin->vAbfertigung();

		if (fabs(dGlobaleZeit - 2) < gZeitschritt && dGlobaleZeit - 2 <= 0)
		{
			cout << "Parkendes Fahrzeug2 wird auf den Weg gesetzt" << endl;
			WegHin->vAnnahme(PKW2, 6.0);
		}

		cout << *WegHin << endl;

		dGlobaleZeit += gZeitschritt;
		//vSleep(500);

	}
}

void vAufgabe_8()
{
	bInitialisiereGrafik(1500, 1000);

	//Kreuzungen initialisieren
	Kreuzung* Kr1 = new Kreuzung("Kr1");
	bZeichneKreuzung(680, 40);
	Kreuzung* Kr2 = new Kreuzung("Kr2", 1000);
	bZeichneKreuzung(680, 300);
	Kreuzung* Kr3 = new Kreuzung("Kr3");
	bZeichneKreuzung(680, 570);
	Kreuzung* Kr4 = new Kreuzung("Kr4");
	bZeichneKreuzung(320, 300);

	//Kreuzungen verbinden und Strassen erstellen
	Kr1->vVerbinde("W12", "W21", 40, Kr2);
	Kr2->vVerbinde("W23a", "W32a", 115, Kr3, Autobahn, false);
	Kr2->vVerbinde("W23b", "W32b", 40, Kr3);
	Kr2->vVerbinde("W24", "W42", 55, Kr4);
	Kr3->vVerbinde("W34", "W43", 85, Kr4, Autobahn, false);
	Kr4->vVerbinde("W44a", "W44b", 130, Kr4, Landstraße, false);

	//Zeichnen
	int coord1[] = { 680, 40, 680, 300 };
	bZeichneStrasse("W12", "W21", 40, 2, coord1);
	int coord2[] = { 680, 300, 850, 300, 970, 390, 970, 500, 850, 570, 680, 570 };
	bZeichneStrasse("W23a", "W32a", 115, 6, coord2);
	int coord3[] = { 680, 300, 680, 570 };
	bZeichneStrasse("W23b", "W32b", 40, 2, coord3);
	int coord4[] = { 680, 300, 320, 300 };
	bZeichneStrasse("W24", "W42", 55, 2, coord4);
	int coord5[] = { 680, 570, 500, 570, 350, 510, 320, 420, 320, 300 };
	bZeichneStrasse("W34", "W43", 85, 5, coord5);
	int coord6[] = { 320, 300, 170, 300, 70, 250, 80, 90, 200, 60, 320, 150, 320, 300 };
	bZeichneStrasse("W44a", "W44b", 130, 7, coord6);

	PKW* PKW1 = new PKW("PKW1", 150, 10);
	PKW* PKW2 = new PKW("PKW2", 150, 3);
	PKW* PKW3 = new PKW("PKW3", 200, 8);
	PKW* PKW4 = new PKW("PKW4", 50, 7);

	Fahrrad* Fahrrad1 = new Fahrrad("Fahrrad1", 30);
	Fahrrad* Fahrrad2 = new Fahrrad("Fahrrad2", 15);

	Kr1->vAnnahme(PKW1, 0.05);
	Kr1->vAnnahme(PKW2, 0.05);
	Kr3->vAnnahme(PKW3, 0.1);
	Kr3->vAnnahme(PKW4, 0.1);
	Kr4->vAnnahme(Fahrrad1, 0.01);
	Kr4->vAnnahme(Fahrrad2, 0.01);

	while (dGlobaleZeit < 5)
	{
		vSetzeZeit(dGlobaleZeit);
		Kr1->vAbfertigung();
		Kr2->vAbfertigung();
		Kr3->vAbfertigung();
		Kr4->vAbfertigung();

		cout << *Kr1 << endl;
		cout << *Kr2 << endl;
		cout << *Kr3 << endl;
		cout << *Kr4 << endl;
		dGlobaleZeit += gZeitschritt;

		vSleep(5);
	}

	getchar();
	vBeendeGrafik();
}

int main()
{
	//vAufgabe_1();
	//vAufgabe_1_deb();
	//vAufgabe_2();
	//vAufgabe_3();
	//vAufgabe_4();
	//vAufgabe_5();
	//vAufgabe_6a();
	//vAufgabe_7();
	vAufgabe_8();

	return 0;
}

