#include <stdio.h>
#include <math.h>
#include <limits.h>

int main() {
    int N;
    int A[5];
    int min_value = INT_MAX;
    int ceiling_value;
    int final_answer;

    // Read the input number N
    scanf("%d", &N);

    // Read the five integers into the list A
    for (int i = 0; i < 5; i++) {
        scanf("%d", &A[i]);
    }

    // Calculate the minimum value in the list A
    for (int i = 0; i < 5; i++) {
        if (A[i] < min_value) {
            min_value = A[i];
        }
    }

    // Calculate the ceiling value of N divided by the minimum value in the list A
    ceiling_value = (int)ceil((double)N / min_value);

    // Add 4 to the ceiling value to get the final answer
    final_answer = ceiling_value + 4;

    // Print the final answer
    printf("%d\n", final_answer);

    return 0;
}
