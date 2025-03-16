

#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);  // Take input from user, store in variables a, b, c

    // Check if the tuple contains exactly two 5s
    if ((a == 5 && b!= 5 && c!= 5) || (a!= 5 && b == 5 && c!= 5) || (a!= 5 && b!= 5 && c == 5)) {
        // Check if the sum of the elements in ABC is 17
        if (a + b + c == 17) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    } else {
        printf("NO\n");
    }

    return 0;
}
