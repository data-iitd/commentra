#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int nextInt() {
    int n;
    scanf("%d", &n);
    return n;
}

float nextFloat() {
    float n;
    scanf("%f", &n);
    return n;
}

char* nextString() {
    char *str = (char*)malloc(100 * sizeof(char));
    scanf("%s", str);
    return str;
}

int abs(int x) {
    return (int)fabs(x);
}

int min(int x, int y) {
    return (x < y) ? x : y;
}

int max(int x, int y) {
    return (x > y) ? x : y;
}

int main() {
    int R = nextInt();
    int G = nextInt();
    int B = nextInt();
    int N = nextInt();

    int ans = 0;
    // Iterate over all possible values of x and y
    for (int x = 0; x <= N; x++) {
        for (int y = 0; y <= N; y++) {
            // Calculate the remaining value after subtracting x*R and y*G
            int tmp = N - R*x - G*y;
            // Check if the remaining value is non-negative and a multiple of B
            if (tmp >= 0 && tmp % B == 0) {
                ans++;
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}
