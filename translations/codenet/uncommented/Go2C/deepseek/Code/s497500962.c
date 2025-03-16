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

int main() {
    int R = nextInt();
    int G = nextInt();
    int B = nextInt();
    int N = nextInt();

    int ans = 0;
    for (int x = 0; x <= N; x++) {
        for (int y = 0; y <= N; y++) {
            int tmp = N - R * x - G * y;
            if (tmp >= 0 && tmp % B == 0) {
                ans++;
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}

int abs(int x) {
    return (x < 0) ? -x : x;
}

int min(int x, int y) {
    return (x < y) ? x : y;
}

int max(int x, int y) {
    return (x > y) ? x : y;
}
