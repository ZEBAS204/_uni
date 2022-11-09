package ar.edu.unlar.paradigmas3.objetos;

import java.util.concurrent.atomic.AtomicInteger;

public abstract class Pedido {
    private static final AtomicInteger _ID = new AtomicInteger(0);
    private final int idPedido;
    private Socio socio;
    private Pelicula pelicula;
    private int precio;

    protected Pedido(Socio socio, Pelicula pelicula, int precio) {
        this.idPedido = _ID.incrementAndGet();
        this.socio = socio;
        this.pelicula = pelicula;
        this.precio = precio;
    }

    public boolean cobrar() {
        Tarjeta tarjeta = socio.getTarjeta();
        int saldo = tarjeta.getSaldo();

        if (saldo <= 0 || precio > saldo) {
            System.out.println("El socio no tiene saldo suficiente para completar esta transaccion.");
            return false;
        }

        // Descontar
        tarjeta.addSaldo(-(precio));
        System.out.println("Se ha realizado la compra de " + this.pelicula.getNombre() + " por $" + this.precio);
        return true;
    }

    public int getIdPedido() {
        return idPedido;
    }

    public Socio getSocio() {
        return socio;
    }

    public Pelicula getPelicula() {
        return pelicula;
    }

    public int getPrecio() {
        return precio;
    }
}
