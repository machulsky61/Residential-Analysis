#include <fstream>
#include <vector>
#include "ejercicios.h"
#include "Funciones_TPI.h"

using namespace std;

int main(){
	ofstream fout;
	fout.open("datos.csv");
	fout << "n\t" << "tiempo" << endl;

    vector<string> archivos = {"eph_3c_2018_100", "eph_3c_2020_100", "eph_3c_2018_1000", "eph_3c_2020_1000"};
    for (int i=0; i < archivos.size(); i++){
        eph_h th;
        eph_i ti;
        leerEncuesta(archivos[i], th, ti);
        double t0 = clock();
		laCasaEstaQuedandoChica(th, ti);
        double t1 = clock();
        double tiempo = (double(t1-t0)/CLOCKS_PER_SEC);
        fout << ti.size() << "\t" << tiempo << endl;
    }
    fout.close();
    return 0;
}