#include <stdio.h>
#include <stdlib.h>
#define CANT_NOTAS 30

int main() {
    int notas[CANT_NOTAS] = {0};
    int mejorPeorNota[] = {10, 0};  // peor, mejor

    printf("Ingrese las notas para los %d alumnos:\n", CANT_NOTAS);

    for (int i = 0; i < CANT_NOTAS; i++) {
        int nota = 0;

        while (1) {
            printf("Nota n%d: ", i + 1);
            scanf("%d", &nota);

            if (nota <= 10 && nota >= 0) {
                if (mejorPeorNota[0] > nota) mejorPeorNota[0] = nota;
                if (mejorPeorNota[1] < nota) mejorPeorNota[1] = nota;
                notas[i] = nota;
                break;
            } else
                printf("\nLa nota debe ser entre 0 (cero) y 10 (diez).\nIntentelo de nuevo. ");
        }
    }

    int aprobados = 0;
    for (int j = 0; j < CANT_NOTAS; j++)
        if (!(notas[j] < 4)) aprobados++;

    float promedio = 0;
    for (int k = 0; k < CANT_NOTAS; k++) promedio += notas[k];

    printf("\nAlumnos aprobados: %d\nAlumnos desaprobados: %d", aprobados, CANT_NOTAS - aprobados);
    printf("\nLa mejor nota es: %d\nLa peor nota es: %d", mejorPeorNota[1], mejorPeorNota[0]);
    printf("\nPromedio general: %.2f", promedio / CANT_NOTAS);

    system("pause");
    return 0;
}
