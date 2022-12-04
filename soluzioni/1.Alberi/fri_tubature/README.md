# Rete idrica ([fri_tubature](https://training.olinfo.it/#/task/fri_tubature/statement))
:small_red_triangle: 74 :hourglass_flowing_sand: 1.0 s :cd: 256.0 MB :label: graphs, pre-oii

## Soluzione O(N)

In questo problema dobbiamo cercare il minimo numero di guardie da incontrare affinchè l'acqua di tutte le città risulti inquinata.
Per farlo, possiamo fare una dfs post visita in cui in ogni nodo esamiamo i figli e se c'è bisogno di inquinarli, vediamo se conviene inquinare la radice o solo i figli a cui sono collegate delle città. Per comodità, ogni volta che inquiniamo una città, segniamo che bisogna inquinare anche la città padre così da trascinarci l'informazione ai nodi sopra.