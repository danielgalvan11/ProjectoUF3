#include <iostream>

#define NAM 20
#define SOCI 30
#define DEPO 5
#define ALLDEPO 30
#define ERROR -1

#define VEJEZ 100
#define YOUTH 16


#define DATASPORTS "dadesEsports.txt"
#define DELDEPO "bajasDeportes.txt"
#define DELSOCI "baixaSocis.txt"
#define DATSOCIOS "infoSocis.dat"
#define EDADSOCI "edadSports.txt"

using namespace std;
        //std::cout

struct Deporte
{
    char nombre[NAM];
    bool morning;
    double horas;
    //double precio;
};

struct Socio
{
    int codSoci=0;
    char nombre[NAM];
    int edad;
    double quota;
    Deporte deportes[DEPO];
};

//imprime opciones del menu
int menu();
//pide el numero del menu
void doMenu();
//realiza un espacio en consola
void space();

//inicializa todos los datos
void hellofriend(Socio socio[], Deporte[]);
//blanqueo de los socios
void clearSocios(Socio socio[]);

//realiza un alta del socio
void altaSocio(Socio socio[], int &contador);
//devuelve el siguiente espacio de socios y ERROR si no hay espacio
int findSpace(Socio socio[]);
//devuelve la posicion del array del codigo dado, si no existe devuelve ERROR
int encontrarCodigo(Socio socio[], int codigo);


//verificar si el int es correcto
int checkInt();
//verificar si el float es correcto
double checkDouble();

//matricula un deporte a un socio
void matriculartoDeporte(Socio socio[], Deporte sports[]);
//obtiene una posicion vacia de deporte de cierto usuario, ERROR si esta llena
int posDeportes(int numSocio, Socio socio[]);
//muestra y cuenta los deportes disponibles
int mostrarTodoDeportes(Deporte depo[]);

//muestra los deportes alta de un socio y devuelve el nº inscrito
int printDeportesUser(Socio socis[],int pos);
//pide codigo de socio y muestra los deportes
void mostrarDeporteUnSocio(Socio soci[]);

//Revisa si hay algun socio
bool atLeastOneSocio(Socio socio[]);

//muesta los datos de un socio, devuelve el numero de deportes
int mostrarUnSocio(Socio socis[], int pos);
//muestra todos los socios matriculados
void mostrarallSocios(Socio soci[],int &cont);

//Da de baja a un socio, añadiendolo a bajas
void bajaSocio(Socio socio[], int &contador);
//elimina un usuario de una posicion
void destroyUser(Socio socis[], int pos, int &contador);

//guarda los datos del programa en el fichero
void GUARDARFICHERO(Socio socis[],int &contador);
//carga los datos del programa en el fichero
void LEERFICHERO(Socio socis[],int &contador);
//busca la ultima version del fichero para cargar o guardar
void lastVersion(string &file, bool read);

//muesta los usuarios que se han dado de baja en un deporte
void leerBajasDeportes(Socio socios[]);
//procedimiento para dar de baja
void bajaDeporte(Socio socis[]);
//actualiza el fihcero de baja de deporte
void salvaBajaDeporte(Socio socio[] ,int posSocio,int  posBorrar);
//borro el deporte de la posicion dada
void destroyDeporte(Socio socio[], int posSoci, int posDepo);

//genera fichero por edades
void edadesDeportes(Socio socis[]);


//suma la quota (de un deporte) al socio
void sumarQuota(Socio socio[], int posSocio,double cuotaDep);
void restarQuota(Socio socio[], int posSocio,double cuotaDep);
