#include <stdio.h>
#include <stdbool.h>

bool d[10] = {0};
int n, k;

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; ++i) {
        int a;
        scanf("%d", &a);
        d[a] = true;
    }
    
    while (1) {
        int x = n;
        bool hantei = true;
        while (x) {
            if (d[x % 10]) {
                hantei = false;
                break;
            }
            x /= 10;
        }
        if (hantei) {
            printf("%d\n", n);
            break;
        }
        n++;
    }
    return 0;
}

// <END-OF-CODE>
