#include <stdio.h>

int main() {
    int v1, v2, t, d;
    
    // Taking two inputs from the user
    scanf("%d %d", &v1, &v2);
    scanf("%d", &t);
    scanf("%d", &d);

    // Initializing variables
    int a = 1;
    int v = v1;
    int distance = 0;

    // Entering a loop that runs `t` times
    for (int i = 0; i < t; i++) {
        // Checking if the current speed `v` minus `v2` is greater than `(t - i - 1) * d`
        if (v - v2 > (t - i - 1) * d) {
            a *= -1;
            v = (t - i - 1) * d + v2;
        }
        // Adding the current speed `v` to `distance`
        distance += v;
        // Updating the speed by adding `a * d` to it
        v += a * d;
    }

    // Printing the total `distance`
    printf("%d\n", distance);

    return 0;
}

// <END-OF-CODE>
