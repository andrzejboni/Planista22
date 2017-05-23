#include "stdafx.h"
#include <iostream>



using namespace std;

struct osoba {

	int wiek;
	osoba *nastepna;    // wskaźnik na następny element
	osoba();            // konstruktor
};

osoba::osoba() {
	nastepna = 0;       // konstruktor 
}


struct lista {
	osoba *pierwsza;  // wskaźnik na początek listy 
	void dodaj_osobe(int wiek);
	void usun_osobe(int nr);
	void wyswietl_liste();
	void zamien_liczby(int nr);
	void suma();
	lista(); // lista nie zwraca żadnych argumentów, przechowuje tylko dane. AB
};



lista::lista() {
	pierwsza = 0;       // konstruktor
}

void lista::wyswietl_liste()
{
	// wskaznik na pierszy element listy
	osoba *temp = pierwsza;

	// przewijamy wskazniki na nastepne elementy
	while (temp)
	{
		cout << temp->wiek << ' ';
		temp = temp->nastepna;
	}
	cout << endl;


}



void lista::usun_osobe(int nr)
{
	// jezeli to pierwszy element listy
	if (nr == 1)
	{
		osoba *temp = pierwsza;
		pierwsza = temp->nastepna; //poczatek listy, 1 el. wskazuje na 2 el. itd..
		delete temp;
	}


}

void lista::dodaj_osobe(int wiek)
{
	osoba *nowa = new osoba;    // tworzy nowy element listy

								// wypełniamy naszymi danymi

	nowa->wiek = wiek;
	nowa->nastepna = pierwsza;
	pierwsza = nowa;


}

void lista::zamien_liczby(int nr)
{
	if (nr == 1)
	{
		return;
	}
	osoba *wskaznik = pierwsza;    // wskaźnik na następny element
	osoba *druga = pierwsza->nastepna;
	//int nrpierwszej = pierwsza->wiek;

	for (int i = 1; i < nr; i++)
	{
		wskaznik = wskaznik->nastepna;
	}
	pierwsza->nastepna = wskaznik->nastepna;
	wskaznik->nastepna = pierwsza;
	pierwsza = druga;


}


void lista::suma()
{
	osoba *temp = pierwsza;
	temp = temp->nastepna;
	int liczba1, liczba2;
	liczba1 = pierwsza->wiek;
	usun_osobe(1);
	liczba2 = temp->wiek;
	usun_osobe(1);
	dodaj_osobe(liczba1 + liczba2);


}


int main()
{

	char wczytaj[100];
	int liczba = 0;
	bool czydodac = false;
	lista *baza = new lista;

	lista baza[3];


	while (cin.good())
	{

		cin >> wczytaj;

		if (wczytaj[0] != 'r')
		{
			if (czydodac == true)
			{
				baza->dodaj_osobe(liczba);
				czydodac = false;
			}

		}
		switch (wczytaj[0])
		{


		case 'x':
		{

			baza->usun_osobe(1);
			break;
		}
		case 'r':
		{
			baza->zamien_liczby(liczba);
			czydodac = false;
			break;
		}
		case 'p':
		{
			baza->wyswietl_liste();

			break;
		}


		case 'q':
		{
			exit(0);
			break;
		}
		case 's':
		{
			baza->zamien_liczby(2);
			break;
		}
		case '+':
		{
			baza->suma();
			break;
		}

		default:
		{
			liczba = atoi(wczytaj); // Konwersja liczby ze stringa na inta.
			czydodac = true;
			break;
		}
		}

	}





	return 0;

}
