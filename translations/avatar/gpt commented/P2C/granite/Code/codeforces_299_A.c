
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Define a lambda function to read an integer input
    int num_inp() {
        int x;
        scanf("%d", &x);
        return x;
    }

    // Define a lambda function to read a list of integers from input
    int* arr_inp() {
        int n = num_inp();
        int* arr = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        return arr;
    }

    // Define a lambda function to read a space-separated list of integers as a map object
    int* sp_inp() {
        int n = num_inp();
        int* arr = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        return arr;
    }

    // Read the input from the first line of the standard input, sort it, and convert it to a list of integers
    int* a = sp_inp();
    qsort(a, num_inp(), sizeof(int), cmpfunc);

    // Check if any element in the list 'a' is not divisible by the first element of 'a'
    // If all elements are divisible, print the first element; otherwise, print -1
    int flag = 0;
    for (int i = 0; i < num_inp(); i++) {
        if (a[i] % a[0]!= 0) {
            flag = 1;
            break;
        }
    }
    printf("%d", flag? -1 : a[0]);

    return 0;
}

