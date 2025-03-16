#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    int ac_count = 0;
    int wa_count = 0;
    int tle_count = 0;
    int re_count = 0;
<<<<<<< HEAD
    char s[4]; // Maximum length of the strings is 3 + 1 for null terminator

    for (int i = 0; i < n; ++i) {
=======
    for (int i = 0; i < n; ++i) {
        char s[4]; // Maximum length of the strings is 3 + 1 for null terminator
>>>>>>> 98c87cb78a (data updated)
        scanf("%s", s);
        if (strcmp(s, "AC") == 0) {
            ac_count += 1;
        } else if (strcmp(s, "WA") == 0) {
            wa_count += 1;
        } else if (strcmp(s, "TLE") == 0) {
            tle_count += 1;
        } else if (strcmp(s, "RE") == 0) {
            re_count += 1;
        }
    }
    printf("AC x %d\n", ac_count);
    printf("WA x %d\n", wa_count);
    printf("TLE x %d\n", tle_count);
    printf("RE x %d\n", re_count);
}

// <END-OF-CODE>
