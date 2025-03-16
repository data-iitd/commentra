#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// This function returns the maximum value among the given integers.
int max(int x, int y) {
	return x > y ? x : y;
}

// This function returns the minimum value among the given integers.
int min(int x, int y) {
	return x < y ? x : y;
}

// This function returns x raised to the power of y.
int pow(int x, int y) {
	return (int)pow(x, y);
}

// This function returns the absolute value of x.
int abs(int x) {
	return x < 0 ? -x : x;
}

// This function returns the floor value of x.
int floor(int x) {
	return (int)floor(x);
}

// This type is a slice of integers that can be sorted by their absolute values.
typedef struct {
	int *arr;
	int len;
} SortBy;

// Len returns the length of the slice.
int len(SortBy a) {
	return a.len;
}

// Swap swaps the elements with indexes i and j.
void swap(SortBy a, int i, int j) {
	int temp = a.arr[i];
	a.arr[i] = a.arr[j];
	a.arr[j] = temp;
}

// Less returns true if the absolute value of the element at index i is less than the absolute value of the element at index j.
int less(SortBy a, int i, int j) {
	return abs(a.arr[i]) < abs(a.arr[j]);
}

int main() {
	int N, M;
	int ans = 0;
	scanf("%d %d", &N, &M);
	if (N == 1 && M == 1) {
		ans += 1;
	} else if (1 < N && 1 < M) {
		ans += (N - 2) * (M - 2);
	} else {
		ans += (N * M) - 2;
	}

	printf("%d\n", ans);
	return 0;
}

