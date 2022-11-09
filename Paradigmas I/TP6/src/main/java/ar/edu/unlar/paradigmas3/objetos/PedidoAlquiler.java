package ar.edu.unlar.paradigmas3.objetos;

public class PedidoAlquiler extends Pedido {
  public PedidoAlquiler(Socio socio, Pelicula pelicula) {
    super(socio, pelicula, pelicula.getPrecioAlquiler());
  }

  @Override
  public boolean cobrar() {
    boolean wasValid = super.cobrar();
    if (!wasValid)
      return false;

    super.getSocio().setAlquilados(super.getPelicula());
    return true;
  }
}
