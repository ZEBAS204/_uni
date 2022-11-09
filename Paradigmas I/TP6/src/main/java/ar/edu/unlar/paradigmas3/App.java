package ar.edu.unlar.paradigmas3;

import ar.edu.unlar.paradigmas3.objetos.Tienda;

public class App {
    public static void main(String[] args) {
        Tienda tienda = new Tienda("Netflox", "Av. Pepito Cautipo 205");
        tienda.init();
    }
}
