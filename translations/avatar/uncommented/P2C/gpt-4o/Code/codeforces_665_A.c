#include <stdio.h>

int main() {
    int a, at, b, bt;
    scanf("%d %d", &a, &at);
    scanf("%d %d", &b, &bt);
    
    int t1, t2;
    scanf("%d:%d", &t1, &t2);
    
    int st = t2 + (t1 - 5) * 60;
    int fin = st + at;
    int now = 0;
    int ans = 0;
    
    while (now < fin && now < 1140) {
        if (now + bt > st) {
            ans += 1;
        }
        now += b;
    }
    
    printf("%d\n", ans);
    return 0;
}

// <END-OF-CODE>
