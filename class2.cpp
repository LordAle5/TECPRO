#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
#include "funciones.h"
/*
 * 
 */
int main(int argc, char** argv) {
    
    double promedio;
    int menor,mayor,cantNotas;
    
    procesarNotas(promedio,cantNotas,mayor,menor);
    imprimirReporte( promedio,  cantNotas, mayor,  menor);
    
    
    return 0;
}



#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void procesarNotas(double &promedio, int &cantNotas, int &mayor, int &menor){
    int nota,suma=0;
    cout<<"Ingrese las notas: "<<endl;
    cantNotas=0;
    while(true){
        cin>>nota;
        if(nota<0) break;
        cantNotas++;
        suma+=nota;
        if(cantNotas==1){
            mayor=menor=nota;
        }
        else{
            if(nota>mayor){
                mayor=nota;
            }
            if(nota<menor){
                menor=nota;
            }
        }
        
    }
    promedio=(double)suma/cantNotas;    
}

void imprimirReporte(double promedio, int cantNotas,int mayor, int menor){
    cout<<setw(50)<<"ESTADSITICA DE NOTAS"<<endl;
    cout<<"El promedio de notas: "<<setw(5)<<promedio<<endl;
    cout<<"La nota mayor: "<<setw(5)<<mayor<<endl;
    cout<<"La nota menor: "<<setw(5)<<menor<<endl;
}


#ifndef FUNCIONES_H
#define FUNCIONES_H

void procesarNotas(double &promedio, int &cantNotas, int &mayor, int &menor);
void imprimirReporte(double promedio, int cantNotas,int mayor, int menor);


#endif /* FUNCIONES_H */
