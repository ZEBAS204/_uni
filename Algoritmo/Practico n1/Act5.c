/*
* ACTIVIDAD N5:
*  Se debera desarrollar un algoritmo que permita hacer un bucle en el
* que el contador(cont) vaya incrementando su valor de dos en dos.
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void sig_handler(int signum) {
    exit(0);
}

int main() {
    int cont = 0;

    // CTRL+C -> exit()
    signal(SIGINT, sig_handler);
    while (1) {
        sleep(0);
        cont += 2;
        printf("%d\n", cont);
    }

    return 0;
}
