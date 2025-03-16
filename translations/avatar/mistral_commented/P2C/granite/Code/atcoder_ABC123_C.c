
#include <stdio.h>
#include <math.h>

int main() {
    int N, A[5], min_value, ceiling_value, final_answer;

    // Input N and the five integers in the list A
    scanf("%d", &N);
    for (int i = 0; i < 5; i++) {
        scanf("%d", &A[i]);
    }

    // Calculate the minimum value in the list A
    min_value = A[0];
    for (int i = 1; i < 5; i++) {
        if (A[i] < min_value) {
            min_value = A[i];
        }
    }

    // Calculate the ceiling value of N divided by the minimum value in the list A
    ceiling_value = ceil(N / (double)min_value);

    // Add 4 to the ceiling value to get the final answer
    final_answer = ceiling_value + 4;

    // Print the final answer
    printf("%d\n", final_answer);

    return 0;
}
