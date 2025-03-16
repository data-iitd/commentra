#include <stdio.h>

int main() {
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);

    if (age == 1) {
        printf("Hello World\n");
    } else {
        int a, b;
        printf("Enter two integers: ");
        scanf("%d %d", &a, &b);
        printf("%d\n", a + b);
    }

    return 0;
}
