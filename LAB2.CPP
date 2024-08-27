* Archivo:   main.cpp
 * Author: 20233429 Abdon Alejandro Vallejo Macha
 * Fecha y Hora: 26 de agosto de 2024, 07:09 PM
 * 
 *============================================================================
 * Programa para encontrar la raiz de una ecuacion empleando el método
 * de la Posicion falsa, ejercicio adaptado del libro de(Schneider et al.,1986)
 * ============================================================================
 */


#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

double calcularFx(double, double, double, double, double,double);
double calcularPotencia(double, int);
void solucionarProblema(double,double,double,double,double,double,double,
                           double,double,double);

#endif /* FUNCIONESAUXILIARES_H */


#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;
#include "FuncionesAuxiliares.h"

int main(int argc, char** argv) {
    double coeficiente4, coeficiente3, coeficiente2, coeficiente1, coeficiente0;
    double x1, x2;
    double epsilon;
    double funcion1, funcion2;
    bool darsePorVencido, datosBuenos;
    
    datosBuenos = false;
    darsePorVencido = false;
    
    while(not datosBuenos && not darsePorVencido){
        cout <<"Ingresar los dos puntos de inicio: "<<endl;
        cin>>x1>>x2;
        if((x1==0) and (x2==0)){
            darsePorVencido = true;
        }
        else{
            cout<<"Ingresar los coeficientes: c4 al c0"<<endl;
            cin>>coeficiente4>>coeficiente3>>coeficiente2>>coeficiente1>>coeficiente0;
            funcion1 = calcularFx(x1, coeficiente4, coeficiente3, coeficiente2,
                       coeficiente1, coeficiente0);
            funcion2 = calcularFx(x2, coeficiente4, coeficiente3, coeficiente2,
                       coeficiente1, coeficiente0);
            if((funcion1<= 0.0 and funcion2 >= 0.0) or
                (funcion1>= 0.0 and funcion2 <= 0.0)){
                datosBuenos = true;
            }
            else{
                cout<<"Lo siento, los puntos dados no estan opuestos"<<endl;
                cout<<"Ingresar 0,0 para terminar (puntos de inicios)"<<endl;
            } 
        }
    }
    if (darsePorVencido){
        cout<<"Lo siento, el programa se concluye por una falla"<<endl;
        cout<<"Para encontrar un intervalo inicial valido"<<endl;
    }
    else{
        solucionarProblema(epsilon, x1, x2,coeficiente4,coeficiente3,coeficiente2,
                         coeficiente1,coeficiente0,funcion1,funcion2);
    }
    return 0;
}

#include <iostream>
#include <cmath>
using namespace std;
#define CUENTA_MAXIMA 100

double calcularPotencia(double x,int n){
    double potencia = 1.0;
    int i;
    for(i=0; i < n; i++)
        potencia *= x;
    return potencia;
}

double calcularFx(double x, double coef4, double coef3, double coef2,
                  double coef1, double coef0){
    double fx;
    
    fx= coef4 * calcularPotencia(x,4) + coef3*calcularPotencia(x,3) +
        coef2*calcularPotencia(x,2) + coef1*x + coef0;
    return fx;
}

void solucionarProblema(double epsilon, double x1,double x2,double coef4,
        double coef3, double coef2, double coef1, double coef0, double funcion1,
        double funcion2){
    int cuenta;
    bool raizEncontrada;
    double x3, funcion3;
    
    cout<<"Ingresar la exactitud deseada: "<<endl;
    cin>>epsilon;
    raizEncontrada = false;
    cuenta=0;
    
    while(not raizEncontrada and (cuenta<=CUENTA_MAXIMA)){
        
        x3 = (x2*funcion1 - x1*funcion2)/(funcion1-funcion2);
        funcion3=calcularFx(x3,coef4,coef3,coef2,coef1,coef0);
        cout<<"cuenta= "<<cuenta<<" x1= "<<x1<<"  x3= "<<x3<<endl;
        if(fabs(funcion3)<epsilon)
            raizEncontrada = true;
        if(((funcion1 <= 0.0) and (funcion3 <= 0.0)) or 
                ((funcion1 >= 0.0) and (funcion3 >= 0.0))){
            x1=x3;
            funcion1=funcion3;
        }
        else{
            x2=x3;
            funcion2=funcion3;
        }
        cuenta +=1;
        if(fabs(funcion3)<epsilon)
            raizEncontrada = true;
    }
    
    if(raizEncontrada)
        cout<<"La raiz es "<< x3 <<", con una exactitud de"
                <<epsilon<<endl;
    else
        cout<<"Lo siento, no pudimos encontrar la raiz en "
                <<CUENTA_MAXIMA<< " iteraciones"<<endl;







