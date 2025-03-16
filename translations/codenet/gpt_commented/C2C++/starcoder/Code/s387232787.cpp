#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;

int main()
{
    char str[1200];
    while (scanf("%s", str) > 0) {
        for (char *p = str; *p; p++) {
            if (islower(*p)) {
                c[*p - 'a']++;
            } else if (isupper(*p)) {
                c[*p - 'A']++;
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        printf("%c : %d\n", 'a' + i, c[i]);
    }
    return 0;
}

