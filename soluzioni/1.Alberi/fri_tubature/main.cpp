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

vector<int> SCELTA;
vector<bool> CITTA;
int *GUARDIE;

void dfs(int node) {

    int tmp = 0;

    for (auto a: g.adj(node)) {
        dfs(a.n);
        tmp += SCELTA[a.n];
    }
    // dobbiamo per forza inquinare anche questo nodo
    if (CITTA[node]) {
        SCELTA[node] = GUARDIE[node];
    }
    // dobbiamo inquinare uno dei suoi figli
    else if (tmp > 0) {
        CITTA[node] = true;
        SCELTA[node] = min(GUARDIE[node], tmp);
    }
}

int pianifica(int N, int M, int da[], int a[], int C[], int G[]) {
    GUARDIE = G;
    g = Graph(N);
    CITTA.assign(N, false);
    SCELTA.assign(N, 0);

    for (int i = 0; i < M; i++) {
        CITTA[C[i]] = true;
    }

    vector<bool> padri(N, true);

    for (int i = 0; i < N - 1; i++) {
        g.insertEdge(da[i], a[i]);
        padri[a[i]] = false;
    }
    
    int radice = 0;
    for (radice = 0; radice < N; radice++) {
        if (padri[radice]) break;
    }

    dfs(radice);
    return SCELTA[radice];
}