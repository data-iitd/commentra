#include <stdio.h>

int main() {
    int age;
    scanf("%d", &age);
    if (age == 1) {
        printf("Hello World\n");
    } else {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", a + b);
    }
    return 0;
}
