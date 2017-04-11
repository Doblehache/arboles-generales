#include "Agen_enla.h"
#include "agen_E-S.h"

//Búsqueda de un elemento
template <typename T>
typename Agen<T>::nodo buscarRec(const T& e, typename Agen<T>::nodo n, const Agen<T>& A) {
    typename Agen<T>::nodo res = Agen<T>::NODO_NULO;
    if (n != Agen<T>::NODO_NULO) {
        if (A.elemento(n) == e)
            return n;
        n = A.hijoIzqdo(n);
        while (n != Agen<T>::NODO_NULO && res == Agen<T>::NODO_NULO) {
            res = buscarRec(e, n, A);
            n = A.hermDrcho(n);
        }
    }
    return res;
}

//Cálculo del grado de un árbol general
template <typename T>
int gradoAgen(const Agen<T> A) {
    if (A.arbolVacio())
        return 0;
    else
        return gradoAgenRec(A.raiz(), A);
}

template <typename T>
int gradoAgenRec(typename Agen<T>::nodo n, const Agen<T>& A) {
    int gradoMax = 0;
    int gradoNodo = 0;
    n = A.hijoIzqdo(n);

    while (n != Agen<T>::NODO_NULO) {
        gradoNodo++;
        gradoMax = std::max(gradoMax, gradoAgenRec(n, A));
        n = A.hermDrcho(n);
    }
    return std::max(gradoMax, gradoNodo);
}

//Cálculo de la profundidad de un nodo en un árbol general
template <typename T>
int profundidadRec(typename Agen<T>::nodo n, const Agen<T>& A) {
    int p = -1;

    while (n != Agen<T>::NODO_NULO) {
        p++;
        n = A.padre(n);
    }
    return p;
}

























//
