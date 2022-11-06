package Interfaz;

public class Perro extends Mascota {
	private boolean tieneCollar;

	public Perro(String nombre, int edad) {
		super(nombre, "perro", edad);
	}

	@Override
	public void dormir() {
		System.out.println("El perro " + nombre + " duerme");
	}

	@Override
	public void hablar() {
		System.out.println("* El perro ladra *");
	}

	// * Getter & Setter
	public void addCollar() {
		System.out.println("Se le puso el collar a " + nombre);
		tieneCollar = true;
	}

	public void removeCollar() {
		System.out.println("Se le quito el collar a " + nombre);
		tieneCollar = false;
	}

	public boolean tieneCollar() {
		return tieneCollar;
	}

	// * Sobrecarga de elementos
	public void fetchStick(int cant) {
		if (cant > 0)
			System.out.println("El perro atrapo " + cant + "palos");
		else
			System.out.println("El perro no atrapo ningun palo");
	}

	public void fetchStick(boolean atrapado) {
		if (atrapado)
			System.out.println("El perro atrapo el palo");
		else
			System.out.println("El perro no atrapo el palo");
	}

	// * Utilizamos el metodo de la clase padre para
	// * obtener el resultado y le aplicamos el collar
	@Override
	public String toString() {
		return super.toString() + " - Tiene collar: " + tieneCollar;
	}
}
