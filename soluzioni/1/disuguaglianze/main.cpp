#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream in ("input.txt");
	ofstream out ("output.txt");

	int N;
	in >> N;

	int i1 = 1, i2 = N;
	char c;

	for (int i = 0; i < N; i++) {
		in >> c;
		if (c == '>')
			out << i2-- << " ";
		else
			out << i1++ << " ";
	}

	in.close();
	out.close();
	return 0;
}