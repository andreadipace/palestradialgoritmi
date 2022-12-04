#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream input ("input.txt");
	ofstream out ("output.txt");

	int N, cP = 0, cD = 0;
	input >> N;

	int P[N], D[N];

	for (int i = 0; i < N; i++) {
		int n;
		input >> n;
		if (n % 2) {
			D[cD] = n;
			cD++;
		}
		else {
			P[cP] = n;
			cP++;
		}
	}

	sort(P, P + cP);
	sort(D, D + cD);
	int pari_somma = -1, dispari_somma = -1;
	
	if (cP >= 2) {
		pari_somma = P[cP - 1] + P[cP - 2];
	}

	if (cD >= 2) {
		dispari_somma = D[cD - 1] + D[cD - 2];
	}
	

	int MAX = max(dispari_somma, pari_somma);
	out << MAX;

	
	input.close();
	out.close();
	return 0;
}