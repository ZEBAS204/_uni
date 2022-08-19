package example.project;

public class Alumno extends Persona {
  private String carreara;
  private String matricula;
  private Integer cantMaterias;

  public String getCarreara() {
    return carreara;
  }

  public void setCarreara(String carreara) {
    this.carreara = carreara;
  }

  public String getMatricula() {
    return matricula;
  }

  public void setMatricula(String matricula) {
    this.matricula = matricula;
  }

  public Integer getCantMaterias() {
    return cantMaterias;
  }

  public void setCantMaterias(Integer cantMaterias) {
    this.cantMaterias = cantMaterias;
  }

  @Override
  public String toString() {
    return "Alumno [cantMaterias=" + cantMaterias + ", carreara=" + carreara + ", matricula=" + matricula + "]";
  }

}
