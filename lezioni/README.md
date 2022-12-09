# STL: Standard Template Library

Contenuti:
1. [Strutture dati base](#strutture-dati-base)
    - [vector](#vector)
    - [queue](#queue)
    - [stack](#stack)
    - [deque](#deque)
    - [set](#set)
    - [map](#map)
    - [unordered_map](#unordered_map)
    - [priority_queue](#priority_queue)
2. [Strutture dati avanzate](#strutture-dati-avanzate)
    - [Union Find](#union-find)
    
## Complessità computazionale

![Img](https://italiancoders.it/wp-content/uploads/2017/12/complessita-computazionale-1920x1150.png)

## Strutture dati base

### vector

| push_back | pop_back | insert | erase | find | find index |
|-|-|-|-|-|-|
| O(1) | O(1) | O(N) | O(N) | O(N) | O(1) |

### queue

| push | pop | front |
|-|-|-|
|O(1)|O(1)|O(1)|

### stack

| push | pop | top |
|-|-|-|
|O(1)|O(1)|O(1)|

### deque

| push_back | pop_back | push_front | pop_front |
|-|-|-|-|
|O(1)|O(1)|O(1)|O(1)|

### set

| insert | remove | find |
|-|-|-|
| O(log(N)) | O(log(N)) | O(log(N)) |

### map

| insert | access | remove |
|-|-|-|
| O(log(N)) | O(log(N)) | O(log(N)) |

### unordered_map

| insert | access | remove |
|-|-|-|
| O(1) | O(1) | O(1) |

### priority_queue

| push | pop | top |
|-|-|-|
|O(log(N))|O(log(N))|O(1)|

## Strutture dati avanzate

### Union Find

[Union-find](https://en.wikipedia.org/wiki/Disjoint-set_data_structure) è una struttura dati derivante dal concetto di partizione, per cui dato un insieme finito di elementi a volte risulta utile partizionarli in insiemi disgiunti. Le due operazioni possibili su questa struttura sono:
- **ricerca**: determina l'insieme di appartenenza di un elemento;
- **unione**: combina due insiemi in un unico.

<details>
<summary>Implementazione</summary>

```cpp
class UF {
  int *id, cnt, *sz;
  public:
UF(int N) {
    cnt = N; id = new int[N]; sz = new int[N];
    for (int i = 0; i<N; i++)  id[i] = i, sz[i] = 1; }
~UF() { delete[] id; delete[] sz; }
int find(int p) {
    int root = p;
    while (root != id[root])	root = id[root];
    while (p != root) { int newp = id[p]; id[p] = root; p = newp; }
    return root;
}
void merge(int x, int y) {
    int i = find(x); int j = find(y); if (i == j) return;
    if (sz[i] < sz[j]) { id[i] = j, sz[j] += sz[i]; }
    else { id[j] = i, sz[i] += sz[j]; }
    cnt--;
}
bool connected(int x, int y) { return find(x) == find(y); }
int count() { return cnt; }
};
```
Presa da [qui](https://github.com/kartikkukreja/blog-codes/blob/master/src/Union%20Find%20(Disjoint%20Set)%20Data%20Structure.cpp).

</details>