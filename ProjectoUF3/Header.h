#include <iostream>

#define NAM 20
#define SOCI 5
#define DEPO 5
#define ALLDEPO 30
#define ERROR -1

#define DATASPORTS "dadesEsports.txt"
#define DELDEPOFILE "bajasDeportes.txt"
#define DELSOCIFILE "baixaSocis.txt"
#define COUNTFILE "count.txt"
#define DATSOCIOS "infoSocis.dat"

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

//reset de los socios
void clearSocios(Socio socio[]);

//inicializa todos los datos
void initialize(Socio socio[], Deporte[]);

//devuelve la posicion del array del codigo dado, si no existe devuelve ERROR
int encontrarCodigo(Socio socio[], int codigo);

//realiza un alta del socio
void altaSocio(Socio socio[], int &contador);

//imprime opciones del menu
int menu();
//pide el numero del menu
void doMenu();
//realiza un espacio en consola
void space();
//encontrar espacio vacio
int findSpace(Socio socio[]);

//verificar si el int es correcto
int checkInt();
//verificar si el float es correcto
float checkDouble();
//matricula un deporte a un socio
void matricularToDeporte(Socio socio[], Deporte sports[]);
//verifica que posciciones de los deportes de un socio estan vacios
int posDeportes(int numSocio, Socio socio[]);
//muestra y cuenta los deporte a matricular
int mostrarTodoDeportes(Deporte depo[]);

//muestra los deportes de un socio
int printDeportesUser(Socio socis[],int pos);

//pide codigo de socio y muestra los deportes
void mostrarDeporteUnSocio(Socio soci[]);

//Revisa si hay socios
bool atLeastOneSocio(Socio socio[]);

//muestra todos los socios matriculados
void mostrarSocios(Socio soci[],int &cont);

//Da de baja a un socio, añadiendolo a bajas
void bajaSocio(Socio socio[], int &contador);

//muesta los datos de un socio
int mostrarUnSocio(Socio socis[], int pos);
//elimina un usuario de una posicion
void destroyUser(Socio socis[], int pos, int &contador);
//borro el deporte de la posicion dada
void destroyDeporte(Socio socio[], int posSoci, int posDepo);
//guarda los datos de los usuarios
void GUARDARFICHERO(Socio socis[],int &contador);
//carga los datos del programa
void LEERFICHERO(Socio socis[],int &contador);
//procesidimiento para dar de baja
void bajaDeporte(Socio socis[]);
//busca la ultima version del ficheto para cargar o guardar
void lastVersion(string &file, bool read);
//muesta los usuarios que se han dado de baja en un deporte
void leerBajasDeportes(Socio socios[]);
//actualiza el fihcero de baja de deporte
void salvaBajaDeporte(Socio socio[] ,int posSocio,int  posBorrar);

//obtine la primera columna de un txt
string getFirst(string linea);

void sumarQuota(Socio socio[], int posSocio,double cuotaDep);
void restarQuota(Socio socio[], int posSocio,double cuotaDep);

void edadesDeportes(Socio socis[]);
