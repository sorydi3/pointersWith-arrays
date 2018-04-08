// PointerArrays.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
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
	cout << "INPUT THE NAME OF THE FILE" << endl;
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
	if (opcio == 1) {
		menor = pre_a.codi < pre_b.codi;
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

void load_preinscriptions(School *A, School *B) {	string name;     name = nameFile();	ifstream in_file(name.c_str());
	if (in_file.is_open()) {
		read_file(in_file, A, B);
	}
	else {
		cout << "UNABLE TO OPEN THE GIVEN FILE" << endl;
	}}void List(School *A) {	Preinscripcion * v=NULL;	Preinscripcion * s = A->vec + A->size;	unsigned countador = 1;	for (v = A->vec; v < s; v++) {		Data data;		data.llegir(v->Data);		cout << countador<< "  " << setw(4) << setfill('0') <<v->codi<< " ";		data.mostrar(1);		cout << endl;		countador++;			}}
int main()
{
	School A, B, C;
	A.size = 0;
	B.size = 0;
	C.size = 0;
	load_preinscriptions(&A, &B);
	List(&A);
	cout << "size of A : " << A.size << endl;
	cout << "---------------------------------" << endl;
	List(&B);
	cout <<"size of B : "<< B.size << endl;
    return 0;
}

