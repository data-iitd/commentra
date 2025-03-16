#include <stdio.h>

int main() {
    int sec, per_num, max_sec;
    scanf("%d", &sec);
    scanf("%d", &per_num);
    scanf("%d", &max_sec);
    max_sec += 0.5; // This will be treated as a double, but we can ignore the decimal part in the loop.

    int ans_num = 0;
    for (int i = sec; i < max_sec; i += sec) {
        ans_num += per_num;
    }
    
    printf("%d\n", ans_num);
    return 0;
}

// <END-OF-CODE>
