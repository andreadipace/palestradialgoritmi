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

	const vector<struct Edge>& adj(int n) const {
		return edges[n];
	}
};

Graph g(0);
vector<int> value;

void visitDFS(int node) {
	int cont = 0;
	for (auto ad: g.adj(node)) {
		auto n = ad.n;
		visitDFS(n);
		// sommo i figli
		cont += value[n];
	}
	// aggiorno la scelta
	value[node] = max(cont, value[node]);
}

int main() {
	ifstream in ("input.txt");
	ofstream out ("output.txt");

	int N;
	in >> N;

	g = Graph(N);
	value.resize(N);

	int w, p;
	in >> w >> p;
	value[0] = w;

	for (int i = 1; i < N; i++) {
		in >> w >> p;
		value[i] = w;
		g.insertEdge(p, i);
	}

	visitDFS(0);

	out << value[0];

	in.close();
	out.close();
	return 0;
}