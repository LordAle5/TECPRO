#include <iostream>
#include <iomanip>
using namespace std;
#include <cmath>
#include "FuncionesAuxiliares.h"

//#define EXACTITUD 0.000001

int main(int argc, char** argv) {
    double c5, c4, c3, c2, c1, c0;
    double limiteInferior, limiteSuperior;
    double h, x1, x2, y1, y2;
    int numIntervalos=0, i;
    double area = 0.0, areaAnterior, longitud = 0.0, longitudAnterior;
    bool fin = false;
    double diferenciaAreas, diferenciaLongitudes;
    double exactitud;
    cout.precision(7);
    cout<<fixed;
    
    cout<<"Ingrese los coeficientes c5, c4, c3, c2, c1 y c0: ";
    cin >> c5>> c4 >> c3 >> c2 >> c1 >> c0;
    
    cout<<endl<<"Ingrese los limites inferior y superior: ";
    cin >> limiteInferior >> limiteSuperior;
    
    cout<<endl<<"Ingrese la exactitud: ";
    cin >> exactitud;
    
    
    cout<<endl<<left<<setw(18)<<"Intervalos"<<setw(20)<<"Area"
            <<setw(20)<<"Longitud"<<endl;

    while(not fin){
        areaAnterior = area;
        longitudAnterior = longitud;
        area = longitud = 0.0;
        numIntervalos++;
        h = (limiteSuperior - limiteInferior) / numIntervalos;

        x1 = limiteInferior;
        
        for(i = 1; i<=numIntervalos; i++){
            x2 = x1 + h;
            y1 = evaluaLaFuncion(x1, c5, c4, c3, c2, c1, c0);
            y2 = evaluaLaFuncion(x2, c5, c4, c3, c2, c1, c0);
            area += (y1 + y2)*h/2;
            longitud += sqrt( potencia(y2-y1,2) + potencia(h,2) );
            x1 = x2;
        }
        cout<<right<<setw(7)<<numIntervalos<<setw(20)<<area
                <<setw(20)<<longitud<<endl;
        diferenciaAreas = fabs(area-areaAnterior);
        diferenciaLongitudes = fabs(longitud-longitudAnterior);
        fin =  diferenciaAreas <= exactitud or 
               diferenciaLongitudes <= exactitud;
    }

    cout<<endl;
    cout<<left<<setw(25)<<"Area bajo la curva ="<<right<<setw(10)<<area<<endl;
    cout<<left<<setw(25)<<"Longitud de la curva ="<<right<<setw(10)<<longitud<<endl;
    

    return 0;
}

#include "FuncionesAuxiliares.h"

double evaluaLaFuncion(double x, double c5, double c4, double c3, double c2, 
                      double c1, double c0){
    double resultado;
    resultado = c5*potencia(x,5) + c4*potencia(x,4) + c3*potencia(x,3) + 
                c2*potencia(x,2) + c1*potencia(x,1) + c0*potencia(x,0);
    return resultado;
}

double potencia(double x, int n){
    double pot=1;
    for(int i=0; i<n; i++){
        pot *=(x);
    }
    return pot;
}

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

double evaluaLaFuncion(double, double, double, double, double, double, double);
double potencia(double, int);

#endif /* FUNCIONESAUXILIARES_H */
