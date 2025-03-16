#include <stdio.h>

int main() {
    int sec, per_num;
    double max_sec;
    int ans_num = 0;

    scanf("%d %d %lf", &sec, &per_num, &max_sec);

    for (int i = sec; i < max_sec; i += sec) {
        ans_num += per_num;
    }

    printf("%d\n", ans_num);

    return 0;
}
