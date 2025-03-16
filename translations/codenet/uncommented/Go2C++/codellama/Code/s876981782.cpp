#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<float> values(N);
	for (int i = 0; i < N; i++) {
		cin >> values[i];
	}

	sort(values.begin(), values.end());
	float generated = 0;
	//fmt.Println(values)
	for (int i = 0; i < N-1; i++) {
		generated = (values[i] + values[i+1]) / 2;
		values[i+1] = generated;
	}

	cout << generated << endl;
	return 0;
}

