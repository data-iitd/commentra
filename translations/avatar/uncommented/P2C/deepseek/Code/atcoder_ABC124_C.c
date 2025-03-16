#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char s[1000];
    int even[2] = {0}, odd[2] = {0};
    
    scanf("%s", s);
    
    for (int i = 0; i < strlen(s); i++) {
        if (i % 2 == 0) {
            even[s[i] - '0']++;
        } else {
            odd[s[i] - '0']++;
        }
    }
    
    int result = abs(even[0] + odd[1] - (strlen(s) / 2)) < abs(even[1] + odd[0] - (strlen(s) / 2)) ? 
                 abs(even[0] + odd[1] - (strlen(s) / 2)) : 
                 abs(even[1] + odd[0] - (strlen(s) / 2));
    
    printf("%d\n", result);
    
    return 0;
}
