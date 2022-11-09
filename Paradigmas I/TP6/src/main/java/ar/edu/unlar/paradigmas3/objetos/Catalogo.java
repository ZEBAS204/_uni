package ar.edu.unlar.paradigmas3.objetos;

import java.util.ArrayList;

public class Catalogo {
    private final Tienda tienda;
    private ArrayList<Item> items = new ArrayList<>();

    public Catalogo(Tienda tienda) {
        this.tienda = tienda;
    }

    public void addMovie(Pelicula pelicula, int cantidad, int alquilados) {
        Item newMovie = new Item();
        newMovie.setPelicula(pelicula);
        newMovie.setCantidad(cantidad);
        newMovie.setAlquilados(alquilados);
        items.add(newMovie);
        System.out.println("Se ha añadido: " + newMovie.getPelicula().getNombre());
    }

    public Pelicula crearPelicula(String nombre, String genero, String clasificacion,
            int año, int precioAlquiler, int precioVenta) {
        return new Pelicula(nombre, genero, clasificacion, año, precioAlquiler, precioVenta);
    }

    public void printCatalogo() {
        System.out.println("Peliculas dentro del catalogo:");
        for (Item item : items)
            System.out.println("* " + item.toString());
    }

    public Tienda getTienda() {
        return tienda;
    }

    public ArrayList<Item> getItems() {
        return items;
    }
}
