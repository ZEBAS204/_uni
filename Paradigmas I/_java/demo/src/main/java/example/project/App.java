package example.project;

import java.util.InputMismatchException;
import java.util.Scanner;
import java.time.LocalDate;

/**
 * Hello world!
 */
public class App {

    static Integer handleIntegers(Scanner sc) {
        int num = -1;

        while (true) {
            if (num > 0)
                break;

            try {
                num = sc.nextInt();
            } catch (InputMismatchException e) {
                sc.next(); // clear buffer
                System.out.println("Ingrese un numero!\nEl numero debe ser mayor a 0 (cero)");
            }
        }

        return num;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Persona alumno = new Persona();

        System.out.println("...Ingrese los datos del alumno...");

        System.out.print("Ingrese nombre: ");
        alumno.setNombre(scanner.nextLine());
        System.out.println();

        System.out.print("Ingrese apellido: ");
        alumno.setApellido(scanner.nextLine());
        System.out.println();

        System.out.print("Ingrese sexo: ");
        alumno.setSexo(scanner.nextLine());
        System.out.println();

        // System.out.print("Ingrese fecha de nacimiento: ");
        alumno.setFechaNacimiento(LocalDate.now()); // I'm lazy and it's just for testing
        // System.out.println();

        System.out.print("Ingrese edad: ");
        alumno.setEdad(handleIntegers(scanner));
        System.out.println();

        alumno.printDatos();
        scanner.close();
    }
}
