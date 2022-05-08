/*
* ACTIVIDAD N3:
*  Desarrollar un algoritmo que me permita ingresar tres numeros por teclado y
* determinar cual de ellos es el mayor.
* Por ultimo calcular el promedio de ellos y mostrarlo por pantalla.
*/

#include <stdio.h>
// #define _CRT_SECURE_NO_WARNINGS

int bigNumOfTwo(int x, int y) {
    return x < y ? y : x;
}

int bigNumOfThree(int x, int y, int z) {
    return bigNumOfTwo(z, bigNumOfTwo(x, y));
}

int main() {
    int val1, val2, val3;
    printf("Ingrese val1: ");
    scanf("%d", &val1);
    printf("Ingrese val2: ");
    scanf("%d", &val2);
    printf("Ingrese val3: ");
    scanf("%d", &val3);

    printf("\nEl numero mayor es: %d\n", bigNumOfThree(val1, val2, val3));

    return 0;
}
