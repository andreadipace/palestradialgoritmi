# Introduzione

Contenuti della lezione
1. [Presentazioni](#presentazioni)
2. [c++ vs python3](#c++-vs-python3)
3. [Contest](#contest)

## Presentazioni

Compilate il [questionario](https://forms.gle/ztjYqHgbpb2oCfAk7)

## c++ vs python3

### Intro

<details>
<summary>Scheletro</summary>
c++
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    return 0;
}
```

python3:
```python
```
</details>

<details>
<summary>Variabili</summary>

c++
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a = 5;
    double b = 3.5;
    float c = 7.2;
    char d = 'a';
    cout << a << " " << b << " " << c << " " << d;
    return 0;
}
```

python3:
```python
a = 5
b = 3.5
c = 7.2
d = 'a'

print(f"{a} {b} {c} {d}")
```
</details>

<details>
<summary>Operazioni con le variabili</summary>

c++
```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    int a = 3, b = 2;
    int somma = a+b;
    int differenza = a-b;
    int prodotto = a*b;
    int rapporto = a/b;
    int resto = a%b;

    cout << somma << " " << differenza << " " << prodotto << " " << rapporto << " " << resto;
    return 0;
}
```

python3
```python
a, b = 3, 2
somma = a + b
differenza = a - b
prodotto = a * b
rapporto = a / b
resto = a % b
print(f"{somma} {differenza} {prodotto} {rapporto} {resto}")
```
</details>

<details>
<summary>Input e Output</summary>

c++
```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string S;
    cin >> S >> N;
    cout << S << " " << N << endl;
    return 0;
}
```

python3
```python
S = input()
N = int(input())
print(f"{S} {N}")
```

N.B: in python input() legge fino alla fine della riga.
</details>



<details>
<summary>File</summary>

c++
```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    ifstream in ("input.txt");
	ofstream out ("output.txt");

    // adesso in si comporterà come cin
    // lo stesso vale per out e cout
	
    int a;
	in >> a;

	out << "Ciao! La variabile a vale " << a;
	
	in.close();
	out.close();
    return 0;
}
```

python3
```python
with open("input.txt", "r") as fi: 
    a = int(fi.readline())

with open("output.txt", "w") as fo:
    fo.write(f"Ciao! La variabile a vale {a}")
```
</details>

<details>
<summary>Controllo</summary>

c++
```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    if (N > 100) {
        cout << "Maggiore di 100" << endl;
    }
    else if (N > 10) {
        cout << "Maggiore di 10" << endl;
    }
    else {
        cout << "Minore o uguale a 10" << endl;
    }
    return 0;
}
```

python3
```python
N = int(input())
if N > 100:
    print("Maggiore di 100")
elif N > 10:
    print("Maggiore di 10")
else:
    print("Minore o uguale a 10")
```
</details>

<details>
<summary>Ciclo while</summary>

c++
```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    int c = 0;
    while (c < 10) {
        cout << c << endl;
        c++;
    }
    return 0;
}
```

python3
```python
c = 0
while c < 10:
    print(c)
    c += 1
```
</details>

<details>
<summary>Ciclo for</summary>

c++
```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    for (int c = 0; c < 10; c++) {
        cout << c  << endl;
    }
    return 0;
}
```

python3
```python
inizio = 0 # opzionale, default 0
fine = 10 # non incluso
step = 1 # opzionale, default 1

for c in range(inizio, fine, step):
    print(c)

for c in range(fine):
    print(c)
```
</details>

<details>
<summary>Funzioni</summary>

c++
```cpp
#include<bits/stdc++.h>
using namespace std;

int somma(int a, int b) {
    return a + b;
}

int GLOB = 10;
void globale() {
    GLOB++;
}

int main() {
    int a = 30, b = 12;
    cout << somma(a, b) << endl;

    // chiamo una funzione che modificherà
    // una variabile globale
    globale();
    cout << GLOB << endl;
    return 0;
}
```

python3
```python
def somma(a, b):
    return a + b

GLOB = 10
def globale():
    global GLOB
    GLOB += 1

a, b = 30, 12
print(somma(a, b))

# chiamo una funzione che modificherà
# una variabile globale
globale()
print(GLOB)
```
</details>

### Strutture dati

#### Vettori

<details>
<summary>Creazione, rimozione, ricerca</summary>

c++
```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    // creo un vettore di 10 elementi, tutti uguali a 2
    vector<int> v1 = vector<int>(10, 2);
    cout << v1.size() << endl;

    // creo un vettore di 10 elementi
    vector<int> v2 = vector<int>(10);
    // ridimensiono il vettore
    v2.resize(100);

    // ridimensiono e assegno un valore uguale a tutti gli elementi
    v2.assign(100, -1); 

    // creo un vettore
    vector<int> v = { 2, 3 };
    
    // inserisco in fondo
    v.push_back(4);
    
    // inserisco in posizione 1
    v.insert(v.begin() + 1, 5);

    // rimuovo l'ultimo elemento
    v.pop_back();

    // rimuovo l'elemento con valore 1000
    auto t = find(v.begin(), v.end(), 1000); // ritorna un iteratore
    if (t != v.end()) {
        v.erase(t);
    }

    // conto quanti elementi sono uguali a 3
    int c = count(v.begin(), v.end(), 3);

    // copio
    vector<int> cv(v);

    // pulisco
    v.clear();
    return 0;
}
```

python3
```python
v = [2, 3]
# inserisco in fondo
v.append(4)
assert(v == [2,3,4])

print(len(v))

# inserisco in posizione 0
v.insert(0, 1000)
assert(v == [1000,2,3,4])

# rimuovo l'ultimo elemento
l = v.pop()
assert(l == 4)

# rimuovo in posizione 1
f = v.pop(1)
assert(f == 2)

# rimuovo l'elemento con valore 1000
v.remove(1000)
assert(v == [3])

# conto quanti elementi sono uguali a 3
c = v.count(3)
assert(c == 1)

# estendo
v.extend([11, 12])
assert(v == [3,11,12])

# copio
vc = v.copy()
assert(vc == v)

# pulisco
v.clear()
assert(v == [])
```
</details>

<details>
<summary>Iterazione</summary>

c++
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = { 123, 43, 1, 58};
    for (int e: v) {
        cout << e << endl;
    }
    return 0;
}
```

python3:
```python
v = [123, 43, 1, 58]
for e in v:
    print(e)
```

N.B: il valore è solo una copia, qualsiasi modifica sarà solo locale.
</details>

<details>
<summary>Ordinamento</summary>

c++
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = { 123, 43, 1, 58};

    // ordino crescente
    sort(v.begin(), v.end());
    for (auto e: v) {
        cout << e << endl;
    }

    // orindo decrescente
    sort(v.begin(), v.end(), greater<int>());
    for (auto e: v) {
        cout << e << endl;
    }

    return 0;
}
```

python3:
```python
v = [123, 43, 1, 58]

# ordino crescente
v.sort()
for e in v:
    print(e)

# ordino decrescente
v.sort(reverse=True)
for e in v:
    print(e)
```
</details>

#### Dizionari

### Pros & Cons

[Link1](https://www.quora.com/How-good-is-Python-for-competitive-programming)

[Link2](https://www.quora.com/Should-I-begin-with-C++-or-python-in-competitive-programming)

## Contest

Un po' di esercizi per conoscerci meglio :)

Riscaldamento:
* [easy1](https://training.olinfo.it/#/task/easy1/statement)
* [easy2](https://training.olinfo.it/#/task/easy2/statement)
* [easy3](https://training.olinfo.it/#/task/easy3/statement)


E dopo i primi tre esercizi on 100/100:

* [ois_carrucole](https://training.olinfo.it/#/task/ois_carrucole/statement)
* [spartizione](https://training.olinfo.it/#/task/spartizione/statement)
* [disuguaglianze](https://training.olinfo.it/#/task/disuguaglianze/statement)