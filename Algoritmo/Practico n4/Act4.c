#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ServicioHuesped {
    bool pensionCompleta;
    bool pensionMedia;
    bool soloDesayuno;
    bool soloHabitacion;
};

struct CiudadesHuesped {
    // Supongamos que solo pueden ser de tres: (Córdoba - La Rioja - San Luis)
    bool cordoba;
    bool laRioja;
    bool sanLuis;
};

struct Huespedes {
    char nombre[30];
    char apellido[30];
    int id; // ID del huesped
    int cantidad; // Cantidad de dias que se va a hospedar el huesped
    float importe; // Monto que paga el huesped
    // Objetos en C? No, aca utilizamos structuras
    struct ServicioHuesped servicio; // Tipo de Servicio del huesped
    struct CiudadesHuesped ciudad; // Ciudad de residencia del huesped
};


void agregarHuesped(struct Huespedes* huesped, int i);
int filtrarCiudad(struct Huespedes* huesped, int cantHuespedes, int ciudad);
void showGuests(struct Huespedes* huesped, int cantHuespedes);
float pensionCompletaPorCiudad(struct Huespedes* huesped, int cantHuespedes, int ciudad);

int main() {
    fflush(stdin);
    struct Huespedes* huesped;
    int cantHuespedes = 0;

    printf("\nIngresar el numero de huespes del hotel: ");
    scanf("%i", &cantHuespedes);
    fflush(stdin);

    // Alocar memoria para n cantidad de struct Huespedes
    huesped = (struct Huespedes*)malloc(cantHuespedes * sizeof(struct Huespedes));

    if (huesped == NULL) {
        puts("Sin memoria!\n");
        exit(1);
    }

    for (int i = 0; i < cantHuespedes; i++)
        agregarHuesped(huesped, i);

    showGuests(huesped, cantHuespedes);

    printf(
        "\n\nEl importe total de los huespedes de residencia\ncordobesa suman un total de $%.2f diarios\n\n",
        pensionCompletaPorCiudad(huesped, cantHuespedes, 1)
    );

    system("pause");
    return 0;
}

void showGuests(struct Huespedes* huesped, int cantHuespedes) {
    printf("\nHuespedes por ciudad registrados:");
    printf("\nCordoba: %d", filtrarCiudad(huesped, cantHuespedes, 1));
    printf("\nLa Rioja: %d", filtrarCiudad(huesped, cantHuespedes, 2));
    printf("\nSan Luis: %d", filtrarCiudad(huesped, cantHuespedes, 3));
}

void agregarHuesped(struct Huespedes* huesped, int i) {
    printf("\n[Enter para confirmar]\n");
    printf("\nCreando nuevo huesped N%d\n", i + 1);

    printf("Ingresar el numero de id del huesped: ");
    scanf("%i", &(huesped[i].id));
    fflush(stdin);

    printf("Ingresar nombre del huesped: ");
    scanf("%30s", &(huesped[i].nombre));
    fflush(stdin);

    printf("Ingresar apellido del huesped: ");
    scanf("%30s", &(huesped[i].apellido));
    fflush(stdin);

    printf("Ingresar el numero de dias que se va a hospedar el huesped: ");
    scanf("%i", &(huesped[i].cantidad));
    fflush(stdin);

    printf("Ingresar el importe por los dias de hospedaje del huesped: $");
    scanf("%f", &(huesped[i].importe));
    fflush(stdin);

    // For some reason, the default value of a boolean in a struct is true
    // Soo... time to set everything to false :D
    huesped[i].servicio.pensionCompleta = false;
    huesped[i].servicio.pensionMedia = false;
    huesped[i].servicio.soloDesayuno = false;
    huesped[i].servicio.soloHabitacion = false;
    huesped[i].ciudad.cordoba = false;
    huesped[i].ciudad.laRioja = false;
    huesped[i].ciudad.sanLuis = false;

    while (1) {
        int servicio = 0;
        printf("\nIngrese el tipo de servicio para el huesped");
        printf("\n1: Pension Completa\n2: Media Pension\n3: Solo Desayuno\n4:Solo Habitacion\n:: ");
        scanf("%d", &servicio);
        fflush(stdin);

        if (servicio <= 4 && servicio >= 1) {
            switch (servicio) {
            case 1:
                huesped[i].servicio.pensionCompleta = true;
                break;
            case 2:
                huesped[i].servicio.pensionMedia = true;
                break;
            case 3:
                huesped[i].servicio.soloDesayuno = true;
                break;
            case 4:
                huesped[i].servicio.soloHabitacion = true;
                break;
            }
            break;
        }
        else
            printf("\nNumero incorrecto, porfavor seleccione uno en el rango de 1-4\n");
    }

    while (1) {
        int ciudad = 0;
        printf("\nIngrese la ciudad del huesped\n1: Cordoba\n2: La Rioja\n3: San Luis\n:: ");
        scanf("%d", &ciudad);
        fflush(stdin);

        if (ciudad <= 3 && ciudad >= 1) {
            switch (ciudad) {
                case 1:
                    huesped[i].ciudad.cordoba = true;
                    break;
                case 2:
                    huesped[i].ciudad.laRioja = true;
                    break;
                case 3:
                    huesped[i].ciudad.sanLuis = true;
                    break;
            }
            break;
        }
        else
            printf("\nNumero incorrecto, porfavor seleccione uno en el rango de 1-3\n");
    }
}

/// <summary>
/// Filtra los huespedes por las ciudades
/// </summary>
/// <param name="huesped">Estructura de Huespedes</param>
/// <param name="cantHuespedes">Cantidad total de huespedes</param>
/// <param name="ciudad">[cordoba, laRioja, sanLuis]+1</param>
/// <returns>Int: cantidad de huespedes en la ciudad</returns>
int filtrarCiudad(struct Huespedes* huesped, int cantHuespedes, int ciudad) {
    int huespedCiudad = 0;

    for (int i = 0; i < cantHuespedes; i++) {
        if (ciudad == 1 && huesped[i].ciudad.cordoba) huespedCiudad++;
        if (ciudad == 2 && huesped[i].ciudad.laRioja) huespedCiudad++;
        if (ciudad == 3 && huesped[i].ciudad.sanLuis) huespedCiudad++;
    }

    return huespedCiudad;
}

/// <summary>
/// Filtra los huespedes por las ciudades y retorna la cantidad de importe total
/// </summary>
/// <param name="huesped">Estructura de Huespedes</param>
/// <param name="cantHuespedes">Cantidad total de huespedes</param>
/// <param name="ciudad">[cordoba, laRioja, sanLuis]+1</param>
/// <returns>Double: cantidad total importe por huespedes de la ciudad</returns>
float pensionCompletaPorCiudad(struct Huespedes* huesped, int cantHuespedes, int ciudad) {
    double importeTotal = 0;

    for (int i = 0; i < cantHuespedes; i++) {
        if (ciudad == 1 && huesped[i].ciudad.cordoba)
            importeTotal = importeTotal + huesped[i].importe;
        if (ciudad == 2 && huesped[i].ciudad.laRioja)
            importeTotal = importeTotal + huesped[i].importe;
        if (ciudad == 3 && huesped[i].ciudad.sanLuis)
            importeTotal = importeTotal + huesped[i].importe;
    }
    return importeTotal;
}
