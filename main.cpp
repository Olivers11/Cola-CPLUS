#include <iostream>
#include <string>
using namespace std;
#include "Cola.h"

int main()
{
	Cola a = Cola(5);
	int opcion;
	do
	{
		system("cls");
		cout << "[1] Ingresar " << endl;
		cout << "[2] Ver" << endl;
		cout << "[3] Eliminar" << endl;
		cout << "[4] Eliminar por valor \n";
		cout << "[5] Buscar por Valor \n"; 
		cout << "[6] Salir" << endl;
		cout << "    ingrese opcion \n";
		cin >> opcion;
		if(opcion == 1)
		{
			system("cls");
			string n;
			int e;
			cout << "Nombre: ";
			cin >> n;
			cout << "Edad: ";
			cin >> e;
			a.Insertar(n, e);
			system("pause");
		}
		else if(opcion == 2)
		{
			system("cls");
			cout << "Elementos: \n";
			a.Imprimir();
			system("pause");
		}
		else if(opcion == 3)
		{
			system("cls");
			cout << "Eliminando... \n";
			a.EliminarFrente();
			system("pause");
		}
		else if(opcion == 4)
		{
			system("cls");
			string ref;
			cout << "Nombre: ";
			cin >> ref;
			a.EliminarPorValor(ref);
			system("pause");
		}
		else if(opcion == 5)
		{
			system("cls");
			string n;
			cout << "Nombre: ";
			cin >> n;
			cout << "Es el: " << a.BuscarPorValor(n)->RetornarNombre() << endl;
			system("pause");
		}
	}while(opcion != 6);
}
