//#include "stdafx.h"
#include "Data.h"
#include<string>
#include <iomanip>
#include<iostream>
using namespace std;
//CONSTANS	DE	CLASSE	
const int Data::DIES_MES[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const string Data::NOM_MES[] = { "CAP", "GENER", "FEBRER", "MARC", "ABRIL", "MAIG",
"JUNY", "JULIOL", "AGOST", "SETEMBRE", "OCTUBRE", "NOVEMBRE", "DESEMBRE" };

//CONSTRUCTORS	
Data::Data() {
	//Pre:	--;	Post:	es	la	data	1/1/2001	
	d_dia = 1;
	d_mes = 1;
	d_any = 2001;
}

//CONSULTORS	
void Data::mostrar(int format) const {
	//Pre:	format	1	o	2;	Post:	mostra	la	data	actual	en	format	d/m/a	o	d–mes–a
	if (format == 1)
		cout << setw(2) << setfill('0') << d_dia << "/" <<setw(2)<<setfill('0')<< d_mes << "/" <<setw(4) << setfill('0')<< d_any << endl;
	else cout << d_dia << "-" << NOM_MES[d_mes] << "-" << d_any << endl;//	es	pot	usar	NOM_MES[mes]	i	no	un	condicional	múlZple	
}

bool Data::esMenor(Data d) const {
	//Pre:--;	
	//Post:	cert	si	d	és	una	data	posterior	a	l’actual,	fals	altrament
	bool menor = false;
	menor = d.getAny() > d_any;
	if (d.getAny() == d_any) {
		menor = d.getMes() > d_mes;
		if (d.getMes() == d_mes) {
			menor = d.getDia() > d_dia;
		}
	}
	return menor;
}

bool Data::esIgual(Data d) const {
	//Pre:--;	
	//Post:	cert	si	d	és	una	data	posterior	a	l’actual,	fals	altrament
	bool igual = false;
	bool menor = false;
	menor = d.getAny() > d_any;
	if (d.getAny() == d_any) {
		menor = d.getMes() > d_mes;
		if (d.getMes() == d_mes) {
			menor = d.getDia() > d_dia;
			if (d.getDia() == d_dia) {
				igual = true;
			}
		}
	}
	return igual;
}

//	MODIFICADORES	
void Data::llegir(int format) {
	//Pre:	format	1	o	2;	Post:	llegeix	dates	en	format	AAAAMMDD		o	d	m	a,	fins	a	llegir-ne	una	de	correcte
	int data;
	unsigned dia;
	unsigned mes;
	unsigned any;

	do { //	cal	declarar	les	variables	que	es	facin	servir	
		if (format == 1) {
			cin >> data;
			dia = data % 100;
			data /= 100;
			mes = data % 100;
			data /= 100;
			any = data;
		}  //	llegir	AAAAMMDD	i	separar-ho	en	any,	mes	i	dia	
		else {
			cin >> dia >> mes >> any;
		}
	} while (!esDataValida(dia, mes, any));
	//	es	guarda	dia,	mes	i	any	en	els	atributs
	d_dia = dia;
	d_mes = mes;
	d_any = any;

}

void Data::llegir(unsigned data) {
	unsigned dia;
	unsigned mes;
	unsigned any;
	do { //	cal	declarar	les	variables	que	es	facin	servir	
			dia = data % 100;
			data /= 100;
			mes = data % 100;
			data /= 100;
			any = data;
	} while (!esDataValida(dia, mes, any));
	//	es	guarda	dia,	mes	i	any	en	els	atributs
	d_dia = dia;
	d_mes = mes;
	d_any = any;

}
//	FUNCIONS	DE	CLASSE
bool Data::esDataValida(int dia, int mes, int any) {
	//Pre:	--;	Post:	cert	si	dia/mes/any	seria	una	data	vàlida,	fals	altrament
	bool correcte = true;
	bool esDeTraspas = (any % 4 == 0) && (any % 100 != 0 || any % 400 == 0);
	if (any>3999 || any<1600 || mes>12 || mes<1 || dia<1)
		correcte = false;
	else {
		int diesMes;
		if (esDeTraspas && mes == 2) diesMes = 29;
		else diesMes = DIES_MES[mes];

		if (dia > diesMes) correcte = false;
	}
	return correcte;
}

unsigned Data::getDia()const {
	return d_dia;
}
unsigned Data::getMes()const {
	return d_mes;
}
unsigned Data::getAny()const {
	return d_any;
}