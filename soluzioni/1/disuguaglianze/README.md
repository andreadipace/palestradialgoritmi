# Rispetta i versi (disuguaglianze)

Dobbiamo sistemare i numeri tra 1 e N (inclusi) e N - 1 segni in input.
L'idea è quella di sisteamre il numero a sinistra del segno appena letto. Abbiamo due casi:

* \<: in questo caso prendiamo il più piccolo dei numeri che abbiamo a disposizione, poiché, indipendentemente da ciò che avremo dopo questo sarà minore di tutti gli altri;
* \>: come prima, ma prendiamo il più grande di quelli a disposizione.

Per farlo, usiamo semplicemente due variabili contatori, una con il minimo (1) e l'altra al massimo (N). Ogni volta che inseriamo un numero, andremo a incrementare o decrementare uno dei due.

Alla fine, stampiamo uno dei due contatori: è indifferente quale dei due poiché avranno lo stesso valore.