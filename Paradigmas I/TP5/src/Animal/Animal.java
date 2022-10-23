/**
 * Realizar un programa para una veterinaria que atendera diversos Animales,
 * Perros, Gatos, etc, ingresando El nombre de la mascota, peso, raza.
 *
 * Se debera implementar herencia con la Clase Animal.
 * Crear una arrayList con los animales atendidos.
 * Mostrando el Listado de los Mismos, una vez terminada la carga de datos con
 * la cantidad por tipo (Clase) de Animal.
 */

package Animal;

public abstract class Animal {
  public int peso;
  public String raza;
  public String color;

  public Animal() {}
  public Animal(String raza, int peso, String color) {
    // Capitalize first letter
    this.raza = raza.toLowerCase();
    this.peso = peso;
    this.color = color;
  }

  public String getAnimal() {
    return this.raza;
  }

}
