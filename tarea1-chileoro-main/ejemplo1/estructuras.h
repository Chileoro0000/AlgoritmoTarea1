// V 2.1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Estructuras de cola
struct ALCANO {
  char nombreA[500];
} typedef ALCANO;

struct Nodo{
  ALCANO* dato;
  struct Nodo* siguiente;
} typedef Nodo;

struct Cola {
  int largo;
  Nodo* inicio;
  Nodo* final;
} typedef Cola;
//Fin estructuras de cola

//Defino funciones cola
Cola* crearCola();
void encolar(Cola* C, ALCANO* dato_a_encolar );
void mostrarCola(Cola *C);
ALCANO desencolar(Cola* C);
char *invertir(char cadena[]);
void crearSalida(Cola* Cola1, int totalAlcanos, FILE* salida);
void crearDiagrama(Cola* Cola2, int totalAlcanos, FILE* diagramas);
char* enterar(int a);
void escribirEtil(int esEtil, FILE *salida);
void escribirMetil(int esMetil, FILE *salida);
void escribirPropil(int esPropil, FILE *salida);
void escribirPentil(int esPentil, FILE *salida);
void escribirR(int esR, FILE *salida);
void escribirButil(int esButil, FILE *salida);



//Funcion para invertir
char *invertir(char cadena[]) {
  int Largo = strlen(cadena);
  char temporal;
  for (int izquierda = 0, derecha = Largo - 1; izquierda < (Largo / 2);
       izquierda++, derecha--) {
    temporal = cadena[izquierda];
    cadena[izquierda] = cadena[derecha];
    cadena[derecha] = temporal;
  }
  return cadena;
}

//Funciones cola
Cola* crearCola(){
  Cola* cola_a_retornar = (Cola*)malloc(sizeof(Cola));
  cola_a_retornar->inicio = NULL;
  cola_a_retornar->final = NULL;
  cola_a_retornar->largo = 0;
  return cola_a_retornar;
}

void encolar(Cola* C, ALCANO* dato_a_encolar ){
  Nodo* nodo_a_encolar = (Nodo*)malloc(sizeof(Nodo));
  nodo_a_encolar->dato = dato_a_encolar;
  nodo_a_encolar->siguiente = NULL;
  if (C->inicio == NULL) { 
    C->inicio = nodo_a_encolar;
    C->final = nodo_a_encolar;
  }
  else {
    C->final->siguiente = nodo_a_encolar; 
    C->final = nodo_a_encolar; 
  }
  C->largo = C->largo + 1;
}

ALCANO desencolar(Cola* C){
  if(C->largo > 0) {
    Nodo* primer_elemento = C->inicio;
    ALCANO variable_a_retornar = *primer_elemento->dato;
    C->inicio = C->inicio->siguiente; 
    if (C->largo == 1){
      C->final = NULL;
    }   
    free(primer_elemento);
    C->largo = C->largo-1;
    return variable_a_retornar;
  }
  else {
    printf("La cola esta vacia");
  }
  //return 0;
}

void mostrarCola(Cola *C){
  Nodo* nos_paramos_en = C->inicio; 
  while(nos_paramos_en != NULL){
    printf("Alcano --> %c\n", nos_paramos_en->dato->nombreA);
    nos_paramos_en = nos_paramos_en->siguiente;
  }
  printf("La cola esta vacia.\n");
}






