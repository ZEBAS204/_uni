## Video Club

Un Videoclub tiene como fin manejar el pedido de películas,
navegar por el catálogo de la tienda y el manejo de socios con tarjetas recargables.

### Características:
- Los socios pueden alquilar las películas con sus tarjetas.
- El crédito de la tarjeta se actualiza, cuando se realiza alguna operación con las películas.
- Los socios pueden comprar películas y sus datos se guardan en  en el pedido realizado.
- Identificacion de las clases del sistema (?)

### Crear un sistema que permita:
- Tomar los pedidos/ventas
- Alta de Socios
- Gestion de Peliculas
- Gestion de Tarjetas

Mostrar en pantalla un reporte de los usuarios con sus saldos y peliculas alquiladas o compradas.

---

```
+------------+          +--------------+         +--------------+
|            |          |              |         |              |
|   Tienda   +--------->+   Catalogo   +-------->+   Pelicula   |
|            |          |              |         |              |
+------------+          +--------------+         +------+-------+
                                                        ^
                                                        |
                                                        |
 +-----------+          +-------------+           +-----+------+
 |           |          |             |           |            |
 |   Socio   +--------->+   Tarjeta   +<----------+   Pedido   |
 |           |          |             |           |            |
 +-----------+          +-------------+           +------------+
```
