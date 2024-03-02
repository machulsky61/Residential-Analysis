#ifndef SOLUCION_AUXILIARES_H
#define SOLUCION_AUXILIARES_H

#include "definiciones.h"

//Devuelve el indice del ultimo elemento de v menor o igual a e, -1 si no hay.
template<typename T>
int indiceMenorigual(T e, vector<T>& v){
    int i = 0;
    int j = v.size() - 1;
    while (i <= j){
        int k = (i + j) / 2;
        if (v[k] <=  e){
            i = k + 1;
        } else {
            j = k - 1;
        }
    }
    return i - 1;
}

//Devuelve el indice del ultimo par de v con primer elemento menor o igual a e, -1 si no hay.
int indiceMenorigual(int e, vector<pair<int, int>>& v);

//Devuelve el indice del ultimo subvector cuyo primer elemento es menor o igual a e, -1 si no hay.
int indiceMenorigual(int e, vector<vector<int>>& v);

template<typename T>
void insertarOrdenado(T e, vector<T>& v){
    v.insert(v.begin() + indiceMenorigual(e, v) + 1, e);
}

void ordenarSegun(int e, vector<vector<int>>& v);

void ordenarSegunSegundo(vector<pair<int, int>>& v);

float distanciaEuclideana(pair<int, int> centro, int latitud, int longitud);

bool cumpleBusqueda(individuo i, vector<pair<int, dato>> busqueda);

//Devuelve true si y solo si hay un elemento en v igual a e
bool perteneceBinario(int e, vector<int> v);

//Devuelve true si y solo si hay un subvector en v con primer valor igual a e
bool perteneceBinario(int e, vector<vector<int>> v);

vector<pair<int, int>> ingresosPorHogar(eph_i& ti);

//Devuelve los cota elementos de la k-esima columna de m
vector<int> columna(vector<vector<int>> m, int k, int cota);

#endif //SOLUCION_AUXILIARES_H