#include "Header.h"
#include <iostream>

using namespace std;
        //std::cout

int main(int argc, const char * argv[])
{
    int contSocios=0;
    int contActi=0;
    int contS=1;
    
    Socio socis[SOCI];
    Deporte allDeportes[ALLDEPO];
    Actividad actividades[ACTI];
    Socio deBaja[BAJA];
    
    hellofriend(socis,allDeportes,actividades);
    
    int resp=-1;
    do
    {
        try
        {
            resp=menu();
            switch (resp)
            {
                case 1:
                    altaSocio(socis, contSocios);
                    break;
                case 2:
                matriculartoDeporte(socis,allDeportes);
                    break;
                case 3:
                    mostrarallSocios(socis, contSocios);
                    break;
                case 4:
                    mostrarDeporteUnSocio(socis);
                    break;
                case 5:
                    bajaSocio(socis, contSocios);
                    break;
                case 6:
                    bajaDeporte(socis);
                    break;
                case 7:
                    readSaveState(socis, contSocios);
                    break;
                case 8:
                    saveCurrentState(socis, contSocios);
                    break;
                case 9:
                    edadesDeportes(socis);
                    break;
                case 10:
                    leerBajasDeportes(socis);
                    break;
                case 11:
                    crearActividad(actividades,contActi);
                    break;
                case 12:
                    asociarActi(socis, actividades, contActi);
                    break;
                case 13:
                    guardarFileDepo(allDeportes);
                    break;
                case 14:
                    cargarSociosBaja(deBaja);
                    mostrarallSocios(deBaja,contS);
                    break;
                case 15:
                    
                    break;
                    
                case 0:
                    
                    break;
                    
                default:
                    cout<<"\nOpción incorrecta, Ingrese un numero del 1 al 15";
                    break;
            }
        }catch(exception ex){
            cout<<ex.what();
        }
        space();
    }while(resp!=0);
    
    
    //instead of System_Pause
    return 0;
}



/*
 fstream myfile;
 char c; string s;
 int count = 0;
 
 // << Caracter a caracter >>
 myfile.open("carAcar.txt", ios::in);
 if (myfile.is_open()) {
 while (!myfile.eof()) { // Fins final de fitxer
 c = myfile.get();
 cout << c;
 count++;
 }
 cout << endl << "---> S'han fet -" << count << "- iteracions dins del bucle" << endl << endl;
 myfile.close();
 }
 
 // << Línia a línia >>
 count = 0;
 myfile.open("carAcar.txt", ios::in);
 if (myfile.is_open()) {
 while (!myfile.eof()) {
 getline(myfile, s);
 cout << s; // <<-- fixeu-vos què passa
 count++;
 }
 cout << endl << "---> S'han fet -" << count << "- iteracions dins del bucle" << endl << endl;
 myfile.close();
 }
 
 // << Llegint info i guardant-la a diferents tipus de dades >>
 int col; char fila;
 count = 0;
 myfile.open("coordinatesLetter.txt", ios::in);
 if (myfile.is_open()) {
 while (!myfile.eof()) {
 myfile >> fila;
 myfile >> col;
 cout << endl << "Disparo a la casella " << fila << col;
 count++;
 }
 cout << endl << "---> S'han fet -" << count << "- iteracions dins del bucle" << endl << endl;
 my
 */

