#include <stdio.h>
#include <stdlib.h>
#include<iostream>

struct nodoPila {
	int dato;
	struct nodoPila *ptrSiguiente;
};

using namespace std;

typedef struct nodoPila NodoPila;
typedef NodoPila *ptrNodoPila;

void apilar(ptrNodoPila *topeptr, int numero)
{
	ptrNuevo = malloc(sizeof(ptrNodoPila));
	ptrNodoPila ptrNuevo;

	if (ptrNuevo != NULL)
	{
		ptrNuevo->dato = numero;
		ptrNuevo->ptrSiguiente = *topeptr;
		ptrNuevo++;
		*topeptr = ptrNuevo;
	}
	else
	{
		cout << "Memoria insuficiente." << endl;
	}
}

int eliminar(ptrNodoPila *topeptr)
{
	ptrNodoPila ptrTemp;
	int valor;
	ptrTemp = *topeptr;
	valor = (*topeptr)->dato;
	*topeptr = (*topeptr)->ptrSiguiente;
	free(ptrTemp);
	topeptr--;

	return valor;
}

void mostrar(ptrNodoPila ptrActual)
{
	if (ptrActual == NULL)
	{
		cout << "---PILA VACIA---" << endl;

	}
	else
	{
		while (ptrActual != NULL)
		{
			cout << " " << ptrActual->ptrSiguiente;
		}
	}
}

void pil ()
{
	ptrNodoPila ptrPila = NULL;

	int op, numero, num, opa;
	do {

		cout << "\t-----OPCIONES-----" << endl;
		cout << "1. Insertar." << endl;
		cout << "2. Eliminar." << endl;
		cout << "3. Mostrar." << endl;
		cin >> op;

		switch (op)
		{

		case 1:

			system("cls");
			cout << "Introduzca un valor: " << endl;
			cin >> numero;
			apilar(&ptrPila, numero);
			mostrar(ptrPila);

			break;
		case 2:
			system("cls");
			eliminar(&ptrPila);
			break;
		}
		cout << "Desea regresar a las opciones. (SI/1)(NO/0)" << endl;
		cin >> num;
	} while (num != 0);
}

typedef struct {
	NodoCola *Frente, *Final;
}Cola;


void VaciarC(Cola* C), AnadeC(Cola* C, TipoElemento e), BorrarC(Cola* C);
TipoElemento PrimeroC(Cola C);
int EsvaciaC(Cola C);

void VaciaC(Cola* C) {
	C->Frente = NULL;
	C->Final = NULL;
}

int EsVaciaC(Cola C) {
	return (C.Frente == NULL);
}

void AnadeC(Cola* C, TipoElemento e) {
	NodoCola*a;
	a = (NodoCola*)malloc(sizeof(NodoCola));
	a->e = e;
	a->sif = NULL;
	if (EsVaciaC(*C))
		C->Frente = a;
	else
		C->Final->sig = a;
	C->Final = a;
}


void BorrarC(Cola* C) {
	NodoCola *a;
	if (!EsVaciaC(*C))
	{
		a = C->Frente;
		C->Frente = C->Frente->sig;
		if (C->Frente == NULL)
			C->Final = NULL;
		free(a);
	}
	else
	{
		puts("Error eliminacion de una cola Vacia");
		exit(-1);
	}
}

TipoElemento PrimeroC(Cola C) {
	if (EsVaciaC(C)) {
		puts("Error: Cola Vacia");
		exit(-1);
	}
	return (C.Frente->e);
}

void col() {
	int a;
	cout << "elija una opcion" << endl;
	cout << "1. vaciar cola" << endl;
	cout << "2. aniadir elementos" << endl;
	cout << "3.borrar elemento" << endl;

	switch (a) {
	case 1: 
		VaciaC(Cola* C);
		break;
	case 2:
		void AnadeC(Cola* C, TipoElemento e);
		break;
	case 3:
		void BorrarC(Cola* C);
		break;
	default:
		cout << "opcion invalida" << endl;
		break;
}

}



struct nodo {
	int nro;
	struct nodo *sgte;
};

typedef struct nodo *Tlista;

void insertarInicio(Tlista &lista, int valor)
{
	Tlista q;
	q = new(struct nodo);
	q->nro = valor;
	q->sgte = lista;
	lista = q;
}

void insertarFinal(Tlista &lista, int valor)
{
	Tlista t, q = new(struct nodo);

	q->nro = valor;
	q->sgte = NULL;

	if (lista == NULL)
	{
		lista = q;
	}
	else
	{
		t = lista;
		while (t->sgte != NULL)
		{
			t = t->sgte;
		}
		t->sgte = q;
	}
}

int insertarAntesDespues()
{
	int _op, band;
	cout << endl;
	cout << "\t 1. Antes de la posicion   " << endl;
	cout << "\t 2. Despues de la posicion " << endl;

	cout << "\n\t Opcion: "; cin >> _op;

	if (_op == 1)
		band = -1;
	else
		band = 0;

	return band;
}

void insertarElemento(Tlista &lista, int valor, int pos)
{
	Tlista q, t;
	int i;
	q = new(struct nodo);
	q->nro = valor;

	if (pos == 1)
	{
		q->sgte = lista;
		lista = q;
	}
	else
	{
		int x = insertarAntesDespues();
		t = lista;

		for (i = 1; t != NULL; i++)
		{
			if (i == pos + x)
			{
				q->sgte = t->sgte;
				t->sgte = q;
				return;
			}
			t = t->sgte;
		}
	}
	cout << "Error...Posicion no encontrada...!" << endl;
}

void buscarElemento(Tlista lista, int valor)
{
	Tlista q = lista;
	int i = 1, band = 0;

	while (q != NULL)
	{
		if (q->nro == valor)
		{
			cout << endl << "Encontrada en posicion " << i << endl;
			band = 1;
		}
		q = q->sgte;
		i++;
	}

	if (band == 0)
		cout << "\n\n Numero no encontrado...!" << endl;
}

void reportarLista(Tlista lista)
{
	int i = 0;

	while (lista != NULL)
	{
		cout << ' ' << i + 1 << ") " << lista->nro << endl;
		lista = lista->sgte;
		i++;
	}
}

void eliminarElemento(Tlista &lista, int valor)
{
	Tlista p, ant;
	p = lista;
	ant = NULL;

	if (lista != NULL)
	{
		while (p != NULL)
		{
			if (p->nro == valor)
			{
				if (p == lista)
					lista = lista->sgte;
				else ant->sgte = p->sgte;

				delete(p);
				return;
			}
			ant = p;
			p = p->sgte;
		}
	}
	else
		cout << " Lista vacia...!";
}

void eliminarRepetidos(Tlista &lista, int valor)
{
	Tlista q, ant;
	q = lista;
	ant = lista;

	while (q != NULL)
	{
		if (q->nro == valor)
		{
			if (q == lista)
			{
				lista = lista->sgte;
				delete(q);
				q = lista;
			}
			else
			{
				ant->sgte = q->sgte;
				delete(q);
				q = lista;
			}
		}
		else
		{
			ant = q;
			q = q->sgte;
		}
	}
	cout << "\n\n Valores eliminados..!" << endl;
}

void menu1()
{
	cout << "\n\t\tLISTA ENLAZADA SIMPRE\n\n";
	cout << " 1. INSERTAR AL INICIO					" << endl;
	cout << " 2. INSERTAR AL FINAL					" << endl;
	cout << " 3. INSERTAR EN UNA POSICION			" << endl;
	cout << " 4. REPORTAR LISTA						" << endl;
	cout << " 5. BUSCAR ELEMENTO					" << endl;
	cout << " 6. ELIMINAR ELEMENTO 'V'				" << endl;
	cout << " 7. ELIMINAR ELEMENTOS CON VALOR 'V'	" << endl;
	cout << " 8. SALIR								" << endl;
	cout << "\n INGRESE OPCION: ";
}


void lis_simple()
{
	Tlista lista = NULL;
	int op;
	int _dato;
	int pos;

	system("color 0b");

	do
	{
		menu1(); cin >> op;

		switch (op)
		{
		case 1:
			cout << "\n NUMERO A INSERTAR: "; cin >> _dato;
			insertarInicio(lista, _dato);
			break;

		case 2:
			cout << "\n NUMERO A INSERTAR: "; cin >> _dato;
			insertarFinal(lista, _dato);
			break;

		case 3:
			cout << "\n NUMERO A INSERTAR: "; cin >> _dato;
			insertarElemento(lista, _dato, pos);
			break;

		case 4:
			cout << "\n\n MOSTRANDO LISTA:\n\n"; cin >> _dato;
			reportarLista(lista);
			break;

		case 5:
			cout << "\n Valor a buscar: "; cin >> _dato;
			buscarElemento(lista, _dato);
			break;

		case 6:
			cout << "\n Valor a eliminar: "; cin >> _dato;
			eliminarElemento(lista, _dato);
			break;

		case 7:
			cout << "\n Valor repetido a eliminar: "; cin >> _dato;
			eliminarRepetidos(lista, _dato);
			break;
		}
		cout << endl << endl;
		system("pause");
		system("cls");
	} while (op != 8);
	system("pause");
	
}

typedef struct _nodo {
	int valor;
	struct _nodo *siguiente;
	struct _nodo *anterior;
} tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Lista;

/* Funciones con listas: */
void Insertar(Lista *l, int v);
void Borrar(Lista *l, int v);

void BorrarLista(Lista *);
void MostrarLista(Lista l, int orden);

void lis_doble() {
	Lista lista = NULL;
	pNodo p;

	Insertar(&lista, 20);
	Insertar(&lista, 10);
	Insertar(&lista, 40);
	Insertar(&lista, 30);

	MostrarLista(lista, ASCENDENTE);
	MostrarLista(lista, DESCENDENTE);

	Borrar(&lista, 10);
	Borrar(&lista, 15);
	Borrar(&lista, 45);
	Borrar(&lista, 30);

	MostrarLista(lista, ASCENDENTE);
	MostrarLista(lista, DESCENDENTE);

	BorrarLista(&lista);

	
}

void Insertar(Lista *lista, int v) {
	pNodo nuevo, actual;

	/* Crear un nodo nuevo */
	nuevo = (pNodo)malloc(sizeof(tipoNodo));
	nuevo->valor = v;

	/* Colocamos actual en la primera posición de la lista */
	actual = *lista;
	if (actual) while (actual->anterior) actual = actual->anterior;
	/* Si la lista está vacía o el primer miembro es mayor que el nuevo */
	if (!actual || actual->valor > v) {
		/* Añadimos la lista a continuación del nuevo nodo */
		nuevo->siguiente = actual;
		nuevo->anterior = NULL;
		if (actual) actual->anterior = nuevo;
		if (!*lista) *lista = nuevo;
	}
	else {
		/* Avanzamos hasta el último elemento o hasta que el siguiente tenga
		un valor mayor que v */
		while (actual->siguiente &&actual->siguiente->valor <= v)
			actual = actual->siguiente;
		/* Insertamos el nuevo nodo después del nodo anterior */
		nuevo->siguiente = actual->siguiente;
		actual->siguiente = nuevo;
		nuevo->anterior = actual;
		if (nuevo->siguiente) nuevo->siguiente->anterior = nuevo;
	}
}

void Borrar(Lista *lista, int v) {
	pNodo nodo;

	/* Buscar el nodo de valor v */
	nodo = *lista;
	while (nodo && nodo->valor < v) nodo = nodo->siguiente;
	while (nodo && nodo->valor > v) nodo = nodo->anterior;

	/* El valor v no está en la lista */
	if (!nodo || nodo->valor != v) return;

	/* Borrar el nodo */
	/* Si lista apunta al nodo que queremos borrar, apuntar a otro */
	if (nodo == *lista)
		if (nodo->anterior) *lista = nodo->anterior;
		else *lista = nodo->siguiente;

		if (nodo->anterior) /* no es el primer elemento */
			nodo->anterior->siguiente = nodo->siguiente;
		if (nodo->siguiente) /* no es el último nodo */
			nodo->siguiente->anterior = nodo->anterior;
		free(nodo);
}

void BorrarLista(Lista *lista) {
	pNodo nodo, actual;

	actual = *lista;
	while (actual->anterior) actual = actual->anterior;

	while (actual) {
		nodo = actual;
		actual = actual->siguiente;
		free(nodo);
	}
	*lista = NULL;
}

void MostrarLista(Lista lista, int orden) {
	pNodo nodo = lista;

	if (!lista) cout<<"Lista vacía"<<endl;

	nodo = lista;
	if (orden == ASCENDENTE) {
		while (nodo->anterior) nodo = nodo->anterior;
		cout<<"Orden ascendente: "<<endl;
		while (nodo) {
			cout<<" -> "<< nodo->valor<<endl
				;
			nodo = nodo->siguiente;
		}
	}
	else {
		while (nodo->siguiente) nodo = nodo->siguiente;
		cout << "Orden descendente: " << endl;
		while (nodo) {
			cout<<"-> "<<nodo->valor<<endl;
			nodo = nodo->anterior;
		}
	}

	
}

void lis_cir() {
	int a;
	cout << "elija una opcion:" << endl;
	cout << "insertar" << endl;
	cout << "2.borrar elemento" << endl;
	cout << "3.vaciar lista" << endl;
	cout << "4.mostrar" << endl;
	cin >> a;

	switch (a) {
	case 1:
		void Insertar(Lista *lista, int v);
		break;
	case 2:
		void Borrar(Lista *lista, int v);
		break;
	case 3:
			void BorrarLista(Lista *lista);
			break;
	case 4:
		void MostrarLista(Lista lista, int orden);
		break;
	default:
		cout << "opcion invalida" << endl;
	}


}




int main() {
	int a, b;


	do {
		cout << "elija una opcion:" << endl;
		cout << "1.pila" << endl;
		cout << "2.cola" << endl;
		cout << "3.lista simple" << endl;
		cout << "4.lista doble" << endl;
		cout << "5.lista circular" << endl;

		switch (a) {
		case 1:
			void pil();
			break;
		case 2:
			void col();
			break;
		case 3:
			void lis_simple();
			break;
		case 4:
			void lis_doble();
			break;
		case 5:
			void lis_cir();
			break;
		default:
			cout << "opcion invalida" << endl;
		}

		cout << "Ingrese 1 para volver a iniciar y 0 para salir" << endl;
		cin >> b;
	} while (b != 0);

	system("pause");

}