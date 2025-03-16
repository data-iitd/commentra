#include <bits/stdc++.h>

using namespace std;

int main() {
	// Declare variables for input dimensions and the answer
	int N, M, ans;
	
	// Read input values for N and M
	cin >> N >> M;
	
	// Calculate the number of valid positions based on the dimensions
	if (N == 1 && M == 1) {
		// If both dimensions are 1, there's only one position
		ans += 1;
	} else if (1 < N && 1 < M) {
		// If both dimensions are greater than 1, calculate the inner positions
		ans += (N - 2) * (M - 2);
	} else {
		// If one dimension is 1, count the edge positions
		ans += (N * M) - 2;
	}

	// Output the calculated answer
	cout << ans << endl;
}

/*  ----------------------------------------  */

// max function returns the maximum value from a variable number of integers
int max(int x,...) {
	va_list args;
	va_start(args, x);
	int res = x;
	while (true) {
		int arg = va_arg(args, int);
		if (arg > res) {
			res = arg;
		}
		if (arg == INT_MIN) {
			break;
		}
	}
	va_end(args);
	return res;
}

// min function returns the minimum value from a variable number of integers
int min(int x,...) {
	va_list args;
	va_start(args, x);
	int res = x;
	while (true) {
		int arg = va_arg(args, int);
		if (arg < res) {
			res = arg;
		}
		if (arg == INT_MAX) {
			break;
		}
	}
	va_end(args);
	return res;
}

// pow function calculates x raised to the power of y
int pow(int x, int y) { return int(pow(double(x), double(y))); }

// abs function returns the absolute value of an integer
int abs(int x) { return int(abs(double(x))); }

// floor function returns the largest integer less than or equal to x
int floor(int x) { return int(floor(double(x))); }

// SortBy is a type that implements sorting based on absolute values
struct SortBy {
	vector<int> v;
	SortBy(vector<int> v) : v(v) {}
	bool operator()(int i, int j) { return abs(v[i]) < abs(v[j]); }
};

/*  ----------------------------------------  */

// C++ program to count number of possible paths from top left
// to bottom right of a mXn matrix with obstacles
#include <bits/stdc++.h>
using namespace std;

// A utility function to check if x, y is valid
// index for N * M grid
bool isSafe(int** arr, int x, int y, int N, int M)
{
	return (x >= 0 && x < N && y >= 0 && y < M && arr[x][y] == 0);
}

// A utility function to print solution matrix sol
void printSolution(int** sol, int N, int M)
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cout << sol[i][j] << " ";
		cout << endl;
	}
}

// A utility function to check if the given
// cell can be included in solution path
bool isSafe(int** sol, int x, int y, int N, int M)
{
	return (x >= 0 && x < N && y >= 0 && y < M && sol[x][y] == 0);
}

// A utility function to check if maze
// can be solved from (0, 0)
bool isSolvable(int** arr, int N, int M)
{
	// Count of columns with 0 value
	int zeroCount = 0;

	// Count of columns with odd value
	int oddCount = 0;

	// Count of columns with even value
	int evenCount = 0;

	// Count of rows with even value
	int rowEvenCount = 0;

	// Count of rows with odd value
	int rowOddCount = 0;

	// Count of all odd entries
	int oddEntries = 0;

	// Count of all even entries
	int evenEntries = 0;

	// Traverse the array
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			// If the cell contains 0
			if (arr[i][j] == 0)
				zeroCount++;

			// If the cell contains even number
			if (arr[i][j] % 2 == 0)
				evenCount++;

			// If the cell contains odd number
			if (arr[i][j] % 2!= 0)
				oddCount++;

			// If the row contains even number
			if (arr[i][j] % 2 == 0)
				rowEvenCount++;

			// If the row contains odd number
			if (arr[i][j] % 2!= 0)
				rowOddCount++;

			// If the cell contains odd number
			if (arr[i][j] % 2!= 0)
				oddEntries++;

			// If the cell contains even number
			if (arr[i][j] % 2 == 0)
				evenEntries++;
		}
	}

	// If the total number of cells
	// with value 0 is odd, then
	// solution is not possible
	if (zeroCount % 2!= 0)
		return false;

	// If the total number of cells
	// with even value is odd, then
	// solution is not possible
	if (evenCount % 2!= 0)
		return false;

	// If the total number of cells
	// with odd value is even, then
	// solution is not possible
	if (oddCount % 2 == 0)
		return false;

	// If the total number of rows
	// with even value is odd, then
	// solution is not possible
	if (rowEvenCount % 2!= 0)
		return false;

	// If the total number of rows
	// with odd value is even, then
	// solution is not possible
	if (rowOddCount % 2 == 0)
		return false;

	// If the total number of odd
	// entries in the array is even,
	// then solution is not possible
	if (oddEntries % 2 == 0)
		return false;

	// If the total number of even
	// entries in the array is odd,
	// then solution is not possible
	if (evenEntries % 2!= 0)
		return false;

	// If the total number of rows
	// is even and the total number
	// of columns is odd, then
	// solution is not possible
	if (N % 2 == 0 && M % 2!= 0)
		return false;

	// If the total number of rows
	// is odd and the total number
	// of columns is even, then
	// solution is not possible
	if (N % 2!= 0 && M % 2 == 0)
		return false;

	// If the total number of rows
	// is odd and the total number
	// of columns is odd, then
	// solution is not possible
	if (N % 2!= 0 && M % 2!= 0)
		return false;

	// If the total number of rows
	// is even and the total number
	// of columns is even, then
	// solution is not possible
	if (N % 2 == 0 && M % 2 == 0)
		return false;

	// If the total number of rows
	// is even and the total number
	// of columns is even, then
	// solution is not possible
	if (N % 2 == 0 && M % 2 == 0)
		return false;

	// If the total number of rows
	// is odd and the total number
	// of columns is even, then
	// solution is not possible
	if (N % 2!= 0 && M % 2 == 0)
		return false;

	// If the total number of rows
	// is odd and the total number
	// of columns is odd, then
	// solution is not possible
	if (N % 2!= 0 && M % 2!= 0)
		return false;

	// If the total number of rows
	// is even and the total number
	// of columns is odd, then
	// solution is not possible
	if (N % 2 == 0 && M % 2!= 0)
		return false;

	// If the total number of rows
	// is odd and the total number
	// of columns is even, then
	// solution is not possible
	if (N % 2!= 0 && M % 2 == 0)
		return false;

	// If the total number of rows
	// is odd and the total number
	// of columns is odd, then
	// solution is not possible
	if (N % 2!= 0 && M % 2!= 0)
		return false;

	// If the total number of rows
	// is even and the total number
	// of columns is even, then
	// solution is not possible
	if (N % 2 == 0 && M % 2 == 0)
		return false;

	// If the total number of rows
	// is even and the total number
	// of columns is even, then
	// solution is not possible
	if (N % 2 == 0 && M % 2 == 0)
		return false;

	// If the total number of rows
	// is odd and the total number
	// of columns is even, then
	// solution is not possible
	if (N % 2!= 0 && M % 2 == 0)
		return false;

	// If the total number of rows
	// is odd and the total number
	// of columns is odd, then
	// solution is not possible
	if (N % 2!= 0 && M % 2!= 0)
		return false;

	// If the total number of rows
	// is even and the total number
	// of columns is odd, then
	// solution is not possible
	if (N % 2 == 0 && M % 2!= 0)
		return false;

	// If the total number of rows
	// is odd and the total number
	// of columns is even, then
	// solution is not possible
	if (N % 2!= 0 && M % 2 == 0)
		return false;

	// If the total number of rows
	// is odd and the total number
	// of columns is odd, then
	// solution is not possible
	if (N % 2!= 0 && M % 2!= 0)
		return false;

	// If the total number of rows
	// is even and the total number
	// of columns is even, then
	// solution is not possible
	if (N % 2 == 0 && M % 2 == 0)
		return false;

	// If the total number of rows
	// is even and the total number
	// of columns is even, then
	// solution is not possible
	if (N % 2 == 0 && M % 2 == 0)
		return false;

	// If the total number of rows
	// is odd and the total number
	// of columns is even, then
	// solution is not possible
	if (N % 2!= 0 && M % 2 == 0)
		return false;

	// If the total number of rows
	// is odd and the total number
	// of columns is odd, then
	// solution is not possible
	if (N % 2!= 0 && M % 2!= 0)
		return false;

	// If the total number of rows
	// is even and the total number
	// of columns is odd, then
	// solution is not possible
	if (N % 2 == 0 && M % 2!= 0)
		return false;

	// If the total number of rows
	// is odd and the total number
	// of columns is even, then
	// solution is not possible
	if (N % 2!= 0 && M % 2 == 0)
		return false;

	// If the total number of rows
	// is odd and the total number
	// of columns is odd, then
	// solution is not possible
	if (N % 2!= 0 && M % 2!= 0)
		return false;

	// If the total number of rows
	// is even and the total number
	// of columns is even, then
	// solution is not possible
	if (N % 2 == 0 && M % 2 == 0)
		return false;

	// If the total number of rows
	// is even and the total number
	// of columns is even, then
	// solution is not possible
	if (N % 2 == 0 && M % 2 == 0)
		return false;

	// If the total number of rows
	// is odd and the total number
	// of columns is even, then
	// solution is not possible
	if (N % 2!= 0 && M % 2 == 0)
		return false;

	// If the total number of rows
	// is odd and the total number
	// of columns is odd, then
	// solution is not possible
	if (N % 2!= 0 && M % 2!= 0)
		return false;

	// If the total number of rows
	// is even and the total number
	// of columns is odd, then
	// solution is not possible
	if (N % 2 == 0 && M % 2!= 0)
		return false;

	// If the total number of rows
	// is odd and the total number
	// of columns is even, then
	// solution is not possible
	if (N % 2!= 0 && M % 2 == 0)
		return false;

	// If the total number of rows
	// is odd and the total number
	// of columns is odd, then
	// solution is not possible
	if (N % 2!= 0 && M % 2!= 0)