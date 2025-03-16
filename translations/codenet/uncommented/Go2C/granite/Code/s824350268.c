
#include <stdio.h>
#include <math.h>

#define initialBufSize 10000
#define maxBufSize 10000000
#define mod 1e9 + 7

int N;
int sqrtN;
int min;

int main() {
    N = 100; // Replace with actual input value
    sqrtN = (int)sqrt(N);

    min = N;
    for (int i = 1; i <= sqrtN; i++) {
        if (N % i!= 0) {
            continue;
        }

        int num = i + (N/i) - 2;
        if (num < min) {
            min = num;
        }
    }

    printf("%d\n", min); // Replace with actual output value

    return 0;
}

