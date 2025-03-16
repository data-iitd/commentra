

#include <stdio.h>
#include <stdlib.h>

int main() {
    // Step 1: Read an integer N and a long integer x from the standard input
    int N;
    long x;
    scanf("%d %ld", &N, &x);

    // Step 2: Read N long integers and store them in an array called sweet
    long sweet[N];
    for (int i = 0; i < N; i++) {
        scanf("%ld", &sweet[i]);
    }

    // Step 3: Sort the array sweet
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (sweet[j] > sweet[j + 1]) {
                long temp = sweet[j];
                sweet[j] = sweet[j + 1];
                sweet[j + 1] = temp;
            }
        }
    }

    // Step 4: Initialize a counter num to 0 and iterate through the sorted array sweet
    int num = 0;
    for (int i = 0; i < N; i++) {
        // Step 5: Check if subtracting the element from x results in a non-negative value
        if (x - sweet[num] >= 0) {
            // Step 6: Subtract the element from x and increment the counter num
            x = x - sweet[num];
            num++;
        } else {
            // Step 7: Break out of the loop if the condition is not met
            break;
        }
    }

    // Step 8: After the loop, if num equals N and x is greater than 0, decrement num by 1
    if ((num == N) && (x > 0)) {
        num--;
    }

    // Step 9: Print the value of num
    printf("%d\n", num);

    return 0;
}
