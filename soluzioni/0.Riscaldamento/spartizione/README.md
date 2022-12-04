# La spartizione di Totò (spartizione)

Ci sono due soluzioni a questo problema (entrambe 100/100).

La prima banale simula quello farebbe Totò con la distribuzione delle gemme.

L'altra consiste nel calcolarlo direttamente in questo modo:
sappiamo che Totò ad ogni giro si prende una gemma in più del giro precendente, mentre ai suoi compagni dà sempre una gemmma a testa.
Usando:
* la **I** per indicare il numero di giri completi;
* la **G** il numero di gemme;
* e **P** il numero dei complici (incluso Totò). 

Possiamo dire che:
* totò prenderà **I * (I + 1) / 2** gemme (più quelle che avanzano);
* i complici prenderanno **I * (P - 1)** gemme.

Unendo questi due termini in una disugualianza:

**I * (I + 1) / 2 + I * (P - 1) \<= G**

Siccome G, P sono costanti che sappiamo, ci basta trovare le soluzioni della disuguaglianza di secondo grado per I in modo tale da trovare il numero di giri completi che Totò farà.

Una volta fatto questo, ci calcoliamo quante gemme prenderà Totò, quante i suoi complici. Adesso le sottraiamo a quelle totali per poi aggiungere ciò che ne rimane a quelle che prenderà Totò.

**TOTO = I * (I + 1) / 2**

**SOCI = I * (P - 1)**

**G -= TOTO + SOCI**

**TOTO += G**