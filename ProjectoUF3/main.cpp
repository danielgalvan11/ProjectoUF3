#include "Header.h"
#include <iostream>

using namespace std;
        //std::cout

int main(int argc, const char * argv[])
{
    int contSocios=0;
    
    Socio socis[SOCI];
    Deporte allDeportes[ALLDEPO];
    
    initialize(socis,allDeportes);
    
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
                matricularToDeporte(socis,allDeportes);
                    break;
                case 3:
                    mostrarSocios(socis, contSocios);
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
                    LEERFICHERO(socis, contSocios);
                    break;
                case 8:
                    GUARDARFICHERO(socis, contSocios);
                    break;
                case 9:
                    edadesDeportes(socis);
                    break;
                case 10:
                    leerBajasDeportes(socis);
                    break;
                case 0:
                    break;
                    
                default:
                    cout<<"\nOpcion incorrecta, Ingrese un numero del 1 al 10";
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

