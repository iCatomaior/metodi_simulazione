# Progettazione del codice

Bisogna fare un doppio loop

* Un loop sugli step di montecarlo (da 1 a NMC) //loop esterno

* All'interno di ciascun montecarlo step si fanno tanti tentativi di mossa quante sono le particelle 

* Il numero di estrazioni nella catena di markov è NMC * N
    
* mossa : scelgo una direzione a caso e valuto lo spostamento
* se è occupato rifiuto lo spostamento
* se è vuoto valuto con metropolis

Bisogna tenere conto delle condizoni periodiche al contorno

# Codice

* inserire parametro J/KT = beta_j

