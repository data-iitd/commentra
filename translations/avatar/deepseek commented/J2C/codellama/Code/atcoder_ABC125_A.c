#include <stdio.h>

int main() {
    int sec, per_num, max_sec, ans_num;
    scanf("%d %d %d", &sec, &per_num, &max_sec);
    
    ans_num = 0;
    
    for (int i = sec; i < max_sec; i += sec) {
        ans_num += per_num;
    }
    
    printf("%d", ans_num);
    
    return 0;
}

