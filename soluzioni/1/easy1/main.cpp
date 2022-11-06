#include <fstream>

using namespace std;

int main() {
	ifstream input ("input.txt");
	ofstream out ("output.txt");

	int N;
	input  >> N;

	int V[N];

	for (int i = 0; i < N; i++) {
		input >> V[i];
	}

	int MAX = V[0];
	for (int i = 1; i < N; i++) {
		if (MAX < V[i])
			MAX = V[i];
	}

	out << MAX;

	input.close();
	out.close();
	return 0;
}