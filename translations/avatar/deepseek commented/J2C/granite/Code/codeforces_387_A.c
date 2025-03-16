

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Step 1: Read two times from the user, split by colon and convert to LocalTime objects
    char s[10], t[10];
    scanf("%s %s", s, t);
    int h1 = atoi(s);
    int m1 = atoi(s + 3);
    int h2 = atoi(t);
    int m2 = atoi(t + 3);

    // Step 2: Calculate the difference between the two times
    int h = h1 - h2;
    int m = m1 - m2;
    if (m < 0) {
        m += 60;
        h--;
    }

    // Step 3: Print the difference
    printf("%d:%02d\n", h, m);

    return 0;
}

