#include <stdio.h>
<<<<<<< HEAD
#include <stdlib.h>
#include <string.h>
=======
#include <string.h>
#include <stdlib.h>
>>>>>>> 98c87cb78a (data updated)
#include <math.h>

#define INITIAL_BUF_SIZE 10000
#define MAX_BUF_SIZE 1000000
#define MOD 1000000007

// Function to get the number of days until Sunday for a given day.
int daysUntilSunday(const char *day) {
    const char *week[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int index = -1;
    for (int i = 0; i < 7; i++) {
        if (strcmp(day, week[i]) == 0) {
            index = i; // Set the index of the day found in the week array.
            break;
        }
    }
    return 7 - index; // Return the number of days until Sunday.
}

// Main function
int main() {
    char input[4]; // Buffer to hold the input day (3 letters + null terminator)
    scanf("%s", input); // Get the input day as a string.
    
<<<<<<< HEAD
    int days = daysUntilSunday(input); // Calculate days until Sunday.
    printf("%d\n", days); // Print the number of days until Sunday.
=======
    int result = daysUntilSunday(input); // Calculate days until Sunday.
    printf("%d\n", result); // Print the result.
>>>>>>> 98c87cb78a (data updated)
    
    return 0;
}

// Helper function to return the absolute value of an integer.
int abs(int a) {
    return a < 0 ? -a : a;
}

// Function to return the result of raising the first argument to the power of the second argument.
<<<<<<< HEAD
int pow(int p, int q) {
    return (int)pow((double)p, (double)q);
=======
int powInt(int p, int q) {
    return (int)pow(p, q);
>>>>>>> 98c87cb78a (data updated)
}

// Function to return the smallest integer from a list of integers.
int min(int count, ...) {
    va_list args;
    va_start(args, count);
    int res = va_arg(args, int);
    for (int i = 1; i < count; i++) {
        int num = va_arg(args, int);
        if (num < res) {
            res = num;
        }
    }
    va_end(args);
    return res;
}

// Function to return the largest integer from a list of integers.
int max(int count, ...) {
    va_list args;
    va_start(args, count);
    int res = va_arg(args, int);
    for (int i = 1; i < count; i++) {
        int num = va_arg(args, int);
        if (num > res) {
            res = num;
        }
    }
    va_end(args);
    return res;
}

// Function to check if a string is present in a list of strings.
int strSearch(const char *a[], int size, const char *b) {
    for (int i = 0; i < size; i++) {
        if (strcmp(a[i], b) == 0) {
            return 1; // Found
        }
    }
    return 0; // Not found
}

<<<<<<< HEAD
// Function to return the modulo of an integer with respect to mod.
=======
// Function to return the modulo of an integer with respect to MOD.
>>>>>>> 98c87cb78a (data updated)
int calcMod(int x) {
    return x % MOD;
}

// Function to print an array of integers in a specific format.
void printIntArray(int *array, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

<<<<<<< HEAD
// Note: The above functions (abs, pow, min, max, strSearch, calcMod, printIntArray) are included for completeness,
// but they are not used in the main functionality of the program.
=======
// Note: The above functions (abs, powInt, min, max, strSearch, calcMod, printIntArray) are included for completeness,
// but they are not used in the main logic of the program.
>>>>>>> 98c87cb78a (data updated)

