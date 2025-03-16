#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);
    
    int i;
    char str[100000];
    char past[100000];
    char next;
    int ans = 1;
    
    for (i = 0; i < N; i++) {
        scanf("%s", str);
        
        if (strstr(past, str)!= NULL) {
            ans = 0;
            break;
        }
        strcpy(past, str);
        
        if (i!= 0) {
            if (str[0]!= next) {
                ans = 0;
                break;
            }
        }
        next = str[strlen(str) - 1];
    }
    
    if (ans) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    
    return 0;
}
