// V 2.1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"
#define LARGOBUFER 600

//funcion principal
int main()
{
  FILE *entrada = fopen("alcanos.txt", "r"); //Creo una entrada de tipo File y la leo
  FILE *salida = fopen("salida.txt", "w"); //Creo archivo de salida
  FILE *diagramas = fopen("diagramas.txt", "w");

  //Verifico si el archivo esta.
  if (!entrada) 
  {
    printf("No se puede leer archivo.");
    return -1;
  }

  //VARIABLES DE ARCHIVO                     
  char bufer[LARGOBUFER];
  int totalAlcanos = 0;       

  //Creo las colitas
  Cola* Cola1 = crearCola();
  Cola* Cola2 = crearCola();
  
  //obtengo el total de alcanos
  fgets(bufer, LARGOBUFER, entrada);
  totalAlcanos = atoi(bufer); //trasformo a int el char w

  //Agrego todos los alcanos dentro de una cola.
  for(int i = 0; i < totalAlcanos; i++){
    fgets(bufer, LARGOBUFER, entrada);
    ALCANO* nuevo = (ALCANO*)malloc(sizeof(ALCANO));    
    strcpy(nuevo->nombreA, bufer);
    encolar(Cola1, nuevo);
    encolar(Cola2, nuevo);
  }

  //Ejecutamos algoritmos
  crearSalida(Cola1, totalAlcanos,salida);
  crearDiagrama(Cola2, totalAlcanos, diagramas);

  fclose(entrada); 
  fflush(diagramas);
  fclose(diagramas);
  fflush(salida);
  fclose(salida);
  //crear otros archivos .h para facilitar la lectura de codigo y orden. No aplica en este proyecto.
  //Faltan hallar las posiciones
  return 0;
}

void crearSalida(Cola* Cola1, int totalAlcanos, FILE *salida){
  for(int n = 0; n < totalAlcanos; n++){
    char alcanoN[LARGOBUFER];
    ALCANO extraido = desencolar(Cola1);
    strcpy(alcanoN, extraido.nombreA);

    //Ciclo para contar el total de carbonos
    int totalCarbonos = 0;
    for(int i = 0; i < strlen(alcanoN); i++){
      if(alcanoN[i] == '3' || alcanoN[i] == '2'){
        totalCarbonos++;
      }else{
        if(alcanoN[i] == '+' && alcanoN[i+1] == '-'){
          totalCarbonos++;
          i = i + 3;
          while(alcanoN[i] != '#'){
            i++;
          }
          i = i + 2;
          while(alcanoN[i] != '#'){
            i++;
          }
        }else{
          if(alcanoN[i] == '+' || alcanoN[i] == '-'){
            totalCarbonos++;
            i = i + 2;
            while(alcanoN[i] != '#'){
              i++;
            }
          }
        }
      }
    }
    //Fin del ciclo para contar carbonos.

    //Ciclo para contar cuando alquilos tiene cada alcano.
    int esMetil = 0;
    int esEtil = 0;
    int esPropil = 0;
    int esButil = 0;
    int esPentil = 0; 
    int esR = 0;

    for(int a = 0; a < strlen(alcanoN); a++){
      if(alcanoN[a] == '#' && alcanoN[a+1] == '3' && alcanoN[a+2] == '#'){ 
        esMetil ++;
      }else{
        if(alcanoN[a] == '#' && alcanoN[a+1] == '2' && alcanoN[a+2] == '3' && alcanoN[a+3] == '#'){
          esEtil++;
        }else{
          if(alcanoN[a] == '#' && alcanoN[a+1] == '2' && alcanoN[a+2] == '2' && alcanoN[a+3] == '3' && alcanoN[a+4] == '#'){
            esPropil++;
          }else{
            if(alcanoN[a] == '#' && alcanoN[a+1] == '2' && alcanoN[a+2] == '2' && alcanoN[a+3] == '2' && alcanoN[a+4] == '3' && alcanoN[a+5] == '#'){
              esButil++;
            }else{
              if(alcanoN[a] == '#' && alcanoN[a+1] == '2' && alcanoN[a+2] == '2' && alcanoN[a+3] == '2' && alcanoN[a+4] == '2' && alcanoN[a+5] == '3' && alcanoN[a+6] == '#'){
                esPentil++;
              }else{
                if(alcanoN[a] == '#' && alcanoN[a+1] == '2' && alcanoN[a+2] == '2' && alcanoN[a+3] == '2' && alcanoN[a+4] == '2' && alcanoN[a+5] == '2' && alcanoN[a+6] == '3' && alcanoN[a+7] == '#'){
                  esR++;
                }else{
                  if(alcanoN[a] == '#' && alcanoN[a+1] == '2' && alcanoN[a+2] == '2' && alcanoN[a+3] == '2' && alcanoN[a+4] == '2' && alcanoN[a+5] == '2' && alcanoN[a+6] == '2' && alcanoN[a+7] == '3' && alcanoN[a+8] == '#'){
                    esR++;
                  }else{
                    if(alcanoN[a] == '#' && alcanoN[a+1] == '2' && alcanoN[a+2] == '2' && alcanoN[a+3] == '2' && alcanoN[a+4] == '2' && alcanoN[a+5] == '2' && alcanoN[a+6] == '2' && alcanoN[a+7] == '2' && alcanoN[a+8] == '3' && alcanoN[a+9] == '#'){
                      esR++;
                    }else{
                      if(alcanoN[a] == '#' && alcanoN[a+1] == '2' && alcanoN[a+2] == '2' && alcanoN[a+3] == '2' && alcanoN[a+4] == '2' && alcanoN[a+5] == '2' && alcanoN[a+6] == '2' && alcanoN[a+7] == '2' && alcanoN[a+8] == '2' && alcanoN[a+9] == '3'  && alcanoN[a+10] == '#'){
                        esR++;
                      }else{
                        if(alcanoN[a] == '#' && alcanoN[a+1] == '2' && alcanoN[a+2] == '2' && alcanoN[a+3] == '2' && alcanoN[a+4] == '2' && alcanoN[a+5] == '2' && alcanoN[a+6] == '2' && alcanoN[a+7] == '2' && alcanoN[a+8] == '2' && alcanoN[a+9] == '2'  && alcanoN[a+10] == '3'  && alcanoN[a+11] == '#'){
                          esR++;
                        }else{
                          if(alcanoN[a] == '#' && alcanoN[a+1] == '2' && alcanoN[a+2] == '2' && alcanoN[a+3] == '2' && alcanoN[a+4] == '2' && alcanoN[a+5] == '2' && alcanoN[a+6] == '2' && alcanoN[a+7] == '2' && alcanoN[a+8] == '2' && alcanoN[a+9] == '2'  && alcanoN[a+10] == '2'  && alcanoN[a+11] == '3' && alcanoN[a+12] == '#'){
                            esR++;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }

    //FIN DE CICLO PARA CONTAR CUANTOS ALQUILOS TIENE


    //Saber las posiciones
    int posicionI = 0;
    int posicionN = 0;
    char invertido[LARGOBUFER];
    strcpy(invertido, alcanoN);
    invertir(invertido);
    //Almaceno la poscionI que seria la poscion del invertido
    //almaceno la posicionN que seria la posicion del normal
    for(int a = 0; a < strlen(alcanoN); a++){
      if(alcanoN[a] == '-'){
        posicionN = a;
        break;
      }else{
        if(alcanoN[a] == '+'){
          posicionN = a;
          break;
        }else{
          if(alcanoN[a] == '-' && alcanoN[a+1] == '+'){
            posicionN = a;
            break;
          }else{
            if(alcanoN[a] == '+' && alcanoN[a+1] == '#'){
              posicionN = a;
              break;
            }
          }
        }
      }
    }

    for(int a = 0; a < strlen(invertido); a++){
      if(invertido[a] == '#'){
        posicionI = a-1;
        break;
      }
    }
    //VER POR DONDE PARTIR 
    char var_alcano[LARGOBUFER];
    int i=0;

    if(posicionI < posicionN){
      strcpy(var_alcano, invertido);
      i = 1;
    }else{
      strcpy(var_alcano, alcanoN);
    }
    //Fin de ver por donde partir


    if(esButil > 0){
      for(int bu = 0; bu < esButil; bu++){
      int pos = 0;
      int al = 0;
      char *agr;
      for(int i = 1; i < strlen(var_alcano); i++){
        if(var_alcano[i] == '3' || var_alcano[i] == '2'){
          pos++;
        }else{
          if(var_alcano[i] == '#'){
            i++;
            while(var_alcano[i] != '#'){
              i++;
              al++;
            }
            pos++;
            if(al == 4){
              agr = enterar(pos);
              fputs(agr, salida);
              al = 0;
            }
            if(var_alcano[i+1] == '#'){
              al = 0;
              i = i + 2;
              while(var_alcano[i] != '#'){
                i++;
                al++;
              }
              if(al == 4){
                agr = enterar(pos);
                fputs(agr, salida);
                al = 0;
              }
            al = 0;  
            }
          }else{
            if(var_alcano[i] == '-' && var_alcano[i+1] == '+'){
              pos++;
            }else{
              if(var_alcano[i] == '-' || var_alcano[i] == '+'){
              }
            }
          }
        }
      }
      if(bu != (esButil-1)){
        fputs(",", salida);
      }
    }
    escribirButil(esButil, salida);
  }
  
    if(esEtil > 0){
      int pos = 0;
      int al = 0;
      char *agr;
      int et = 0;
      for(int i = 1; i < strlen(var_alcano); i++){
        if(var_alcano[i] == '3' || var_alcano[i] == '2'){
          pos++;
        }else{
          if(var_alcano[i] == '#'){
            i++;
            while(var_alcano[i] != '#'){
              i++;
              al++;
            }
            pos++;
            et++;
            if(al == 2){
              agr = enterar(pos);
              fputs(agr, salida);
              al = 0;
            }
            if(et != (esEtil)){
                fputs(",", salida);
            }
            if(var_alcano[i+1] == '#'){
              al = 0;
              i = i + 2;
              while(var_alcano[i] != '#'){
                i++;
                al++;
              }
              if(al == 2){
                agr = enterar(pos);
                fputs(agr, salida);
                al = 0;
              }
              if(et != (esEtil)){
                fputs(",", salida);
              }
            al = 0;  
            }
          }else{
            if(var_alcano[i] == '-' && var_alcano[i+1] == '+'){
              pos++;
            }else{
              if(var_alcano[i] == '-' || var_alcano[i] == '+'){
              }
            }
          }
        }
      }
      if(et != (esEtil-1)){
        fputs(",", salida);
      }
    escribirEtil(esEtil, salida);
  }


    if(esMetil > 0){
      int pos = 0;
      int al = 0;
      char *agr;
      int me = 0;
      for(int i = 1; i < strlen(var_alcano); i++){
        if(var_alcano[i] == '3' || var_alcano[i] == '2'){
          pos++;
        }else{
          if(var_alcano[i] == '#'){
            i++;
            while(var_alcano[i] != '#'){
              i++;
              al++;
            }
            me++;
            pos++;
            if(al == 1){
              agr = enterar(pos);
              fputs(agr, salida);
              al = 0;
            }
            if(me != (esMetil)){
              fputs(",", salida);
            }
            if(var_alcano[i+1] == '#'){
              al = 0;
              i = i + 2;
              while(var_alcano[i] != '#'){
                i++;
                al++;
              }
              if(al == 1){
                agr = enterar(pos);
                fputs(agr, salida);
                al = 0;
              }
              if(me != (esMetil)){
                fputs(",", salida);
              }
            al = 0;  
            }
          }else{
            if(var_alcano[i] == '-' && var_alcano[i+1] == '+'){
              pos++;
            }else{
              if(var_alcano[i] == '-' || var_alcano[i] == '+'){
              }
            }
          }
        }
      }
    escribirMetil(esMetil,salida);
  }

    if(esPentil > 0){
      for(int pe = 0; pe < esPentil; pe++){
        int pos = 0;
        int al = 0;
        char *agr;
        for(int i = 1; i < strlen(var_alcano); i++){
          if(var_alcano[i] == '3' || var_alcano[i] == '2'){
            pos++;
          }else{
            if(var_alcano[i] == '#'){
              i++;
              while(var_alcano[i] != '#'){
                i++;
                al++;
              }
              pos++;
              if(al == 5){
                agr = enterar(pos);
                fputs(agr, salida);
                al = 0;
              }
              if(var_alcano[i+1] == '#'){
                al = 0;
                i = i + 2;
                while(var_alcano[i] != '#'){
                  i++;
                  al++;
                }
                if(al == 5){
                  agr = enterar(pos);
                  fputs(agr, salida);
                  al = 0;
                }
              al = 0;  
              }
            }else{
              if(var_alcano[i] == '-' && var_alcano[i+1] == '+'){
                pos++;
              }else{
                if(var_alcano[i] == '-' || var_alcano[i] == '+'){
                }
              }
            }
          }
        }
        if(pe != (esPentil-1)){
          fputs(",", salida);
        }
      }
      escribirPentil(esPentil, salida);
    }

    if(esPropil > 0){
      for(int pr = 0; pr < esPropil; pr++){
        int pos = 0;
        int al = 0;
        char *agr;
        for(int i = 1; i < strlen(var_alcano); i++){
          if(var_alcano[i] == '3' || var_alcano[i] == '2'){
            pos++;
          }else{
            if(var_alcano[i] == '#'){
              i++;
              while(var_alcano[i] != '#'){
                i++;
                al++;
              }
              pos++;
              if(al == 3){
                agr = enterar(pos);
                fputs(agr, salida);
                al = 0;
              }
              if(var_alcano[i+1] == '#'){
                al = 0;
                i = i + 2;
                while(var_alcano[i] != '#'){
                  i++;
                  al++;
                }
                if(al == 3){
                  agr = enterar(pos);
                  fputs(agr, salida);
                  al = 0;
                }
              al = 0;  
              }
            }else{
              if(var_alcano[i] == '-' && var_alcano[i+1] == '+'){
                pos++;
              }else{
                if(var_alcano[i] == '-' || var_alcano[i] == '+'){
                }
              }
            }
          }
        }
        if(pr != (esPropil-1)){
          fputs(",", salida);
        }
      }
      escribirPropil(esPropil, salida);  
    }



    //ingresar totalCarbonos escrito
    char *totalCarbonosChar =  NULL;
    if(totalCarbonos == 1) totalCarbonosChar = "metano"; 
    if(totalCarbonos == 2) totalCarbonosChar = "etano"; 
    if(totalCarbonos == 3) totalCarbonosChar = "propano"; 
    if(totalCarbonos == 4) totalCarbonosChar = "butano"; 
    if(totalCarbonos == 5) totalCarbonosChar = "pentano"; 
    if(totalCarbonos == 6) totalCarbonosChar = "hexano"; 
    if(totalCarbonos == 7) totalCarbonosChar = "heptano";
    if(totalCarbonos == 8) totalCarbonosChar = "octano";
    if(totalCarbonos == 9) totalCarbonosChar = "nonano";
    if(totalCarbonos == 10) totalCarbonosChar = "decano";
    if(totalCarbonos == 11) totalCarbonosChar = "undecano";
    if(totalCarbonos == 12) totalCarbonosChar = "dodecano";
    if(totalCarbonos == 13) totalCarbonosChar = "tridecano"; 
    if(totalCarbonos == 14) totalCarbonosChar = "tetradecano"; 
    if(totalCarbonos == 15) totalCarbonosChar = "pentadecano"; 
    if(totalCarbonos == 16) totalCarbonosChar = "hexadecano"; 
    if(totalCarbonos == 17) totalCarbonosChar = "heptadecano"; 
    if(totalCarbonos == 18) totalCarbonosChar = "octadecano"; 
    if(totalCarbonos == 19) totalCarbonosChar = "nonedecano";
    if(totalCarbonos == 20) totalCarbonosChar = "eicosano";
    if(totalCarbonos == 21) totalCarbonosChar = "heneicosano";
    if(totalCarbonos == 22) totalCarbonosChar = "docosano";
    if(totalCarbonos == 23) totalCarbonosChar = "tricosano";
    if(totalCarbonos>=24&&totalCarbonos<30)totalCarbonosChar = "tetracosano";
    if(totalCarbonos>=30&&totalCarbonos<40)totalCarbonosChar = "tricontano";
    if(totalCarbonos >= 40)totalCarbonosChar = "tetracontano";
    //Ingresar alcano en archivo
    fputs(totalCarbonosChar, salida);
    fputc('\n', salida);
  } 
}

void crearDiagrama(Cola* Cola2, int totalAlcanos, FILE* diagramas){
  //Ingreso a diagrama
  for(int d = 0; d < totalAlcanos; d++){
    char alcanoD[LARGOBUFER]; //creo alcanoDiagrama
    ALCANO extraidoD = desencolar(Cola2);
    strcpy(alcanoD, extraidoD.nombreA);
    int ramasuperior = 0;
    for(int a = 0; a < strlen(alcanoD); a++){
          if(alcanoD[a] == '+'){
            ramasuperior = 1;
            break;
          }
    }
    if(d != 0){
      fputs("\n\n", diagramas);
    }
    int espacios = 0;
    int alquilo = 0;
    if(ramasuperior == 1){   
      for(int p = 0; p < strlen(alcanoD); p++){
        if(alcanoD[p] == '3' || alcanoD[p] == '2'){
          espacios = espacios + 3;
        }else{
          if(alcanoD[p] == '+' && alcanoD[p+1] == '-'){
            p++;
            p++;
            p++;
            while(alcanoD[p] != '#'){
              alquilo++;
              p++;
            }
            if(alquilo == 2){
              for(int po = 0; po < espacios; po++){
                fputs(" ", diagramas);
              }
              fputs("CH2CH3", diagramas);
              alquilo = 0;
              espacios = -5;
            }else{
              if(alquilo == 1){
                for(int po = 0; po < espacios; po++){
                  fputs(" ", diagramas);
                }
                fputs("CH3", diagramas);
                alquilo = 0;
                espacios = -2;
              }else{
                if(alquilo == 3){
                  for(int po = 0; po < espacios; po++){
                    fputs(" ", diagramas);
                  }
                  fputs("CH2CH2CH3", diagramas);
                  alquilo = 0;
                  espacios = -8;
                }else{
                  if(alquilo == 4){
                    for(int po = 0; po < espacios; po++){
                      fputs(" ", diagramas);
                    }
                    fputs("CH2CH2CH2CH3", diagramas);
                    alquilo = 0;
                    espacios = -11;
                  }else{
                    if(alquilo == 5){
                      for(int po = 0; po < espacios; po++){
                        fputs(" ", diagramas);
                      }
                      fputs("CH2CH2CH2CH2CH3", diagramas);
                      alquilo = 0;
                      espacios = -14;
                    }else{
                      if(alquilo > 5){
                        for(int po = 0; po < espacios; po++){
                          fputs(" ", diagramas);
                        }
                        fputs("R", diagramas);
                        alquilo = 0;
                        espacios = 0;
                      }
                    }
                  }
                }
              }
            }
          }else{
            if(alcanoD[p] == '#'){
              p++;
              while(alcanoD[p] != '#'){
                p++;
              }
            }else{
              if(alcanoD[p] == '-'){
                p++;
                p++;
                while(alcanoD[p] != '#'){
                  p++;
                }
                espacios++;
                espacios++;
              }else{
                if(alcanoD[p] == '+'){
                  p++;
                  p++;
                  while(alcanoD[p] != '#'){
                    p++;
                    alquilo++;
                  }
                  for(int pu = 0; pu < espacios; pu++){
                    fputs(" ", diagramas);
                  }
                  if(alquilo == 1){
                    fputs("CH3", diagramas);
                    alquilo = 0;
                    espacios = -2;
                  }else{
                    if(alquilo == 2){
                      fputs("CH2CH3", diagramas);
                      alquilo = 0;
                      espacios = -5;
                    }else{
                      if(alquilo == 3){
                        fputs("CH2CH2CH3", diagramas);
                        alquilo = 0;
                        espacios = -8;
                      }else{
                        if(alquilo == 4){
                          fputs("CH2CH2CH2CH3", diagramas);
                          alquilo = 0;
                          espacios = -11;
                        }else{
                          if(alquilo == 5){
                            fputs("CH2CH2CH2CH2CH3", diagramas);
                            alquilo = 0;
                            espacios = -14;
                          }else{
                            if(alquilo > 5){
                              fputs("R", diagramas);
                              alquilo = 0;
                              espacios = 0;
                            }
                          }
                        }
                      }
                    }
                  }
                  espacios++;
                }
              }
            }
          }
        }
      }
        fputs("\n", diagramas);
        int espaciosEn = 0; 
        for(int en = 0; en < strlen(alcanoD); en++ ){
          if(alcanoD[en] == '3' || alcanoD[en] == '2'){
            espaciosEn = espaciosEn + 3;
          }else{
            if(alcanoD[en] == '+' && alcanoD[en+1] == '-'){
              en = en + 3;
              while(alcanoD[en] != '#'){
                en++;
              }
              for(int av = 0; av < espaciosEn; av++){
                  fputs(" ", diagramas);
              }
              fputs("|", diagramas); 
              espaciosEn = 0;
            }else{
              if(alcanoD[en] == '#'){
                en++;
                while(alcanoD[en] != '#'){
                  en++;
                }
              }else{
                if(alcanoD[en] == '+'){
                  en = en + 2;
                  while(alcanoD[en] != '#'){
                    en++;
                  }
                  for(int av = 0; av < espaciosEn; av++){
                    fputs(" ", diagramas);
                  }
                  fputs("|", diagramas);
                  espaciosEn = 1; 
                }else{
                  if(alcanoD[en] == '-'){
                    en = en + 2;
                    while(alcanoD[en] != '#'){
                      en++;
                    }
                    espaciosEn = espaciosEn +2;
                  }else{
                    if(alcanoD[en] == '#'){
                      en++;
                      while(alcanoD[en] != '#'){
                        en++;
                      }
                    }
                  }
                }
              }
            }
          }

        }
    }else{
      fputs("\n", diagramas);
    }

    //CADENA PRINCIPAL ARMADO ACA YES ACA O SI BEIBI
    fputs("\n", diagramas);
    for(int c = 0; c < strlen(alcanoD); c++){
      if(alcanoD[c] == '3'){
        fputs("CH3", diagramas);
      }else{
        if(alcanoD[c] == '2'){
          fputs("CH2", diagramas);
        }else{
          if(alcanoD[c] == '+' && alcanoD[c+1] == '-'){
            fputs("C", diagramas);
            c = c+3;
            while(alcanoD[c] != '#'){
              c++;
            }
            c++;
            c++;
            while(alcanoD[c] != '#'){
              c++;
            }
          }else{
            if(alcanoD[c] == '+' || alcanoD[c] == '-'){
              fputs("CH", diagramas);
              c++;
              c++;
              while(alcanoD[c] != '#'){
                c++;
              }
            }
          }
        }
      } 
    }  

    //Agregar los  2|
    fputs("\n", diagramas);
    int espaciosEn2 = 0; 
    for(int en2 = 0; en2 < strlen(alcanoD); en2++){
      if(alcanoD[en2] == '3' || alcanoD[en2] == '2'){
        espaciosEn2 = espaciosEn2 + 3;
      }else{
        if(alcanoD[en2] == '+' && alcanoD[en2+1] == '-'){
          en2 = en2 + 3;
          while(alcanoD[en2] != '#'){
            en2++;
          }
          en2++;
          en2++;
          while(alcanoD[en2] != '#'){
            en2++;
          }
          for(int pe = 0; pe < espaciosEn2; pe++){
            fputs(" ", diagramas);
          }
          fputs("|", diagramas);
          espaciosEn2 = 0;
        }else{
          if(alcanoD[en2] == '-'){
            en2 = en2 + 2;
            while(alcanoD[en2] != '#'){
              en2++;
            }
            for(int pe = 0; pe < espaciosEn2; pe++){
              fputs(" ", diagramas);
            }
            fputs("|", diagramas);
            espaciosEn2 = 1;
          }else{
            if(alcanoD[en2] == '#'){
              en2++;
              while(alcanoD[en2] != '#'){
                en2++;
              }
            }else{
              if(alcanoD[en2] == '+'){
                en2++;
                en2++;
                while(alcanoD[en2] != '#'){
                  en2++;
                }
                espaciosEn2++;
                espaciosEn2++;
              }
            }
          }
        }
      }
    }

    //Agregar las ramificaciones finales yuju.
    fputs("\n", diagramas);
    int espaciosR = 0;
    int alquilos2 = 0;
    for(int ra2 = 0; ra2 < strlen(alcanoD); ra2++){
      if(alcanoD[ra2] == '3' || alcanoD[ra2] == '2'){
        espaciosR = espaciosR + 3;
      }else{
        if(alcanoD[ra2] == '-'){
          ra2 = ra2 + 2;
          while(alcanoD[ra2] != '#'){
            alquilos2++;
            ra2++;
          }
          for(int pi = 0; pi < espaciosR; pi++){
            fputs(" ", diagramas);
          }
          if(alquilos2 == 1){
            fputs("CH3", diagramas);
            espaciosR = -1;
            alquilos2 = 0;
          }else{
            if(alquilos2 == 2){
              fputs("CH2CH3", diagramas);
              espaciosR = -4;
              alquilos2 = 0;
            }else{
              if(alquilos2 == 3){
                fputs("CH2CH2CH3", diagramas);
                espaciosR = -7;
                alquilos2 = 0;
              }else{
                if(alquilos2 == 4){
                  fputs("CH2CH2CH2CH3", diagramas);
                  espaciosR = -10;
                  alquilos2 = 0;
                }else{
                  if(alquilos2 == 5){
                    fputs("CH2CH2CH2CH2CH3", diagramas);
                    espaciosR = -13;
                    alquilos2 = 0;
                  }else{
                    if(alquilos2 > 5){
                      fputs("R", diagramas);
                      espaciosR = 0;
                      alquilos2 = 0;
                    }
                  }
                }
              }
            }
          }
        }else{
          if(alcanoD[ra2] == '+' && alcanoD[ra2+1] == '-'){
            ra2 = ra2 + 3;
            while(alcanoD[ra2] != '#'){
              ra2++;
            }
            ra2++;
            ra2++;
            while(alcanoD[ra2] != '#'){
              ra2++;
              alquilos2++;
            }
            for(int pa = 0; pa < espaciosR; pa++){
              fputs(" ", diagramas);
            }
            if(alquilos2 == 1){
              fputs("CH3", diagramas);
              espaciosR = -2;
              alquilos2 = 0;
            }else{
              if(alquilos2 == 2){
                fputs("CH2CH3", diagramas);
                espaciosR = -5;
                alquilos2 = 0;
              }else{
                if(alquilos2 == 3){
                  fputs("CH2CH2CH3", diagramas);
                  espaciosR = -8;
                  alquilos2 = 0;
                }else{
                  if(alquilos2 == 4){
                    fputs("CH2CH2CH2CH3", diagramas);
                    espaciosR = -11;
                    alquilos2 = 0;
                  }else{
                    if(alquilos2 == 5){
                      fputs("CH2CH2CH2CH2CH3", diagramas);
                      espaciosR = -14;
                      alquilos2 = 0;
                    }else{
                      if(alquilos2 > 5){
                        fputs("R", diagramas);
                        espaciosR = 0;
                        alquilos2 = 0;
                      }
                    }
                  }
                }
              }
            }
          }else{
            if(alcanoD[ra2] == '+'){
              ra2 = ra2 + 2;
              while(alcanoD[ra2] != '#'){
                ra2++;
              }
              espaciosR++;
              espaciosR++;
            }
          }
        }
      }
    }
  }//FIN CICLO DIAGRAMAS


}

char *enterar(int a){
  char* retornar = NULL;
  if(a == 2) retornar = "2";
  if(a == 3) retornar = "3";
  if(a == 4) retornar = "4";
  if(a == 5) retornar = "5";
  if(a == 6) retornar = "6";
  if(a == 7) retornar = "7";
  if(a == 8) retornar = "8";
  if(a == 9) retornar = "9";
  if(a == 10) retornar = "10";
  if(a == 11) retornar = "11";
  if(a == 12) retornar = "12";
  if(a == 13) retornar = "13";
  if(a == 14) retornar = "14";
  return retornar;
}


void escribirButil(int esButil, FILE *salida){
      if(esButil > 0){
      fputs("-", salida);
      if(esButil == 1) fputs("butil", salida);
      if(esButil == 2) fputs("dibutil", salida);
      if(esButil == 3) fputs("tributil", salida);
      if(esButil == 4) fputs("tretabutil", salida);
      if(esButil == 5) fputs("pentabutil", salida);
      if(esButil == 6) fputs("hexabutil", salida);
      if(esButil == 7) fputs("heptabutil", salida);
      if(esButil == 8) fputs("octabutil", salida);
      if(esButil == 9) fputs("nonabutil", salida);
      if(esButil == 10) fputs("decabutil", salida);
    }
}

void escribirEtil(int esEtil, FILE *salida){
      if(esEtil > 0){
      fputs("-", salida);
      if(esEtil == 1) fputs("etil", salida);
      if(esEtil == 2) fputs("dietil", salida);
      if(esEtil == 3) fputs("trietil", salida);
      if(esEtil == 4) fputs("tretaetil", salida);
      if(esEtil == 5) fputs("pentaetil", salida);
      if(esEtil == 6) fputs("hexaetil", salida);
      if(esEtil == 7) fputs("heptaetil", salida);
      if(esEtil == 8) fputs("octaetil", salida);
      if(esEtil == 9) fputs("nonaetil", salida);
      if(esEtil == 10) fputs("decaetil", salida);
    }
      
}

void escribirMetil(int esMetil, FILE *salida){
      if(esMetil > 0){
      fputs("-", salida);
      if(esMetil == 1) fputs("metil", salida);
      if(esMetil == 2) fputs("dimetil", salida);
      if(esMetil == 3) fputs("trimetil", salida);
      if(esMetil == 4) fputs("tretametil", salida);
      if(esMetil == 5) fputs("pentametil", salida);
      if(esMetil == 6) fputs("hexametil", salida);
      if(esMetil == 7) fputs("heptametil", salida);
      if(esMetil == 8) fputs("octametil", salida);
      if(esMetil == 9) fputs("nonametil", salida);
      if(esMetil == 10) fputs("decametil", salida);
    }

}
void escribirPentil(int esPentil, FILE *salida){
      if(esPentil > 0){
      fputs("-", salida);
      if(esPentil == 1) fputs("pentil", salida);
      if(esPentil == 2) fputs("dipentil", salida);
      if(esPentil == 3) fputs("tripentil", salida);
      if(esPentil == 4) fputs("tretapentil", salida);
      if(esPentil == 5) fputs("pentapentil", salida);
      if(esPentil == 6) fputs("hexapentil", salida);
      if(esPentil == 7) fputs("heptapentil", salida);
      if(esPentil == 8) fputs("octapentil", salida);
      if(esPentil == 9) fputs("nonapentil", salida);
      if(esPentil == 10) fputs("decapentil", salida);
    }

}
void escribirPropil(int esPropil, FILE *salida){
      if(esPropil > 0){
      fputs("-", salida);
      if(esPropil == 1) fputs("propil", salida);
      if(esPropil == 2) fputs("dipropil", salida);
      if(esPropil == 3) fputs("tripropil", salida);
      if(esPropil == 4) fputs("tretapropil", salida);
      if(esPropil == 5) fputs("pentapropil", salida);
      if(esPropil == 6) fputs("hexapropil", salida);
      if(esPropil == 7) fputs("heptapropil", salida);
      if(esPropil == 8) fputs("octapropil", salida);
      if(esPropil == 9) fputs("nonapropil", salida);
      if(esPropil == 10) fputs("decapropil", salida);
    }


}
void escribirR(int esR, FILE *salida){
      if(esR > 0){
      fputs("-", salida);
      if(esR == 1) fputs("R", salida);
      if(esR == 2) fputs("diR", salida);
      if(esR == 3) fputs("triR", salida);
      if(esR == 4) fputs("tretaR", salida);
      if(esR == 5) fputs("pentaR", salida);
      if(esR == 6) fputs("hexaR", salida);
      if(esR == 7) fputs("heptaR", salida);
      if(esR == 8) fputs("octaR", salida);
      if(esR == 9) fputs("nonaR", salida);
      if(esR == 10) fputs("decaR", salida);
    }  
}
