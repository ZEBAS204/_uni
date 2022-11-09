package ar.edu.unlar.paradigmas3.objetos;

public class Item {
    private Pelicula pelicula;
    private int cantidad;
    private int alquilados;
    // * Can be done with a function, unnecessary
    // private Boolean disponible;

    public boolean isDisponible() {
        return ((cantidad - alquilados) > 0);
    }

    public Pelicula getPelicula() {
        return pelicula;
    }

    public void setPelicula(Pelicula pelicula) {
        this.pelicula = pelicula;
    }

    public int getCantidad() {
        return cantidad;
    }

    public void setCantidad(int cantidad) {
        this.cantidad = cantidad;
    }

    public int getAlquilados() {
        return alquilados;
    }

    public void setAlquilados(int alquilados) {
        this.alquilados = alquilados;
    }

    @Override
    public String toString() {
        return pelicula.getNombre() + " -- Cantidad: " + cantidad + " Alquilados: " + alquilados
                + " Disponible: " + (this.isDisponible() ? "Si" : "No");
    }

}
