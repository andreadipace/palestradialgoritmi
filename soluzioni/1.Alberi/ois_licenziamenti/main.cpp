#include <bits/stdc++.h>
using namespace std;

#define vt vector
#define pb push_back

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

int cont = 0;
vt<int> BRAVURA;

Graph g(0);

void dfs(int node, int vmin) {
	int b = BRAVURA[node];

	if (node != 0 && b > vmin)
		cont++;
	
	vmin = min(vmin, b);

	for (auto ad: g.adj(node)) {
		dfs(ad.n, vmin);
	}
}

int main() {
	ifstream in ("input.txt");
	ofstream out ("output.txt");

	int N;
	in >> N;
	
	BRAVURA.resize(N);
	g = Graph(N);

	int b, p;
	in >> b >> p;
	BRAVURA[0] = b;

	for (int i = 1; i < N; i++) {
		in >> b >> p;
		BRAVURA[i] = b;
		g.insertEdge(p, i);
	}

	dfs(0, INT32_MAX);
	out << cont;

	in.close();
	out.close();
	return 0;
}
