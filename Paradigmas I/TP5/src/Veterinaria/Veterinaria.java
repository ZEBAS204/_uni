package Veterinaria;

import java.util.InputMismatchException;
import java.util.Collections;
import java.util.HashSet;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.Set;

import Animal.Mascota;

public class Veterinaria {
  private static ArrayList<Mascota> mascotasAtendidas = new ArrayList<>();
  static Scanner sc = new Scanner(System.in).skip("\\R");

  static int handleIntegers(Scanner sc, String msg) {
    int num = -1;

    while (true) {
      if (num > 0)
        break;

      System.out.print(msg);

      try {
        num = sc.nextInt();
      } catch (InputMismatchException e) {
        sc.nextLine(); // clear buffer
        System.out.println("Ingrese un numero!\nEl numero debe ser mayor a 0 (cero)");
      }
    }
    // Clear the leftover
    sc.nextLine();
    return num;
  }

  public void addMascotaAtendida() {
    Scanner scan = sc;
    String nombre;
    String raza;
    String color;
    int peso = 0;

    sc.nextLine();
    System.out.println("Ingrese los datos del nuevo animal atendido:");
    System.out.print("Ingrese el nombre: ");
    nombre = scan.nextLine();

    System.out.print("\nIngrese la raza: ");
    raza = scan.nextLine();

    System.out.print("\nIngrese el color: ");
    color = scan.nextLine();
    System.out.println();

    peso = handleIntegers(scan, "Ingrese el peso: ");
    System.out.println();

    Mascota mascota = new Mascota(nombre, raza, peso, color);
    mascotasAtendidas.add(mascota);

    System.out.println("Datos de la mascota añadida:\n" + mascota.toString() + "\n");
  }

  public void printAtendidos() {
    if (mascotasAtendidas.isEmpty()) {
      System.out.println("No se ha atendido a ninguna mascota todavia.");
      return;
    }

    // Keep track of repeated values
    ArrayList<String> repeated = new ArrayList<>();

    for (Mascota mascota : mascotasAtendidas) {
      // Add to the repeated list
      repeated.add(mascota.raza);

      System.out.println("\n-------------------");
      System.out.println(mascota.toString());
    }

    // Print animals countity by their race
    System.out.println("\n-------------------\nTotal:");
    Set<String> set = new HashSet<>(repeated);
    for (String r : set)
      System.out.println("  " + r + ": " + Collections.frequency(repeated, r));
  }

  public void clearAtendidos() {
    mascotasAtendidas.clear();
    System.out.println("Se han eliminado las mascotas atendidas.");
  }

  public void printMenu() {
    System.out.println("----------- ACCIONES -----------");
    System.out.println("0: Exit");
    System.out.println("1: Agregar mascota atendida");
    System.out.println("2: Listar mascotas atendidas");
    System.out.println("3: Limpiar lista de mascotas");
    System.out.println("--------------------------------");
  }

  public void createMenu() {
    Scanner scan = sc;
    int num = -1;

    while (true) {
      this.printMenu();

      try {
        num = scan.nextInt();
        if (num == 0) break;
        else if (num == 1) this.addMascotaAtendida();
        else if (num == 2) this.printAtendidos();
        else if (num == 3) this.clearAtendidos();
      } catch (InputMismatchException e) {
        // Ignore error
        sc.nextLine();
      }
    }
    scan.close();
  }
}
