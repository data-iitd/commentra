#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> aa(n);

	for (int i = 0; i < n; i++) {
		cin >> aa[i];
	}

	vector<int> cumsum = CumSum(aa); // Compute the cumulative sum of the integers.

	//cout << cumsum << endl; // Uncomment to print the cumulative sum for debugging purposes.
	int ans = 2020202020;
	for (int i = 1; i < cumsum.size()-1; i++) {
		ans = min(ans, abs(cumsum[cumsum.size()-1]-cumsum[i]-(cumsum[i]-cumsum[0])));
	}

	cout << ans << endl; // Print the minimum absolute difference.

}

// CumSum computes the cumulative sum of a slice of integers.
vector<int> CumSum(vector<int> nums) {
	vector<int> sums = {0};

	for (int i = 0; i < nums.size(); i++) {
		sums.push_back(sums[i]+nums[i]);
	}
	return sums;
}

// Abs returns the absolute value of an integer.
int Abs(int a) {
	if (a >= 0) {
		return a;
	} else {
		return -a;
	}
}

// Min returns the minimum value among the given integers.
int Min(int nums[], int n) {
	if (n == 0) {
		panic("function min() requires at least one argument.");
	}
	int res = nums[0];
	for (int i = 0; i < n; i++) {
		res = min(res, nums[i]);
	}
	return res;
}

