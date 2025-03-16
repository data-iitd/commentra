
#include <stdio.h>
#include <math.h>

int main() {
    int N, D;
    scanf("%d %d", &N, &D);

    int count = 0;
    for (int i = 0; i < N; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        double distance = sqrt(x * x + y * y);
        if (distance <= D) {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}
