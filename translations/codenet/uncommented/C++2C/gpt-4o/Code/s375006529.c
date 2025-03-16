#include <stdio.h>
#include <string.h>

int main() {
    char s[100]; // Assuming the maximum length of the string is 99
    scanf("%s", s);
    int n = strlen(s);
    int v[26] = {0};
    
    for (int i = 0; i < n; i++) {
        v[s[i] - 'a']++;
    }
    
    char *ans = "Yes";
    for (int i = 0; i < 26; i++) {
        if (v[i] % 2 != 0) {
            ans = "No";
            break;
        }
    }
    
    printf("%s\n", ans);
    return 0;
}

// <END-OF-CODE>
