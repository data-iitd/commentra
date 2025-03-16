
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char a[100];
    char *p;
    char *q;
    char *r;
    char *s;
    char *t;
    char *u;
    char *v;
    char *w;
    char *x;
    char *y;
    char *z;

    printf("Enter a string: ");
    scanf("%s", a);

    p = strchr(a, ',');
    while (p != NULL)
    {
        *p = ' ';
        p = strchr(p + 1, ',');
    }

    printf("Modified string: %s\n", a);

    return 0;
}

