#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10

int main() {
    long long h, w;
    scanf("%lld %lld", &h, &w);
    char t[MAX_SIZE], s[] = "snuke";
    
    for (long long i = 0; i < h; i++) {
        for (long long j = 0; j < w; j++) {
            scanf("%s", t);
            if (strcmp(s, t) == 0) {
                char c = 'A' + j;
                printf("%c%lld\n", c, i + 1);
                return 0;
            }
        }
    }

    return 0;
}

// <END-OF-CODE>
