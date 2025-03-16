

#include <stdio.h>

int main() {
    int N;  // Declaring an integer variable N to store the number of elements.
    scanf("%d", &N);  // Taking an integer input N, which represents the number of elements.

    int V[N];  // Declaring an integer array V of size N to store the first line of space-separated integers.
    for (int i = 0; i < N; i++) {
        scanf("%d", &V[i]);  // Taking the i-th integer input and storing it in the i-th element of V.
    }

    int C[N];  // Declaring an integer array C of size N to store the second line of space-separated integers.
    for (int i = 0; i < N; i++) {
        scanf("%d", &C[i]);  // Taking the i-th integer input and storing it in the i-th element of C.
    }

    int list[N];  // Declaring an integer array list of size N to store the differences between corresponding elements of V and C.
    int ans = 0;  // Declaring an integer variable ans to store the sum of the differences.
    int X = 0;  // Declaring an integer variable X to store the i-th element of V.
    int Y = 0;  // Declaring an integer variable Y to store the i-th element of C.

    for (int i = 0; i < N; i++) {
        if (V[i] - C[i] > 0) {
            X = V[i];  // Assigning the i-th element of V to X.
            Y = C[i];  // Assigning the i-th element of C to Y.
            list[i] = X - Y;  // Assigning the difference X - Y to the i-th element of list.
            ans += list[i];  // Adding the difference X - Y to the variable ans.
        }
    }

    printf("%d", ans);  // Printing the sum of the differences.

    return 0;
}

