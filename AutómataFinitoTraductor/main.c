#include <stdio.h>
#include <stdlib.h>
#define MaxL 50 //Lineas max de fichero.
#define MaxC 25 //Maximos caracteres por linea.

int imprimirMenu();//Donde se elige el apartado a probar.

void borrarConsola();//Despeja la consola.

void aperturaFichero(char fichero[MaxL][MaxC],int opcion);//Saca las palabras del .txt y las copia en la matriz fichero.

enum Boolean//Los boleanos no existen en C tienes que crearlos.
{
	FALSE, TRUE
};

typedef struct
{
     enum Boolean esFinal;
     int numeroEstado;
}AFDT;

AFDT *traductor;


//###################################################################################################################################################
//################################################################################# MAIN ############################################################
//###################################################################################################################################################
int main()
{
    char fichero[MaxL][MaxC];//La matriz fichero es donde se guardaran los automatasb.txt
    borrarConsola();

    aperturaFichero(fichero,imprimirMenu());
    return 0;
}

//##################################################################################################################################################
//################################################################################ FUNCIONES OBLIGATORIAS ##########################################
//##################################################################################################################################################

int imprimirMenu()//######################### IMPRIMIR MENU #################################################################
{
 int opcion;

 printf("\tMENU PRINCIPAL\n\n");
 printf("\t(1) Apartado 'A'\n\n");
 printf("\t(2) Apartado 'B'\n\n");
 printf("\t(3) Apartado 'C'\n\n");
 printf("\t(0) Salir\n\n");//Por si el usuario queria finalizar pero se equivoca y elige volver al menu principal.
 printf("\nElija el apartado que quiera probar mediante '1', '2', '3', o '0' para salir: ");
 scanf("%d",&opcion);
 while(opcion>3 || opcion<0)
  {
   printf("\nHa introducido una opcion que no esta en el menu, porfavor introduzca una viable: ");
   fflush( stdin );
   scanf("%d",&opcion);
  }
return opcion;
}

void borrarConsola()//#### BORRAR CONSOLA #######################################################################################
{
  system("cls");
}

void aperturaFichero(char fichero[MaxL][MaxC],int opcion)//################## APERTURA DE FICHERO ###############################
{
  int cont=0;//Cuenta el numero de lineas(estados) del .txt
  char temp[50];
  FILE *F;
  switch( opcion )
   {
    case 1: F = fopen ("Apartado1.txt","r");
          break;

    case 2: F = fopen ("Apartado2.txt","r");
          break;

    case 3: F = fopen ("Apartado.txt","r");
          break;

    case 0: exit(0);//Comando para terminar la ejecucion entera del programa
          break;
  }
 if (F==NULL)
  {
    printf("\n\t\tERROR:el fichero no se ha abierto correctamente\n");
    exit (EXIT_FAILURE);
  }
 //el fichero se ha abierto correctamente
 while(!feof(F))
  {
   fgets(temp,50,F);//Lee una linea hasta encontrar'\n' o llegar a 50 en este caso y deja el puntero al inicio de la siguiente
   cont++;//Cada aumento es una linea/estado m�s.
   //Cada ciclo del while sobreescribe temp a�adiendo al final un nulo.
  }
  rewind(F);//Devuelve el puntero F al principio del fichero
 fclose(F);
}

