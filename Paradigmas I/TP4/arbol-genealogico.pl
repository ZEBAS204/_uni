/*
  * Del siguiente listado de hombres y mujeres se pide realizar el arbol genealógico de los mismos:
  *   - Alejo, Ignacio, Lalo, Lautaro, Luis, Martin
  *   - Carolina, Constanza, Fiorella, Jimena, Laura, Patricia, Victoria
  *
  * Los cuales son progenitores unos de otros:
  *   - Sebastián es progenitor de Alejo, Lautaro, Victoria y Constanza
  *   - Martin es progenitor de Ignacio y Fiorella
  *   - Luis es progenitor de Carolina y Jimena
  *   - Laura es progenitor de Carolina y Jimena
  *   - Lalo y Patricia son progenitores de Sebastian
  *   - Carolina es progenitor de Victoria Constanza, Alejo y Lautaro
  *   - Jimena es progenitor de Ignacio y Fiorella
  *
  * Se pide determinar las reglas:
  *   - A es diferente de B
  *   - Madre y Padre donde por Ej A es madre de B si A es progenitor de B y A es mujer.
  *   - Hijo e Hija donde A es hija de B si es B progenitor de A y A es mujer.
  *   - Hermanos, Primos, Tia, Nieto y Abuelo.
  *
  *   +-------------------+          +-----------------+
  *   |                   |          |                 |
  *   |  Lalo + Patricia  |          |   Luis + Laura  |
  *   |                   |          |                 |
  *   +-------+-----------+          +--------+--------+
  *           |                               |
  *           |          +--------------------+
  *           |          |                    |
  *    +------|----------|------+       +-----|-------------+
  *    |      v          v      |       |     v             |
  *    |  Sebastian + Carolina  |       |  Jimena + Martin  |
  *    |                        |       |                   |
  *    +--+---------------------+       +--+----------------+
  *       |                                |
  *       |-> Alejo                        |-> Ignacio
  *       |-> Lautaro                      +-> Fiorella
  *       |-> Victoria
  *       +-> Constanza
*/

hombre(lalo).
hombre(luis).
hombre(sebastian).
hombre(martin).
hombre(alejo).
hombre(lautaro).
hombre(ignacio).
mujer(patricia).
mujer(laura).
mujer(carolina).
mujer(jimena).
mujer(constanza).
mujer(victoria).
mujer(fiorella).

%%* Lalo + Patricia
progenitor(lalo, sebastian).
progenitor(patricia, sebastian).
%%* Luis + Laura
progenitor(luis, carolina).
progenitor(luis, jimena).
progenitor(luis, martin).
progenitor(laura, carolina).
progenitor(laura, jimena).
progenitor(laura, martin).
%%* Jimena + Martin
progenitor(martin, ignacio).
progenitor(martin, fiorella).
progenitor(jimena, ignacio).
progenitor(jimena, fiorella).
%%* Sebastian + Carolina
progenitor(carolina, alejo).
progenitor(carolina, lautaro).
progenitor(carolina, victoria).
progenitor(carolina, constanza).
progenitor(sebastian, alejo).
progenitor(sebastian, lautaro).
progenitor(sebastian, victoria).
progenitor(sebastian, constanza).


%%* Reglas
isDiff(A, B) :- not(A == B).
padre(Hijo, Progenitor) :- progenitor(Progenitor, Hijo), hombre(Progenitor).
madre(Hijo, Progenitor) :- progenitor(Progenitor, Hijo), mujer(Progenitor).
hijos(Progenitor, Hijos) :- progenitor(Progenitor, Hijos), hombre(Hijos).
hijas(Progenitor, Hijas) :- progenitor(Progenitor, Hijas), mujer(Hijas).
sonHermanos(A, B) :- progenitor(X, A), progenitor(Y, B), X == Y.
hermanos(Individuo, Hermanos) :- padre(Individuo, Padre), hijos(Padre, Hermanos), isDiff(Individuo, Hermanos).
hermanas(Individuo, Hermanas) :- padre(Individuo, Padre), hijas(Padre, Hermanas), isDiff(Individuo, Hermanas).
abuelo(Individuo, Abuelo) :- padre(Individuo, Padre), padre(Padre, Abuelo).
abuela(Individuo, Abuela) :- padre(Individuo, Madre), madre(Madre, Abuela).
nietos(Progenitor, Nietos) :- hijos(Progenitor, Hijos), hijos(Hijos, Nietos).
nietas(Progenitor, Nietas) :- hijas(Progenitor, Hijas), hijas(Hijas, Nietas).
tios(Individuo, Tios) :- (padre(Padre, Individuo), hermanos(Padre, Tios); madre(Madre, Individuo), hermanos(Madre, Tios)).
tias(Individuo, Tias) :- (padre(Padre, Individuo), hermanas(Padre, Tias); madre(Madre, Individuo), hermanas(Madre, Tias)).
primas(Individuo, Primas) :- tias(Individuo, Tia), hijas(Tia, Primas).
primos(Individuo, Primos) :- tios(Individuo, Tio), hijos(Tio, Primos).
