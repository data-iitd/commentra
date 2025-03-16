#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s1[100000], s2[100000];
    scanf("%s %s", s1, s2);
    int n1 = strlen(s1);
    int n2 = strlen(s2);
    int ans = 0;
    int i, j;
    for (i = 0; i < n2; i++) {
        int x1 = 0, x2 = 0;
        for (j = 0; j < n1; j++) {
            if (s1[j] == s2[i]) {
                x1++;
                x2++;
            }
        }
        ans += (x1 < x2)? x1 : x2;
    }
    printf("%d\n", ans);
    return 0;
}

