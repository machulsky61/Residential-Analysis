#include "definiciones.h"
#include "auxiliares.h"
#include "gtest/gtest.h"
#include "ejercicios.h"

int indiceMenorigual(int e, vector<pair<int, int>>& v){
    int i = 0;
    int j = v.size() - 1;
    while (i <= j){
        int k = (i + j) / 2;
        if (v[k].first <=  e){
            i = k + 1;
        } else {
            j = k - 1;
        }
    }
    return i - 1; 
}

int indiceMenorigual(int e, vector<vector<int>>& v){
    int i = 0;
    int j = v.size() - 1;
    while (i <= j){
        int k = (i + j) / 2;
        if (v[k][0] <=  e){
            i = k + 1;
        } else {
            j = k - 1;
        }
    }
    return i - 1;
}

//Ordena (insertion) un vector de vectores de acuerdo al valor del indice e de cada elemento.
void ordenarSegun(int e, vector<vector<int>>& v){
    for (int i=0; i < v.size(); i++){
        for (int j=i; j > 0 && v[j][e] < v[j-1][e]; j--){
            v[j].swap(v[j-1]);
        }
    }
}

//Ordena (insertion) un vector de vectores de acuerdo al valor del indice e de cada elemento.
void ordenarSegunSegundo(vector<pair<int, int>>& v){
    for (int i=0; i < v.size(); i++){
        for (int j=i; j > 0 && v[j].second < v[j-1].second; j--){
            v[j].swap(v[j-1]);
        }
    }
}

float distanciaEuclideana(pair<int, int> centro, int latitud, int longitud){
    return sqrt((centro.first - latitud)*(centro.first - latitud) + (centro.second - longitud)*(centro.second - longitud)); // Exponenciacion en C++ ???
}

bool cumpleBusqueda(individuo i, vector<pair<int,dato>> busqueda){
    for (pair<int,dato> b: busqueda){
        if (i[b.first] != b.second){
            return false;
        }
    }
    return true;
}

bool perteneceBinario(int e, vector<int> v){
    int indiceDeE = indiceMenorigual(e, v);
    if (indiceDeE < 0 || v[indiceDeE] != e){
        return false;
    }
    return true;
}

bool perteneceBinario(int e, vector<vector<int>> v){
    int indiceDeE = indiceMenorigual(e, v);
    if (indiceDeE < 0 || v[indiceDeE][0] != e){
        return false;
    }
    return true;
}

vector<pair<int, int>> ingresosPorHogar(eph_i& ti){
    vector<pair<int, int>> res;
    for (individuo i: ti){
        int indiceDei = indiceMenorigual(i[INDCODUSU], res);
        if (indiceDei < 0 || res[indiceDei].first != i[INDCODUSU]){
            res.insert(res.begin() + indiceDei + 1, make_pair(i[INDCODUSU], 0));
            indiceDei++; // Porque i se inserta en indiceDei + 1
        }
        if (i[p47T] > -1){
            res[indiceDei].second += i[p47T];
        }
    }
    return res;
}

vector<int> columna(vector<vector<int>> m, int k, int cota){
    vector<int> columna;
    for (int i=0; i < cota; i++){
        columna.push_back(m[i][k]);
    }
    return columna;
}