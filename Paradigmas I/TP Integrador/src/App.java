import Interfaz.*;

public class App {
	public static void main(String[] args) {
		// Como estamos usando interfaces, el tipo de array
		// puede ser de tipo Animal o mascota, Java lo infiere
		Mascota[] mascotas = {
				new Gato("Pepe", 4),
				new Perro("firulais", 10)
		};

		for (Animal animal : mascotas) {
			animal.dormir();
			animal.comer();
			animal.hablar();
			System.out.println(animal.toString() + "\n-------------\n");
		}

		// * Getter & Setters
		// Creamos un nuevo perro y le asignamos collar
		Perro perro = new Perro("Fatiga", 5);
		perro.addCollar();
		perro.removeCollar();
		perro.dormir();
		System.out.println();

		// * Sobrecarga de elementos
		Gato gato = new Gato("Tita", 8);
		gato.chaseMice(5);
		gato.chaseMice(0);
		gato.chaseMice(false);

		// * Utilizamos el metodo estatico de la clase Mascota para
		// * mostrar la cantidad de animales que fueron creados.
		System.out.println("\nTotal de animales: " + Interfaz.Mascota.count);
	}
}
