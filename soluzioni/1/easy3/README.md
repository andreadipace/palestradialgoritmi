# Trova la somma pari massima v2.0 (easy3)

Una prima soluzione potrebbe essere quella di comporre tutte le possibili coppie, vedere se la somma è pari e tenere il massimo. Al costo di **O(n^2)**. Ma questa non fa ottenere il massimo.

Noi sappiamo però che la somma di due numeri è pari se entrambi sono pari o entrambi sono dispari. Quindi ci basterebbe trovare i due numeri pari più grandi e i numeri dispari più grandi (sempre se sono presenti), sommarli tra loro e confrontare quale tra le due somme è più grande. Per far questo abbiamo bisogno di ordinare i numeri, **O(n*log(n))** e poi cercare i due più grandi.

Piccolo consiglio: per una pura questione di velocità nello scrivere la soluzione, conviene dividere in due vettori i numeri pari e dispari.