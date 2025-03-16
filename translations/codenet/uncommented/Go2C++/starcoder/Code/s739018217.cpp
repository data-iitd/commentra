#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int x = m*1900 + (n-m)*100;
	cout << x * pow(2.0, m) << endl;
}

