
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *p;
    int x1, y1, x2, y2, DIF1, DIF2, x3, y3, x4, y4;

    p = (char *)malloc(100 * sizeof(char));
    scanf("%s", p);
    x1 = atoi(strtok(p, " "));
    y1 = atoi(strtok(NULL, " "));
    x2 = atoi(strtok(NULL, " "));
    y2 = atoi(strtok(NULL, " "));
    DIF1 = x2 - x1;
    DIF2 = y2 - y1;
    x3 = x2 - DIF2;
    y3 = y2 + DIF1;
    x4 = x1 - DIF2;
    y4 = y1 + DIF1;
    printf("%d %d %d %d", x3, y3, x4, y4);

    free(p);
    return 0;
}

