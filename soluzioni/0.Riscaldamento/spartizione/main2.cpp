#include <bits/stdc++.h>
using namespace std;

pair<double, double> eq2(double a, double b, double c) {
	// x 1/2 = [-b +- sqrt(b ^ 2 - 4ac)] / 2a
	double det = pow(b, 2) - 4 * a * c;
	double x1 = (-b - sqrt(det)) / 2 * a;
	double x2 = (-b + sqrt(det)) / 2 * a;
	return {x1, x2};
}

int main() {
	ifstream in ("input.txt");
	ofstream out ("output.txt");

	int G, P;
	in >> G >> P;

	//int I = (-2 * P + 1 + sqrt(4 * pow(P, 2) - 4 * P + 1 + 8 * G)) / 2;

	auto sol = eq2(1, 2 * P - 1, -2 * G);
	int I = (int) sol.second;

	int T = I * (I + 1) / 2;
	G -= T + I * (P - 1);
	T += G;

	out << T;

	in.close();
	out.close();
	return 0;
}