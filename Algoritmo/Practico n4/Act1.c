#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define NOTA_MIN_APROVADO 4

struct Alumnos {
    char nombre[30];
    char apellido[30];
    int legajo;
    char sexo[30];
    float notaP1;
    float notaP2;
};

void showMenu(struct Alumnos* alumno, int cantAlumnos);
void agregarAlumno(struct Alumnos* alumno, int i);
void modificarAlumno(struct Alumnos* alumno, int i);
void mostraAlumno(struct Alumnos* alumno, int i);
void mostrarAlumnos(struct Alumnos* alumno, int cantAlumnos);
void mostrarMayorPromedio(struct Alumnos* alumno, int cantAlumnos);
void mostrarTresMayorPromedios(struct Alumnos* alumno, int cantAlumnos);
void mostrarReprobados(struct Alumnos* alumno, int cantAlumnos);
void findLegajo(struct Alumnos* alumno, int cantAlumnos);
void bobTheBuilder(struct Alumnos* xp, struct Alumnos* yp);
void sortArray(struct Alumnos* alumno, int cantAlumnos);

int main() {
    fflush(stdin);
    struct Alumnos* alumno;
    int cantAlumnos = 0;

    // Pedir la cantidad de alumnos a ingresar
    printf("\nIngresar el numero de alumnos: ");
    scanf("%i", &cantAlumnos);
    fflush(stdin);

    // Alocar memoria para n cantidad de struct Alumnos
    alumno = (struct Alumnos*)malloc(cantAlumnos * sizeof(struct Alumnos));

    if (alumno == NULL) {
        puts("Sin memoria!\n");
        exit(1);
    }

    for (int i = 0; i < cantAlumnos; i++)
        agregarAlumno(alumno, i);

    showMenu(alumno, cantAlumnos);

    getchar();
    return 0;
}

/**
 * @brief Agrega un alumno a memoria de la estructura de Alumnos
 *
 * @param alumno Estructura de Alumnos
 * @param i Indice del alumno a agregar (si existe sera sobreescrito)
 */
void agregarAlumno(struct Alumnos* alumno, int i) {
    /* Se pueden usar como:
     * &(*(alumno+i).nombre)
     * &(alumno[i].nombre)
    */

    printf("\n[Enter para confirmar]\n");
    printf("\nCreando nuevo alumno N%d\n", i + 1);

    printf("Ingresar el numero de legajo del alumno: ");
    scanf("%i", &(alumno[i].legajo));
    fflush(stdin);

    printf("Ingresar nombre del alumno: ");
    scanf("%s", &(alumno[i].nombre));
    fflush(stdin);

    printf("Ingresar apellido del alumno: ");
    scanf("%s", &(alumno[i].apellido));
    fflush(stdin);

    printf("Ingresar sexo del alumno (Masculino/Femenino): ");
    scanf("%s", &(alumno[i].sexo));
    fflush(stdin);

    printf("Ingresar notas del alumno:\n* 1 parcial: ");
    scanf("%f", &(alumno[i].notaP1));
    fflush(stdin);
    printf("* 2 parcial: ");
    scanf("%f", &(alumno[i].notaP2));
    fflush(stdin);
}

/**
 * @brief Muestra el alumno registrado de acuerdo al indice provisto
 *
 * @param alumno Estructura de Alumnos
 * @param i Indice del alumno en la estructura
 */
void mostraAlumno(struct Alumnos* alumno, int i) {
    printf("\nLegajo: %i", alumno[i].legajo);
    printf("\nNombre: %s", alumno[i].nombre);
    printf("\nApellido: %s", alumno[i].apellido);
    printf("\nSexo: %s", alumno[i].sexo);
    printf("\nNotas:\n\t* Parcial 1: %.2f", alumno[i].notaP1);
    printf("\n\t* Parcial 2: %.2f\n", alumno[i].notaP2);
}

/**
 * @brief Muestra todos los alumnos registrados
 *
 * @param alumno Estructura de Alumnos
 * @param cantAlumnos Cantidad total de alumnos
 */
void mostrarAlumnos(struct Alumnos* alumno, int cantAlumnos) {
    printf("\nAlumnos:");
    for (int i = 0; i < cantAlumnos; ++i) {
        printf("\n---------------");
        mostraAlumno(alumno, i);
    }
}

void mostrarMayorPromedio(struct Alumnos* alumno, int cantAlumnos) {
    int max = -1;
    float maxPromedio = 0;

    for (int j = 0; j < cantAlumnos - 1; j++) {
        if (max == -1) {
            max = j;
            maxPromedio = (alumno[max].notaP1 + alumno[max].notaP2) / 2;
        }
        else {
            float nextPromedio = (alumno[max + 1].notaP1 + alumno[max + 1].notaP2) / 2;

            if (nextPromedio > maxPromedio) {
                maxPromedio = nextPromedio;
                max = j + 1;
            }
        }
    }

    if (max == -1) return;

    printf("\nLegajo: %i\t", alumno[max].legajo);
    printf("Promedio: %.2f", (alumno[max].notaP1 + alumno[max].notaP2) / 2);
}

void mostrarTresMayorPromedios(struct Alumnos* alumno, int cantAlumnos) {
    for (int i = 0; i < cantAlumnos - 1; i++) {
        for (int j = 0; j < cantAlumnos - i - 1; j++) {
            float pro = (alumno[j].notaP1 + alumno[j].notaP2) / 2;
            float nextPro = (alumno[j + 1].notaP1 + alumno[j + 1].notaP2) / 2;

            if (pro > nextPro)
                bobTheBuilder(&alumno[j], &alumno[j + 1]);
        }
    }

    for (int k = 0; k < 3; k++) {
            printf("\nLegajo: %i\t", alumno[k].legajo);
            printf("Promedio: %.2f", (alumno[k].notaP1 + alumno[k].notaP2) / 2);
    }
}

/**
 * @brief Busca y devuelve el todos los reprobados en el primer parcial
 *
 * @param alumno Pointer: estructura de Alumnos
 * @param cantAlumnos Cantidad total de alumnos
 */
void mostrarReprobados(struct Alumnos* alumno, int cantAlumnos) {
    int cantReporbados = 0;

    for (int i = 0; i < cantAlumnos; i++) {
        if (alumno[i].notaP1 < NOTA_MIN_APROVADO)
            cantReporbados++;
    }
    printf("Cantidad total de alumnos reprobados primer parcial: %d", cantReporbados);
}


void findLegajo(struct Alumnos* alumno, int cantAlumnos) {
    printf("\n[ INGRESE 0 PARA SALIR ]\n");

    while (1) {
        bool found = false;
        int legajo;

        printf("Ingrese el legajo del alumno para modificar: ");
        scanf("%d", &legajo);

        if (legajo == 0) break;

        // Verificamos que el alumno existe
        for (int i = 0; i < cantAlumnos; i++) {
            if (legajo == alumno[i].legajo) {
                found = true;
                printf("Se ha encontrado el alumno!\n");
                modificarAlumno(alumno, i);
            }
        }
        if (found) break;
        else printf("\nNingun alumno coincide con ese legajo. Intentelo de nuevo.\n");
    }
}

void bobTheBuilder(struct Alumnos* xp, struct Alumnos* yp) {
    struct Alumnos temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void sortArray(struct Alumnos* alumno, int cantAlumnos) {
    // Bubble sort
    for (int i = 0; i < cantAlumnos - 1; i++)
        for (int j = 0; j < cantAlumnos - i - 1; j++)
            if (alumno[j].legajo > alumno[j + 1].legajo)
                bobTheBuilder(&alumno[j], &alumno[j + 1]); // macumba
}

void showMenu(struct Alumnos* alumno, int cantAlumnos) {
    bool running = true;

    while (running) {
        fflush(stdin);
        printf("\n-------------------------------------------");
        printf("\n  0: SALIR DEL PROGRAMA");
        printf("\n  1: MOSTRAR ALUMNOS");
        printf("\n  2: VER O MODIFICAR ALUMNO SEGUN LEGAJO");
        printf("\n  3: ORDENAR ARRAY SEGUN LEGAJO");
        printf("\n  4: FILTRAR ALUMNOS SEGUN SEXO");
        printf("\n  5: MOSTRAR ALUMNOS REPROBADOS");
        printf("\n  6: MOSTRAR ALUMNO DE MAYOR PROMEDIO");
        printf("\n  7: MOSTRAR 3 ALUMNOS DE MAYOR PROMEDIO");
        printf("\n  8: LIMPIAR CONSOLA");
        printf("\n-------------------------------------------\n");
        printf("Ingrese accion a realizar: ");
        int busqueda = NULL;
        scanf("%i", &busqueda);

        switch (busqueda) {
        case 0:
            running = !running;
            break;
        case 1:
            mostrarAlumnos(alumno, cantAlumnos);
            break;
        case 2:
            findLegajo(alumno, cantAlumnos);
            break;
        case 3:
            sortArray(alumno, cantAlumnos);
            printf("Se han ordenado los alumnos!\n");
            break;
        case 4:; // C hack
            // Imaginemos que es c++ y podemos usar funciones dentro de otras
            int hombres = 0;
            int mujeres = 0;
            for (int j = 0; j < cantAlumnos; j++) {
                char temp = tolower(alumno[j].sexo[0]);
                if (temp == 'm') hombres++;
                if (temp == 'f') mujeres++;
            }
            printf("Alumnos:\n Varones: %i\n Mujeres: %i", hombres, mujeres);
            break;
        case 5:
            mostrarReprobados(alumno, cantAlumnos);
            printf("\n");
            break;
        case 6:
            mostrarMayorPromedio(alumno, cantAlumnos);
            break;
        case 7:
            mostrarTresMayorPromedios(alumno, cantAlumnos);
            break;
        case 8:
            system("@cls||clear"); // can fail
            break;
        default:
            printf("\nNo se ha encontrado ese resultado.\nPor favor, intentelo de nuevo.\n");
        }
    }
}

/**
 * @brief Permite modificar un alumno
 *
 * @param alumno Estructura de Alumnos
 * @param i Indice de alumno
 */
void modificarAlumno(struct Alumnos* alumno, int i) {
    bool running = true;

    while (running) {
        system("@cls||clear"); // can fail
        fflush(stdin);
        mostraAlumno(alumno, i);
        printf("\n----------------------------------------------------");
        printf("\n  0: SALIR");
        printf("\n  1: CAMBIAR NOMBRE");
        printf("\n  2: CAMBIAR APELLIDO");
        printf("\n  3: CAMBIAR SEXO");
        printf("\n  4: CAMBIAR NOTA PARCIAL 1");
        printf("\n  5: CAMBIAR NOTA PARCIAL 2");
        printf("\n----------------------------------------------------\n");
        printf("Ingrese accion a realizar: ");
        int busqueda = NULL;
        scanf("%i", &busqueda);
        fflush(stdin);

        switch (busqueda) {
        case 0:
            running = !running;
            break;
        case 1:
            printf("Ingrese el nuevo nombre: ");
            scanf("%s", &(alumno[i].nombre));
            break;
        case 2:
            printf("Ingrese el nuevo apellido: ");
            scanf("%s", &(alumno[i].apellido));
            break;
        case 3:
            printf("Ingrese el nuevo sexo: ");
            scanf("%s", &(alumno[i].sexo));
            break;
        case 4:
            printf("Ingrese la nueva nota Parcial 1: ");
            scanf("%f", &(alumno[i].notaP1));
            break;
        case 5:
            printf("Ingrese la nueva nota Parcial 2: ");
            scanf("%f", &(alumno[i].notaP2));
            break;
        default:
            printf("\nNo se ha encontrado ese resultado.\nPor favor, intentelo de nuevo.\n");
        }
    }
}
