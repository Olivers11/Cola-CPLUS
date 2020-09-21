#include <iostream>
#include <string>
using namespace std;
	

class Nodo
{
	private:
		int edad;
		string nombre;
		public:
			Nodo *siguiente;
			Nodo(string n, int e)
			{
				this->nombre = n;
				this->edad = e;
				this->siguiente = NULL;
			}
			
			string RetornarNombre()
			{
				return this->nombre;
			}
			
			int RetornarEdad()
			{
				return this->edad;
			}
};

