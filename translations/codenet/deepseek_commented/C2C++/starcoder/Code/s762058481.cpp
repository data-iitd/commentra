#include <bits/stdc++.h>

using namespace std;

// Function to return the smaller value between two integers
int chmin(int a, int b)
{
	if (a > b)
		return b;
	else
		return a;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;  // Read the number of elements
	int dp[n];        // Declare the dp array
	int h[n];         // Declare the h array
	for (int i = 0; i < n; ++i)
		dp[i] = 10000; // Initialize the dp array to a large value

	for (int i = 0; i < n; ++i)
		cin >> h[i]; // Read the heights into the h array

	dp[0] = 0; // Starting point with no cost
	for (int i = 1; i < n; ++i)
	{
		if (i == 1)
			dp[1] = abs(h[1] - h[0]); // Cost to reach the first step
		else
			dp[i] = chmin(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2])); // Calculate the minimum cost to reach the current step
	}
	cout << dp[n - 1] << endl; // Print the minimum cost to reach the last step
	return 0;
}

