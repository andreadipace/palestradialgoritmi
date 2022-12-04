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
vector<int> MONETE;
int TOTAL = 0;

// ritorna il debito di monete
int cont_dfs(int node) {

    auto adj = g.adj(node);
    int saldo_figli = 0;

    for (auto e: adj) {
        int saldo = cont_dfs(e.n);
        TOTAL += abs(saldo); // accumulo il saldo che equivale alle monete da spostare
        saldo_figli += saldo;
    }

    if (MONETE[node] == 0) {
        saldo_figli -= 1; // se non ho una moneta, ne prendo una e la scalo/aggiungo al saldo dei figli
    }
    else {
        int avanzo = MONETE[node] - 1;
        saldo_figli += avanzo;
    }
    return saldo_figli;
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int N;
    in >> N;

    MONETE.resize(N);
    g = Graph(N);

    for (int i = 0; i < N; i++) {
        in >> MONETE[i];
    }

    for (int i = 1; i < N; i++) {
        int a;
        in >> a;
        g.insertEdge(a - 1, i);
    }

    cont_dfs(0);
    out << TOTAL << endl;

    in.close();
    out.close();
    return 0;
}