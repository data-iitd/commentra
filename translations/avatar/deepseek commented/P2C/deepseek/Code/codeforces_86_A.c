#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int l, r;
    scanf("%d %d", &l, &r);
    
    int curr = r;
    int s = 0;
    
    while (curr) {
        s++;
        curr /= 10;
    }
    
    int first = 10 * s;
    int second = first / 2;
    
    int ans = -1;
    
    int numbers[] = {l, r, first, second};
    for (int i = 0; i < 4; i++) {
        if (numbers[i] >= l && numbers[i] <= r) {
            curr = numbers[i];
            char rev[10];
            sprintf(rev, "%d", curr);
            int len = strlen(rev);
            for (int j = 0; j < len; j++) {
                rev[j] = '9' - rev[j] + '0';
            }
            int rev_num = atoi(rev);
            int product = rev_num * curr;
            if (product > ans) {
                ans = product;
            }
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}

