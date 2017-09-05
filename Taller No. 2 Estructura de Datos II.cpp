/*
*   Programa: Punteros a arreglos, matrices, estructuras y puntero a simples.
*   Fecha: 30/08/2017
*   Elaborado por: Alejandro Santibañez Sanchez
*/

//Librerias
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

//Estructuras
struct Alumno{
	char nombre[30];
	int edad;
	float promedio;
}alumno[3], *puntero_alumno = alumno;

struct Etapa{
	int horas, min, seg;
}etapa[3], *puntero_etapa = etapa;

//Prototipo funciones menus
void menu();
void arreglos();
void matrices();
void simples();
void estructuras();

//Funciones arreglos
void impresion();
void valores();
void arreglo4x4();

//Funciones matrices
void matriz3x3();
void matriz3x3Automatica();
void matriz3x3Primos();

//Funciones simples
void impar();
void primito();
void arregloPosicion();
void menorElemento();
void arregloDinamico();
void funcionArregloDinamico();
void vocales();
void cadenaCaracteres();
void sumaMatricesDinamicas();
void matrizDinamicaTraspuesta();
void alumno_promedio();
void tiempoCiclista();

//Funciones estructuas


//Funcion principal
int main(){

    menu();

    return 0;
}
//Menu principal
void menu(){
    int opcion;

    do{
		printf("|-----------------------------------|\n");
		printf("|           MENU PRINCIPAL          |\n");
		printf("|-----------------------------------|\n");
		printf("|                  |                |\n");
		printf("|  1. Arreglos     |  0. Salir      |\n");
		printf("|  2. Matrices     |                |\n");
		printf("|  3. Simples      |                |\n");
		printf("|  4. Estructuras  |                |\n");
		printf("|                  |                |\n");
		printf("|-----------------------------------|\n\n");
		printf("Ingrese su opcion: ");
		scanf("%d",&opcion);
		system("cls");

		switch(opcion){
		case 1: arreglos();
            break;
		case 2: matrices();
            break;
		case 3: simples();
            break;
		case 4: estructuras();
            break;
		case 0: exit(0);
            break;
		default: printf("\t\tNo es un opcion valida\n");
            break;
		}
		system("pause");
		system("cls");
	}while(opcion != 0);
}
//Menu arreglos
void arreglos(){
    int opcion;

    do{
        printf("|-----------------------------------|\n");
		printf("|             MENU ARREGLOS         |\n");
		printf("|-----------------------------------|\n");
		printf("|                            |      |\n");
		printf("|  1. Array de decimales     |      |\n");
		printf("|  2. Array de ceros y unos  |      |\n");
		printf("|  3. Array de 4x4           |      |\n");
		printf("|  0. Salir                  |      |\n");
		printf("|-----------------------------------|\n\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        system("cls");

        switch(opcion){
            case 1: impresion();
                break;
            case 2: valores();
                break;
            case 3: arreglo4x4();
                break;
            case 0: menu();
                break;
            default: printf("No es una opcion valida");
                break;
        }
        system("pause");
        system("cls");
    }while(opcion != 0);
}
//Funciones arreglos
void impresion(){
    float arreglito[4] = {32.583, 11.239, 45.781, 22.237};
    float *decimales = arreglito;

    for(int i = 0; i < 4; i++){
        printf("%0.2f\n", *(decimales + i));
    }
}

void valores(){
    int filas, columnas;
    int matriz[100][100];
    int *pmatriz = &matriz[0][0];

    printf("Ingrese el numero de filas: ");
    scanf("%d", &filas);
    printf("Ingrese el numero de columnas: ");
    scanf("%d", &columnas);

    for(int f = 0; f < filas; f++){
        for(int c = 0; c < columnas; c++){
            if(f == c){
                *(pmatriz + c + f * columnas) = 1;
            }else{
                *(pmatriz + c + f * columnas) = 0;
            }
        }
    }
    for(int f = 0; f < filas; f++){
        for(int c = 0; c < columnas; c++){
            printf("%d ",*(pmatriz + c + f * columnas));
        }
        printf("\n");
    }
}

void arreglo4x4(){
    //int numerito;
	int matriz[4][4];
	int *p_matriz = &matriz[0][0];
	int f, c;
	int acum=1;

	for(f = 0; f < 4; f++){
        printf("Ingrese un numero: ");
		scanf("%d", &(*(p_matriz + f *4)));
		acum = *(p_matriz + f * 4);
		for(c = 1; c < 4; c++){
			acum = acum * *(p_matriz + f *4);
			*(p_matriz + c + f  * 4) = acum;
		}
	}
	for(f = 0; f < 4; f++){
        for(c = 0; c < 4; c++){
            printf("%d   ", *p_matriz++);
		}
		printf("\n");
	}
}
//Menu matrices
void matrices(){
    int opcion;

    do{
        printf("|----------------------------------------|\n");
		printf("|             MENU MATRICES              |\n");
		printf("|----------------------------------------|\n");
		printf("|                                 |      |\n");
		printf("|  1. Matriz 3x3                  |      |\n");
		printf("|  2. Matriz 3x3 automatica       |      |\n");
		printf("|  3. Matriz 3x3 automatica primos|      |\n");
		printf("|  0. Salir                       |      |\n");
		printf("|----------------------------------------|\n\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        system("cls");

        switch(opcion){
            case 1: matriz3x3();
                break;
            case 2: matriz3x3Automatica();
                break;
            case 3: matriz3x3Primos();
                break;
            case 0: menu();
                break;
            default: printf("No es una opcion valida");
                break;
        }
        system("pause");
        system("cls");
    }while(opcion != 0);
}
//funciones matrices
void matriz3x3(){
    int matriz[3][3];
    int *pma = &matriz[0][0];
    int f = 3,c = 3;
    int suma = 0;

    for(f = 0; f < 3; f++){
        for(c = 0; c < 3; c++){
            printf("Ingrese un numero: ");
            scanf("%d", &(*(pma + c + f * 3)));
        }
    }
    for(f = 0; f < 3; f++){
        for(c = 0; c < 3; c++){
            suma = suma + *(pma + c + f * 3);
        }
    }
    for(f = 0; f < 3; f++){
        for(c = 0; c < 3; c++){
           printf("%d ", *(pma + c + f * 3));
        }
        printf("\n");
    }
    printf("La suma de los numeros de la matriz es: %d\n", suma);
}

void matriz3x3Automatica(){
    int matriz[3][3];
    int *pmatri = &matriz[0][0];
    int f, c;

    srand(time(0));

    for(f = 0; f < 3; f++){
        for(c = 0; c < 3; c++){
            *(pmatri + c + f * 3) = rand()%(20);
            printf("%d ", *(pmatri + c + f * 3));
        }
        printf("\n");
    }
}

void matriz3x3Primos(){
    int primos[3][3];
    int *pprimos = &primos[0][0];
    int filaprima = 0, columnaprima = 0;
    int numero;
    int i = 1, d = 0;

    printf("Ingrese un numero inicial: ");
    scanf("%d", &numero);

    while(filaprima < 3){
        while(true){
            if( numero % i == 0){
              d += 1;
            }
            if(d > 2){
                break;
            }
            if(i >= numero){
        		break;
        	}
            i += 1;
        }
        if(d == 2){
            *(pprimos + columnaprima + filaprima * 3) = numero;
            columnaprima += 1;
            if(columnaprima == 4){
                filaprima += 1;
                columnaprima = 0;
            }
        }
        numero += 1;
        i = 1;
        d = 0;
    }
    for(int i = 0; i < 3; i++){
	    for(int j = 0; j < 3; j++){
	        printf("%d \t", *(pprimos + j + i * 3));
	    }
	    printf("\n");
    }
}
//Menu simples
void simples(){
    int opcion;

    do{
        printf("|------------------------------------------------------------------|\n");
		printf("|                        MENU SIMPLES                              |\n");
		printf("|------------------------------------------------------------------|\n");
		printf("|                             |                                    |\n");
		printf("|  1. Numero par o impar      |  7.  Numero de vocales             |\n");
		printf("|  2. Numero primo o no       |  8.  Cadena de caracteres          |\n");
		printf("|  3. Relleno de un array     |  9.  Suma de dos matrices dinamicas|\n");
		printf("|  4. Arreglo con N numeros   |  10. Matriz traspuesta             |\n");
        printf("|  5. Arreglo dinamico        |  11. Estructura alumno             |\n");
		printf("|  6. Funcion arreglo dinamico|  12. Estructura cliclista          |\n");
		printf("|------------------------------------------------------------------|\n\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        system("cls");

        switch(opcion){
            case 1: impar();
                break;
            case 2: primito();
                break;
            case 3: arregloPosicion();
                break;
            case 4: menorElemento();
                break;
            case 5: arregloDinamico();
                break;
            case 6: funcionArregloDinamico();
                break;
            case 7: vocales();
                break;
            case 8: cadenaCaracteres();
                break;
            case 9: sumaMatricesDinamicas();
                break;
            case 10: matrizDinamicaTraspuesta();
                break;
            case 11: alumno_promedio();
                break;
            case 12: tiempoCiclista();
                break;
            case 0: menu();
                break;
            default: printf("No es una opcion valida");
                break;
        }
        system("pause");
        system("cls");
    }while(opcion != 0);
}
//Funciones punteros a estructuras simples
void impar(){
    int numero;
    int *pnumero = &numero;

    printf("Ingrese un numero: ");
    scanf("%d", &numero);

    if(*pnumero%2==0){
        printf("El numero %d es par\n", *pnumero);
    }else{
        printf("El numero %d es impar\n", *pnumero);
    }
    printf("La direccion de memoria del numero es: %p\n", pnumero);
}

void primito(){
    int num, conta = 0;
    int *pnum = &num;

	printf("Digite un numero: ");
	scanf("%d", &num);

	for(int i = 1;i < *pnum; i++){
		if(*pnum%i == 0){
			conta+=1;
		}
	}
	if(conta < 2){
        printf("El numero %d es primo\n", *pnum);
	}
	else{
		printf("El numero %d no es primo\n", *pnum);
	}
	printf("La direccion es: %p\n", pnum);
}

void arregloPosicion(){
    int numeros[10];
    int *parreglo;

    for(int i = 0; i < 10; i++){
        printf("Ingrese un numero: ");
        scanf("%d", &numeros[i]);
    }
    parreglo = numeros;

    for(int i = 0; i < 10; i++){
        if(*parreglo%2 == 0){
            printf("El numero %d es par\n", *parreglo);
            printf("Direccion de memoria: %p\n", parreglo);
        }
        parreglo++;
    }
}

void menorElemento(){
    int nElementos, valores[100], *pvalores, menor = 999999;

    printf("Ingrese el numero de valores del arreglo: ");
    scanf("%d", &nElementos);

    for(int i = 0; i < nElementos; i++){
        printf("Ingrese un numero en la posicion %d: ", i);
        scanf("%d", &valores[i]);
    }

    pvalores = valores;

    for(int i = 0; i < nElementos; i++){
        if(*pvalores < menor){
            menor = *pvalores;
        }
        *pvalores++;
    }
    printf("El menor elemento es: %d\n", menor);
}

void arregloDinamico(){
    int l, aux;
    int arreglo[100];
    int *parreglo = arreglo;

    printf("Ingrese la longitud del arreglo: ");
    scanf("%d", &l);

    for(int i = 0; i < l; i++){
        printf("Igrese un numero: ");
        scanf("%d", &(*(parreglo + i)));
    }
    for(int i = 0; i < l-1; i++){
        for(int j = i + 1; j < l; j++){
            if(*(parreglo + i) > *(parreglo + j)){
                aux = *(parreglo + i);
                *(parreglo + i) = *(parreglo + j);
                *(parreglo + j) = aux;
            }
        }
    }
    for(int i = 0; i < l; i++){
        printf("%d ", *(parreglo + i));
    }
    printf("\n");
}

void funcionArregloDinamico(){

}

void vocales(){
    char nombre[30];
    int vocales, cont = 0;
    char *pnombre = nombre;

    printf("Ingrese su nombre: ");
    scanf("%s", &nombre );

    strupr(nombre);

    while(*pnombre){
        switch(*pnombre){
            case  'A':
            case  'E':
            case  'I':
            case  'O':
            case  'U': cont+=1;
        }
        pnombre+=1;
    }
    printf("El numero de vocales es: %d\n", cont);
}

void cadenaCaracteres(){

}

void sumaMatricesDinamicas(){
    int filas, columnas;
    int matriz1[100][100], matriz2[100][100],matriz3[100][100];
    int *pmatriz1 = &matriz1[0][0], *pmatriz2 = &matriz2[0][0], *pmatriz3 = &matriz3[0][0];

    printf("Ingrese el numero de filas: ");
    scanf("%d", &filas);
    printf("Ingrese el numero de columnas: ");
    scanf("%d", &columnas);

    printf("Matriz1\n\n");//llenar matriz 1
    for(int f = 0; f < filas; f++){
        for(int c = 0; c < columnas; c++){
            printf("Ingrese un numero: ");
            scanf("%d", &(*(pmatriz1 + c + f * columnas)));
        }
    }

    printf("Matriz2\n\n");//llenar matriz 2
    for(int f = 0; f < filas; f++){
        for(int c = 0; c < columnas; c++){
            printf("Ingrese un numero: ");
            scanf("%d", &(*(pmatriz2 + c + f * columnas)));
        }
    }

    //Suma de matrices
    for(int f = 0; f < filas; f++){
        for(int c = 0; c < columnas; c++){
            *(pmatriz3 + c + f * columnas) = *(pmatriz1 + c + f * columnas) + *(pmatriz2 + c + f * columnas);
        }
    }

    //Impresion matriz3
    for(int f = 0; f < filas; f++){
        for(int c = 0; c < columnas; c++){
            printf("%d ", *(pmatriz3 + c + f * columnas));
        }
        printf("\n");
    }
}

void matrizDinamicaTraspuesta(){
    int filas, columnas;
    int numero[100][100];
    int *pnumero = &numero[0][0];

    printf("Ingrese el numero de filas: ");
    scanf("%d", &filas);
    printf("Ingrese el numero de columnas: ");
    scanf("%d", &columnas);
    //Llenar matriz
    for(int f = 0; f < filas; f++){
        for(int c = 0; c < columnas; c++){
            printf("Ingrese un numero: ");
            scanf("%d", &(*(pnumero + c + f * columnas)));
        }
    }
    //Mostrar matriz original
    printf("\nMatriz Original\n");
    for(int f = 0; f < filas; f++){
        for(int c = 0; c < columnas; c++){
            printf("%d ", *(pnumero + c + f * columnas));
        }
        printf("\n");
    }
    //Matriz traspuesta
    printf("\nMatriz Traspuesta\n");
    for(int f = 0; f < filas; f++){
        for(int c = 0; c < columnas; c++){
            printf("%d ",*(pnumero + f + c * filas));
        }
        printf("\n");
    }
}

void alumno_promedio(){
    float mayor = 0.0;
	int posicion = 0;

	for(int i = 0; i < 3; i++){
		printf("\n\tIngrese Datos Del Estudiante\n");
		fflush(stdin);
		printf("\nIngrese Nombre Del Estudiante: ");
		fgets((puntero_alumno + i) -> nombre, 30, stdin);
		printf("Ingrese La Edad: ");
		scanf("%d", &((puntero_alumno + i) -> edad));
		printf("Ingrese El Promedio: ");
		scanf("%f", &((puntero_alumno + i) -> promedio));
		fflush(stdin);
	}

	for(int i = 0; i < 3; i++){
		if((puntero_alumno + i) -> promedio > mayor){
			mayor = (puntero_alumno + i) -> promedio;
			posicion = i;
		}
	}

	printf("\n\tAlumno Con El Mejor Promedio\n");
	printf("\nNombre: %s", ((puntero_alumno + posicion) -> nombre));
	printf("Edad: %d\n", ((puntero_alumno + posicion) -> edad));
	printf("Promedio: %0.1f", ((puntero_alumno + posicion) -> promedio));
}

void tiempoCiclista(){
    int horasT = 0, minutosT = 0, segundosT = 0;

	printf("\tDigite Los Tiempos Empleados: \n");
	for(int i = 0; i < 3; i++){
		printf("\nHoras: "),
		scanf("%d", &((puntero_etapa + i) -> horas));
		printf("Minutos: ");
		scanf("%d", &((puntero_etapa + i) -> min));
		printf("Segundos: ");
		scanf("%d", &((puntero_etapa + i) -> seg));
		printf("\n");
	}

	for(int i = 0; i < 3; i++){
		horasT += (puntero_etapa + i) -> horas;
		minutosT += (puntero_etapa + i) -> min;
		if(minutosT >= 60){
			minutosT -= 60;
			horasT++;
		}
		segundosT += (puntero_etapa + i) -> seg;
		if(segundosT >= 60){
			segundosT -= 60;
			minutosT++;
		}
	}

	printf("\n\tEl Tiempo Total Es\n");
	printf("\nHoras: %d", horasT);
	printf("\nMinutos: %d", minutosT);
	printf("\nSegundos: %d", segundosT);
}
//Estructuras
void estructuras(){
    int opcion;

    do{
        printf("|----------------------------------------|\n");
		printf("|             MENU MATRICES              |\n");
		printf("|----------------------------------------|\n");
		printf("|                  |                     |\n");
		printf("|  1. Competidor   |   5. promedio dos   |\n");
		printf("|  2. Estudiante   |   6. Discapacidad   |\n");
		printf("|  3. Trabajadores |                     |\n");
		printf("|  4. Promedio     |                     |\n");
		printf("|----------------------------------------|\n\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        system("cls");

        switch(opcion){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 0: menu();
                break;
            default: printf("No es una opcion valida");
                break;
        }
        system("pause");
        system("cls");
    }while(opcion != 0);
}
