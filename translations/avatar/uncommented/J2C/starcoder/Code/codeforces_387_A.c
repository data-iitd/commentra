#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    struct tm *x, *y;
    time_t t;
    char *p;
    char s[100], t[100];
    scanf("%s", s);
    scanf("%s", t);
    x = localtime(&t);
    y = localtime(&t);
    x->tm_hour = atoi(s);
    x->tm_min = atoi(s);
    x->tm_sec = 0;
    y->tm_hour = atoi(t);
    y->tm_min = atoi(t);
    y->tm_sec = 0;
    t = mktime(x);
    t -= mktime(y);
    printf("%ld\n", t);
    return 0;
}

