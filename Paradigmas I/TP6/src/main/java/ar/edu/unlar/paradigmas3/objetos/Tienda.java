package ar.edu.unlar.paradigmas3.objetos;

import ar.edu.unlar.paradigmas3.util.Util;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.Scanner;

public class Tienda {
    private String nombre;
    private String direccion;
    private ArrayList<Catalogo> catalogos = new ArrayList<>();
    private ArrayList<Socio> socios = new ArrayList<>();

    public Tienda(String nombre, String direccion) {
        this.nombre = nombre;
        this.direccion = direccion;
    }

    public int getClientIndex() {
        return Util.getIndexFromList(socios);
    }

    public Socio getClient() {
        return socios.get(getClientIndex());
    }

    public void addPelicula() {
        Scanner sc = Util.getScanner();
        sc.nextLine(); // buffer
        System.out.println("Ingrese los datos de la pelicula:");

        System.out.print("Ingrese el nombre: ");
        String _nombre = sc.nextLine();

        System.out.print("Ingrese el genero: ");
        String genero = sc.nextLine();

        System.out.print("Ingrese la clasificacion: ");
        String clasif = sc.nextLine();

        int año = Util.handleIntegers("Ingrese el año:");
        int cantidad = Util.handleIntegers("Ingrese la cantidad de peliculas:");
        int alquilados = Util.handleIntegers("Ingrese la cantidad de peliculas alquiladas:");

        Pelicula peli = new Pelicula(_nombre, genero, clasif, año);
        catalogos.get(0).addMovie(peli, cantidad, alquilados);
    }

    public void remPelicula() {
        ArrayList<?> catalogo = catalogos.get(0).getItems();
        int index = Util.getIndexFromList(catalogo);
        catalogo.remove(index);
    }

    public void printSocios() {
        for (Socio socio : socios)
            System.out.println(socio.toString());
    }

    public Pelicula getPelicula() {
        Catalogo catalogo = catalogos.get(0);
        int index = Util.getIndexFromList(catalogo.getItems());
        return catalogo.getItems().get(index).getPelicula();
    }

    public void init() {
        System.out.println("-------- " + nombre + " --------\n" + direccion);
        this.addTestValues(); // * Populate w/ test values
        this.createMenu();
    }

    public void printMenu() {
        String rowFormat = "| %-20s | %-20s | %-26s |%n";
        String rowSeparator = "+----------------------+----------------------+----------------------------+";
        System.out.println(rowSeparator);
        System.out.format(rowFormat, "CATALOGOS", "CLIENTES", "PEDIDOS");
        System.out.println(rowSeparator);
        System.out.format(rowFormat, "1: Mostrar catalogo", "4: Mostrar clientes", "7: Mostrar pedidos");
        System.out.format(rowFormat, "2: Añadir pelicula", "5: Añadir cliente", "8: Nuevo pedido Alquiler");
        System.out.format(rowFormat, "3: Remover Pelicula", "6: Alta cliente", "9: Nuevo pedido Compra");
        System.out.println(rowSeparator);
        System.out.format("| %-72s |%n", "0: EXIT");
        System.out.println(rowSeparator);
    }

    public void createMenu() {
        // Welp, here we go...
        Scanner scan = Util.getScanner();
        int num = -1;
        while (true) {
            this.printMenu();
            try {
                num = scan.nextInt();
                if (num == 0) break;
                else if (num == 1) {
                    // Mostrar catalogo
                    for (Catalogo catalogo : catalogos) catalogo.printCatalogo();
                }
                else if (num == 2) addPelicula();
                else if (num == 3) remPelicula();
                else if (num == 4) printSocios();
                else if (num == 5) {
                    // Añadir cliente
                    Socio newSocio = new Socio();
                    newSocio.crearSocio();
                    socios.add(newSocio);
                }
                else if (num == 6) {
                    // Alta cliente
                    int clienteIndex = this.getClientIndex();
                    socios.remove(clienteIndex);
                }
                else if (num == 7) {
                    // Mostrar pedidos
                    for (Socio socio : socios)
                        System.out.format("%s:%n\tAlquilados: %d%n\tCompras: %d%n", socio.getIdSocio(),
                                socio.getAlquilados().size(), socio.getCompras().size());
                }
                else if (num == 8) {
                    Socio socio = getClient();
                    Pelicula peli = this.getPelicula();
                    Pedido pedido = new PedidoAlquiler(socio, peli);
                    pedido.cobrar();
                }
            } catch (InputMismatchException e) {
                scan.nextLine(); // Ignore error
            }
        }
        scan.close();
    }

    public void addTestValues() {
        // Let's add some movies, should we?
        Catalogo defaultCatalogo = new Catalogo(this);
        Pelicula peli1 = new Pelicula("Scary moovie", "Comedia", "R", 2000);
        Pelicula peli2 = new Pelicula("Zoopopia", "Comedia", "G", 2016);
        Pelicula peli3 = new Pelicula("Star Wars: The Empire Strikes Back", "Sci-Fi", "M", 1980);
        Pelicula peli4 = new Pelicula("El rey leon", "Aventura dramatica", "G", 1994);

        defaultCatalogo.addMovie(peli1, 30, 11);
        defaultCatalogo.addMovie(peli2, 15, 15);
        defaultCatalogo.addMovie(peli3, 20, 3);
        defaultCatalogo.addMovie(peli4, 5, 2);
        catalogos.add(defaultCatalogo);

        // Let add some users to test stuff
        String dni = "123.456.789";
        String dir = "Calle falsa 123";
        String tel = "+5400001";
        String mail = "fakerjs@fake.net";

        Socio socio1 = new Socio();
        Socio socio2 = new Socio();
        Socio socio3 = new Socio();
        socio1.crearSocio("Miqueii", "Mouse", dni, dir, tel, mail, 20);
        socio2.crearSocio("Michael", "House", dni, dir, tel, mail, 35);
        socio3.crearSocio("Mario", "N1ntendo", dni, dir, tel, mail, 37);

        // Let make them ritcher
        socio1.getTarjeta().addSaldo(6500);
        socio2.getTarjeta().addSaldo(2000);
        socio3.getTarjeta().addSaldo(500);

        socios.add(socio1);
        socios.add(socio2);
        socios.add(socio3);
    }
}
