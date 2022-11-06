package Interfaz;

/*
 * Usamos una clase abstracta para definir el comportamiento
 * de una mascota y sus componentes.
 */
public abstract class Mascota implements Animal {
  protected String raza;
  protected String nombre;
  protected int edad;

  // * Variable estatica publica
  // La usamos para saber la cantidad
  // de animales que fueron creados
  public static int count;

  protected Mascota(String nombre, String raza, int edad) {
    // Always capitalize first letter on names
    this.nombre = nombre.substring(0, 1).toUpperCase() + nombre.substring(1);
    this.raza = raza.toLowerCase();
    this.edad = edad;
    count++;
  }

  public void comer() {
    System.out.println("El " + raza + " " + nombre + " come.");
  }

  public String getNombre() {
    return nombre;
  }

  public String getRaza() {
    return raza;
  }

  // * Usamos el modificador abstract para forzar
  // * las clases hijas a implementar el metodo
  @Override
  public String toString() {
    return "Nombre: " + nombre + " - Raza: " + raza + " - Edad: " + edad;
  }
}
