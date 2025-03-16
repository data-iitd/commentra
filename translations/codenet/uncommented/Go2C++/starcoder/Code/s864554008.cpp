#include <iostream>
#include <string>

using namespace std;

struct data {
	int n, m;
	string nImg[100000];
	string mImg[100000];
};

int main() {
	data d = newData();
	if (d.exist()) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}

data newData() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> d.nImg[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> d.mImg[i];
	}

	return data{n: n, m: m};
}

bool exist(data d) {
	for (int i = 0; i <= d.n-d.m; i++) {
		for (int j = 0; j <= d.n-d.m; j++) {
			if (match(d, i, j)) {
				return true;
			}
		}
	}

	return false;
}

bool match(data d, int x, int y) {
	for (int i = 0; i < d.m; i++) {
		for (int j = 0; j < d.m; j++) {
			if (d.nImg[x+i][y+j]!= d.mImg[i][j]) {
				return false;
			}
		}
	}

	return true;
}

