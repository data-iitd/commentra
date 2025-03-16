

#include <stdio.h>

int main() {
    int x;
    scanf("%d", &x);
    int bool = x == 1? 1 : 0;
    int result =!bool? 1 : 0;
    printf("%d\n", result);
    return 0;
}

