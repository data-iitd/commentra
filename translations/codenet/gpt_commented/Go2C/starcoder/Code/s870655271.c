

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
	// Declare variables for input dimensions and the answer
	int N, M, ans;
	
	// Read input values for N and M
	scanf("%d %d", &N, &M);
	
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
	printf("%d", ans);
}

/*  ----------------------------------------  */

// max function returns the maximum value from a variable number of integers
int max(int x,...) {
	va_list args;
	va_start(args, x);
	int res = x;
	int arg;
	while ((arg = va_arg(args, int))!= 0) {
		res = (res > arg)? res : arg;
	}
	va_end(args);
	return res;
}

// min function returns the minimum value from a variable number of integers
int min(int x,...) {
	va_list args;
	va_start(args, x);
	int res = x;
	int arg;
	while ((arg = va_arg(args, int))!= 0) {
		res = (res < arg)? res : arg;
	}
	va_end(args);
	return res;
}

// pow function calculates x raised to the power of y
int pow(int x, int y) { return (int)pow(x, y); }

// abs function returns the absolute value of an integer
int abs(int x) { return (x < 0)? -x : x; }

// floor function returns the largest integer less than or equal to x
int floor(int x) { return (int)floor(x); }

// SortBy is a type that implements sorting based on absolute values
typedef struct {
	int *arr;
	int len;
} SortBy;

// Len returns the number of elements in the SortBy slice
int SortBy_len(SortBy *a) { return a->len; }

// Swap exchanges the elements with indexes i and j in the SortBy slice
void SortBy_swap(SortBy *a, int i, int j) {
	int tmp = a->arr[i];
	a->arr[i] = a->arr[j];
	a->arr[j] = tmp;
}

// Less reports whether the element with index i should sort before the element with index j
int SortBy_less(SortBy *a, int i, int j) { return abs(a->arr[i]) < abs(a->arr[j]); }

// SortBy_sort sorts the SortBy slice using the less function
void SortBy_sort(SortBy *a) { qsort(a->arr, a->len, sizeof(int), (int (*)(const void *, const void *))SortBy_less); }

// SortBy_new creates a new SortBy slice
SortBy *SortBy_new(int *arr, int len) {
	SortBy *a = malloc(sizeof(SortBy));
	a->arr = arr;
	a->len = len;
	return a;
}

// SortBy_free frees the memory of a SortBy slice
void SortBy_free(SortBy *a) { free(a); }

// main function
int main() {
	// Declare variables for input dimensions and the answer
	int N, M, ans;
	
	// Read input values for N and M
	scanf("%d %d", &N, &M);
	
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
	printf("%d", ans);
}

/*  ----------------------------------------  */

// max function returns the maximum value from a variable number of integers
int max(int x,...) {
	va_list args;
	va_start(args, x);
	int res = x;
	int arg;
	while ((arg = va_arg(args, int))!= 0) {
		res = (res > arg)? res : arg;
	}
	va_end(args);
	return res;
}

// min function returns the minimum value from a variable number of integers
int min(int x,...) {
	va_list args;
	va_start(args, x);
	int res = x;
	int arg;
	while ((arg = va_arg(args, int))!= 0) {
		res = (res < arg)? res : arg;
	}
	va_end(args);
	return res;
}

// pow function calculates x raised to the power of y
int pow(int x, int y) { return (int)pow(x, y); }

// abs function returns the absolute value of an integer
int abs(int x) { return (x < 0)? -x : x; }

// floor function returns the largest integer less than or equal to x
int floor(int x) { return (int)floor(x); }

// SortBy is a type that implements sorting based on absolute values
typedef struct {
	int *arr;
	int len;
} SortBy;

// Len returns the number of elements in the SortBy slice
int SortBy_len(SortBy *a) { return a->len; }

// Swap exchanges the elements with indexes i and j in the SortBy slice
void SortBy_swap(SortBy *a, int i, int j) {
	int tmp = a->arr[i];
	a->arr[i] = a->arr[j];
	a->arr[j] = tmp;
}

// Less reports whether the element with index i should sort before the element with index j
int SortBy_less(SortBy *a, int i, int j) { return abs(a->arr[i]) < abs(a->arr[j]); }

// SortBy_sort sorts the SortBy slice using the less function
void SortBy_sort(SortBy *a) { qsort(a->arr, a->len, sizeof(int), (int (*)(const void *, const void *))SortBy_less); }

// SortBy_new creates a new SortBy slice
SortBy *SortBy_new(int *arr, int len) {
	SortBy *a = malloc(sizeof(SortBy));
	a->arr = arr;
	a->len = len;
	return a;
}

// SortBy_free frees the memory of a SortBy slice
void SortBy_free(SortBy *a) { free(a); }

// main function
int main() {
	// Declare variables for input dimensions and the answer
	int N, M, ans;
	
	// Read input values for N and M
	scanf("%d %d", &N, &M);
	
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
	printf("%d", ans);
}

/*  ----------------------------------------  */

// max function returns the maximum value from a variable number of integers
int max(int x,...) {
	va_list args;
	va_start(args, x);
	int res = x;
	int arg;
	while ((arg = va_arg(args, int))!= 0) {
		res = (res > arg)? res : arg;
	}
	va_end(args);
	return res;
}

// min function returns the minimum value from a variable number of integers
int min(int x,...) {
	va_list args;
	va_start(args, x);
	int res = x;
	int arg;
	while ((arg = va_arg(args, int))!= 0) {
		res = (res < arg)? res : arg;
	}
	va_end(args);
	return res;
}

// pow function calculates x raised to the power of y
int pow(int x, int y) { return (int)pow(x, y); }

// abs function returns the absolute value of an integer
int abs(int x) { return (x < 0)? -x : x; }

// floor function returns the largest integer less than or equal to x
int floor(int x) { return (int)floor(x); }

// SortBy is a type that implements sorting based on absolute values
typedef struct {
	int *arr;
	int len;
} SortBy;

// Len returns the number of elements in the SortBy slice
int SortBy_len(SortBy *a) { return a->len; }

// Swap exchanges the elements with indexes i and j in the SortBy slice
void SortBy_swap(SortBy *a, int i, int j) {
	int tmp = a->arr[i];
	a->arr[i] = a->arr[j];
	a->arr[j] = tmp;
}

// Less reports whether the element with index i should sort before the element with index j
int SortBy_less(SortBy *a, int i, int j) { return abs(a->arr[i]) < abs(a->arr[j]); }

// SortBy_sort sorts the SortBy slice using the less function
void SortBy_sort(SortBy *a) { qsort(a->arr, a->len, sizeof(int), (int (*)(const void *, const void *))SortBy_less); }

// SortBy_new creates a new SortBy slice
SortBy *SortBy_new(int *arr, int len) {
	SortBy *a = malloc(sizeof(SortBy));
	a->arr = arr;
	a->len = len;
	return a;
}

// SortBy_free frees the memory of a SortBy slice
void SortBy_free(SortBy *a) { free(a); }

// main function
int main() {
	// Declare variables for input dimensions and the answer
	int N, M, ans;
	
	// Read input values for N and M
	scanf("%d %d", &N, &M);
	
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
	printf("%d", ans);
}

/*  ----------------------------------------  */

// max function returns the maximum value from a variable number of integers
int max(int x,...) {
	va_list args;
	va_start(args, x);
	int res = x;
	int arg;
	while ((arg = va_arg(args, int))!= 0) {
		res = (res > arg)? res : arg;
	}
	va_end(args);
	return res;
}

// min function returns the minimum value from a variable number of integers
int min(int x,...) {
	va_list args;
	va_start(args, x);
	int res = x;
	int arg;
	while ((arg = va_arg(args, int))!= 0) {
		res = (res < arg)? res : arg;
	}
	va_end(args);
	return res;
}

// pow function calculates x raised to the power of y
int pow(int x, int y) { return (int)pow(x, y); }

// abs function returns the absolute value of an integer
int abs(int x) { return (x < 0)? -x : x; }

// floor function returns the largest integer less than or equal to x
int floor(int x) { return (int)floor(x); }

// SortBy is a type that implements sorting based on absolute values
typedef struct {
	int *arr;
	int len;
} SortBy;

// Len returns the number of elements in the SortBy slice
int SortBy_len(SortBy *a) { return a->len; }

// Swap exchanges the elements with indexes i and j in the SortBy slice
void SortBy_swap(SortBy *a, int i, int j) {
	int tmp = a->arr[i];
	a->arr[i] = a->arr[j];
	a->arr[j] = tmp;
}

// Less reports whether the element with index i should sort before the element with index j
int SortBy_less(SortBy *a, int i, int j) { return abs(a->arr[i]) < abs(a->arr[j]); }

// SortBy_sort sorts the SortBy slice using the less function
void SortBy_sort(SortBy *a) { qsort(a->arr, a->len, sizeof(int), (int (*)(const void *, const void *))SortBy_less); }

// SortBy_new creates a new SortBy slice
SortBy *SortBy_new(int *arr, int len) {
	SortBy *a = malloc(si