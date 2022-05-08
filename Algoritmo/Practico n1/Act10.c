/*
* ACTIVIDAD N10:
*  Construye un programa en C que, al recibir como datos un grupo de numeros
* naturales positivos, calcule el cuadrado de estos numeros y al final la suma
* de los cuadrados. El programa terminará cuando se ingrese un 0.
* Imprimir por pantalla el resultado de la suma de todos los cuadrados
*/

#include <stdio.h>

int main() {
    int _sumNum = 0;
    int scanNum = 0;

    printf("Suma todos los numeros enteros positivos y retorna su cuadrado.");
    printf("\nIngrese de numero 0 (cero) para finalizar la suma.\n");

    while (1) {
        printf("Nuevo numero: ");
        scanf("%d", &scanNum);

        if (scanNum == 0)
            break;
        if (scanNum > 0) {
            int numCuad = scanNum * scanNum;
            _sumNum += numCuad;
            printf("El cuadrado del numero %d es %d\n", scanNum, numCuad);
        }
    }

    printf("\nLa suma total de los cuadrados es %d.\n", _sumNum);

    return 0;
}
