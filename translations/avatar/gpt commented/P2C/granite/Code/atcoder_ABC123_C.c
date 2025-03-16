
#include <stdio.h>
#include <math.h>

int main() {
    int N, A[5];

    // Read an integer input from the user
    scanf("%d", &N);

    // Read 5 integer inputs from the user and store them in an array A
    for (int i = 0; i < 5; i++) {
        scanf("%d", &A[i]);
    }

    // Calculate the minimum value from the array A, divide N by this minimum value,
    // take the ceiling of the result, and add 4 to it before printing the final result
    printf("%d\n", (int)ceil(N / *min_element(A, A + 5)) + 4);

    return 0;
}
