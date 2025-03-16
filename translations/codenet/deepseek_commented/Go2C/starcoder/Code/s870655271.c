
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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
typedef struct {
	int *a;
	int n;
} SortBy;

// This function returns the length of the slice.
int SortBy_len(SortBy a) { return a.n; }

// This function swaps the elements with indexes i and j.
void SortBy_swap(SortBy a, int i, int j) {
	int t = a.a[i];
	a.a[i] = a.a[j];
	a.a[j] = t;
}

// This function returns true if the absolute value of the element at index i is less than the absolute value of the element at index j.
int SortBy_less(SortBy a, int i, int j) { return abs(a.a[i]) < abs(a.a[j]); }

int main() {
	int N, M, ans;
	scanf("%d %d", &N, &M);
	// If both N and M are 1, there is only one cell, so the answer is 1.
	if (N == 1 && M == 1) {
		ans += 1;
	} else if (1 < N && 1 < M) {
		// If both N and M are greater than 1, the number of cells is (N-2)*(M-2).
		ans += (N - 2) * (M - 2);
	} else {
		// If either N or M is 1, the number of cells is (N*M) - 2.
		ans += (N * M) - 2;
	}
	printf("%d\n", ans);
	return 0;
}

/*  ----------------------------------------  */

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
typedef struct {
	int *a;
	int n;
} SortBy;

// This function returns the length of the slice.
int SortBy_len(SortBy a) { return a.n; }

// This function swaps the elements with indexes i and j.
void SortBy_swap(SortBy a, int i, int j) {
	int t = a.a[i];
	a.a[i] = a.a[j];
	a.a[j] = t;
}

// This function returns true if the absolute value of the element at index i is less than the absolute value of the element at index j.
int SortBy_less(SortBy a, int i, int j) { return abs(a.a[i]) < abs(a.a[j]); }

int main() {
	int N, M, ans;
	scanf("%d %d", &N, &M);
	// If both N and M are 1, there is only one cell, so the answer is 1.
	if (N == 1 && M == 1) {
		ans += 1;
	} else if (1 < N && 1 < M) {
		// If both N and M are greater than 1, the number of cells is (N-2)*(M-2).
		ans += (N - 2) * (M - 2);
	} else {
		// If either N or M is 1, the number of cells is (N*M) - 2.
		ans += (N * M) - 2;
	}
	printf("%d\n", ans);
	return 0;
}

/*  ----------------------------------------  */

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
typedef struct {
	int *a;
	int n;
} SortBy;

// This function returns the length of the slice.
int SortBy_len(SortBy a) { return a.n; }

// This function swaps the elements with indexes i and j.
void SortBy_swap(SortBy a, int i, int j) {
	int t = a.a[i];
	a.a[i] = a.a[j];
	a.a[j] = t;
}

// This function returns true if the absolute value of the element at index i is less than the absolute value of the element at index j.
int SortBy_less(SortBy a, int i, int j) { return abs(a.a[i]) < abs(a.a[j]); }

int main() {
	int N, M, ans;
	scanf("%d %d", &N, &M);
	// If both N and M are 1, there is only one cell, so the answer is 1.
	if (N == 1 && M == 1) {
		ans += 1;
	} else if (1 < N && 1 < M) {
		// If both N and M are greater than 1, the number of cells is (N-2)*(M-2).
		ans += (N - 2) * (M - 2);
	} else {
		// If either N or M is 1, the number of cells is (N*M) - 2.
		ans += (N * M) - 2;
	}
	printf("%d\n", ans);
	return 0;
}

/*  ----------------------------------------  */

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
typedef struct {
	int *a;
	int n;
} SortBy;

// This function returns the length of the slice.
int SortBy_len(SortBy a) { return a.n; }

// This function swaps the elements with indexes i and j.
void SortBy_swap(SortBy a, int i, int j) {
	int t = a.a[i];
	a.a[i] = a.a[j];
	a.a[j] = t;
}

// This function returns true if the absolute value of the element at index i is less than the absolute value of the element at index j.
int SortBy_less(SortBy a, int i, int j) { return abs(a.a[i]) < abs(a.a[j]); }

int main() {
	int N, M, ans;
	scanf("%d %d", &N, &M);
	// If both N and M are 1, there is only one cell, so the answer is 1.
	if (N == 1 && M == 1) {
		ans += 1;
	} else if (1 < N && 1 < M) {
		// If both N and M are greater than 1, the number of cells is (N-2)*(M-2).
		ans += (N - 2) * (M - 2);
	} else {
		// If either N or M is 1, the number of cells is (N*M) - 2.
		ans += (N * M) - 2;
	}
	printf("%d\n", ans);
	return 0;
}

/*  ----------------------------------------  */

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
typedef struct {
	int *a;
	int n;
} SortBy;

// This function returns the length of the slice.
int SortBy_len(SortBy a) { return a.n; }

// This function swaps the elements with indexes i and j.
void SortBy_swap(SortBy a, int i, int j) {
	int t = a.a[i];
	a.a[i] = a.a[j];
	a.a[j] = t;
}

// This function returns true if the absolute value of the element at index i is less than the absolute value of the element at index j.
int SortBy_less(SortBy a, int i, int j) { return abs(a.a[i]) < abs(a.a[j]); }

int main() {
	int N, M, ans;
	scanf("%d %d", &N, &M);
	// If both N and M are 1, there is only one cell, so the answer is 1.
	if (N == 1 && M == 1) {
		ans += 1;
	} else if (1 < N && 1 < M) {
		// If both N and M are greater than 1, the number of cells is (N-2)*(M-2).
		ans += (N - 2) * (M - 2);
	} else {
		// If either N or M is 1, the number of cells is (N*M) - 2.
		ans += (N * M) - 2;
	}
	printf("%d\n", ans);
	return 0;
}

/*  ----------------------------------------  */

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
typedef struct {
	int *a;
	int n;
} SortBy;

// This function returns the length of the slice.
int SortBy_len(SortBy a) { return a.n; }

// This function swaps the elements with indexes i and j.
void SortBy_swap(SortBy a, int i, int j) {
	int t = a.a[i];
	a.a[i] = a.a[j];
	a.a[j] = t;
}

// This function returns true if the absolute value of the element at index i is less than the absolute value of the element at index j.
int SortBy_less(SortBy a, int i, int j) { return abs(a.a[i]) < abs(a.a[j]); }

int main() {
	int N, M, ans;
	scanf("%d %d", &N, &M);
	// If both N and M are 1, there is only one cell, so the answer is 1.
	if (N == 1 && M == 1) {
		ans += 1;
	} else if (1 < N && 1 < M) {
		// If both N and M are greater than 1, the number of cells is (N-2)*(M-2).
		ans += (N - 2) * (M - 2);
	} else {
		// If either N or M is 1, the number of cells is (N*M) - 2.
		ans += (N * M) - 2;
	}
	printf("%d\n", ans);
	return 0;
}

/*  ----------------------------------------  */

// This function returns the maximum value among the given integers.
int max(int x, int y) { return x > y? x : y; }

// This function returns the minimum value among the given integers.
int min(int x, int y) { return x < y? x : y; }

// This function returns x 