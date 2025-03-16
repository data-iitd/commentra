#include <stdio.h>
#include <string.h>

int main() {
    char s[100]; // Assuming the input string will not exceed 99 characters
    scanf("%s", s);
    
    char *ans = "No";
    int indexC = strchr(s, 'C') ? strchr(s, 'C') - s : -1;
    int lastIndexF = strrchr(s, 'F') ? strrchr(s, 'F') - s : -1;

    if (indexC >= 0 && indexC < lastIndexF) {
        ans = "Yes";
    }
    if (indexC < 0) {
        ans = "No";
    }
    
    printf("%s\n", ans);
    return 0;
}

// <END-OF-CODE>
