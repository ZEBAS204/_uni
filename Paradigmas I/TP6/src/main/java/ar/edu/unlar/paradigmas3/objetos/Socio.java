package ar.edu.unlar.paradigmas3.objetos;

import ar.edu.unlar.paradigmas3.util.Util;
import java.util.ArrayList;
import java.util.Scanner;

public class Socio {
    private String nombre;
    private String apellido;
    private String dni;
    private String direccion;
    private String telefono;
    private String email;
    // * Having age and birthday is redundant
    // private String fechaNacimiento;
    private int edad;

    private String idSocio = Util.generateUUID();
    private Tarjeta tarjeta;

    // * Alquilados y compras
    private ArrayList<Pelicula> alquilados = new ArrayList<>();
    private ArrayList<Pelicula> compras = new ArrayList<>();

    public void crearSocio() {
        Scanner sc = Util.getScanner();
        sc.nextLine(); // buffer

        // Assign new card
        Tarjeta card = new Tarjeta(this.idSocio);
        this.tarjeta = card;

        System.out.println("Ingrese los datos del nuevo cliente:");
        System.out.print("Ingrese el nombre: ");
        this.nombre = sc.nextLine();
        System.out.print("Ingrese el Apellido: ");
        this.apellido = sc.nextLine();
        System.out.print("Ingrese el DNI: ");
        this.dni = sc.nextLine();
        System.out.print("Ingrese su direccion: ");
        this.direccion = sc.nextLine();
        System.out.print("Ingrese su telefono: ");
        this.telefono = sc.nextLine();
        System.out.print("Ingrese su email: ");
        this.email = sc.nextLine();
        this.edad = Util.handleIntegers("Ingrese la edad:");

    }

    public void crearSocio(String nombre, String apellido, String dni, String direccion, String telefono, String email,
            int edad) {
        Tarjeta card = new Tarjeta(this.idSocio);
        this.tarjeta = card;
        this.nombre = nombre;
        this.apellido = apellido;
        this.dni = dni;
        this.direccion = direccion;
        this.telefono = telefono;
        this.email = email;
        this.edad = edad;
    }

    @Override
    public String toString() {
        return String.format("ID: %s %n\tApellido y Nombre(s): %s %s %n\tDNI: %s %n\tE-Mail: %s %n\tSaldo: $%d",
                idSocio, apellido, nombre, dni, email, tarjeta.getSaldo());
    }

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

    public String getDni() {
        return dni;
    }

    public void setDni(String dni) {
        this.dni = dni;
    }

    public String getDireccion() {
        return direccion;
    }

    public void setDireccion(String direccion) {
        this.direccion = direccion;
    }

    public String getTelefono() {
        return telefono;
    }

    public void setTelefono(String telefono) {
        this.telefono = telefono;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public int getEdad() {
        return edad;
    }

    public void setEdad(int edad) {
        this.edad = edad;
    }

    public String getIdSocio() {
        return idSocio;
    }

    public Tarjeta getTarjeta() {
        return tarjeta;
    }

    public void setTarjeta(Tarjeta tarjeta) {
        this.tarjeta = tarjeta;
    }

    public ArrayList<Pelicula> getAlquilados() {
        return alquilados;
    }

    public void setAlquilados(ArrayList<Pelicula> alquilados) {
        this.alquilados = alquilados;
    }

    public void setAlquilados(Pelicula pelicula) {
        this.alquilados.add(pelicula);
    }

    public ArrayList<Pelicula> getCompras() {
        return compras;
    }

    public void setCompras(ArrayList<Pelicula> compras) {
        this.compras = compras;
    }

    public void setCompras(Pelicula pelicula) {
        this.compras.add(pelicula);
    }
}
