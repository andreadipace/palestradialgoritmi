#include <fstream>

using namespace std;

int main() {
	ifstream input ("input.txt");
	ofstream out ("output.txt");

	int N;
	input  >> N;
	int MAX = -1;

	for (int i = 0; i < N; i++) {
		int a, b, s;
		input >> a >> b;
		s = a + b;
		if (s % 2 == 0 && MAX < s)
			MAX = s;
	}
	
	out << MAX;

	input.close();
	out.close();
	return 0;
}