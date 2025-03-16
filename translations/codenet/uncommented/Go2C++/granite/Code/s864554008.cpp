
#include <iostream>
#include <string>
#include <vector>

struct data {
	int n, m;
	std::vector<std::string> nImg, mImg;
};

data newData() {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::string> nImg(n), mImg(m);
	for (auto &e : nImg) std::cin >> e;
	for (auto &e : mImg) std::cin >> e;
	return data{n, m, nImg, mImg};
}

bool exist(const data &d) {
	for (int i = 0; i <= d.n - d.m; i++) {
		for (int j = 0; j <= d.n - d.m; j++) {
			if (match(d, i, j)) return true;
		}
	}
	return false;
}

bool match(const data &d, int x, int y) {
	for (int i = 0; i < d.m; i++) {
		for (int j = 0; j < d.m; j++) {
			if (d.nImg[x + i][y + j]!= d.mImg[i][j]) return false;
		}
	}
	return true;
}

int main() {
	data d = newData();
	std::cout << (exist(d)? "Yes" : "No") << std::endl;
}

