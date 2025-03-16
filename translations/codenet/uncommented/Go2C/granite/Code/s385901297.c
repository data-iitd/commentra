
#include <stdio.h>
#include <stdlib.h>

int main() {
    int ns[4];
    int i;
    char buf[1024];

    if (fgets(buf, sizeof(buf), stdin) == NULL) {
        exit(1);
    }
    if (sscanf(buf, "%d %d %d %d", &ns[0], &ns[1], &ns[2], &ns[3])!= 4) {
        exit(1);
    }

    for (i = 0; i < 4; i++) {
        int j;
        for (j = i + 1; j < 4; j++) {
            if (ns[i] > ns[j]) {
                int tmp = ns[i];
                ns[i] = ns[j];
                ns[j] = tmp;
            }
        }
    }

    if (ns[0] == 1 && ns[1] == 4 && ns[2] == 7 && ns[3] == 9) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
