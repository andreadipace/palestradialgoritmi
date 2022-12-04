# Christmas Balls ([ois_christmasballs](https://training.olinfo.it/#/task/ois_christmasballs/statement))
:small_red_triangle: 183 :hourglass_flowing_sand: 1.5 s :cd: 256.0 MB :label: ois, graphs

## Soluzione O(N * log<sup>2</sup>N)

La soluzione non è facile, e ci si arriva con vari miglioramenti.
Prima di tutto eseguiamo una dfs e ogni volta che visitiamo un nodo, contiamo le sue occorrenze dei colori che hanno i suoi figli.

L'idea è quella di usare una unordered_map per contare le frequenze, in modo tale da non dover creare tutto l'array di frequenze.

Il problema risiede nel merging: per farlo in modo ottimale bisogna usare una tecnica chiamata [small to large](https://usaco.guide/plat/merging?lang=cpp) che unisce la mappa più piccola a quella più grande.

Inoltre, mentre si fa il merging si può anche contare e aggiornare la frequenza maggiore.