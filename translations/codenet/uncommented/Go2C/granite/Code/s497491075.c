
#include <stdio.h>
#include <math.h>

int main() {
    int a[2];
    int N, D;
    int count = 0;
    int line[2];

    scanf("%d %d", &N, &D);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &line[0], &line[1]);
        double d = sqrt(line[0] * line[0] + line[1] * line[1]);
        if (d <= D) {
            count++;
        }
    }
    printf("%d\n", count);

    return 0;
}
