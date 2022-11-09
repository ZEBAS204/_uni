package ar.edu.unlar.paradigmas3.objetos;

import java.time.LocalDate;
import java.time.ZoneId;
import java.util.Date;

public class Tarjeta {
    private final String idTarjeta;
    private Date fechaVencimiento;
    private int saldo = 0;

    public Tarjeta(String ID) {
        this.idTarjeta = ID;
        this.fechaVencimiento = renovar();
    }

    private Date renovar() {
        // * Set expiration to 5 months from the current date
        LocalDate exp = LocalDate.now().plusMonths(5);
        return Date.from(exp.atStartOfDay().atZone(ZoneId.systemDefault()).toInstant());
    }

    public void renovarFechaVencimiento() {
        this.fechaVencimiento = this.renovar();
    }

    public String getIdTarjeta() {
        return idTarjeta;
    }

    public Date getFechaVencimiento() {
        return fechaVencimiento;
    }

    public int getSaldo() {
        return saldo;
    }

    public void addSaldo(int saldo) {
        this.saldo += saldo;
    }

    @Override
    public String toString() {
        return "Tarjeta [idTarjeta=" + idTarjeta + ", fechaVencimiento=" + fechaVencimiento + ", saldo=" + saldo + "]";
    }

}
