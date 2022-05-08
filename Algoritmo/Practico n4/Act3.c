#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


struct Empleado {
    int legajo;
    char nombre[30];
    char apellido[30];
    char cargo[30];
    char sexo[30];
    float salario;
    int antiguedad;
};

void showMenu(struct Empleado* alumno, int cantAlumnos);
void agregarEmpleado(struct Empleado* empleado, int i);
void mostraEmpleado(struct Empleado* empleado, int i);
void mostrarEmpleados(struct Empleado* empleado, int cantEmpleados);
void findByWorkPosition(struct Empleado* empleado, int cantEmpleados);
void findByLegajo(struct Empleado* empleado, int cantEmpleados);
void sortArray(struct Empleado* alumno, int cantAlumnos);
void bobTheBuilder(struct Empleado* xp, struct Empleado* yp);
bool compare(char a[], char b[]);

bool compare(char a[], char b[]) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) return true;
        i++;
    }
    return false;
}

int main() {
    fflush(stdin);
    struct Empleado* empleado;
    int cantEmpleados = 0;

    // Pedir la cantidad de alumnos a ingresar
    printf("\nIngresar el numero de empleados: ");
    scanf("%i", &cantEmpleados);
    fflush(stdin);

    // Alocar memoria para n cantidad de struct Alumnos
    empleado = (struct Empleado*)malloc(cantEmpleados * sizeof(struct Empleado));

    if (empleado == NULL) {
        puts("Sin memoria!\n");
        exit(1);
    }

    for (int i = 0; i < cantEmpleados; i++)
        agregarEmpleado(empleado, i);

    showMenu(empleado, cantEmpleados);

    getchar();
    return 0;
}

void agregarEmpleado(struct Empleado* empleado, int i) {
    printf("\n[Enter para confirmar]\n");
    printf("\nCreando nuevo empleado N%d\n", i + 1);

    printf("Ingresar el numero de legajo del empleado: ");
    scanf("%i", &(empleado[i].legajo));
    fflush(stdin);

    printf("Ingresar nombre del empleado: ");
    scanf("%30s", &(empleado[i].nombre));
    fflush(stdin);

    printf("Ingresar apellido del empleado: ");
    scanf("%30s", &(empleado[i].apellido));
    fflush(stdin);

    printf("Ingresar cargo del empleado: ");
    scanf("%30s", &(empleado[i].cargo));
    fflush(stdin);

    printf("Ingresar sexo del empleado: ");
    scanf("%30s", &(empleado[i].sexo));
    fflush(stdin);

    printf("Ingresar el salario del empleado: $");
    scanf("%f", &(empleado[i].salario));
    fflush(stdin);

    printf("Ingresar el numero de anos de antiguedad del empleado: ");
    scanf("%i", &(empleado[i].antiguedad));
    fflush(stdin);
}

void mostraEmpleado(struct Empleado* empleado, int i) {
    printf("\nLegajo: %i", empleado[i].legajo);
    printf("\nNombre: %s", empleado[i].nombre);
    printf("\nApellido: %s", empleado[i].apellido);
    printf("\nCargo: %s", empleado[i].cargo);
    printf("\nSalario: $%.2f", empleado[i].salario);
    printf("\nSexo: %s", empleado[i].sexo);
    printf("\nAntiguedad: %i anos", empleado[i].antiguedad);
}

void mostrarEmpleados(struct Empleado* empleado, int cantEmpleados) {
    printf("\nEmpleados (%d):", cantEmpleados);
    for (int i = 0; i < cantEmpleados; ++i) {
        printf("\n---------------");
        mostraEmpleado(empleado, i);
    }
}

void findByWorkPosition(struct Empleado* empleado, int cantEmpleados) {
    printf("\n[ INGRESE 0 PARA SALIR ]\n");

    while (1) {
        bool found = false;
        char puesto[30];

        printf("Ingrese el puesto del empleado a buscar: ");
        scanf("%30s", puesto);
        fflush(stdin);

        if (puesto[0] == '0') break;

        // Verificamos que el alumno existe
        for (int i = 0; i < cantEmpleados; i++) {
            if (!compare(puesto, empleado[i].cargo)) {
                if (!found) found = true;
                printf("Empleados encontrados con el puesto de \"%s\":", puesto);
                printf("\n------");
                mostraEmpleado(empleado, i);
            }
        }
        if (found) break;
        else printf("\nNingun empleado coincide con ese puesto. Intentelo de nuevo.\n");
    }
}

void bobTheBuilder(struct Empleado* xp, struct Empleado* yp) {
    struct Empleado temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void static sortArray(struct Empleado* empleado, int cantEmpleados) {
    bool static wasSorted = false; // static, prevent re-sorting the struct
    if (wasSorted)
        return;

    printf("\nSorting...\n");

    for (int i = 0; i < cantEmpleados - 1; i++)
        for (int j = 0; j < cantEmpleados - i - 1; j++)
            if (empleado[j].legajo > empleado[j + 1].legajo)
                bobTheBuilder(&empleado[j], &empleado[j + 1]);

    wasSorted = true;
}

void findByLegajo(struct Empleado* empleado, int cantEmpleados) {
    printf("\n[ INGRESE 0 PARA SALIR ]\n");

    sortArray(empleado, cantEmpleados);

    while (1) {
        bool found = false;
        int legajo;
        int first = 0;
        int last = cantEmpleados - 1;
        int middle = (first + last) / 2;

        printf("Ingrese el puesto del empleado a buscar: ");
        scanf("%i", &legajo);

        if (legajo == 0) break;

        while (first <= last) {
            if (empleado[middle].legajo < legajo)
                first = middle + 1;
            else if (empleado[middle].legajo == legajo) {
                found = true;
                printf("Se ha encontrado el empleado!\n");
                mostraEmpleado(empleado, middle + 1);
                break;
            }
            else
                last = middle - 1;

            middle = (first + last) / 2;
        }
        if (found) break;
        else printf("\nNingun empleado coincide con ese legajo. Intentelo de nuevo.\n");
    }
}

void showMenu(struct Empleado* empleado, int cantEmpleados) {
    bool running = true;

    while (running) {
        fflush(stdin);
        printf("\n-------------------------------------------");
        printf("\n  0: SALIR DEL PROGRAMA");
        printf("\n  1: MOSTRAR EMPLEADOS");
        printf("\n  2: MOSTRAR EMPLEADOS SEGUN CARGO");
        printf("\n  3: MOSTRAR TOTAL PAGADO A EMPLEADOS");
        printf("\n  4: BUSCAR EMPLEADO SEGUN LEGAJO");
        printf("\n  5: LIMPIAR CONSOLA");
        printf("\n-------------------------------------------\n");
        printf("Ingrese accion a realizar: ");
        int busqueda = NULL;
        scanf("%i", &busqueda);
        fflush(stdin);

        switch (busqueda) {
        case 0:
            running = !running;
            break;
        case 1:
            mostrarEmpleados(empleado, cantEmpleados);
            break;
        case 2:
            findByWorkPosition(empleado, cantEmpleados);
            break;
        case 3:;
            float pagado = 0;
            for (int i = 0; i < cantEmpleados; i++)
                pagado = pagado + empleado[i].salario;
            printf("\nSalario total pagado de empleados: $%.2f\n", pagado);
            break;
        case 4:
            findByLegajo(empleado, cantEmpleados);
            break;
        case 5:
            system("@cls||clear"); // can fail
            break;
        default:
            printf("\nNo se ha encontrado ese resultado.\nPor favor, intentelo de nuevo.\n");
        }
    }
}
