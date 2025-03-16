
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int64_t A, B, C;
    scanf("%ld %ld %ld", &A, &B, &C);
    if (C >= A && C <= B) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}
