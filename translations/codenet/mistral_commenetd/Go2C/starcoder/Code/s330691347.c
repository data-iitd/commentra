#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a type Data to represent a single data point
typedef struct {
	char X[1000001];
} Data;

// Define a type Datas as a slice of Data
typedef Data Datas[1000001];

// Function out is used to print the output to the console
void out(int N, int L, Datas s) {
	//	printf("%d %d", N, L);
	//	for (int i = 0; i < N; i++) {
	//		printf(" %s", s[i].X);
	//	}
	//	printf("\n");
}

// Function nextInt reads an integer from the input
int nextInt() {
	int i;
	scanf("%d", &i);
	return i;
}

// Function nextString reads a string from the input
char* nextString() {
	char* s = malloc(1000001);
	scanf("%s", s);
	return s;
}

// Main function starts here
int main() {
	// Initialize scanner for reading input from stdin
	//	scanf("%d %d", &N, &L);
	int N = nextInt();
	int L = nextInt();

	// Initialize a slice of Data type named s with capacity N
	Datas s;

	// Read data points X from the input and store them in the slice s
	for (int i = 0; i < N; i++) {
		//		scanf("%s", s[i].X);
		strcpy(s[i].X, nextString());
	}

	// Print the number of data points N, number of queries L, and the slice s
	out(N, L, s);

	// Sort the slice s in ascending order based on X field
	//	qsort(s, N, sizeof(Data), compare);
	qsort(s, N, sizeof(Data), compare);

	// Initialize an empty string ans to store the concatenated X values
	char* ans = malloc(1000001);
	ans[0] = '\0';

	// Iterate through the slice s and concatenate X values to the string ans
	for (int i = 0; i < N; i++) {
		strcat(ans, s[i].X);
	}

	// Print the concatenated string ans to the console
	printf("%s\n", ans);
}

// Function compare is used to compare two Data objects based on X field
int compare(const void* a, const void* b) {
	Data* da = (Data*)a;
	Data* db = (Data*)b;
	return strcmp(da->X, db->X);
}

