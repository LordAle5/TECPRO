#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    int num1=1256,num2=98,num3=122434;
  
    cout.width(10);
    cout<<num2<<endl;
    cout.width(10);
    cout<<num3<<endl;
    //espacio de justificacion
    cout.width(10);
    cout<<num1<<endl;
    
    cout<<setw(10)<<num1<<endl<<setw(10)<<num2<<endl<<setw(10)<<num3<<endl;
    
    //alineacion a la izquierda
    cout<<left<<setw(10)<<num1<<endl<<setw(10)<<num2<<endl;
    cout<<left<<setw(10)<<num1<<setw(10)<<num2<<endl;
    
    //alineacion a la derecha
    cout<<right<<setw(10)<<num1<<endl<<setw(10)<<num2<<endl;
    cout<<right<<setw(10)<<num1<<setw(10)<<num2<<endl;
    
    //cambiar base. solo se puede en hex y oct 
    cout<<hex<<setw(10)<<num1<<setw(10)<<num2<<endl;
    
    //cambiar letras a mayusculas
    cout<<uppercase<<setw(10)<<num1<<setw(10)<<num2<<endl;
    //devolver a base
    cout<<dec;
    return 0;
}

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    int dia,mes,anio,num1=1256;
    dia=1;
    mes=1;
    anio=2024;
    
    cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
    cout<<right<<setw(2)<<dia<<"/"<<setw(2)<<mes<<"/"<<anio<<endl;
    cout.fill('0');
    //a partir de esta linea todo se llena con cero
    cout<<right<<setw(2)<<dia<<"/"<<setw(2)<<mes<<"/"<<anio<<endl;
    cout<<setw(10)<<num1<<endl;
    cout.fill(' ');
    cout<<right<<setw(2)<<dia<<"/"<<setw(2)<<mes<<"/"<<anio<<endl;
    //solo para esa linea
    cout<<setfill('0')<<setw(2)<<dia<<"/"<<setw(2)<<mes<<"/"<<anio<<endl;
    
    return 0;
}

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    double real1=12.5667,real2=123.6,real3=2424234.4;
    cout<<real1<<endl<<real2<<endl<<real3<<endl;
    cout<<setw(15)<<real1<<endl<<setw(15)<<real2<<endl<<setw(15)<<real3<<endl;
    cout<<"Precision 5"<<endl;
    cout.precision(5);
    cout<<fixed<<setw(15)<<real1<<endl<<setw(15)<<real2<<endl<<setw(15)<<real3
            <<endl;
    cout<<setprecision(5)<<fixed<<setw(15)<<real1<<endl<<setw(15)<<real2<<endl
            <<setw(15)<<real3<<endl;
    return 0;
}

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    cout<<"REPORTE DE ALUMNOS"<<endl;
    cout<<setw(65)<<"REPORTE DE ALUMNOS"<<endl<<endl;
    cout<<setw(20)<<"CODIGO"<<setw(38)<<"NOMBRE"<<setw(45)<<"MONTO A PAGAR"<<endl;
    cout<<setw(21)<<"20233429"<<setw(39)<<"Alejandro"<<setw(41)<<"10 soles"<<endl;
    return 0;
}
