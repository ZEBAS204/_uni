package ar.edu.unlar.paradigmas3.objetos;

public class PedidoVenta extends Pedido {
  public PedidoVenta(Socio socio, Pelicula pelicula) {
    super(socio, pelicula, pelicula.getPrecioVenta());
  }

  @Override
  public boolean cobrar() {
    boolean wasValid = super.cobrar();
    if (!wasValid)
      return false;

    super.getSocio().setCompras(super.getPelicula());
    return true;
  }
}
