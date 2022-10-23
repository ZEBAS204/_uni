package Animal;

public class Mascota extends Animal {
  private String nombre;
  private boolean tiene_collar;

  public Mascota(String nombre, String raza, int peso, String color) {
    super(raza, peso, color);

    // Always capitalize first letter
    this.nombre = nombre.substring(0, 1).toUpperCase() + nombre.substring(1);

    // If a doggo, assing a collar (useless but wanted to try handling strings)
    this.tiene_collar = raza.equalsIgnoreCase("perro");
  }

  public String getNombre() {
    return nombre;
  }

  @Override
  public String toString() {
    return this.nombre
        + ":\n    \\ Raza  : " + this.raza
        + "\n    \\ Color : " + this.color
        + "\n    \\ Peso  : " + this.peso
        + "\n    \\ Collar: " + (this.tiene_collar ? "Si" : "No");
  }
}
