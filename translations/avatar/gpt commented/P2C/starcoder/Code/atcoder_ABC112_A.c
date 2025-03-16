#include <stdio.h>

int main() {
    int age;
    scanf("%d", &age);

    if (age == 1) {
        printf("Hello World");
    } else {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d", a + b);
    }

    return 0;
}
