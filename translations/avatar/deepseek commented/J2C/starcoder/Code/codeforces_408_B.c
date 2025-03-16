
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function to check if s1 is a valid substring of s2
bool isValid(char *s1, char *s2) {
    int n1 = strlen(s1);
    int n2 = strlen(s2);
    bool map[256] = {0};
    
    // Populate the map with characters from s1
    for (int i = 0; i < n1; i++) {
        map[s1[i]] = true;
    }
    
    // Check if all characters of s1 are present in s2
    for (int i = 0; i < n2; i++) {
        if (!map[s2[i]]) return false;
    }
    
    return true;
}

// Driver program
int main() {
    char s1[100000], s2[100000];
    scanf("%s %s", s1, s2);
    
    // Check if the strings are valid using the isValid method
    if (isValid(s1, s2) == false) {
        printf("-1\n");
    } else {
        int ans = 0;
        char c;
        int x1, x2;
        bool hs[256] = {0};
        
        // Iterate over the characters of s2
        for (int i = 0; i < strlen(s2); i++) {
            c = s2[i];
            if (!hs[c]) {
                hs[c] = true;
                x1 = 0;
                x2 = 0;
                
                // Get frequency of character in s1
                for (int j = 0; j < strlen(s1); j++) {
                    if (s1[j] == c) x1++;
                }
                
                // Get frequency of character in s2
                for (int j = 0; j < strlen(s2); j++) {
                    if (s2[j] == c) x2++;
                }
                
                x1 = (x1 < x2)? x1 : x2;
                ans += x1;
            }
        }
        
        printf("%d\n", ans);
    }
    
    return 0;
}

