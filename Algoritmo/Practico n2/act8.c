#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CANT_VALORES 200

/*
 * Se que deberia escanear el resultado y todo pero...
 * no es mejor simplemente verlo llenarse solo y ya?
*/

int main() {
    srand((unsigned int)time(NULL));  // Seed
    int V[CANT_VALORES] = {0};
    int VP2[CANT_VALORES] = {0};

    // Populate array
    for (size_t i = 0; i < CANT_VALORES; i++) {
        V[i] = rand() % 200;         // random number between 0 and 200
        VP2[i] = (int)pow(V[i], 2);  // high number generate overflow, hence negative values
    }

    for (int k = 0; k < CANT_VALORES; k++)
        printf("\nV[%d]:\t%d^2\t= %d", k + 1, V[k], VP2[k]);

    system("pause");
    return 0;
}
