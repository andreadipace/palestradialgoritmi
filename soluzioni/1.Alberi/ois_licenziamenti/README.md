# Tagli al personale ([ois_licenziamenti](https://training.olinfo.it/#/task/ois_licenziamenti/statement))
:small_red_triangle: 10 :hourglass_flowing_sand: 1.0 s :cd: 256.0 MB :label: graphs, ois

## Soluzione O(n)

Questo problema si risolve con una dfs pre visita in cui ogni volta aggiorniamo il valore minimo incontrato lungo la discesa fino alle foglie. Usiamo una variabile globale per contare quanti nodi sono da scartare. Appena entriamo in un nuovo nodo controlliamo se la sua bravura è maggiore del minimo incontrato fino ad ora: se è così, allora incrementiamo il contatore, altrimenti aggiorniamo il minimo e continuiamo la visita.