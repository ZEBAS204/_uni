#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <time.h>
#define MAX_BUFFER 1024  // Magic num
#define CANT_VALORES 50
#define CLOCKS_PER_SEC ((clock_t)1000)

void cargarVector(int V[CANT_VALORES]) {
    int valor = 0;

    for (int i = 0; i < CANT_VALORES; i++) {
        printf("Valor n%d: ", i + 1);
        scanf("%d", &valor);
        V[i] = valor;
    }
}

int main() {
    char buff[BUFSIZ];
    int Vector[CANT_VALORES] = {0};
    char *arr[CANT_VALORES] = {NULL};
    char **numMatches = arr;

    printf("Cargar vector con %d valores:\n", CANT_VALORES);
    cargarVector(Vector);

    printf("\n[ INGRESE \"-1\" (menos uno) PARA FINALIZAR ]");
    while (1) {
        int num = 0;
        int wasFound = 0;

        printf("\nIngrese un numero a buscar: ");
        scanf("%d", &num);

        if (num == -1) break;

        for (int i = 0; i < CANT_VALORES; i++) {
            if (wasFound) break;

            // clock_t begin = clock();
            if (num == Vector[i]) {
                wasFound = 1;

                int duplicates = 1;
                int locations[CANT_VALORES] = {-1};
                locations[0] = i;
                for (int d = i + 1; d < CANT_VALORES; d++) {
                    if (Vector[d] == num) {
                        locations[duplicates] = d;
                        duplicates++;
                    }
                }

                for (int k = 0; k < duplicates; k++) {
                    const int locIndex = locations[k];

                    if (numMatches[locIndex] == NULL) {
                        printf("\nSe encontro el numero '%d' en la posicion %d", num, locIndex + 1);
                        numMatches[locIndex] = "SI";
                    } else
                        printf("\nYa se encontro anteriormente. %d : %s", locIndex + 1, numMatches[locIndex]);
                }

                // clock_t end = clock();
                // printf("\nTook %f seconds to iterate over.\n", (double)(end - begin) / CLOCKS_PER_SEC);
            }
        }
        if (wasFound == 0)
            printf("\nNo se encontro el numero indicado.");
    }

    system("pause");
    return 0;
}
