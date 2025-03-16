#include <stdio.h>

int main() {
    int A, B;  // Declare two integer variables A and B
    scanf("%d %d", &A, &B);  // Taking two integer inputs A and B
    int ans = A - 2 * B;  // Calculating the value of ans as A minus two times B
    if (ans < 0) {  // Checking if ans is less than 0
        ans = 0;  // Setting ans to 0 if it is less than 0
    }
    printf("%d\n", ans);  // Printing the value of ans
    return 0;  // Return 0 to indicate successful execution
}

// <END-OF-CODE>
