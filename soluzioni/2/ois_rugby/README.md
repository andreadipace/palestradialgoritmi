# Torneo di rugby ([ois_rugby](https://training.olinfo.it/#/task/ois_rugby/statement))
:small_red_triangle: 13 :hourglass_flowing_sand: 1.0 s :cd: 256.0 MB :label: graphs, ois

## Soluzione O(N)

Vogliamo creare la squadra di rugby più potente con i giocatori a disposizione, senza limiti o condizioni sul numero di giocatori, ma solo con una regola: non possiamo prendere persone con una relazione gerarchica.

Per risolvere il problema, usiamo una dfs post visita in cui ogni volta sommiamo la bravura dei figli di un nodo e poi prendiamo il massimo tra la bravura del padre e la somma dei figli. Una volta fatta questa scelta, dobbiamo però aggiornare il valore del nodo in modo tale da poterlo usare per le considerazioni future.

La soluzione alla fine sarà in posizione 0 nel vettore delle bravure.