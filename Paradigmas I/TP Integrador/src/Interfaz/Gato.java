package Interfaz;

public class Gato extends Mascota {
	public Gato(String nombre, int edad) {
		super(nombre, "gato", edad);
	}

	@Override
	public void dormir() {
		System.out.println(nombre + " duerme otra vez");
	}

	@Override
	public void hablar() {
		System.out.println("* " + nombre + " maulla *");
	}

	// * Sobrecarga de metodos
	public void chaseMice(int cant) {
		if (cant > 0)
			System.out.println("El gato persigue " + cant + " ratones");
		else
			System.out.println("El gato no persigue ningun raton");
	}

	public void chaseMice(boolean atrapo) {
		if (atrapo)
			System.out.println("El gato atrapo un raton");
		else
			System.out.println("El gato no atrapo ningun raton");
	}

	// * No es necesario asignarle un toString() porque no
	// * estamos modificando nada, automaticamente utilizara
	// * el metodo de la clase padre Mascota.
	// @Override
	// public String toString() {...}
}
