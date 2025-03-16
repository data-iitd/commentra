#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readInt() {
    int num;
    scanf("%d", &num);
    return num;
}

int readLong() {
    long long num;
    scanf("%lld", &num);
    return num;
}

char* readString() {
    char* str = (char*)malloc(100 * sizeof(char));
    scanf("%s", str);
    return str;
}

int main() {
    int a = readInt();
    int b = readInt();

    if (a > 0) {
        printf("Positive\n");
    } else if (a <= 0 && b >= 0) {
        printf("Zero\n");
    } else {
        if ((a + b) % 2 == 0) {
            printf("Negative\n");
        } else {
            printf("Positive\n");
        }
    }

    return 0;
}
