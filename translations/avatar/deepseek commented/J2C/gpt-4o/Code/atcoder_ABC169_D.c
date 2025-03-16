#include <stdio.h>
#include <math.h>

int main() {
    // Step 1: Read a long integer n from the user
    long n;
    scanf("%ld", &n);

    // Step 2: Calculate the integer square root of n
    int sqrt_n = (int)sqrt(n);

    // Step 3: Initialize an answer variable to 0
    int answer = 0;

    // Step 4: Iterate from 2 to the square root of n
    for (int i = 2; i <= sqrt_n; i++) {
        // Step 5: For each number i in this range, count the number of times i divides n
        int count = 0;
        while (n % i == 0) {
            n /= i; // Step 6: Update the value of n by dividing it by i
            count++;
        }

        // Step 7: Calculate the number of times i can be subtracted from the count
        for (int j = 1; count - j >= 0; j++) {
            count -= j; // Step 8: Update the answer variable with the number of times i can be subtracted
            answer++;
        }
    }

    // Step 9: If n is greater than 1 after the loop, it means n is a prime number and increments the answer by 1
    if (n > 1) {
        answer++;
    }

    // Step 10: Print the answer
    printf("%d\n", answer);

    return 0;
}
