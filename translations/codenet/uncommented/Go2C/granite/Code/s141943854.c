
#include <stdio.h>
#include <stdlib.h>

int main() {
    char buf[1024];
    fgets(buf, sizeof(buf), stdin);
    char *sage = buf;

    if (strcmp(sage, "1\n") == 0) {
        printf("Hello World\n");
    } else if (strcmp(sage, "2\n") == 0) {
        int sum = 0;
        for (int i = 0; i < 2; i++) {
            fgets(buf, sizeof(buf), stdin);
            char *num_str = buf;
            int num = atoi(num_str);
            sum += num;
        }
        printf("%d\n", sum);
    }

    return 0;
}
