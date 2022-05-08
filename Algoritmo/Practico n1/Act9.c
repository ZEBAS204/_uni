/*
* ACTIVIDAD N9:
*  Escribe un programa en C que, al recibir como datos los pagos efectuados
* en el ultimo mes, permite obtener la suma de los mismos. El programa terminara
* cuando se ingrese un pago=0. Imprimir por pantalla el resultado de la suma.
*/

#include <stdio.h>

int main() {
    int sumPagos = 0;
    int scanNum = 0;

    printf("Suma todos los pagos del ultimo mes.\nAgrege pago de 0 (cero) para finalizar la suma.\n");

    while (1) {
        printf("Pago: $");
        scanf("%d", &scanNum);

        if (scanNum == 0)
            break;

        sumPagos += scanNum;
    }

    printf("\nLa suma total es de %d$.\n", sumPagos);

    return 0;
}
