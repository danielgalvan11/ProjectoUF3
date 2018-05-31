#include "Header.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

void clearSocios(Socio socio[])
{
    for(int i=0;i<SOCI;i++)
    {
        //todos los socios
        socio[i].codSoci=ERROR;
        strcpy(socio[i].nombre, "");
        socio[i].edad=ERROR;
        socio[i].quota=ERROR;
    }
}

void initialize(Socio socio[], Deporte depo[])
{
    
    clearSocios(socio);
    for(int i=0;i<ALLDEPO;i++)
    {
        //el array de deporte
        strcpy(depo[i].nombre, "");
        depo[i].horas=ERROR;
        //depo[i].precio=ERROR;
        
    }
    
    
    //cargo los deportes
    fstream myfile;
    string filename = DATASPORTS;
    int i = 0;
    char time;
    
    myfile.open(filename, ios::in);
    if (myfile.is_open())
    {
        do{
            
            myfile >> depo[i].nombre;
            
            
            myfile >> time;
            if(time=='T')
            {
                depo[i].morning=true;
            }else{
                depo[i].morning=false;
            }
            
            myfile >> depo[i].horas;
            
            i++;
        }while (!myfile.eof());
        
        myfile.close();
    }
    
}

bool atLeastOneSocio(Socio socio[])
{
    bool there=false;
    
    int i=0;
    if(socio[i].codSoci!=ERROR)
        there=true;
    
    if(!there)
    {
        space();
        cout << "No hay socios Matriculados, presione '1' para Matricular" << endl;
    }
    return there;
}

int encontrarCodigo(Socio socio[], int codigo)
{
    bool found=false;
    int i=ERROR;
    
    while (i<SOCI && found==false)
    {
        i++;
        if(codigo==socio[i].codSoci)
        {
            found=true;
        }
    }
    if(!found)
    {
        i = ERROR;
    }
    
    return i;
}

int posDeportes(int numSocio, Socio socio[])
{
    int posDeporte=ERROR;
    bool thisone = false;
    //+ERROR
    while(posDeporte<DEPO+ERROR && !thisone)
    {
        posDeporte++;
        //si  hay uni que este vacio
        if((strcmp(socio[numSocio].deportes[posDeporte].nombre, "") == 0))
        {
            thisone=true;
        }
    }
    if(!thisone)
    {
        posDeporte=ERROR;
    }
    return posDeporte;
}

void altaSocio(Socio socio[], int& cont)
{
    
    if(cont>=SOCI){
        cout << "\nYa el club esta a petar, " << SOCI << " socios ya estan inscritos!";
    }else{
        cout << "\nIngrese el codigo de socio: ";
        int codio;
        codio = checkInt();
        
        int posCod=encontrarCodigo(socio, codio);
        
        if(posCod!=ERROR)
        {
            cout << "\nEste Socio ya esta registrado";
        }else{
            Socio so;
            
            
            //para juntar nombre y apellido jeje
            char nombre[NAM] = "";
            char apellido[NAM] = "";
            char fullname[NAM] = "";
            
            cout << "\nIngrese su nombre: ";
            cin >> nombre;
            
            cout << "\nSu Apellido: ";
            
            cin >> apellido;
            strcpy(fullname, nombre);
            strcat(fullname, " ");
            strcat(fullname, apellido);
            //fin
            
            
            so.codSoci=codio;
            
            strcpy(so.nombre, fullname);
            
            cout << "\nSu Edad: ";
            so.edad=checkInt();
            
            cout << "\nSu Quota: ";
            so.quota=checkDouble();
            
            //inicializo su array de deportes
            for(int f = 0;f<DEPO;f++)
            {
                strcpy(so.deportes[f].nombre, "");
                so.deportes[f].horas=ERROR;
                
            }
            
            //guardo el socio en el espacio disponible
            socio[findSpace(socio)]=so;
            cont++;
            
            space();
            cout << endl << "Se ha Inscrito el socio con Codigo: " << so.codSoci;
            
            
        }
    }
}

int findSpace(Socio socio[])
{
    int i = 0;
    while(socio[i].codSoci!=ERROR && i<SOCI){
        //recorro el array hasta encontrar un espacio vacio
        i++;
    };
    return i;
}

int menu()
{
    int cho;
    cout << endl << "Club Esportiu Politècnics\n";
    
    cout <<"    1. Alta Socio\n";
    cout <<"    2. Matricular Socio en un Deporte\n";
    cout <<"    3. Mostrar Socios\n";
    cout <<"    4. Mostrar Deportes de un Socio\n";
    cout <<"    5. Baja Socio\n";
    cout <<"    6. Baja de un deporte Socio\n";
    cout <<"    7. LOAD Datos del fichero\n";
    cout <<"    8. SAVE Datos del fichero\n";
    cout <<"    9. Generar fichero de Socios por Edad\n";
    cout <<"    10.Socios dados de baja al Deporte\n";
    cout <<"    0. Salir\n";
    
    cout << endl << endl << "Opcion: ";
    
    cho = checkInt();
    space();
    return cho;
}

void space()
{
    cout<<"\n\n\n\n";
}

int checkInt()
{
    int input=ERROR;
    bool valid= false;
    do
    {
        
        cin >> input;
        
        if (cin.good())
        {
            //todo salio bien, continuamos el programa
            valid = true;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            if(input<0)
                cout << "El numero tiene que ser positivo: ";
        }
        else
        {
            //algo salio mal, reseteamos el state del buffer a 'ok'
            cin.clear();
            //lo vaciamos
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "\nError, ingrese un numero: ";
        }
        
    } while (!valid || input<0);
    
    return (input);
}

float checkDouble()
{
    double input=ERROR;
    bool valid= false;
    do
    {
        cin >> input;
        if (cin.good())
        {
            //todo salio bien, continuamos el programa
            valid = true;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            if(input<0)
                cout << "El numero tiene que ser positivo: ";
        }
        else
        {
            //algo salio mal, reseteamos el state del buffer a 'ok'
            cin.clear();
            //lo vaciamos
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "\nError, ingrese un numero: ";
        }
    } while (!valid || input<0);
    
    return (input);
}

void matricularToDeporte(Socio socio[], Deporte sports[])
{
    int codigo=ERROR;
    int posSocio=ERROR;
    int decision=ERROR;
    int numDeportes=ERROR;
    int posDeporte=ERROR;
    
    
    if(atLeastOneSocio(socio))
    {
        do{
            
            cout << "\nIngrese Codigo de Socio: ";
            codigo=checkInt();
            
            posSocio = encontrarCodigo(socio, codigo);
            if(posSocio==ERROR){cout << endl << "\nTry Again: " << endl;}
        }while(posSocio==ERROR);
        
        posDeporte=posDeportes(posSocio, socio);
        
        if(posDeporte==ERROR)
        {
            cout << endl << "Ya este socio tiene " << DEPO << " Deportes registrados";
        }else{
            space();
            
            numDeportes=mostrarTodoDeportes(sports);
            
            if(numDeportes!=0)
            {
                do{
                    cout << endl << "Seleccione cual desea añadir: ";
                    decision=checkInt();
                }while(decision<=0 || decision>numDeportes);
                
                //las opciones son del 1 al 9
                //pero el array de 0 a 8, por ende le aplico un patch
                decision--;
                
                bool already=false;
                
                for (int i = 0; i<DEPO; i++)
                {
                    if(strcmp(socio[posSocio].deportes[i].nombre, sports[decision].nombre)==0)
                    {
                        if(socio[posSocio].deportes[i].morning == sports[decision].morning)
                        {
                            already=true;
                            cout << endl << "El Socio ya esta matriculado en este Deporte"<< endl;
                        }
                    }
                }
                if(!already)
                {
                    //le añado la casilla de deportes al usuario
                    socio[posSocio].deportes[posDeporte]=sports[decision];
                    //double cuota= sports[decision].precio;
                    
                    //actualizo la cuota el usuario
                    //sumarQuota(socio, posSocio, cuota);
                    cout << endl << "Se ha Matriculado el Socio '"<< socio[posSocio].nombre
                    << "' en el Deporte '" << sports[decision].nombre << "' ";
                }
            }
        }
    }
}

int mostrarTodoDeportes(Deporte depo[])
{
    int numDeportes=0;
    cout << "Estos son los Deportes disponibles: " << endl;
    for(int i = 0;i<ALLDEPO;i++)
    {
        if(!(strcmp(depo[i].nombre, "") == 0))
        {
            cout << endl << i+1 << ".- " << depo[i].nombre;
            //cout << " " << depo[i].horas;
            //cout << " " << depo[i].morning;
            //cout << " " << depo[i].precio;
            numDeportes++;
        }
        
        
    }
    if(numDeportes==0)
    {
        cout << endl << "No hay ningun deporte";
    }
    return numDeportes;
}

void mostrarSocios(Socio socis[], int& contSocios)
{
    
    if(atLeastOneSocio(socis))
    {
        for(int i = 0; i<contSocios; i++)
        {
            mostrarUnSocio(socis, i);
        }
        
        cout << endl << "Un total de '" << contSocios << "' inscrito(s)" << endl;
    }
}

int printDeportesUser(Socio socis[],int posSocio)
{
    int contDep=0;
    //int pos = encontrarCodigo(socis, code);
    for (int j=0; j<DEPO; j++)
    {
        if(strcmp(socis[posSocio].deportes[j].nombre, ""))
        {
            
            cout << endl << j+1 << "  Nombre: "
            << socis[posSocio].deportes[j].nombre << endl;
            
            cout << "   Horas: " << socis[posSocio].deportes[j].horas << endl;
            if(socis[posSocio].deportes[j].morning)
            {
                cout << "   Horario de Mañanas" << endl;
            }else{
                cout << "   Horario de Tardes" << endl;
            }
            //cout << "   Precio: " << socis[pos].deportes[j].precio << endl;
            
            contDep++;
        }
        
    }
    if(contDep==0)
    {
        cout << "    No esta inscrito en ningun deporte" << endl << endl;
    }
    return contDep;
}

void mostrarDeporteUnSocio(Socio socio[])
{
    int pos=ERROR;
    int code = ERROR;
    if(atLeastOneSocio(socio))
    {
        
        cout << "Ingrese el codigo del Socio: " << endl;
        //verificar que exista el usuario
        code = checkInt();
        pos = encontrarCodigo(socio, code);
        if (pos == ERROR)
        {
            cout << endl << "\nNo existe el Socio" << endl;
            space();
            
        }else{
            space();
            cout << "Deporte(s) de " << socio[pos].nombre << ": "<< endl;
            printDeportesUser(socio, pos);
            
        }
    }
}

void bajaSocio(Socio socio[], int& contador)
{
    char ele;
    int codigo=ERROR;
    int posSocio=ERROR;
    int numDeportes=ERROR;
    
    
    if(atLeastOneSocio(socio))
    {
        
        //get poscontDep = printDeportesUser(socis, pos);
        //ask for int of soci wtf
        
        cout << "\nIngrese Codigo de Socio: ";
        codigo=checkInt();
        
        posSocio = encontrarCodigo(socio, codigo);
        if(posSocio==ERROR)
        {
            cout << "Error";
        }else{
            
            numDeportes = mostrarUnSocio(socio,posSocio);
            
            if(numDeportes!=0)
            {
                
                do{
                    space();
                    cout << endl << "¿Seguro que quieres dar de baja a "
                    << socio[posSocio].nombre <<"? (S/N):" << endl;
                    cin >> ele;
                }while (ele!='s' && ele!='S' && ele!='N' && ele!='n');
                space();
                if(ele=='n'||ele=='N')
                {
                    cout<< endl << "No se realizo nada...";
                    space();
                }else{
                    
                    
                    ofstream deleting (DELSOCIFILE, ofstream::out | ofstream::app);
                    int posDep=0;
                    if(deleting.is_open())
                    {
                        //los guardo en el fichero de borrados
                        
                        deleting << socio[posSocio].codSoci << " ";
                        deleting << socio[posSocio].nombre << " ";
                        deleting << socio[posSocio].edad << endl;
                        //deleting << " " << socio[posSocio].quota << endl;
                        for (posDep = 0; posDep<numDeportes; posDep++)
                        {
                            salvaBajaDeporte(socio,posSocio , posDep);
                            
                        }deleting.close();
                    }
                    
                    destroyUser(socio,posSocio, contador);
                    
                    cout << "Un Socio menos :(" << endl;
                }
            }
        }
    }
}

int  mostrarUnSocio(Socio socis[], int pos)
{
    int numDeportes=0;
    if(!(strcmp(socis[pos].nombre, "") == 0))
    {
        cout << endl;
        cout << "Codigo: "<< socis[pos].codSoci <<endl;
        cout << "Nombre: "<< socis[pos].nombre <<endl;
        cout << "Edad: "<<socis[pos].edad <<endl;
        //cout << "Quota: "<<socis[pos].quota <<endl;
        cout << "Deportes: " << endl;
        
        
        numDeportes=printDeportesUser(socis, pos);
        
    }
    return numDeportes;
}

void destroyUser(Socio socio[], int pos, int& contador)
{
    /*
     Los borro solo cuando es individual
     //borro todos sus deportes
     for(int f = 0;f<DEPO;f++)
     {
     destroy_Deporte(socio, pos, 0);
     }
     */
    
    
    
    //desplazo el array de socios
    if(contador<SOCI)
    {
        //desplazo todos los socios para que siempre me quden las primeras pos llenas
        for (int actual=pos; actual<contador; actual++)
        {
            socio[actual]=socio[actual+1];
        }
    }
    
    //fusilo la socio de ultimo en la lista
    socio[contador].codSoci=ERROR;
    strcpy(socio[contador].nombre, "");
    socio[contador].edad=ERROR;
    socio[contador].quota=ERROR;
    
    
    contador--;
    
    
}

void destroyDeporte(Socio socio[], int posSoci, int posDepo)
{
    if(posDepo<DEPO+ERROR)
    {
        for(int depoActual = posDepo; depoActual<DEPO+ERROR; depoActual++)
        {
            socio[posSoci].deportes[depoActual]=socio[posSoci].deportes[depoActual+1];
        }
    }
    
    
    strcpy(socio[posSoci].deportes[DEPO+ERROR].nombre, "");
    socio[posSoci].deportes[DEPO+ERROR].horas=ERROR;
    //bool?
    
}

void GUARDARFICHERO(Socio socio[], int& contador)
{
    string filename = DATSOCIOS;
    fstream fichero;
    
    
    if (contador == 0)
    {
        cout << "No hay datos para guardar...";
    }else{
        Socio existentes[SOCI];
        
        for (int i = 0; i < contador; i++)
        {
            //confio en mi contador
            existentes[i]=socio[i];
            
        }
        
        /*
        //leo el contador de Socios....
        fichero.open(COUNTFILE, ios::out|ios::trunc);
        if (fichero.is_open())
        {
            fichero << contador;
            fichero.close();
        }
        */
        
        
        //guardo la cantidad de socios en un fichero
        
        //-------
        
        //cambio el nombre del fichero respectivamente..
        lastVersion(filename,false);
        
        fichero.open(filename, ios::out | ios::binary);
        if(!fichero.is_open())
        {
            cout << "error";
        }else{
            for (int i = 0; i<contador; i++) {
                fichero.write((const char*)&existentes[i], sizeof(Socio));
            }
            
            cout << "Se han guardado los datos" << endl;
            
            
            fichero.close();
        }
    }
    
}

void LEERFICHERO(Socio socis[],int& mainCont)
{
    string filename = DATSOCIOS;
    fstream fichero;
    
    /*
    string s;
    
    int numSocis = 0;
    
    // N∫ elements que volem llegir
    fichero.open(COUNTFILE, ios::in);
    if (fichero.is_open())
    {//si existe leo el numero de socios en el txt
        while(!fichero.eof())
        {
            getline(fichero, s);
        }
        
        //si encuentra un numero en el fichero
        if (s.compare("") != 0)
        {
            numSocis=stoi(s);
        }
        fichero.close();
        
        if(numSocis>0 && ifstream(DATSOCIOS))// si el txt me indica que hay socios
        {
            
            mainCont=numSocis;
            
            for (int i = 0; i<numSocis; i++)
            {
                destroyUser(socis, 0, mainCont);
            }*/
            
            clearSocios(socis);
            
            //ya tengo la cantidad de socios en el .dat
            lastVersion(filename,true);
            
            
            Socio spawning[SOCI];
            fichero.open(filename, ios::in | ios::binary);
            int i =0;
            if (fichero.is_open())
            {
                
                do
                {
                    fichero.read((char *)&spawning[i], sizeof(Socio));
                    
                    if(spawning[i].codSoci!=0){
                    socis[i]=spawning[i];
                    i++;
                    }
                } while (!fichero.eof());
                fichero.close();
                
            }
    
    if (i<=0) {
        cout << "NADA";
    }else{
    
    cout << "Socios leidos" << i;
        mainCont=i;
    }
                /*
                fichero.read((char *)&spawning, sizeof(spawning));
                for (int pos = 0; pos < numSocis; pos++)
                {
                    socis[pos]=spawning[pos];
                }
                fichero.close();
                cout << "Se han cargado los datos" << endl;
                
                mainCont=numSocis;
                 
            }
            
        }else{
            cout << "El fichero no tiene usuarios guardados..." << endl;
        }
    }else{
        cout << "No hay Datos que cargar..." << endl;
        space();
    }
    */
}

void bajaDeporte(Socio socio[])
{
    int codigo=ERROR;
    int posSocio=ERROR;
    int numDeporte=ERROR;
    int posBorrar=ERROR;
    
    if(atLeastOneSocio(socio))
    {
        do{
            cout << "\nIngrese el Codigo de Socio: ";
            codigo=checkInt();
            
            posSocio = encontrarCodigo(socio, codigo);
            if(posSocio==ERROR){cout << endl << "\nTry Again: " << endl;}
        }while(posSocio==ERROR);
        
        
        
        numDeporte = printDeportesUser(socio, posSocio);
        char ele;
        //double precio;
        //si hay deportes pregunto
        if(numDeporte!=0)
        {
            
            cout << "Que deporte quiere dar de baja: ";
            posBorrar = checkInt();
            if(posBorrar>0 &&  posBorrar<=numDeporte)
            {
                posBorrar+=ERROR;
                
                do{
                    space();
                    cout << endl << "¿Seguro que quieres dar de baja en este Deporte? (S/N):" << endl;
                    cin >> ele;
                }while (ele!='s' && ele!='S' && ele!='N' && ele!='n');
                space();
                
                if(ele=='n'||ele=='N')
                {
                    cout<< endl << "Nothing happened...";
                    space();
                }else{
                    //obtengo el precio del deporte
                    //precio = socio[posSocio].deportes[posBorrar].precio;
                    
                    //restarQuota(socio, posSocio, socio[posSocio].deportes[posBorrar].precio);
                    
                    salvaBajaDeporte(socio,posSocio,posBorrar);
                    destroyDeporte(socio, posSocio, posBorrar);
                    
                    cout << "Se ha borrado el deporte";
                }
                
                
            }else{
                cout << endl << endl << "Wrong Awnser, no se ha borrado nada";
                space();
            }
        }
    }
}

void lastVersion(string &file, bool read)
{
    int ver=0;
    if(!read)
    {
        if (ifstream(file))
        {
            file=file.substr(0, file.length() - 4);
            ver++;
            file=file + "(" + to_string(ver) + ").dat";
            
            while(ifstream(file))
            {
                file=file.substr(0, file.length() - 7);
                ver++;
                file=file + "(" + to_string(ver) + ").dat";
            }
        }
    }else if(read){
        if(ifstream(file))
        {
            //si existe el archivo original, puebo el siguiente
            file=file.substr(0, file.length()-4);
            ver++;
            file=file + "(" + to_string(ver) + ").dat";
            //si existe (1)
            if(ifstream(file))
            {
                file=file.substr(0, file.length() - 7);
                ver++;
                file=file + "(" + to_string(ver) + ").dat";
                
                //pruebo con (2)
                while(ifstream(file))
                {
                    file=file.substr(0, file.length() - 7);
                    ver++;
                    file=file + "(" + to_string(ver) + ").dat";
                }
                //cuando no encuentre un numero (num)..
                //le indico que lea el ultimo que econtro
                file=file.substr(0, file.length() - 7);
                ver--;
                file=file + "(" + to_string(ver) + ").dat";
            }else{
                //cargo el original si no hay (1)..
                file=file.substr(0, file.length() - 7);
                file=file + ".dat";
            }
            
        }
    }
}

void leerBajasDeportes(Socio socios[])
{
    
    fstream myfile;
    string input;
    string deporte;
    string getter;
    bool found = false;
    
    cout << "¿Que deporte estas buscando?"<<endl << endl;
    cin >> input;
    
    space();
    cout << "Pues..." << endl << endl;
    myfile.open(DELDEPOFILE, ios::in);
    if (myfile.is_open())
    {
        while (!myfile.eof())
        {
            //obtengo el nombre del deporte
            myfile >> deporte;
            
            
            //si el nombre del deporte es igual al indicado por el usuario
            if(deporte.compare(input)==0)
            {
                myfile >> getter;
                cout << getter << " ";
                myfile >> getter;
                cout << getter << endl;
                
                found = true;
            }else{
                //simplemente paso de largo el nombre de esa baja
                myfile >> getter;
                myfile >> getter;
            }
            
        }
        myfile.close();
    }
    
    if(!found)
        cout << "Uy.. no se ha encontrado nada";
    /*
     int words = 3;
     string arr[words];
     
     
     
     fstream myfile;
     string lineaDoing;
     int posLineaALeer = 0;
     int contLineas = 0;
     
     char nombre[SOCI];
     string input="";
     
     
     cout << "¿Que deporte estas buscando?"<<endl;
     cin >> nombre;
     
     myfile.open(DELDEPOFILE, ios::in);
     if (myfile.is_open())
     {
     while (!myfile.eof())
     {
     //obtengo la primera palabra de cada linea(deporte)
     getline(myfile, lineaDoing);
     
     
     input = getFirst(lineaDoing);
     
     //cout << input << endl;
     
     if(input=="")
     {
     //no hay lienas pongo el cont a 0
     contLineas--;
     }else if(strcasecmp(nombre,input.c_str())==0){
     
     
     posLineaALeer=contLineas;
     }
     contLineas++;
     }
     myfile.close();
     }
     
     if(contLineas==0)
     cout << "No hay deportes que leer";
     else if(posLineaALeer>0)
     {
     myfile.open(DELDEPOFILE, ios::in);
     if(myfile.is_open())
     {
     int i = ERROR;
     myfile.seekg(0, ios::beg);
     while (!myfile.eof() && i<posLineaALeer)
     {
     i++;
     getline(myfile, lineaDoing);
     
     }
     
     stringstream sin(lineaDoing);
     
     string temp;
     vector<string> Socios;
     while(getline(sin, temp, ' '))
     Socios.push_back(temp);
     
     //for(auto& itr : Socios)
     //cout << itr << endl;
     
     cout << "Los Socios dados de baja en '" <<  nombre << "':" << endl;
     for (int i = 1; i<=(Socios.size()-1); i+=2)
     {
     cout << endl << Socios[i] << " " <<(Socios[i+1]) << endl;
     }
     
     myfile.close();
     
     } else {
     cout << "Error";
     }
     
     }else{
     space();
     cout << "No se ha encontrado nada";
     }*/
}

void salvaBajaDeporte(Socio socio[] ,int posSocio,int  posBorrar)
{
    
    //Otra manera de Guardar la baja deporte txt
    //deporte---socio
    
    fstream myfile;
    string lineaDoing;
    
    
    myfile.open(DELDEPOFILE, ios::out | ios::app);
    
    if (myfile.is_open())
    {
        //si esta vacio no agrego un salto de linea
        if (!(myfile.tellg() == 0)) {
            myfile << endl;
        }
        
        myfile << socio[posSocio].deportes[posBorrar].nombre;
        myfile << " " << socio[posSocio].nombre;
        
        myfile.close();
    }
    
    
    
    /*
     //------deporte por linea
     fstream myfile;
     string lineaDoing;
     int posLineaAmodificar = 0;
     int contLineas = 0;
     
     bool found_depo = false;
     
     myfile.open(DELDEPOFILE, ios::in);
     if (myfile.is_open())
     {
     while (!myfile.eof())
     {
     
     
     //obtengo la primera palabra de cada linea(deporte)
     getline(myfile, lineaDoing);
     
     
     string input = getFirst(lineaDoing);
     
     //cout << input << endl;
     
     if(input=="")
     {
     //no hay lienas pongo el cont a 0
     contLineas--;
     }else if(strcmp(socio[posSocio].deportes[posBorrar].nombre,input.c_str())==0){
     found_depo=true;
     posLineaAmodificar=contLineas;
     }
     contLineas++;
     
     }
     myfile.close();
     
     }
     
     if(found_depo)
     {
     
     //posLineaAmodificar es en la linea donde esta
     myfile.open(DELDEPOFILE, ios::in|ios::out);
     string lineas="";
     char temp[contLineas][SOCI*3];
     if (myfile.is_open())
     {
     for (int cont=0; cont<contLineas; cont++)
     {
     getline(myfile, lineas);
     //lo salvo al temp
     strcpy(temp[cont],lineas.c_str());
     }
     
     strcat(temp[posLineaAmodificar], " ");
     strcat(temp[posLineaAmodificar], socio[posSocio].nombre);
     
     
     
     myfile.close();
     }else{
     cout << "Error abriendo archivo";
     }
     
     
     myfile.open(DELDEPOFILE, ios::out);
     if(myfile.is_open())
     {
     
     
     for (int i = 0; i<contLineas; i++)
     {
     myfile << temp[i] << endl;
     
     }myfile.close();
     }else{
     cout << "Error abriendo archivo";
     }
     
     
     }else{//si es un deporte nuevo
     myfile.open(DELDEPOFILE, ios::out | ios::app);
     
     if (myfile.is_open())
     {
     
     myfile << socio[posSocio].deportes[posBorrar].nombre;
     myfile << " " << socio[posSocio].nombre << endl;
     
     myfile.close();
     }else{
     cout << "Error abriendo archivo";
     }
     }
     */
}

string getFirst(string linea)
{
    long strpos = linea.find(" ");
    return linea.substr(0, strpos);;
    
}

void sumarQuota(Socio socio[], int posSocio,double cuota)
{
    socio[posSocio].quota+=cuota;
}
void restarQuota(Socio socio[], int posSocio, double cuota)
{
    socio[posSocio].quota-=cuota;
}

void edadesDeportes(Socio socis[])
{
    
}

