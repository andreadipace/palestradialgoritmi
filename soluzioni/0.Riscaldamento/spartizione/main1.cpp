#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream in ("input.txt");
	ofstream out ("output.txt");

	int G, P;
	in >> G >> P;

	int T = 0;
	for (int i = 1;;i++) {
		if (G < i)
			break;
		T += i;
		G -= i + P - 1;
	}
	T += G;
	out << T;

	in.close();
	out.close();
	return 0;
}