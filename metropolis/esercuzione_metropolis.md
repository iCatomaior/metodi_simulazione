fare un doppio loop

loop sui montecarlo step from 1 --> NMC //loop esterno

* all'interno di ciascun montecarlo step si fanno tanti tentativi di mossa quante sono le particelle 

*    ==> Il numero di estrazioni nella catena di markov è NMC * N
    
*mossa : scelgo una direzione a caso e valuto lo spostamento
        * se è occupato rifiuto lo spostamento
        * se è vuoto valuto con metropolis
    tenere conto delle condizoni periodiche al contorno

# Codice

* inserire parametro J/KT = beta_j

