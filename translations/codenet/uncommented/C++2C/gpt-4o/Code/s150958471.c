#include <stdio.h>

int main() {
    int train[2];
    int bus[2];

    scanf("%d %d", &train[0], &train[1]);
    scanf("%d %d", &bus[0], &bus[1]);

    printf("%d\n", (train[0] < train[1] ? train[0] : train[1]) + (bus[0] < bus[1] ? bus[0] : bus[1]));

    return 0;
}

// <END-OF-CODE>
