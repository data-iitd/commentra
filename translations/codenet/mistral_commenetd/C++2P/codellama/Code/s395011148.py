#include <iostream>
#include <algorithm> // We include the algorithm library to use functions like max()
using namespace std; // We use the standard namespace to avoid writing std:: before every standard library function

long long N, A[1 << 18]; // We declare the variables N and A of type long long
long long dp[1 << 18][2][20]; // We declare a 3-dimensional array dp of size (1 << 18) x 2 x 20

int main() {
	cin >> N; // We read the value of N from the standard input
	for (int i = 1; i <= N; i++) cin >> A[i]; // We read the values of the array A from the standard input

	# Initialize dp array with minimum values
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j < 20; j++) {
			dp[i][0][j] = -(1LL << 60); // Initialize dp[i][0][j] with a very large negative value
			dp[i][1][j] = -(1LL << 60); // Initialize dp[i][1][j] with a very large negative value
		}
	}

	# Base case: dp[0][0][10] = 0
	dp[0][0][10] = 0;

	# Iterate through all the elements of the array A
	for (int i = 1; i <= N; i++) {
		for (int j = 6; j <= 14; j++) { # We only consider the cases where j is between 6 and 14
			if (dp[i - 1][0][j] != (1LL << 60)): # If dp[i-1][0][j] is not equal to the very large negative value
				dp[i][1][j + 1] = max(dp[i][1][j + 1], dp[i - 1][0][j] + A[i]); # Update dp[i][1][j+1] with the maximum of its current value and dp[i-1][0][j] + A[i]
				dp[i][0][j - 1] = max(dp[i][0][j - 1], dp[i - 1][0][j]); # Update dp[i][0][j-1] with the maximum of its current value and dp[i-1][0][j]
			if (dp[i - 1][1][j] != (1LL << 60)): # If dp[i-1][1][j] is not equal to the very large negative value
				dp[i][0][j - 1] = max(dp[i][0][j - 1], dp[i - 1][1][j]); # Update dp[i][0][j-1] with the maximum of its current value and dp[i-1][1][j]
		}
	}

	# Calculate the value of T1 and T2
	V = 10LL + (N / 2) - (N - (N / 2));
	T1 = dp[N][0][V];
	T2 = dp[N][1][V];

	# Print the maximum value of T1 and T2
	print(max(T1, T2));

	return 0;
}

