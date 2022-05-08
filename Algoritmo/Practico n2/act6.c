#include <stdio.h>
#include <stdlib.h>
#define CANT_VALORES 100

int main() {
    int notas[CANT_VALORES] = {0};
    float promedio = 0;

    printf("Ingrese %d valores para el vector:\n", CANT_VALORES);

    for (int i = 0; i < CANT_VALORES; i++) {
        int nota = 0;

        while (1) {
            printf("Valor n%d: ", i + 1);
            scanf("%d", &nota);

            if (nota > 0) {
                promedio += (float)nota;
                notas[i] = nota;
                break;
            } else
                printf("\nEl valor debe ser mayor a 0 (cero).\nIntentelo de nuevo. ");
        }
    }

    promedio = promedio / CANT_VALORES;

    int mayoresAlPromedio = 0;
    printf("\nNotas mayores al promedio:\n");
    for (int k = 0; k < CANT_VALORES; k++) {
        if (notas[k] > promedio) {
            mayoresAlPromedio++;
            printf("%d%s", notas[k], mayoresAlPromedio % 10 == 0 ? "\n" : "\t");
        }
    }
    printf("\nLas notas mayores al promedio son: %d\n", mayoresAlPromedio);

    system("pause");
    return 0;
}
