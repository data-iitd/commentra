#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data represents a single data entry with a string field.
typedef struct {
	char *X;
} Data;

// Datas is a slice of Data, implementing sort.Interface.
typedef struct {
	int len;
	Data *data;
} Datas;

// Len returns the number of elements in the slice.
int Len(Datas *p) {
	return p->len;
}

// Swap exchanges the elements with indexes i and j.
void Swap(Datas *p, int i, int j) {
	Data temp = p->data[i];
	p->data[i] = p->data[j];
	p->data[j] = temp;
}

// Less reports whether the element with index i should sort before the element with index j.
int Less(Datas *p, int i, int j) {
	return strcmp(p->data[i].X, p->data[j].X) < 0;
}

// Sort sorts the slice of Data entries.
void Sort(Datas *p) {
	int i, j, k;
	for (i = 0; i < p->len; i++) {
		for (j = i + 1; j < p->len; j++) {
			if (Less(p, i, j)) {
				Swap(p, i, j);
			}
		}
	}
}

// Read reads the next integer from input and returns it.
int Read() {
	int i;
	scanf("%d", &i);
	return i;
}

// ReadString reads the next string from input and returns it.
char *ReadString() {
	char *s = malloc(100);
	scanf("%s", s);
	return s;
}

// out is a utility function for printing output, currently commented out.
void out(int N, int L, Datas *s) {
	//	printf("%d %d\n", N, L);
	//	for (int i = 0; i < N; i++) {
	//		printf("%s\n", s->data[i].X);
	//	}
}

int main() {
	int N = Read(); // Read the number of data entries
	int L = Read(); // Read an additional integer (not used further in the code)
	Datas *s = malloc(sizeof(Datas)); // Create a slice of Datas with length N
	s->len = N;
	s->data = malloc(N * sizeof(Data)); // Read N strings into the slice s
	for (int i = 0; i < N; i++) {
		s->data[i].X = ReadString(); // Populate each Data entry with a string
	}

	out(N, L, s); // Output the initial values (commented out)
	Sort(s); // Sort the slice of Data entries
	out(s); // Output the sorted slice (commented out)

	// Concatenate all strings in the sorted slice into a single result
	char *ans = malloc(1000);
	ans[0] = '\0';
	for (int i = 0; i < N; i++) {
		strcat(ans, s->data[i].X); // Append each string to ans
	}
	printf("%s\n", ans); // Print the concatenated result
	return 0;
}

