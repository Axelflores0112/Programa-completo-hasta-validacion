#pragma once
#include<iostream>
#include<sstream>
using namespace std;

class Fecha {
private:
	string digitofecha="";
public:
	Fecha(string);
	void validarfecha();
	operator const char* () 
	{
	return digitofecha.c_str();
	}
};
Fecha::Fecha(string _digitofecha) {
	digitofecha = _digitofecha;

};





void Fecha::validarfecha() {
	int D_fecha, A, M, D;
		cout << "Ingrese la fecha: " << endl;
		cin >> digitofecha;
		istringstream(digitofecha) >> D_fecha;
		A = D_fecha / 10000;
		M = (D_fecha / 100) % 100;
		D = D_fecha % 100;
		cout << "Su fecha es: " << A << "/" << M << "/" << D << endl;
		if (A != 0 && (M == 1 || M == 3 || M == 5 || M == 7 || M == 8 || M == 10 || M == 12) && (D >= 1 && D <= 31)) {
			cout << "Fecha Correcta" << endl;
		}
		else {
			if (A != 0 && (M == 4 || M == 6 || M == 9 || M == 11) && (D >= 1 && D <= 30)) {
				cout << "Fecha Correcta" << endl;
			}
			else {
				if (A != 0 && (M == 2) && (D >= 1 && D <= 28)) {
					cout << "Fecha Correcta" << endl;
				}
				else {
					cout << "Fecha Incorrecta" << endl;
				}
			}
		}
		cout << "La fecha incrementada es: "<<endl;
		D++;
		
		ostringstream formatteddate;
		formatteddate << A << "/" << M << "/" << D;
		digitofecha = formatteddate.str();
}
