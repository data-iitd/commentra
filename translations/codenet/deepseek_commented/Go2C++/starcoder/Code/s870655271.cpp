
#include <bits/stdc++.h>
using namespace std;

// This function returns the maximum value among the given integers.
int max(int x, int y) { return x > y? x : y; }

// This function returns the minimum value among the given integers.
int min(int x, int y) { return x < y? x : y; }

// This function returns x raised to the power of y.
int pow(int x, int y) { return (int)pow((double)x, (double)y); }

// This function returns the absolute value of x.
int abs(int x) { return x < 0? -x : x; }

// This function returns the floor value of x.
int floor(int x) { return (int)floor((double)x); }

// This type is a slice of integers that can be sorted by their absolute values.
typedef vector<int> SortBy;

// This function returns the length of the slice.
int len(SortBy a) { return (int)a.size(); }

// This function swaps the elements with indexes i and j.
void swap(SortBy &a, int i, int j) { int t = a[i]; a[i] = a[j]; a[j] = t; }

// This function returns true if the absolute value of the element at index i is less than the absolute value of the element at index j.
bool less(SortBy a, int i, int j) { return abs(a[i]) < abs(a[j]); }

// This function sorts the slice by their absolute values.
void sort(SortBy &a) { sort(a.begin(), a.end(), less); }

// This function returns the number of cells in the grid.
int countCells(int N, int M) {
	// If both N and M are 1, there is only one cell, so the answer is 1.
	if (N == 1 && M == 1) return 1;
	// If both N and M are greater than 1, the number of cells is (N-2)*(M-2).
	if (1 < N && 1 < M) return (N - 2) * (M - 2);
	// If either N or M is 1, the number of cells is (N*M) - 2.
	return (N * M) - 2;
}

// This function prints the result to the standard output.
void printResult(int ans) {
	cout << ans << endl;
}

// This is the main function where the program starts execution.
// It reads two integers N and M from the standard input.
// Depending on the values of N and M, it calculates the number of cells in the grid.
// Finally, it prints the result to the standard output.
int main() {
	int N, M, ans;
	cin >> N >> M;
	ans = countCells(N, M);
	printResult(ans);
	return 0;
}

/*  ----------------------------------------  */

// This function returns the number of cells in the grid.
int countCells(int N, int M) {
	// If both N and M are 1, there is only one cell, so the answer is 1.
	if (N == 1 && M == 1) return 1;
	// If both N and M are greater than 1, the number of cells is (N-2)*(M-2).
	if (1 < N && 1 < M) return (N - 2) * (M - 2);
	// If either N or M is 1, the number of cells is (N*M) - 2.
	return (N * M) - 2;
}

// This function prints the result to the standard output.
void printResult(int ans) {
	cout << ans << endl;
}

// This is the main function where the program starts execution.
// It reads two integers N and M from the standard input.
// Depending on the values of N and M, it calculates the number of cells in the grid.
// Finally, it prints the result to the standard output.
int main() {
	int N, M, ans;
	cin >> N >> M;
	ans = countCells(N, M);
	printResult(ans);
	return 0;
}

/*  ----------------------------------------  */

// This function returns the number of cells in the grid.
int countCells(int N, int M) {
	// If both N and M are 1, there is only one cell, so the answer is 1.
	if (N == 1 && M == 1) return 1;
	// If both N and M are greater than 1, the number of cells is (N-2)*(M-2).
	if (1 < N && 1 < M) return (N - 2) * (M - 2);
	// If either N or M is 1, the number of cells is (N*M) - 2.
	return (N * M) - 2;
}

// This function prints the result to the standard output.
void printResult(int ans) {
	cout << ans << endl;
}

// This is the main function where the program starts execution.
// It reads two integers N and M from the standard input.
// Depending on the values of N and M, it calculates the number of cells in the grid.
// Finally, it prints the result to the standard output.
int main() {
	int N, M, ans;
	scanf("%d %d", &N, &M);
	ans = countCells(N, M);
	printResult(ans);
	return 0;
}

/*  ----------------------------------------  */

// This function returns the number of cells in the grid.
int countCells(int N, int M) {
	// If both N and M are 1, there is only one cell, so the answer is 1.
	if (N == 1 && M == 1) return 1;
	// If both N and M are greater than 1, the number of cells is (N-2)*(M-2).
	if (1 < N && 1 < M) return (N - 2) * (M - 2);
	// If either N or M is 1, the number of cells is (N*M) - 2.
	return (N * M) - 2;
}

// This function prints the result to the standard output.
void printResult(int ans) {
	printf("%d\n", ans);
}

// This is the main function where the program starts execution.
// It reads two integers N and M from the standard input.
// Depending on the values of N and M, it calculates the number of cells in the grid.
// Finally, it prints the result to the standard output.
int main() {
	int N, M, ans;
	scanf("%d %d", &N, &M);
	ans = countCells(N, M);
	printResult(ans);
	return 0;
}

/*  ----------------------------------------  */

// This function returns the number of cells in the grid.
int countCells(int N, int M) {
	// If both N and M are 1, there is only one cell, so the answer is 1.
	if (N == 1 && M == 1) return 1;
	// If both N and M are greater than 1, the number of cells is (N-2)*(M-2).
	if (1 < N && 1 < M) return (N - 2) * (M - 2);
	// If either N or M is 1, the number of cells is (N*M) - 2.
	return (N * M) - 2;
}

// This function prints the result to the standard output.
void printResult(int ans) {
	printf("%d\n", ans);
}

// This is the main function where the program starts execution.
// It reads two integers N and M from the standard input.
// Depending on the values of N and M, it calculates the number of cells in the grid.
// Finally, it prints the result to the standard output.
int main() {
	int N, M, ans;
	scanf("%d %d", &N, &M);
	ans = countCells(N, M);
	printf("%d\n", ans);
	return 0;
}

/*  ----------------------------------------  */

// This function returns the number of cells in the grid.
int countCells(int N, int M) {
	// If both N and M are 1, there is only one cell, so the answer is 1.
	if (N == 1 && M == 1) return 1;
	// If both N and M are greater than 1, the number of cells is (N-2)*(M-2).
	if (1 < N && 1 < M) return (N - 2) * (M - 2);
	// If either N or M is 1, the number of cells is (N*M) - 2.
	return (N * M) - 2;
}

// This function prints the result to the standard output.
void printResult(int ans) {
	printf("%d\n", ans);
}

// This is the main function where the program starts execution.
// It reads two integers N and M from the standard input.
// Depending on the values of N and M, it calculates the number of cells in the grid.
// Finally, it prints the result to the standard output.
int main() {
	int N, M, ans;
	scanf("%d %d", &N, &M);
	ans = countCells(N, M);
	printf("%d\n", ans);
	return 0;
}

/*  ----------------------------------------  */

// This function returns the number of cells in the grid.
int countCells(int N, int M) {
	// If both N and M are 1, there is only one cell, so the answer is 1.
	if (N == 1 && M == 1) return 1;
	// If both N and M are greater than 1, the number of cells is (N-2)*(M-2).
	if (1 < N && 1 < M) return (N - 2) * (M - 2);
	// If either N or M is 1, the number of cells is (N*M) - 2.
	return (N * M) - 2;
}

// This function prints the result to the standard output.
void printResult(int ans) {
	printf("%d\n", ans);
}

// This is the main function where the program starts execution.
// It reads two integers N and M from the standard input.
// Depending on the values of N and M, it calculates the number of cells in the grid.
// Finally, it prints the result to the standard output.
int main() {
	int N, M, ans;
	scanf("%d %d", &N, &M);
	ans = countCells(N, M);
	printf("%d\n", ans);
	return 0;
}

/*  ----------------------------------------  */

// This function returns the number of cells in the grid.
int countCells(int N, int M) {
	// If both N and M are 1, there is only one cell, so the answer is 1.
	if (N == 1 && M == 1) return 1;
	// If both N and M are greater than 1, the number of cells is (N-2)*(M-2).
	if (1 < N && 1 < M) return (N - 2) * (M - 2);
	// If either N or M is 1, the number of cells is (N*M) - 2.
	return (N * M) - 2;
}

// This function prints the result to the standard output.
void printResult(int ans) {
	printf("%d\n", ans);
}

// This is the main function where the program starts execution.
// It reads two integers N and M from the standard input.
// Depending on the values of N and M, it calculates the number of cells in the grid.
// Finally, it prints the result to the standard output.
int main() {
	int N, M, ans;
	scanf("%d %d", &N, &M);
	ans = countCells(N, M);
	printf("%d\n", ans);
	return 0;
}

/*  ----------------------------------------  */

// This function returns the number of cells in the grid.
int countCells(int N, int M) {
	// If both N and M are 1, there is only one cell, so the answer is 1.
	if (N == 1 && M == 1) return 1;
	// If both N and M are greater than 1, the number of cells is (N-2)*(M-2).
	if (1 < N && 1 < M) return (N - 2) * (M - 2);
	// If either N or M is 1, the number of cells is (N*M) - 2.
	return (N * M) - 2;
}

// This function prints the result to the standard output.
void printResult(int ans) {
	printf("%d\n", ans);
}

// This is the main function where the program starts execution.
// It reads two integers N and M from the standard input.
// Depending on the values of N and M, it calculates the number of cells in the grid.
// Finally, it prints the result to the standard output.
int main() {
	int N, M, ans;
	scanf("%d %d", &N, &M);
	ans = countCells(N, M);
	printf("%d\n", ans);
	return 0;
}

/*  ----------------------------------------  */

// This function returns the number of cells in the grid.
int countCells(int N, int M) {
	// If both N and M are 1, there is only one cell, so the answer is 1.
	if (N == 1 && M == 1) return 1;
	// If both N and M are greater than 1, the number of cells is (N-2)*(M-2).
	if (1 < N