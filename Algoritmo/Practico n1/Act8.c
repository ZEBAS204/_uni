/*
* ACTIVIDAD N8:
*  Escribe un programa en C que, al recibir como datos N numeros enteros,
* obtenga solamente la suma de los numeros positivos ingresados.
*/

#include <stdio.h>

int main() {
    int sumEnteros = 0;
    int scanNum = 0;

    printf("Suma todos los numeros enteros positivos.\nIngrese de numero 0 (cero) para finalizar la suma.\n");

    while (1) {
        printf("Numero a sumar: ");
        scanf("%d", &scanNum);

        if (scanNum == 0)
            break;
        if (scanNum > 0)
            sumEnteros += scanNum;
    }

    printf("\nLa suma total es de %d.\n", sumEnteros);

    return 0;
}
