// PointerArrays.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include<iostream>
#include <iomanip>
#include<string>
#include<fstream>
#include"Data.h"
using namespace std;
const unsigned MAX = 400;
typedef unsigned Natural;
struct  Preinscripcion {
	Natural codi;
	unsigned Data;
};

struct School
{
	string name;
	Preinscripcion vec[MAX];
	unsigned size;
};
string nameFile() {
	//pre:cert
	//post:return name given by user
	cout << "> FITXER PREINSCRIPCIONS:" << endl;
	cout << endl;
	string name;
	cin >> name;
	return name;
}
Preinscripcion read_pre(ifstream &in_file) {
	//pre:--
	//post:--
	Preinscripcion pre;
	in_file>> pre.codi >> pre.Data;
	return pre;
}
bool isLess(Preinscripcion pre_a, Preinscripcion pre_b,unsigned opcio) {
	bool menor = false;
	Data dataA;
	Data dataB;
	dataB.llegir(pre_b.Data);
	dataA.llegir(pre_a.Data);
	if (opcio == 1) {
		menor = dataA.esMenor(dataB);
		if (dataA.esIgual(dataB))
		{
			menor = pre_a.codi < pre_b.codi;
		}
	}
	else {

	}
	return menor;
}
void SortedIncert(School *escola,Preinscripcion pre,unsigned opcio) {
	Preinscripcion * v = escola->vec;
	Preinscripcion *i = escola->vec + escola->size;
	while ( i>v && isLess(pre, *(i - 1),opcio)) {
		*i= *(i-1);
		i--;
	}
	*i = pre;
	escola->size++;
}
void read_file(ifstream &in_file,School *A,School *B) {
	unsigned opcio = 1;
	Preinscripcion pre = read_pre(in_file);
	while (!in_file.eof()) {
		if (pre.codi % 2 == 0) {
			SortedIncert(A, pre, opcio);
		}
		else {
			SortedIncert(B, pre, opcio);
		}
	pre = read_pre(in_file);
	}
}

void load_preinscriptions(School *A, School *B,bool &is_open) {	string name;     name = nameFile();	ifstream in_file(name.c_str());
	is_open = in_file.is_open();
	if (in_file.is_open()) {
		read_file(in_file, A, B);
	}
	else {
		cout << " Fitxer inexistent!" << endl;
	}}void computeMedian(School *X,unsigned counter) {	Data data;	if (X->size % 2 == 0) {		Preinscripcion *p = X->vec;		cout << " " << setw(4) << setfill('0') << (p + (X->size / 2)-1)->codi << " ";		data.llegir((p + (X->size / 2)-1)->Data);		data.mostrar(1);		cout << " " << setw(4) << setfill('0') << (p + (((X->size) / 2)))->codi << " ";		data.llegir((p + (((X->size) / 2)))->Data);		data.mostrar(1);			}	else {		Preinscripcion *p = X->vec;		cout <<" "<< setw(4) << setfill('0') << (p+((X->size)/2))->codi << " ";		data.llegir((p+ ((X->size) / 2))->Data);		data.mostrar(1);			}}void List(School *X) {	Preinscripcion * v=NULL;	Preinscripcion * s = X->vec + X->size;	unsigned counter = 1;	cout << " LLISTAT ESCOLA " << X->name << ":" << endl;	if (X->size != 0) {		for (v = X->vec; v < s; v++) {			Data data;			data.llegir(v->Data);			cout << setw(4) << setfill(' ') << counter << " " << setw(4) << setfill('0') << v->codi << " ";			data.mostrar(1);			counter++;		}		cout << endl;		cout << " MEDIANA ESCOLA " << X->name << ":" << endl;		computeMedian(X, counter - 1);		cout << endl;	}	else {		cout << " Conjunt buit!" << endl;		cout << endl;		cout << " MEDIANA ESCOLA " << X->name << ":" << endl;		cout << " No existeix!" << endl;		cout << endl;	}}
void merge(School *A,School *B,School *C) {
	unsigned opcio = 1;
	Preinscripcion *i = A->vec;
	Preinscripcion *s_i = A->vec + A->size;
	Preinscripcion *j = B->vec;
	Preinscripcion *s_j =B->vec + B->size;
	Preinscripcion *k =C->vec ;
	while ( i<s_i && j<s_j) {
		if (isLess(*i, *j, opcio)) {
			*(k + C->size) = *i;
			i++;
		}
		else {
			*(k + C->size) = *j;
		j++;
		}
		C->size++;
	}
	while (i<s_i)
	{
		*(k+C->size)= *i;
		i++;
		C->size++;
	}

	while (j<s_j)
	{
		*(k + C->size) = *j;
		j++;
		C->size++;
	}
}
int main()
{
	School A, B, C;
	A.size = 0;
	A.name = "A";
	B.size = 0;
	B.name = "B";
	C.size = 0;
	C.name = "C";
	bool is_open = false;
	load_preinscriptions(&A, &B,is_open);
	if (is_open) {
		List(&A);
		List(&B);
		merge(&A, &B, &C);
		List(&C);
	}
    return 0;
}

