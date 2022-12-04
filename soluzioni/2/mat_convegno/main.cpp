#include <cstdio>
#include <cassert>
#include <cstdlib>

static FILE *fr, *fw;

// Declaring variables
static int N;
static int* C;
static int res;

// Declaring functions
int coppie(int N, int* C);

int main() {
	fr = stdin;
	fw = stdout;

	// Reading input
	fscanf(fr, " %d", &N);
	C = (int*)malloc((N) * sizeof(int));
	for (int i0 = 0; i0 < N; i0++) {
		fscanf(fr, " %d", &C[i0]);
	}

	// Calling functions
	res = coppie(N, C);

	// Writing output
	fprintf(fw, "%d\n", res);

	fclose(fr);
	fclose(fw);
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

struct Edge {
	int n, w;
};

class Graph {
protected:
	int N;
	vector<vector<struct Edge>> edges;
public:
	Graph(int N) {
		this->N = N;
		edges.assign(N, vector<struct Edge>());
	}

	size_t size() {
		return this->N;
	}

	void insertEdge(int a, int b) {
		insertEdge(a, b, 1);
	}

	void insertEdge(int a, int b, int w) {
		struct Edge e = {b, w};
		edges[a].push_back(e);
	}

	vector<struct Edge> adj(int n) {
		return edges[n];
	}
};

Graph g(0);
int TOTALE = 0;

// ritorna quanti figli nodi sono presenti nel suo
// sotto albero (compresa la radice)
int count_dfs(int node) {
    int tot = 0;
    for (auto e: g.adj(node)) {
        tot += count_dfs(e.n);
    }
    TOTALE += tot;
    return 1 + tot;
}

int coppie(int N, int *C) {
    int root;
	// costruisco il mio grafo a partire dal vettore dei padri
    g = Graph(N);
    for (int i = 0; i < N; i++) {
        if (C[i] != -1)
            g.insertEdge(C[i], i);
        else
            root = i;
    }
    count_dfs(root);
    return TOTALE;
}