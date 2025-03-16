#include <stdio.h>

int main() {
    int T, S, q;
    long previous;
    int answer = 0;

    // Read the values of T, S, and q from the user input
    scanf("%d %d %d", &T, &S, &q);

    // Initialize the variable `previous` with the value of S
    previous = S;

    // Enter a while loop that continues until `previous` is less than T
    while (previous < T) {
        // Inside the loop, multiply `previous` by q and increment the `answer` by 1
        previous *= q;
        answer++;
    }

    // After the loop, print the value of `answer`
    printf("%d\n", answer);

    return 0;
}

