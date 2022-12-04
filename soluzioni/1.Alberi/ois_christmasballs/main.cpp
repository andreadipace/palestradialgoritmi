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

vector<int> COLORS;
vector<unordered_map<int, int>> COUNT;
vector<pair<int, int>> MAX;
int ANSWER = 0;

Graph g(0);

void merge(int a1, int a2) {
    int m = MAX[a1].first, c = MAX[a1].second;

    for (auto e: COUNT[a2]) {
        COUNT[a1][e.first] += e.second;
        auto mn = COUNT[a1][e.first];
        if (mn > m) {
            m = mn;
            c = 1;
        }
        else if (mn == m) {
            c++;
        }
    }
    MAX[a1].first = m;
    MAX[a1].second = c;
}

void dfs(int node) {
    COUNT[node][COLORS[node]] = 1;

    auto adj = g.adj(node);

    if (adj.size() == 0) {
        MAX[node].first = 1;
        MAX[node].second = 1;
        return;
    }

    for (auto ad: adj) {
		dfs(ad.n);

        if (COUNT[node].size() < COUNT[ad.n].size()) { // small-to-large
            swap(COUNT[node], COUNT[ad.n]);
            swap(MAX[node], MAX[ad.n]);
        }

        merge(node, ad.n);
	}
    ANSWER = max(MAX[node].second, ANSWER);
}

int main() {
	int N;
	cin >> N;

    COLORS.resize(N);
    COUNT.resize(N);
    MAX.assign(N, {1, 1});
	g = Graph(N);

    for (int i = 0; i < N; i++) {
        cin >> COLORS[i];
    }

	for (int i = 1; i < N; i++) {
		int f;
        cin >> f;
		g.insertEdge(f, i);
	}
    dfs(0);
	cout << ANSWER << endl;
    return 0;
}
