
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    // Step 1: Read two times from the user, split by colon and convert to LocalTime objects
    struct tm x, y;
    time_t t;
    char *p;
    char s[100], t[100];
    scanf("%s", s);
    scanf("%s", t);
    x = *localtime(&t);
    y = *localtime(&t);

    // Step 2: Calculate the difference between the two times
    printf("%d\n", x.tm_hour - y.tm_hour);
    printf("%d\n", x.tm_min - y.tm_min);

    return 0;
}

