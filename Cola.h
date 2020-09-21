#include "Nodo.h"

class Cola
{
	private:
		Nodo *frente;
		Nodo *final;
		int tamanio;
		int max;
		public:
			Cola(int tam)
			{
				this->max = tam;
				this->frente = NULL;
				this->final = NULL;
				this->tamanio = 0;
			}
			
			
		
			bool EstaVacia()
			{
				return (this->frente == NULL)?true:false;
			}
			
			
			void Insertar(string n, int e)
			{
				if(this->tamanio < this->max)
				{
					
					if(this->EstaVacia())
					{
						Nodo *nuevo = new Nodo(n, e);
						this->frente = nuevo;
						this->final = nuevo;
					}
					else
					{
						Nodo *nuevo = new Nodo(n, e);
						Nodo *aux = this->final;
						aux->siguiente = nuevo;
						this->final = nuevo;
					}
					this->tamanio++;
				}
				else
				{
					cout << "COLA LLENA" << endl;
				}
			}
			
			void Imprimir()
			{
				Nodo *aux = this->frente;
				while(aux != NULL)
				{
					cout << aux->RetornarNombre() << endl;
					aux = aux->siguiente;
				}
			}
			
			void EliminarFrente()
			{
				Nodo *aux = this->frente;
				this->frente = aux->siguiente;
				delete aux;
			}
			
			void EliminarFinal()
			{
				Nodo *aux = this->final;
				this->final = aux->siguiente;
				delete aux;
			}
			
			Nodo *BuscarPorValor(string nombre)
			{
				Nodo *aux = this->frente;
				while(aux != NULL)
				{
					if(aux->RetornarNombre() == nombre)
					{
						return aux;
					}
					aux = aux->siguiente;
				}
				return aux;
			}
			
			
			void EliminarPorValor(string ref)
			{
				Nodo *aux = this->BuscarPorValor(ref);
				if(aux == NULL)
				{
					cout << "Valor inexistente :( \n";
				}
				else
				{
					if(this->frente == this->final)
					{
						this->frente = NULL;
						this->final = NULL;
					}
					else
					{
						if(this->frente == aux)
						{
							this->EliminarFrente();
						}
						else if(this->final == aux)
						{
							this->EliminarFinal();
						}
						else
						{
							int posicion = this->ObtenerPosicion(aux);
							Nodo *anterior = this->ObtenerPorPosicion(posicion - 1);
							anterior->siguiente = aux->siguiente;
							delete aux->siguiente;
						}
					}
				}
			}
			
			
			
			Nodo *ObtenerPorPosicion(int pos)
			{
				int contador = 0;
				Nodo *aux = this->frente;
				while(aux != NULL)
				{
					if(contador == pos)
					{
						break;
					}
					aux = aux->siguiente;
					contador++;
				}
				return aux;
			}
			
			
			
			
			int ObtenerPosicion(Nodo *ref)
			{
				Nodo *aux = this->frente;
				int contador = 0;
				while(aux != NULL)
				{
					if(aux == ref)
					{
						return contador;
					}
					contador++;
					aux = aux->siguiente;
				}
				return -1;
			}
			
};
