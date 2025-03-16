
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function out is used to print the output to the console
void out(int x,...) {
    va_list args;
    va_start(args, x);
    vprintf(args);
    va_end(args);
}

// Function nextInt reads an integer from the input
int nextInt() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function nextString reads a string from the input
char* nextString() {
    int size = 100;
    char* str = (char*)malloc(sizeof(char) * size);
    if (!fgets(str, size, stdin)) {
        return NULL;
    }
    char* token = strtok(str, " \n");
    return token;
}

// Define a struct Data to represent a single data point
typedef struct {
    char* X;
} Data;

// Define a struct Datas as an array of Data
typedef struct {
    Data* data;
    int size;
} Datas;

// Function Datas_init initializes a Datas struct with the given size
Datas Datas_init(int size) {
    Datas datas;
    datas.data = (Data*)malloc(sizeof(Data) * size);
    datas.size = size;
    return datas;
}

// Function Datas_free frees the memory allocated for the Datas struct
void Datas_free(Datas* datas) {
    for (int i = 0; i < datas->size; i++) {
        free(datas->data[i].X);
    }
    free(datas->data);
}

// Function Datas_append appends a new data point to the Datas struct
void Datas_append(Datas* datas, char* X) {
    if (datas->size == 0) {
        datas->data = (Data*)malloc(sizeof(Data));
        datas->size = 1;
    } else {
        datas->data = (Data*)realloc(datas->data, sizeof(Data) * (datas->size + 1));
        datas->size++;
    }
    datas->data[datas->size - 1].X = X;
}

// Function Datas_sort sorts the Datas struct in ascending order based on X field
void Datas_sort(Datas* datas) {
    qsort(datas->data, datas->size, sizeof(Data), [](const void* a, const void* b) {
        return strcmp(((Data*)a)->X, ((Data*)b)->X);
    });
}

// Main function starts here
int main() {
    // Initialize scanner for reading input from stdin
    setbuf(stdin, NULL);

    // Read number of data points N from the input
    int N = nextInt();

    // Read number of queries L from the input
    int L = nextInt();

    // Initialize a Datas struct named s with capacity N
    Datas s = Datas_init(N);

    // Read data points X from the input and store them in the Datas struct s
    for (int i = 0; i < N; i++) {
        char* X = nextString();
        Datas_append(&s, X);
    }

    // Print the number of data points N, number of queries L, and the Datas struct s
    out("%d %d", N, L);
    for (int i = 0; i < s.size; i++) {
        out(" %s", s.data[i].X);
    }
    out("\n");

    // Sort the Datas struct s in ascending order based on X field
    Datas_sort(&s);

    // Initialize an empty string ans to store the concatenated X values
    char* ans = "";

    // Iterate through the Datas struct s and concatenate X values to the string ans
    for (int i = 0; i < s.size; i++) {
        ans = strcat(ans, s.data[i].X);
    }

    // Print the concatenated string ans to the console
    out("%s\n", ans);

    // Free the memory allocated for the Datas struct s
    Datas_free(&s);

    return 0;
}
