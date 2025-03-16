#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    struct tm *x, *y;
    time_t t;
    char s[9], t[9];
    scanf("%s", s);
    scanf("%s", t);
    x = localtime(&t);
    y = localtime(&t);
    x->tm_hour = atoi(s[0]);
    x->tm_min = atoi(s[1]);
    y->tm_hour = atoi(t[0]);
    y->tm_min = atoi(t[1]);
    printf("%d", (x->tm_hour - y->tm_hour) * 60 + (x->tm_min - y->tm_min));
    return 0;
}

