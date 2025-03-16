#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function out is used to print the output to the console
void out(int x) {
	//	printf("%d\n", x);
}

// Function nextInt reads an integer from the input
int nextInt() {
	int i;
	scanf("%d", &i);
	return i;
}

// Function nextString reads a string from the input
char* nextString() {
	char* s = (char*)malloc(100 * sizeof(char));
	scanf("%s", s);
	return s;
}

// Define a type Data to represent a single data point
typedef struct {
	char* X;
} Data;

// Define a type Datas as a slice of Data
typedef struct {
	Data* data;
	int len;
	int cap;
} Datas;

// Implement Len method for Datas type to get the length of the slice
int Datas_Len(Datas* p) {
	return p->len;
}

// Implement Swap method for Datas type to swap elements in the slice
void Datas_Swap(Datas* p, int i, int j) {
	Data temp = p->data[i];
	p->data[i] = p->data[j];
	p->data[j] = temp;
}

// Implement Less method for Datas type to sort the slice based on X field
int Datas_Less(Datas* p, int i, int j) {
	return strcmp(p->data[i].X, p->data[j].X) < 0;
}

// Main function starts here
int main() {
	// Initialize scanner for reading input from stdin
	//	sc.Split(bufio.ScanWords)

	// Read number of data points N from the input
	int N = nextInt();

	// Read number of queries L from the input
	int L = nextInt();

	// Initialize a slice of Data type named s with capacity N
	Datas* s = (Datas*)malloc(sizeof(Datas));
	s->data = (Data*)malloc(N * sizeof(Data));
	s->len = N;
	s->cap = N;

	// Read data points X from the input and store them in the slice s
	for (int i = 0; i < N; i++) {
		s->data[i].X = nextString();
	}

	// Print the number of data points N, number of queries L, and the slice s
	out(N, L, s);

	// Sort the slice s in ascending order based on X field
	qsort(s->data, s->len, sizeof(Data), (int (*)(const void*, const void*))Datas_Less);

	// Initialize an empty string ans to store the concatenated X values
	char* ans = (char*)malloc(100 * sizeof(char));
	ans[0] = '\0';

	// Iterate through the slice s and concatenate X values to the string ans
	for (int i = 0; i < N; i++) {
		strcat(ans, s->data[i].X);
	}

	// Print the concatenated string ans to the console
	printf("%s\n", ans);

	// Free the memory allocated for s and ans
	free(s->data);
	free(s);
	free(ans);

	return 0;
}

