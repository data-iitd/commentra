
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define magic 1000000007

int find(int n) {
    for (int i = 0; i < N; i++) {
        if (n == p[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    // Create an Io instance for reading input
    struct Io io;
    io_init(&io);

    // Parse input using the NextInt function of the Io instance
    int X = io_nextInt(&io);
    printf("%d\n", X);
    N = io_nextInt(&io);
    printf("%d\n", N);
    for (int i = 0; i < N; i++) {
        p[i] = io_nextInt(&io);
    }
    printf("p %d %d %d %d %d %d %d %d %d\n", p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7], p[8], p[9]);

    // Check if X or its neighbors are present in the p slice
    for (int i = 0; i <= 100; i++) {
        if (find(X-i) == 1) {
            printf("%d\n", X-i);
            exit(0);
        }
        if (find(X+i) == 1) {
            printf("%d\n", X+i);
            exit(0);
        }
    }

    // OUTPUT GENERATION PART
    // int ans = 0;
    // printf("%d\n", ans);

    // If ans > 0, print "Yes" and exit; otherwise, print "No"
    // if (ans > 0) {
    //     printf("Yes\n");
    // } else {
    //     printf("No\n");
    // }

    // main function initializes flags for CPU and memory profiling and calls the solve function
    return 0;
}

