#include <bits/stdc++.h>

using namespace std;

// reva takes a vector of integers and reverses it in place.
void reva(vector<int> &b) {
	for (int i = 0; i < b.size()/2; i++) {
		swap(b[i], b[b.size()-1-i]);
	}
}

// main is the entry point of the program.
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int b, e; cin >> b >> e;
		reva(a.begin()+b, a.begin()+e);
	}
	for (int i = 0; i < n; i++) {
		if (i > 0) {
			cout << " ";
		}
		cout << a[i];
	}
	cout << "\n";
	return 0;
}

