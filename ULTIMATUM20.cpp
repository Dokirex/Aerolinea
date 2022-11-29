#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>

//---------------------------------------------------------------------------------------------------------


//---------------------------------------------------------------------------------------------------------
struct Vuelo{
    char NroDeVuelo [7];
    char Origen[9];
    char Destino[9];
    char MatriculaAvion[7];
    char NombrePiloto[21];
    char Hora [5];
    char Fecha[7];
    char Estado;
    struct Vuelo *sigV;
}Vuelo;
//---------------------------------------------------------------------------------------------------------
struct Pasajeros{
    char NroDeVuelo [7];
    char Cedula[11];
    char Nombre[21];
    char Telefono[11];
    char Estado;
    struct Pasajeros *sig;
}Pasajeros;
//---------------------------------------------------------------------------------------------------------
struct Vuelo *tpunterov, *ultimov;
struct Pasajeros *tpunterop, *ultimop;
//---------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------

void Menu();
void validar();
void crear();
void crear2 ();
void AdicionarVuelos();
void AdicionarPasajero();
void ListaPasajero();
void BuscarPasajero();
void ModificarEstado();
//---------------------------------------------------------------------------------------------------------
int main()
{
    Menu();
    getchar();
    return 0;
}
//---------------------------------------------------------------------------------------------------------
void Menu(){
    printf("Menu Aerolinea Viajar\n\n");
    printf(" 1. crear el archivo VUELOS.dat\n");
    printf(" 2. Crear el archivo PASAJEROS.dat\n");
    printf(" 3. Adicionar Vuelos\n");
    printf(" 4. Adicionar Pasajeros\n");
    printf(" 5. Lista de Pasajeros\n");
    printf(" 6. Buscar Pasajeros\n");
    printf(" 7. Modificar estado del vuelo.\n");
    printf(" 8. Registrar pasajero\n");
    printf(" 0. Salir\n");
    printf(" Ingrese alguna opcion: ");
    validar();
}
//---------------------------------------------------------------------------------------------------------
void validar(){

int Opcion= 0;
scanf("%d", &Opcion);
fflush(stdin);
if(Opcion >=0 && Opcion <=8){
    switch(Opcion){
            case 1:
            printf("Se va a crear el archivo de vuelos\n");
                crear();
            break;
            case 2:
            printf("se va a crear el archivo de pasajeros\n");
                crear2();
            break;
            case 3:
            printf("Se van a adicionar vuelos\n");
                AdicionarVuelos();
            break;
            case 4:
            printf("Se va adicionar un pasajero\n");
                AdicionarPasajero();
            break;
            case 5:
            printf("Se van a listar los pasajeros\n");
                ListaPasajero();
            break;
            case 6:
            printf("Buscando pasajeros\n");
                BuscarPasajero();
            break;
            case 7:
            printf("Modificando el estado del vuelo\n");
                ModificarEstado();
            break;

            default:
                printf("Saliendo del aplicativo\n");
            break;
        }
    }
    else{
        printf("La opcion es incorrecta\n");
        getchar();
        Menu();
    }
}
//---------------------------------------------------------------------------------------------------------
void crear(){
system("CLS");
FILE *archdisco;
archdisco = fopen("D:\\ac\\VUELOS.dat","w");
fclose(archdisco);
printf("\nARCHIVO CREADO\n");
system("PAUSE"); system("PAUSE");
fflush(stdin);
    getchar();
    Menu();
}
//---------------------------------------------------------------------------------------------------------
void crear2(){
system("CLS");
FILE *archdisco;
archdisco = fopen("D:\\ac\\PASAJEROS.dat","w");
fclose(archdisco);
printf("\nARCHIVO CREADO\n");
system("PAUSE"); system("PAUSE");
fflush(stdin);
    getchar();
    Menu();
}
//--------------------------------------------------------------------------------------------------------
void AdicionarVuelos(){
system("CLS");
struct Vuelo *nuevov;

nuevov = (struct Vuelo *) malloc(sizeof(struct Vuelo));
if (nuevov==NULL) printf( "No hay memoria disponible!\n");

printf("dame Numero de vuelo :"); fflush(stdin);
scanf("%s",&nuevov->NroDeVuelo);getchar();

printf("dame Origen :"); fflush(stdin);
scanf("%s",&nuevov->Origen);getchar();

printf("dame Destino :");fflush(stdin);
scanf("%s",&nuevov->Destino);getchar();

printf("dame la matricula del avion :"); fflush(stdin);
scanf("%s",&nuevov->MatriculaAvion);getchar();

printf("dame Nombre del piloto :"); fflush(stdin);
scanf("%s",&nuevov->NombrePiloto);getchar();

printf("dame Hora :"); fflush(stdin);
scanf("%s",&nuevov->Hora);getchar();

printf("dame Fecha :"); fflush(stdin);
scanf("%s",&nuevov->Fecha);getchar();

printf("dame estado :"); fflush(stdin);
scanf("%c",&nuevov->Estado);getchar();

nuevov->sigV=NULL;

if (tpunterov == NULL){
    tpunterov = nuevov;
    ultimov = nuevov;
}
else{
    ultimov->sigV = nuevov;
    ultimov = nuevov;
}

FILE *archdisco;
archdisco = fopen("D:\\ac\\VUELOS.dat","at+");
fwrite(&Vuelo,sizeof(Vuelo),1,archdisco);
fclose(archdisco);

printf("Vuelo insertado");
system("PAUSE"); system("PAUSE");

Menu();
}
//---------------------------------------------------------------------------------------------------------
void AdicionarPasajero(){
system("CLS");
struct Pasajeros *nuevo;
nuevo = (struct Pasajeros *) malloc(sizeof(struct Pasajeros));
if (nuevo==NULL) printf( "No hay memoria disponible!\n");

printf("dame Numero de vuelo :"); fflush(stdin);
scanf("%s",nuevo->NroDeVuelo);getchar();
printf("dame Cedula :"); fflush(stdin);
scanf("%s",nuevo->Cedula);getchar();
printf("dame Nombre :"); fflush(stdin);
scanf("%s",nuevo->Nombre);getchar();
printf("dame el telefono :"); fflush(stdin);
scanf("%s",nuevo->Telefono);getchar();
printf("dame estado :"); fflush(stdin);
scanf("%c",&nuevo->Estado);getchar();

nuevo->sig=NULL;

if (tpunterop ==NULL){
    tpunterop = nuevo;
    ultimop = nuevo;
}
else{
    ultimop->sig =nuevo;
    ultimop = nuevo;
}

FILE *archdisco;
archdisco = fopen("D:\\ac\\PASAJEROS.dat","at+");
fwrite(&Pasajeros,sizeof(Pasajeros),1,archdisco);
fclose(archdisco);

//avisando usuario
printf("Pasajero insertado");
system("PAUSE"); system("PAUSE");
Menu();
}
//---------------------------------------------------------------------------------------------------------

void ListaPasajero(){

system("CLS");

FILE *archdisco;
archdisco = fopen("D:\\ac\\PASAJEROS.dat","at+");

struct Pasajeros *aux;
int i;

i=0;

aux = tpunterop;

printf(" Mostrando lista de pasajeros: ");

while (aux != EOF){

	printf( "NroDevuelo: %s, Cedula: %s, Nombre: %s, Telefono: %s, Estado %c \n ",
	aux->NroDeVuelo, aux->Cedula, aux->Nombre, aux->Telefono, aux->Estado);

	aux = aux->sig;

	i++;


}

fclose(archdisco);
system("PAUSE"); system("PAUSE");

Menu();

if (i==0)printf( "La lista esta vacia \n");
Menu();
}


//---------------------------------------------------------------------------------------------------------

void BuscarPasajero(){
system("CLS");

printf("Que pasajero quiere buscar?");

FILE *archdisco;
archdisco = fopen("D:\\ac\\PASAJEROS.dat","at+");
struct Pasajeros *aux1, *nuevo;

char comparar[20];

printf(" introduzca el nombre");

gets(comparar);

aux1 = tpunterop;
int cambio;
int i;

i=0;

while (aux1!=NULL){
    if (aux1->Nombre == comparar){

    printf( "NroDevuelo: %s, Cedula: %s, Nombre: %s, Telefono: %s, Estado %c \n ",
	aux1->NroDeVuelo, aux1->Cedula, aux1->Nombre, aux1->Telefono, aux1->Estado);

	aux1 = aux1->sig;

	i++;

    }else{
            aux1 = aux1->sig;
            }
}
i++;

if (i==0)

    printf (" la lista esta vacia!!\n" );

fclose(archdisco);
system("PAUSE"); system("PAUSE");

Menu();
}
//---------------------------------------------------------------------------------------------------------
void ModificarEstado(){

		FILE *arch1;

arch1 = fopen("D:\\ac\\PASAJEROS.dat","r+");

struct Pasajeros *aux1, *nuevo;

char comparar[20];

printf(" introduzca el nombre");

gets(comparar);

aux1 = tpunterop;
int cambio;
int i;

i=0;

while (aux1!=NULL){
    if (aux1->Nombre == comparar){
    scanf("%c",&nuevo->Estado);getchar();
    }else{
            aux1 = aux1->sig;
            }
}
i++;

if (i==0)

    printf (" la lista esta vacia!!\n" );

fclose(arch1);

puts("Estado cambiado");

Menu();
}
//---------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------
