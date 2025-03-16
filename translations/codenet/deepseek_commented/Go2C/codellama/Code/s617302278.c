
#include <stdio.h>

int main() {
    int x;
    scanf("%d", &x);
    int i = 1;
    int sum = 0;
    while (1) {
        sum += i;
        if (sum >= x) {
            break;
        }
        i++;
    }
    printf("%d\n", i);
    return 0;
}

