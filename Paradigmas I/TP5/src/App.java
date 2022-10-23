/**
 * Realizar un programa para una veterinaria que atendera diversos Animales,
 * Perros, Gatos, etc, ingresando El nombre de la mascota, peso, raza.
 *
 ** Se debera implementar herencia con la Clase Animal.
 ** Crear una arrayList con los animales atendidos.
 * Mostrando el Listado de los Mismos, una vez terminada la carga de datos con
 * la cantidad por tipo (Clase) de Animal.
 */

import Veterinaria.Veterinaria;

public class App {
    public static void main(String[] args) {
        System.out.println("====== Veterinaria ======");
        System.out.println("[ Presiona ENTER para continuar ]");

        Veterinaria vet = new Veterinaria();
        vet.createMenu();
    }

}
