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
    return 0;
}
