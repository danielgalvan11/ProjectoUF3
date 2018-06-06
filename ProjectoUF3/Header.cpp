#include "Header.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
void clearSocios(Socio socio[])
{
    for (int i = 0; i<SOCI; i++)
    {
        //todos los socios
        socio[i].codSoci = ERROR;
        strcpy(socio[i].nombre, "");
        socio[i].edad = ERROR;
        socio[i].quota = ERROR;
        
    }
}

void hellofriend(Socio socio[], Deporte depo[], Actividad activ[])
{
    
    clearSocios(socio);
    for (int i = 0; i<ALLDEPO; i++)
    {
        //el array de deporte
        strcpy(depo[i].nombre, "");
        depo[i].horas = ERROR;
        //depo[i].precio=ERROR;
    }
    

    
    
    //cargo los deportes
    fstream myfile;
    int i = 0;
    char time;
    
    myfile.open(DATASPORTS, ios::in);
    if (myfile.is_open())
    {
        do {
            
            myfile >> depo[i].nombre;
            
            
            myfile >> time;
            if (time == 'T')
            {
                depo[i].morning = true;
            }
            else {
                depo[i].morning = false;
            }
            
            myfile >> depo[i].horas;
            
            i++;
        } while (!myfile.eof());
        
        myfile.close();
        
    }
    
    i=0;
    string s;
    string nombre="";
    myfile.open(FICHEACTI, ios::in);
    if(myfile.is_open())
    {
        
        while (!myfile.eof())
        {
            myfile >> s;
            
            
        }
        
        myfile.close();
    }else{
        cout << "Not found";
    }
    
    i/=3;
    
    myfile.open(FICHEACTI, ios::in);
    if(myfile.is_open())
    {
        

        for (int k=0; k<i; k++)
        {
            
            myfile >>  activ[k].nombre;
            
            
        }
        for (int k=0; k<i; k++)
        {
            myfile >> activ[k].sala;
            
        }for (int k=0; k<i; k++)
        {
            myfile >> activ[k].nivel;
            
        }
        
        myfile.close();
    }else{
        cout << "Not found";
    }
    
    
}
    

bool atLeastOneSocio(Socio socio[])
{
    bool there = false;
    
    if (socio[0].codSoci != ERROR)
        there = true;
    
    if (!there)
    {
        space();
        cout << "No hay socios Matriculados, presione '1' para Matricular" << endl;
    }
    return there;
}

int encontrarCodigo(Socio socio[], int codigo)
{
    bool found = false;
    int i = ERROR;
    
    while (i<SOCI && found == false)
    {
        i++;
        if (codigo == socio[i].codSoci)
        {
            found = true;
        }
    }
    if (!found)
    {
        i = ERROR;
    }
    
    return i;
}

int posDeportes(int numSocio, Socio socio[])
{
    int posDeporte = ERROR;
    bool thisone = false;
    //+ERROR
    while (posDeporte<DEPO - 1 && !thisone)
    {
        posDeporte++;
        //si  hay uni que este vacio
        if ((strcmp(socio[numSocio].deportes[posDeporte].nombre, "") == 0))
        {
            thisone = true;
        }
    }
    if (!thisone)
    {
        posDeporte = ERROR;
    }
    return posDeporte;
}

void altaSocio(Socio socio[], int& cont)
{
    
    if (cont >= SOCI) {
        cout << "\nYa el club esta a petar, " << SOCI << " socios ya estan inscritos!";
    }
    else {
        cout << "\nIngrese el codigo de socio: ";
        int codio;
        codio = checkInt();
        
        int posCod = encontrarCodigo(socio, codio);
        
        if (posCod != ERROR)
        {
            cout << "\nEste Socio ya esta registrado";
        }
        else {
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
            
            
            so.codSoci = codio;
            
            strcpy(so.nombre, fullname);
            
            cout << "\nSu Edad: ";
            so.edad = checkInt();
            
            cout << "\nSu Quota: ";
            so.quota = checkDouble();
            
            //inicializo su array de deportes
            for (int f = 0; f<DEPO; f++)
            {
                strcpy(so.deportes[f].nombre, "");
                so.deportes[f].horas = ERROR;
                
            }
            strcpy(so.inscrito.nombre, "");
            so.inscrito.sala = NULL;
            so.inscrito.nivel =ERROR;
            
            
            //guardo el socio en el espacio disponible
            socio[findSpace(socio)] = so;
            cont++;
            
            space();
            cout << endl << "Se ha Inscrito el socio con Codigo: " << so.codSoci;
            
            
        }
    }
}

int findSpace(Socio socio[])
{
    int i = 0;
    while (socio[i].codSoci != ERROR && i<SOCI) {
        //recorro el array hasta encontrar un espacio vacio
        i++;
    };
    return i;
}

int menu()
{
    int cho;
    cout << endl << "Club Esportiu Politécnics\n";
    
    cout << "    1. Alta Socio\n";
    cout << "    2. Matricular Socio en un Deporte\n";
    cout << "    3. Mostrar Socios\n";
    cout << "    4. Mostrar Deportes de un Socio\n";
    cout << "    5. Baja Socio\n";
    cout << "    6. Baja de un deporte Socio\n";
    cout << "    7. LOAD Datos del fichero\n";
    cout << "    8. SAVE Datos del fichero\n";
    cout << "    9. Generar fichero de Socios por Edad\n";
    cout << "    10.Socios dados de baja al Deporte\n";
    cout << "    11.Crear actividad Dirigida\n";
    cout << "    12.Vincular Socio con Actividad\n";
    cout << "    13.Guardar fichero de Deportes\n";
    cout << "    14.Cargar Socios de baja\n";
    cout << "    15.(Calcular y guardar estadisticas)\n";
    cout << "    0. Salir\n";
    
    cout << endl << endl << "Opcion: ";
    
    cho = checkInt();
    space();
    return cho;
}

void space()
{
    cout << "\n\n\n\n";
}

int checkInt()
{
    int input = ERROR;
    bool valid = false;
    do
    {
        
        cin >> input;
        
        if (cin.good())
        {
            //todo salio bien, continuamos el programa
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (input<0)
                cout << "El numero tiene que ser positivo: ";
            else
                valid = true;
        }
        else
        {
            //algo salio mal, reseteamos el state del buffer a 'ok'
            cin.clear();
            //lo vaciamos
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nError, ingrese un numero: ";
        }
        
    } while (!valid || input<0);
    
    return (input);
}

double checkDouble()
{
    double input = ERROR;
    bool valid = false;
    do
    {
        cin >> input;
        if (cin.good())
        {
            //todo salio bien, continuamos el programa
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (input<0)
                cout << "El numero tiene que ser positivo: ";
            else
                valid = true;
        }
        else
        {
            //algo salio mal, reseteamos el state del buffer a 'ok'
            cin.clear();
            //lo vaciamos
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nError, ingrese un numero: ";
        }
    } while (!valid);
    
    return (input);
}

void matriculartoDeporte(Socio socio[], Deporte sports[])
{
    int codigo = ERROR;
    int posSocio = ERROR;
    int decision = ERROR;
    int numDeportes = ERROR;
    int posDeporte = ERROR;
    
    
    if (atLeastOneSocio(socio))
    {
        do {
            
            cout << "\nIngrese Codigo de Socio: ";
            codigo = checkInt();
            
            posSocio = encontrarCodigo(socio, codigo);
            if (posSocio == ERROR) { cout << endl << "\nTry Again: " << endl; }
        } while (posSocio == ERROR);
        
        posDeporte = posDeportes(posSocio, socio);
        
        if (posDeporte == ERROR)
        {
            cout << endl << "Ya este socio tiene " << DEPO << " Deportes registrados";
        }
        else {
            space();
            
            numDeportes = mostrarTodoDeportes(sports);
            
            if (numDeportes != 0)
            {
                do {
                    cout << endl << "Seleccione cual desea añadir: ";
                    decision = checkInt();
                } while (decision <= 0 || decision>numDeportes);
                
                //las opciones son del 1 al 9
                //pero el array de 0 a 8, por ende le aplico un patch
                decision--;
                
                bool already = false;
                
                for (int i = 0; i<DEPO; i++)
                {
                    if (strcmp(socio[posSocio].deportes[i].nombre, sports[decision].nombre) == 0)
                    {
                        if (socio[posSocio].deportes[i].morning == sports[decision].morning)
                        {
                            already = true;
                            cout << endl << "El Socio ya esta matriculado en este Deporte" << endl;
                        }
                    }
                }
                if (!already)
                {
                    //le aÒado la casilla de deportes al usuario
                    socio[posSocio].deportes[posDeporte] = sports[decision];
                    //double cuota = sports[decision].precio;
                    
                    //actualizo la cuota el usuario
                    //sumarQuota(socio, posSocio, cuota);
                    cout << endl << "Se ha Matriculado el Socio '" << socio[posSocio].nombre
                    << "' en el Deporte '" << sports[decision].nombre << "' ";
                }
            }
        }
    }
}

int mostrarTodoDeportes(Deporte depo[])
{
    int numDeportes = 0;
    cout << "Estos son los Deportes disponibles: " << endl;
    for (int i = 0; i<ALLDEPO; i++)
    {
        if (!(strcmp(depo[i].nombre, "") == 0))
        {
            cout << endl << i + 1 << ".- " << depo[i].nombre;
            //cout << " " << depo[i].horas;
            //cout << " " << depo[i].morning;
            //cout << " " << depo[i].precio;
            numDeportes++;
        }
        
        
    }
    if (numDeportes == 0)
    {
        cout << endl << "No hay ningun deporte";
    }
    return numDeportes;
}

void mostrarallSocios(Socio socis[], int& contSocios)
{
    
    if (atLeastOneSocio(socis))
    {
        for (int i = 0; i<contSocios; i++)
        {
            mostrarUnSocio(socis, i);
        }
        
        cout << endl << "Un total de '" << contSocios << "' inscrito(s)" << endl;
    }
}

int printDeportesUser(Socio socis[], int posSocio)
{
    int contDep = 0;
    //int pos = encontrarCodigo(socis, code);
    for (int j = 0; j<DEPO; j++)
    {
        if (strcmp(socis[posSocio].deportes[j].nombre, ""))
        {
            
            cout << endl << j + 1 << "  Nombre: "
            << socis[posSocio].deportes[j].nombre << endl;
            
            cout << "   Horas: " << socis[posSocio].deportes[j].horas << endl;
            if (socis[posSocio].deportes[j].morning)
            {
                cout << "   Horario de Mañanas" << endl;
            }
            else {
                cout << "   Horario de Tardes" << endl;
            }
            //cout << "   Precio: " << socis[pos].deportes[j].precio << endl;
            
            contDep++;
        }
        
    }
    if (contDep == 0)
    {
        cout << "    No esta inscrito en ningun deporte" << endl << endl;
    }
    return contDep;
}

void mostrarDeporteUnSocio(Socio socio[])
{
    int pos = ERROR;
    int code = ERROR;
    if (atLeastOneSocio(socio))
    {
        
        cout << "Ingrese el codigo del Socio: " << endl;
        //verificar que exista el usuario
        code = checkInt();
        pos = encontrarCodigo(socio, code);
        if (pos == ERROR)
        {
            cout << endl << "\nNo existe el Socio" << endl;
            space();
            
        }
        else {
            space();
            cout << "Deporte(s) de " << socio[pos].nombre << ": " << endl;
            printDeportesUser(socio, pos);
            
        }
    }
}

void bajaSocio(Socio socio[], int& contador)
{
    char ele;
    int codigo = ERROR;
    int posSocio = ERROR;
    int numDeportes = ERROR;
    
    
    if (atLeastOneSocio(socio))
    {
        
        //get poscontDep = printDeportesUser(socis, pos);
        //ask for int of soci wtf
        
        cout << "\nIngrese Codigo de Socio: ";
        codigo = checkInt();
        
        posSocio = encontrarCodigo(socio, codigo);
        if (posSocio == ERROR)
        {
            cout << "Your amigo no found, sorry mate";
        }
        else {
            
            numDeportes = mostrarUnSocio(socio, posSocio);
            
            
            do {
                space();
                cout << endl << "¿Seguro que quieres dar de baja a "
                << socio[posSocio].nombre << "? (S/N):" << endl;
                cin >> ele;
            } while (ele != 's' && ele != 'S' && ele != 'N' && ele != 'n');
            space();
            if (ele == 'n' || ele == 'N')
            {
                cout << endl << "No se realizo nada...";
                space();
            }
            else {
                
                
                fstream deleting(DELSOCI, ios::out | ios::app);
                int posDep = 0;
                if (deleting.is_open())
                {
                    //los guardo en el fichero de borrados
                    
                    //salto de linea si no esta vacio que no funciona con visual estudio
                    if (!(deleting.tellg()==0)){
                        deleting << endl;
                    }
                    deleting << socio[posSocio].codSoci << " ";
                    deleting << socio[posSocio].nombre << " ";
                    deleting << socio[posSocio].edad;
                    //deleting << " " << socio[posSocio].quota;
                    
                    //deleting << endl;
                    
                    for (posDep = 0; posDep<numDeportes; posDep++)
                    {
                        salvaBajaDeporte(socio, posSocio, posDep);
                        
                    }
                    
                    
                    deleting.close();
                }
                
                destroyUser(socio, posSocio, contador);
                
                cout << "Un Socio menos :(" << endl;
            }
            
        }
    }
}

int  mostrarUnSocio(Socio socis[], int pos)
{
    int numDeportes = 0;
    if (!(strcmp(socis[pos].nombre, "") == 0))
    {
        cout << endl;
        cout << "Codigo: " << socis[pos].codSoci << endl;
        cout << "Nombre: " << socis[pos].nombre << endl;
        cout << "Edad: " << socis[pos].edad << endl;
        //cout << "Quota: "<<socis[pos].quota <<endl;
        cout << "Actividad: " << socis[pos].inscrito.nombre << endl;
        cout << "Deportes: " << endl;
        
        
        numDeportes = printDeportesUser(socis, pos);
        
        
    }
    return numDeportes;
}

void destroyUser(Socio socio[], int pos, int& contador)
{
    
    
    //desplazo el array de socios
    if (contador<SOCI)
    {
        //desplazo todos los socios para que siempre me quden las primeras pos llenas
        for (int actual = pos; actual<contador; actual++)
        {
            socio[actual] = socio[actual + 1];
        }
    }
    
    //fusilo la socio de ultimo en la lista
    socio[contador].codSoci = ERROR;
    strcpy(socio[contador].nombre, "");
    socio[contador].edad = ERROR;
    socio[contador].quota = ERROR;
    
    
    contador--;
    
    
}

void destroyDeporte(Socio socio[], int posSoci, int posDepo)
{
    
    int macDeportes = DEPO - 1;
    if (posDepo<macDeportes)
    {
        for (int depoActual = posDepo; depoActual<macDeportes; depoActual++)
        {
            socio[posSoci].deportes[depoActual] = socio[posSoci].deportes[depoActual + 1];
        }
    }
    
    
    strcpy(socio[posSoci].deportes[macDeportes].nombre, "");
    socio[posSoci].deportes[macDeportes].horas = ERROR;
    //bool?
    
}

void saveCurrentState(Socio socio[], int& contador)
{
    string filename = DATSOCIOS;
    fstream fichero;
    
    
    if (contador == 0)
    {
        cout << "No hay datos para guardar...";
    }
    else {
        Socio existentes[SOCI];
        
        for (int i = 0; i < contador; i++)
        {
            //confio en mi contador
            existentes[i] = socio[i];
            
        }
        
        lastVersion(filename, false);
        
        fichero.open(filename, ios::out | ios::binary);
        if (!fichero.is_open())
        {
            cout << "No se pudo crear el fichero";
        }
        else {
            for (int i = 0; i<contador; i++) {
                fichero.write((const char*)&existentes[i], sizeof(Socio));
            }
            
            cout << "Se han guardado los datos" << endl;
            
            
            fichero.close();
        }
    }
    
}

void readSaveState(Socio socis[], int& mainCont)
{
    string filename = DATSOCIOS;
    fstream fichero;
    
    clearSocios(socis);
    
    //ya tengo la cantidad de socios en el .dat
    lastVersion(filename, true);
    
    
    Socio spawning[SOCI];
    fichero.open(filename, ios::in | ios::binary);
    int i = 0;
    if (fichero.is_open())
    {
        
        do
        {
            fichero.read((char *)&spawning[i], sizeof(Socio));
            
            if (spawning[i].codSoci != 0) {
                socis[i] = spawning[i];
                i++;
            }
        } while (!fichero.eof());
        
        fichero.close();
        cout << i << " Socios cargados al programa";
        mainCont = i;
    }else {
        cout << "No existen datos que cargar";
        
        
    }
    
}

void bajaDeporte(Socio socio[])
{
    int codigo = ERROR;
    int posSocio = ERROR;
    int numDeporte = ERROR;
    int posBorrar = ERROR;
    
    if (atLeastOneSocio(socio))
    {
        do {
            cout << "\nIngrese el Codigo de Socio: ";
            codigo = checkInt();
            
            posSocio = encontrarCodigo(socio, codigo);
            if (posSocio == ERROR) { cout << endl << "\nTry Again: " << endl; }
        } while (posSocio == ERROR);
        
        
        
        numDeporte = printDeportesUser(socio, posSocio);
        char ele;
        //double precio;
        //si hay deportes pregunto
        if (numDeporte != 0)
        {
            
            cout << "Que deporte quiere dar de baja: ";
            posBorrar = checkInt();
            if (posBorrar>0 && posBorrar <= numDeporte)
            {
                posBorrar += ERROR;
                
                do {
                    space();
                    cout << endl << "¿Seguro que quieres dar de baja en este Deporte? (S/N):" << endl;
                    cin >> ele;
                } while (ele != 's' && ele != 'S' && ele != 'N' && ele != 'n');
                space();
                
                if (ele == 'n' || ele == 'N')
                {
                    cout << endl << "Nothing happened...";
                    space();
                }
                else {
                    //obtengo el precio del deporte
                    //precio = socio[posSocio].deportes[posBorrar].precio;
                    
                    //restarQuota(socio, posSocio, socio[posSocio].deportes[posBorrar].precio);
                    
                    salvaBajaDeporte(socio, posSocio, posBorrar);
                    destroyDeporte(socio, posSocio, posBorrar);
                    
                    cout << "Se ha borrado el deporte";
                }
                
                
            }
            else {
                cout << endl << endl << "Wrong Awnser, no se ha borrado nada";
                space();
            }
        }
    }
}

void lastVersion(string &file, bool read)
{
    int ver = 0;
    
    string ext = ").dat";
    if (!read)
    {
        if (ifstream(file))
        {
            file = file.substr(0, file.length() - 4);
            ver++;
            file = file + "(" + to_string(ver) + ext;
            
            while (ifstream(file))
            {
                file = file.substr(0, file.length() - 7);
                ver++;
                file = file + "(" + to_string(ver) + ext;
            }
        }
    }
    else {
        if (ifstream(file))
        {
            //si existe el archivo original, puebo el siguiente
            file = file.substr(0, file.length() - 4);
            ver++;
            file = file + "(" + to_string(ver) + ext;
            //si existe (1)
            if (ifstream(file))
            {
                file = file.substr(0, file.length() - 7);
                ver++;
                file = file + "(" + to_string(ver) + ext;
                
                //pruebo con (2)
                while (ifstream(file))
                {
                    file = file.substr(0, file.length() - 7);
                    ver++;
                    file = file + "(" + to_string(ver) + ext;
                }
                //cuando no encuentre un numero (num)..
                //le indico que lea el ultimo que econtro
                file = file.substr(0, file.length() - 7);
                ver--;
                file = file + "(" + to_string(ver) + ext;
            }
            else {
                //cargo el original si no hay (1)..
                file = file.substr(0, file.length() - 7);
                ext = ext.substr(1, ext.length());
                file = file + ext;
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
    
    cout << "¿Que deporte estas buscando?" << endl << endl;
    cin >> input;
    
    space();
    cout << "Pues..." << endl << endl;
    myfile.open(DELDEPO, ios::in);
    if (myfile.is_open())
    {
        while (!myfile.eof())
        {
            //obtengo el nombre del deporte
            myfile >> deporte;
            
            
            //si el nombre del deporte es igual al indicado por el usuario
            if (deporte.compare(input) == 0)
            {
                myfile >> getter;
                cout << getter << " ";
                myfile >> getter;
                cout << getter << endl;
                
                found = true;
            }
            else {
                //simplemente paso de largo el nombre de esa baja
                myfile >> getter;
                myfile >> getter;
            }
            
        }
        myfile.close();
    }
    
    if (!found)
        cout << "Uy.. no se ha encontrado nada";
    
}

void salvaBajaDeporte(Socio socio[], int posSocio, int  posBorrar)
{
    
    
    fstream myfile;
    string lineaDoing;
    
    
    myfile.open(DELDEPO, ios::out | ios::app);
    
    if (myfile.is_open())
    {
        //si esta vacio no agrego un salto de linea, para no tener lineas vacias al final
        //del documento
        if (!(myfile.tellg()==0))
            myfile << endl;
        
        
        //NO funciona en visual, lo tuve que a ser a lo picapiedra
        
        myfile << socio[posSocio].deportes[posBorrar].nombre;
        myfile << " " << socio[posSocio].nombre;
        
        //asi
        //myfile << endl;
        
        
        myfile.close();
    }
}

void edadesDeportes(Socio socis[])
{
    if (atLeastOneSocio(socis))
    {
        fstream myfile;
        myfile.open(EDADSOCI, ios::out);
        bool endedad = false;
        bool first = true;
        
        if (myfile.is_open())
        {
            for (int age = YOUTH; age < VEJEZ; age++)
            {
                
                for (int posSoci = 0; posSoci < SOCI; posSoci++)
                {
                    
                    
                    if (socis[posSoci].edad == age)
                    {
                        
                        if (first)
                        {
                            myfile << age << " aÒos: " << endl;
                            first = false;
                            endedad = true;
                        }
                        
                        
                        
                        
                        myfile << socis[posSoci].codSoci << " - ";
                        myfile << socis[posSoci].nombre << endl;
                        
                    }
                    
                }
                if (endedad)
                {
                    myfile << "-----------" << endl;
                    endedad = false;
                }
                
                
                first = true;
                
            }
            
            cout << "Se ha creado el fichero por edades";
            
            myfile.close();
        }
    }
}

void crearActividad(Actividad activ[], int& conta)
{
    char c;
    int num;
    if(conta<=ACTI)
    {
        cout << "Ingrese el nombre";
        cin >> activ[conta].nombre;
        do{
            cout << "Ingrese la Sala";
            cin >> c;
        }while(c<65 && c>90);
        
        cin >> activ[conta].sala;
        //65 a 90
        cout << "Ingrese el nivel";
        cin >> num;
        if(num <1 || num >10)
        {
            num=5;
        }
        activ[conta].nivel= num;
        
        
        
    }else{
        cout << "No se pueden registrar mas actividades";
    }
}

int mostrarTodoActi(Actividad acti[])
{
    int numActi = 0;
    cout << "Estos son las Actividades disponibles: " << endl;
    for (int i = 0; i<ACTI; i++)
    {
        if (!(strcmp(acti[i].nombre, "") == 0))
        {
            cout << endl << i + 1 << ".- " << acti[i].nombre;
            //cout << " " << depo[i].horas;
            //cout << " " << depo[i].morning;
            //cout << " " << depo[i].precio;
            numActi++;
        }
        
        
    }
    if (numActi == 0)
    {
        cout << endl << "No hay ninguna Actividad";
    }
    return numActi;
}

void asociarActi(Socio socis[], Actividad activ[],int& conta)
{
    if(atLeastOneSocio(socis))
    {
        int code;
        char ele='z';
        bool pass=true;
        int decision;
        int numActi;
        int posSocio;
        
        cout << "Ingrese el codigo de usuario" << endl;
        code=checkInt();
        posSocio=encontrarCodigo(socis,code);
        
        if(posSocio==ERROR)
        {
            cout << "No se ha encontrado este socio";
        }else{
            
            
            if(strcmp(socis[posSocio].inscrito.nombre, "")==0)
            {

                do{
                    space();
                    cout << endl << "Ya este Socio esta matriculado en una actividad, Desea sobreescribir esta? (S/N):" << endl;
                    cin >> ele;
                } while (ele != 's' && ele != 'S' && ele != 'N' && ele != 'n');
                
                if(ele == 's' || ele == 'S')
                {
                    pass=true;
                }else{
                    pass=false;
                    cout << "No se han hecho cambios";
                }
            }
                
            if(pass)
            {
                numActi=mostrarTodoActi(activ);
                if(numActi!=0)
                {
                    do {
                        cout << endl << "Seleccione cual Avtidad desea asociar al Usuario: ";
                        decision = checkInt();
                    } while (decision <= 0 || decision>numActi);
                    
                    
                    if(socis[posSocio].inscrito.nombre == activ[decision].nombre)
                    {
                        cout << "No te puedes inscribir en la misma actividad";
                    }else{
                        socis[posSocio].inscrito = activ[decision];
                    }
                }
            }

        }
    }
}

void guardarFileDepo(Deporte depo[])
{
    int numDeportes=ERROR;
    int decision=ERROR;
    int posDep=ERROR;
    
    numDeportes=mostrarTodoDeportes(depo);
    if (numDeportes != 0)
    {
        do {
            cout << endl << "Seleccione cual desea añadir: ";
            decision = checkInt();
        } while (decision <= 0 || decision>numDeportes);
        
        //las opciones son del 1 al 9
        //pero el array de 0 a 8, por ende le aplico un patch
        posDep=decision-1;
        
        fstream deporteFichero;
        string nombreDep= depo[posDep].nombre;
        
        nombreDep=nombreDep+".dat";
        
        
        
        deporteFichero.open(nombreDep, ios::out|ios::trunc);
        if(deporteFichero.is_open())
        {
            deporteFichero.write((const char*)&depo[posDep], sizeof(Deporte));
            
            cout << "Se han guardado los datos" << endl;
            
            deporteFichero.close();
        }
    }
}


void cargarSociosBaja(Socio baja[])
{
    fstream bajax;
    
    char nombre[NAM] = "";
    char apellido[NAM] = "";
    char fullname[NAM] = "";
    bajax.open(DELSOCI, ios::in);
    if(bajax.is_open())
    {
        do {
            for (int i=0; i<BAJA; i++)
            {
                bajax >> baja[i].codSoci;
                
                bajax >> nombre;
                bajax >> apellido;
                strcpy(fullname, nombre);
                strcat(fullname, " ");
                strcat(fullname, apellido);
                
                strcpy(baja[i].nombre, nombre);
                
                bajax >> baja[i].edad;
                
                bajax >> baja[i].quota;
            }
            
            
            //baja[i].inscrito.sala='\0';
            for (int f =0 ; f<DEPO; f++)
            {
                //baja[i].deportes[f].nombre;
            }
        } while (!bajax.eof());
        
        cout << "Se han cargados los Socios de Baja";
        space();
        bajax.close();
    }
}
