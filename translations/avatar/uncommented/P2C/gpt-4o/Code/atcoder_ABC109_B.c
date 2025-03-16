#include <stdio.h>
#include <string.h>

#define MAX_N 1000
#define MAX_LEN 100

int main() {
    int n;
    scanf("%d", &n);
    
    char l[MAX_N][MAX_LEN];
    int s[256] = {0}; // To count occurrences of characters (ASCII range)
    char f[4] = "Yes"; // Initialize f to "Yes"
    
    for (int i = 0; i < n; i++) {
        scanf("%s", l[i]);
    }
    
    int i = -1;
    for (int j = 0; j < n; j++) {
        s[l[j][0]]++; // Increment the count for the first character of the string
        
        if (s[l[j][0]] >= 2) {
            strcpy(f, "No");
        }
        
        if (i != -1 && l[i][strlen(l[i]) - 1] != l[j][0]) {
            strcpy(f, "No");
        }
        
        i++;
    }
    
    printf("%s\n", f);
    return 0;
}

// <END-OF-CODE>
