package ar.edu.unlar.paradigmas3.util;

import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.UUID;

public final class Util {
  private static Scanner sc = new Scanner(System.in).skip("\\R");

  private Util() {
    throw new IllegalStateException("Utility class");
  }

  /**
   * @param msg Message to repeat until a valid integer is submitted
   */
  public static int handleIntegers(String msg) {
    int num = -1;
    while (true) {
      if (num >= 0)
        break;

      System.out.print(msg);
      try {
        num = sc.nextInt();
      } catch (InputMismatchException e) {
        sc.nextLine(); // clear buffer
        System.out.println("Ingrese un numero!\nEl numero debe ser mayor o igual 0 (cero)");
      }
    }
    // Clear the leftover
    sc.nextLine();

    return num;
  }

  public static Scanner getScanner() {
    return sc;
  }

  public static String generateUUID() {
    return UUID.randomUUID().toString().replace("-", "");
  }

  public static int getIndexFromList(ArrayList array) {
    // Hope there's a better way to do generics
    int index = -1;
    int min = 0;
    int max = array.size();

    for (int i = min; i < max; i++)
      System.out.format("%d: %s%n", i, array.get(i).toString());

    while (index == -1) {
      int select = Util.handleIntegers("Selecciona un elemento de la lista:");
      if (select <= max && select >= min) {
        index = select;
        break;
      }
    }
    return index;
  }
}
