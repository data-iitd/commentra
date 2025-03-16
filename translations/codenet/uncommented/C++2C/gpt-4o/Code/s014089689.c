#include <stdio.h>
<<<<<<< HEAD
#include <string.h>
=======
>>>>>>> 98c87cb78a (data updated)

int main() {
    int n;
    scanf("%d", &n);
    char s[n + 1]; // +1 for the null terminator
    scanf("%s", s);
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        cnt++;
        int j = i + 1;
        for (; j < n; j++) {
            if (s[i] != s[j]) {
                break;
            }
        }
        i = j - 1;
    }
    
    printf("%d\n", cnt);
    return 0;
}

// <END-OF-CODE>
