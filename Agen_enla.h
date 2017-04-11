/**
Declaración de la clase Árbol General.
*/

#ifndef AGEN_H
#define AGEN_H
#include <cassert>

template <typename T>
class Agen {
	struct celda;   // declaración adelantada privada
public:
	typedef celda* nodo;
	static const nodo NODO_NULO;
	Agen();
	// constructor
	void insertarRaiz(const T& e);
	void insertarHijoIzqdo(nodo n, const T& e);
	void insertarHermDrcho(nodo n, const T& e);
	void eliminarHijoIzqdo(nodo n);
	void eliminarHermDrcho(nodo n);
	void eliminarRaiz();
	bool arbolVacio() const;
	const T& elemento(nodo n) const;
	// acceso a elto, lectura
	T& elemento(nodo n);
	// acceso a elto, lectura/escritura
	nodo raiz() const;
	nodo padre(nodo n) const;
	nodo hijoIzqdo(nodo n) const;
	nodo hermDrcho(nodo n) const;
	Agen(const Agen<T>& a);
	// ctor. de copia
	Agen<T>& operator =(const Agen<T>& a);
	// asignación de árboles
	~Agen();
private:
	struct celda {
		T elto;
		nodo padre, hizq, heder;
		celda(const T& e, nodo p = NODO_NULO): elto(e),
		padre(p), hizq(NODO_NULO), heder(NODO_NULO) {}
	};
	nodo r;   // nodo raíz del árbol
	void destruirNodos(nodo& n);
	nodo copiar(nodo n);
};

/* Definición del nodo nulo */
template <typename T>
const typename Agen<T>::nodo Agen<T>::NODO_NULO(0);