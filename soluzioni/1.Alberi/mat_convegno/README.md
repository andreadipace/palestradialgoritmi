# Convegno aziendale ([mat_convegno](https://training.olinfo.it/#/task/mat_convegno/statement))
:small_red_triangle: 21 :hourglass_flowing_sand: 1.0 s :cd: 256.0 MB :label: graphs, greedy, math, dp

## Soluzione O(n)

La soluzione è molto semplice: per ogni nodo vogliamo sapere quanti figli ci sono sotto di lui, quindi facciamo una dfs post visita che ritorna il numero di nodi del suo sottoalbero (compresa la radice). Lo facciamo per ogni nodo a partire dalla radice e man mano sommiamo i risultati per ogni figlio. Ogni volta che un nodo è stato completato, sommiamo il totale dei suoi figli al risultato finale.