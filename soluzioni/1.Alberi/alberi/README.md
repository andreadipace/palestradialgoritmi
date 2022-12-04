# Alberi ([alberi](https://training.olinfo.it/#/task/alberi/statement))
:small_red_triangle: 158 :hourglass_flowing_sand: 1.0 s :cd: 256.0 MB :label: divide_and_conquer, graphs, nazionali

## Soluzione O(N)

Assunzioni:
- (pre, post) i nodi dei rispettivi sotto alberi sono contigui;
- (pre) il primo elemento dopo la radice è la radice del sotto albero sinistro;
- (post) il penultimo elemento è la radice del sotto albero destro.

L'idea è quella di spezzare l'albero in tre parti:

**PRE**:
- radice;
- albero sinistro;
- albero destro.

**POST**:
- albero sinistro;
- albero destro;
- radice.

E poi chiamare ricorsivamente la funzione sui due alberi e tra le due chiamate stampare la radice in modo tale da avere una visita di mezzo.