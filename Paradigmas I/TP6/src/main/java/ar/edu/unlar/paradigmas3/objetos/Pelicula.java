package ar.edu.unlar.paradigmas3.objetos;

public class Pelicula {
    private String nombre;
    private String genero;
    private String clasificacion;
    private int año;
    private int precioAlquiler;
    private int precioVenta;

    // * Precios por defecto
    private int _precioAlquiler = 500;
    private int _precioVenta = 1000;

    public Pelicula(String nombre, String genero, String clasificacion, int año) {
        this.nombre = nombre;
        this.genero = genero;
        this.clasificacion = clasificacion;
        this.año = año;
        this.precioAlquiler = _precioAlquiler;
        this.precioVenta = _precioVenta;
    }

    public Pelicula(String nombre, String genero, String clasificacion, int año, int precioAlquiler, int precioVenta) {
        this.nombre = nombre;
        this.genero = genero;
        this.clasificacion = clasificacion;
        this.año = año;
        this.precioAlquiler = precioAlquiler;
        this.precioVenta = precioVenta;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getGenero() {
        return genero;
    }

    public void setGenero(String genero) {
        this.genero = genero;
    }

    public String getClasificacion() {
        return clasificacion;
    }

    public void setClasificacion(String clasificacion) {
        this.clasificacion = clasificacion;
    }

    public int getAño() {
        return año;
    }

    public void setAño(int año) {
        this.año = año;
    }

    public int getPrecioAlquiler() {
        return precioAlquiler;
    }

    public void setPrecioAlquiler(int precioAlquiler) {
        this.precioAlquiler = precioAlquiler;
    }

    public int getPrecioVenta() {
        return precioVenta;
    }

    public void setPrecioVenta(int precioVenta) {
        this.precioVenta = precioVenta;
    }

    @Override
    public String toString() {
        return "Pelicula [nombre=" + nombre + ", genero=" + genero + ", clasificacion=" + clasificacion + ", año=" + año
                + ", precioAlquiler=" + precioAlquiler + ", precioVenta=" + precioVenta + "]";
    }

}
