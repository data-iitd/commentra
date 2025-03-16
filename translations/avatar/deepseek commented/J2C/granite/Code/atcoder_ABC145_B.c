

#include <stdio.h>
#include <string.h>

int main() {
    // Reading the integer input n
    int n;
    scanf("%d", &n);
    
    // Reading the string input str
    char str[n];
    scanf("%s", str);
    
    // Constructing the string a by taking the first n/2 characters of str
    char a[n/2];
    for (int i = 0; i < n/2; i++) {
        a[i] = str[i];
    }
    
    // Checking if str is equal to a + a and printing the result
    if (strcmp(str, a) == 0) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    
    return 0;
}
// END-OF-CODE