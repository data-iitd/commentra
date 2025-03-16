#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char sage[10];
    int sum = 0;
    int num;
    int i;

    scanf("%s", sage);

    switch (atoi(sage)) {
        case 1:
            printf("Hello World\n");
            break;
        case 2:
            for (i = 0; i < 2; i++) {
                scanf("%d", &num);
                sum += num;
            }
            printf("%d\n", sum);
            break;
    }

    return 0;
}

