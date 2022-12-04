#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000010

static int N,i ;
static int preordine [MAXN] ;
static int postordine[MAXN] ;
static int simmetrica[MAXN] ;

void visita(int N, int *PRE, int *POST, int *SIMM);

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");

	in >> N;
	for (int i = 0; i < N; i++) {
		in >> preordine[i];
	}

	for (int i = 0; i < N; i++) {
		in >> postordine[i];
	}

	visita(N,preordine,postordine,simmetrica);

	for( i = 0 ; i < N ; i++ )
		cout << simmetrica[i] << " ";

	in.close();
	out.close();
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int INDEX_SIMM = 0;

// [a, b]
void idk(int *PRE, int *POST, int *SIMM, int a1, int b1, int a2, int b2) {
	int root = PRE[a1];
	int left = PRE[a1 + 1];
	int right = POST[b2 - 1];

	if (a1 == b1 && a2 == b2) {
		SIMM[INDEX_SIMM++] = root;
		return;
	}

	int end_pre;
	for (end_pre = b1; end_pre > a1; end_pre--) {
		if (PRE[end_pre] == right)
			break;
	}
	end_pre--;
	
	int start_post;
	for (start_post = a2; start_post < b2; start_post++) {
		if (POST[start_post] == left)
			break;
	}

	// left
	idk(PRE, POST, SIMM, a1 + 1, end_pre, a2, start_post);
	// middle
	SIMM[INDEX_SIMM++] = root;
	// right
	idk(PRE, POST, SIMM, end_pre + 1, b1, start_post + 1, b2 - 1);
}

void visita(int N, int *PRE, int *POST, int *SIMM) {
	idk(PRE, POST, SIMM, 0, N - 1, 0, N - 1);
}