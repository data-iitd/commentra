#include <stdio.h>
#include <stdlib.h>

int main() {
    int x, i = 1, sum = 0;
    scanf("%d", &x);
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
