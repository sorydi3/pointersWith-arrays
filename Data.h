#pragma once
#include<iostream>
#include<fstream>
using namespace std;
class Data
{
	//	Descripció:	guarda	el	dia,	mes	i	any	d’una	data	
	//	Invariant:	dia/mes/any	és	una	data	correcta
public:
	//	CONSTRUCTORS	
	Data(); //Pre:	--;	Post:	és	la	data	1/1/2001	
			//	CONSULTORS	
	void mostrar(int format) const;
	//Pre:	format	1	o	2;	Post:	mostra	la	data	actual	en	format	d/m/a	o	d–mes–a
	bool esMenor(Data d) const;
	//Pre:--;	Post:	cert	si	d	és	una	data	posterior	a	l’actual,	fals	altrament
	bool esIgual(Data d) const;
	//	MODIFICADORS	
	void llegir(int format);
	//Pre:	format	1	o	2;	Post:	llegeix	dates	en	format	AAAAMMDD		o	d	m	a,	fins	a	llegir-ne	una	de	correcte
	void llegir(unsigned data);
private:
	unsigned d_dia;
	unsigned d_mes;
	unsigned d_any;

	//	CONSTANTS	DE	CLASSE
	static const int DIES_MES[];
	static const string NOM_MES[];
	//	FUNCIO	DE	CLASSE
	static bool esDataValida(int dia, int mes, int any);
	//Pre:	cert;	Post:	retorna	cer	si	dia/mes/any	formen	una	data	vàlida	en	el	calendari	gregorià
	unsigned getDia() const;
	unsigned getMes() const;
	unsigned getAny() const;
};