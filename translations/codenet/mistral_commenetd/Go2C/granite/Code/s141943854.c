

#include <stdio.h>
#include <stdlib.h>

int main() {
    char sage[10];
    scanf("%s", sage);

    if (strcmp(sage, "1") == 0) {
        printf("Hello World\n");
    } else if (strcmp(sage, "2") == 0) {
        int sum = 0;
        for (int i = 0; i < 2; i++) {
            char num[10];
            scanf("%s", num);
            int n = atoi(num);
            sum += n;
        }
        printf("%d\n", sum);
    }

    return 0;
}

// END-OF-CODE