%% Sistema solar basico

astro(sol).
astro(mercurio).
astro(venus).
astro(tierra).
astro(marte).
astro(jupiter).
astro(saturno).
astro(urano).
astro(neptuno).


astro(luna).
astro(fobos).
astro(deimos).
astro(miranda).
astro(caronte).


%% Quien orbita a quien
orbita(mercurio,sol).
orbita(venus,sol).
orbita(tierra,sol).
orbita(marte,sol).
orbita(jupiter,sol).
orbita(saturno,sol).
orbita(neptuno,sol).
orbita(urano,sol).
orbita(pluton,sol).
orbita(luna,tierra).
orbita(fobos,marte).
orbita(deimos,marte).
orbita(miranda,urano).
orbita(caronte,pluton).

%% Mostrar quienes orbitan al sol
%% orbita(sol, X).



planeta(P) :- astro(P), orbita(P, sol).
satelite(S) :- astro(S), orbita(S, P), planeta(P).
