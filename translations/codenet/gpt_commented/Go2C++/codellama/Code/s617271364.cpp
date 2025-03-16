
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Initialize global variables
int N, ss, ans, A, B, C;

// Declare a function to read input values
void readInput() {
	string X;
	cin >> X;
	stringstream ss(X);
	ss >> N >> A >> B >> C;
}

// Declare a function to calculate the cost of a distribution
int calc(vector<int> dp, vector<int> arr) {
	int cost = 0, AA = 0, BB = 0, CC = 0;
	vector<int> memo(4);
	for (int i = 0; i < N; i++) {
		memo[dp[i]]++;
		if (dp[i] == 1) {
			AA += arr[i];
		} else if (dp[i] == 2) {
			BB += arr[i];
		} else if (dp[i] == 3) {
			CC += arr[i];
		}
	}
	cost += abs(A - AA) + abs(B - BB) + abs(C - CC);
	for (int i = 1; i < 4; i++) {
		int a = memo[i];
		if (a < 1) {
			cost += 10000;
		} else {
			cost += (a - 1) * 10;
		}
	}
	return cost;
}

// Declare a function to perform depth-first search
void dfs(vector<int> dp, int times, vector<int> arr) {
	if (times >= N) {
		ans = min(ans, calc(dp, arr));
		return;
	}
	for (int i = 0; i < 4; i++) {
		dp[times] = i;
		dfs(dp, times + 1, arr);
	}
}

// Declare a function to read the next line of input
string nextLine() {
	string X;
	getline(cin, X);
	return X;
}

// Declare a function to find the minimum of two integers
int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

// Declare a function to find the absolute value of an integer
int abs(int a) {
	if (a < 0) {
		return a * -1;
	}
	return a;
}

int main() {
	readInput();
	vector<int> arr(N);
	vector<int> dp(N);
	ans = 10000;
	for (int i = 0; i < N; i++) {
		string Y = nextLine();
		stringstream ss(Y);
		int a;
		ss >> a;
		arr[i] = a;
	}
	dfs(dp, 0, arr);
	cout << ans << endl;
	return 0;
}

