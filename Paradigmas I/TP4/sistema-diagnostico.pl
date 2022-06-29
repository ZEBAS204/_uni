/*
* Los sintomas de la gripe, son tos y cansancio, los de la hepatitis son fiebre y nauseas, y el de la
* intoxicación es la diarrea, sabiendo que las vitaminas curan el cansancio, las aspirinas la fiebre, el
* jarabe la tos, el bismuto la diarrea y los antihistamínicos las nauseas.
* Determinar a partir de que sebastian tiene tos y cansancio, Ariel diarrea y Hugo fiebre y nauseas.
* Cual es la enfermedad de cada uno de ellos y cuales son los remedios que debo recetarles.
*/

tiene_sintoma(sebastian,cansancio).
tiene_sintoma(sebastian,tos).
tiene_sintoma(ariel,diarrea).
tiene_sintoma(hugo,fiebre).
tiene_sintoma(hugo,nauseas).

sintoma_de(tos,gripe).
sintoma_de(fiebre,hepatitis).
sintoma_de(nauseas,hepatitis).
sintoma_de(cansancio,gripe).
sintoma_de(diarrea,intoxicacion).

elimina(vitaminas,cansancio).
elimina(aspirinas,fiebre).
elimina(jarabe,tos).
elimina(bismuto,diarrea).
elimina(antihistaminicos,nauseas).

recetar_a(X,Y) :- enfermo_de(Y,A), alivia(X,A).
alivia(X,Y) :- elimina(X,A), sintoma_de(A,Y).
enfermo_de(X,Y) :- tiene_sintoma(X,Z), sintoma_de(Z,Y).

/*
  * El sistema receto lo siguiente:
  * - Sebastian:
  *   - Enfermedad: gripe
  *   - Recetar: vitaminas y jarabe
  *
  * - Ariel:
  *   - Enfermedad: intoxicacion
  *   - Recetar: bismuto
  *
  * - Hugo:
  *   - Enfermedad: hepatitis
  *   - Recetar: aspirinas y antihistaminicos
*/
