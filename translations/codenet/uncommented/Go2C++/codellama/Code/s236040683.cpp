
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void out(int x) {
	cout << x << endl;
}

int getInt() {
	int x;
	cin >> x;
	return x;
}

string getString() {
	string x;
	cin >> x;
	return x;
}

// Node :
struct Node {
	vector<int> to;
};

int main() {
	int N, M;
	cin >> N >> M;
	vector<Node> n(N);
	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		n[from-1].to.push_back(to-1);
		n[to-1].to.push_back(from-1);
	}

	for (int i = 0; i < N; i++) {
		out(n[i].to.size());
	}

	return 0;
}

