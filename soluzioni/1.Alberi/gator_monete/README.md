# Monete a posto ([gator_monete](https://training.olinfo.it/#/task/gator_monete/statement))
:small_red_triangle: 44 :hourglass_flowing_sand: 1.0 s :cd: 512.0 MB :label: gator, graphs, greedy

# Soluzione O(n)

In questo problema dobbiamo trovare il numero minimo di mosse per rimettere tutte le monete al posto (una per ogni nodo).
L'idea è quella di effettuare una dfs post visita in cui in ogni nodo esaminiamo i figli e sommiamo il loro saldo (positivo o negativo di monete).

Partiamo dai casi base, sia **n** il numero di monete presente in un nodo qualunque:
1. se **n** > 1: allora dobbiamo spostare **n - 1** monete dal nodo corrente al nodo padre;
2. se **n** = 1: perfetto così;
3. se **n** = 0: dobbiamo prenderci una moneta dal padre e quindi torniamo un saldo negativo di -1.

Ogni spostamento che facciamo lo sommiamo al numero di spostamenti totali.