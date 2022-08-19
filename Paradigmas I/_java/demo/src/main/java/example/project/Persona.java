package example.project;

import java.time.LocalDate;

public class Persona {

  private String nombre;
  private String apellido;
  private Integer edad;
  private String sexo;
  private LocalDate fechaNacimiento;

  private boolean tieneHijos;
  private int cantidadHijos;

  public String getNombre() {
    return nombre;
  }

  public void setNombre(String nombre) {
    this.nombre = nombre;
  }

  public String getApellido() {
    return apellido;
  }

  public void setApellido(String apellido) {
    this.apellido = apellido;
  }

  public Integer getEdad() {
    return edad;
  }

  public void setEdad(Integer edad) {
    this.edad = edad;
  }

  public String getSexo() {
    return sexo;
  }

  public void setSexo(String sexo) {
    this.sexo = sexo;
  }

  public LocalDate getFechaNacimiento() {
    return fechaNacimiento;
  }

  public void setFechaNacimiento(LocalDate fechaNacimiento) {
    this.fechaNacimiento = fechaNacimiento;
  }

  public boolean isTieneHijos() {
    return tieneHijos;
  }

  public void setTieneHijos(boolean tieneHijos) {
    this.tieneHijos = tieneHijos;
  }

  public int getCantidadHijos() {
    return cantidadHijos;
  }

  public void setCantidadHijos(int cantidadHijos) {
    this.cantidadHijos = cantidadHijos;
  }

  public void saludar() {
    System.out.println("Hola " + this.nombre);
  }

  /**
   * Print current persona information
   */
  public void printDatos() {
    System.out.println("Nombre: " + this.nombre);
    System.out.println("Apellido: " + this.apellido);
    System.out.println("Sexo: " + this.sexo);
    System.out.println("Edad: " + this.edad);
    System.out.println("Nacimiento: " + this.fechaNacimiento);

    if (this.tieneHijos) {
      System.out.println("Tiene Hijos: " + this.tieneHijos);
      System.out.println("Cantidad de hijos" + this.cantidadHijos);
    }

  }

}
