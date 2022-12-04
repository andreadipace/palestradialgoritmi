#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream in ("input.txt");
	ofstream out ("output.txt");

	int N, M;
	in >> N >> M;
	vector<int> alberi(N);

	for (int i = 0; i < N; i++)
		in >> alberi[i];

	int cont = 0;
	for (int i = 0; i < M; i++) {
		int a, b;
		in >> a >> b;
		if (alberi[a] && alberi[b])
			cont++;
	}
	out << cont;
	in.close();
	out.close();
	return 0;
}
