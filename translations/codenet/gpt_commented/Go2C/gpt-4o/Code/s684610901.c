#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define INITIAL_BUF_SIZE 10000
#define MAX_BUF_SIZE 100000000
#define INF 100000000

// Function to read an integer from input
long long readInt() {
    long long read;
    scanf("%lld", &read);
    return read;
}

// Function to check if C is within the range [A, B]
void checkRange(long long A, long long B, long long C) {
    if (C >= A && C <= B) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}

int main() {
    // Read three integers A, B, C
    long long A = readInt();
    long long B = readInt();
    long long C = readInt();

    // Check if C is within the range [A, B]
    checkRange(A, B, C);

    return 0;
}

/*==========================================
 *             Library Functions
 *==========================================*/

// Function to calculate the absolute value of an integer
long long absVal(long long i) {
    return i < 0 ? -i : i;
}

// Function to find the maximum value from a list of integers
long long max(long long a, long long b) {
    return a > b ? a : b;
}

// Function to find the minimum value from a list of integers
long long min(long long a, long long b) {
    return a < b ? a : b;
}

// Function to calculate the sum of an array of integers
long long sum(long long* arr, int size) {
    long long total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}

// Function to split a string into tokens
char** split(const char* str, int* count) {
    char* temp = strdup(str);
    char* token;
    char** result = NULL;
    *count = 0;

    token = strtok(temp, " ");
    while (token != NULL) {
        result = realloc(result, sizeof(char*) * (*count + 1));
        result[*count] = strdup(token);
        (*count)++;
        token = strtok(NULL, " ");
    }
    free(temp);
    return result;
}

// Function to convert a string to an integer
long long s2i(const char* s) {
    return atoll(s);
}

// Function to convert an integer to a string
char* i2s(long long i) {
<<<<<<< HEAD
    char* str = malloc(20); // Enough space for long long
=======
    char* str = malloc(20); // Enough for 64-bit integer
>>>>>>> 98c87cb78a (data updated)
    sprintf(str, "%lld", i);
    return str;
}

// Function to reverse an array of integers
void reverse(long long* arr, int size) {
    for (int i = 0; i < size / 2; i++) {
        long long temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

// Function to check if two arrays are equal
bool aryEq(long long* a, long long* b, int size) {
    for (int i = 0; i < size; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

// Function to clone an array
long long* clone(long long* arr, int size) {
    long long* newArr = malloc(size * sizeof(long long));
    memcpy(newArr, arr, size * sizeof(long long));
    return newArr;
}

// Function to initialize an array with a given value
void ini(int* arr, int size, int init) {
    if (size > 0) {
        arr[0] = init;
        for (int i = 1; i < size; i++) {
            arr[i] = arr[i - 1];
        }
    }
}

// Function to free a string array
void freeStringArray(char** arr, int size) {
    for (int i = 0; i < size; i++) {
        free(arr[i]);
    }
    free(arr);
}

<<<<<<< HEAD
// Function to free a long long array
=======
// Function to free an integer array
>>>>>>> 98c87cb78a (data updated)
void freeLongLongArray(long long* arr) {
    free(arr);
}

// Uncomment the following function to see a regex example
/*
void regexpExample() {
    // Your code here!
    char* str = "13:20";
    // Regex implementation in C would require additional libraries
}
*/

// Uncomment the following struct and function to see a stable sort example
/*
typedef struct {
    int gold;
    int silver;
    int bronze;
} Country;

int compareCountries(const void* a, const void* b) {
    Country* countryA = (Country*)a;
    Country* countryB = (Country*)b;
    if (countryA->gold != countryB->gold) {
        return countryB->gold - countryA->gold; // Descending order
    }
    if (countryA->silver != countryB->silver) {
        return countryB->silver - countryA->silver; // Descending order
    }
    return countryB->bronze - countryA->bronze; // Descending order
}

<<<<<<< HEAD
void stableSortExample() {
    Country countries[] = {
        {1, 2, 3},
        {1, 2, 3},
        {1, 3, 2},
        {1, 3, 3},
    };
    int size = sizeof(countries) / sizeof(countries[0]);
    qsort(countries, size, sizeof(Country), compareCountries);
=======
Country* stableSortExample(int* size) {
    Country* countries = malloc(4 * sizeof(Country));
    countries[0] = (Country){1, 2, 3};
    countries[1] = (Country){1, 2, 3};
    countries[2] = (Country){1, 3, 2};
    countries[3] = (Country){1, 3, 3};
    *size = 4;
    qsort(countries, *size, sizeof(Country), compareCountries);
    return countries;
>>>>>>> 98c87cb78a (data updated)
}
*/

