#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int nextInt() {
    int value;
    scanf("%d", &value);
    return value;
}

float nextFloat() {
    float value;
    scanf("%f", &value);
    return value;
}

char* nextString() {
    char *str = (char*)malloc(100 * sizeof(char));
    scanf("%s", str);
    return str;
}

int abs(int x) {
    return abs(x);
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
