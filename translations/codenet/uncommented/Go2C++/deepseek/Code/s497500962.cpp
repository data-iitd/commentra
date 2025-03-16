#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int nextInt() {
	int i;
	cin >> i;
	return i;
}

float nextFloat() {
	float f;
	cin >> f;
	return f;
}

string nextString() {
	string s;
	cin >> s;
	return s;
}

int abs(int x) {
	return abs(x);
}

int min(int x, int y) {
	return min(x, y);
}

int max(int x, int y) {
	return max(x, y);
}

float abs(float x) {
	return abs(x);
}

float min(float x, float y) {
	return min(x, y);
}

float max(float x, float y) {
	return max(x, y);
}

int main() {
	int R = nextInt();
	int G = nextInt();
	int B = nextInt();
	int N = nextInt();

	int ans = 0;
	for (int x = 0; x <= N; x++) {
		for (int y = 0; y <= N; y++) {
			int tmp = N - R * x - G * y;
			if (tmp >= 0 && tmp % B == 0) {
				ans++;
			}
		}
	}

	cout << ans << endl;
}
