#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[4][3];
    int i, j, yes = 0;
    
    for (i = 0; i < 4; i++) {
        scanf("%s", str[i]);
    }
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            if ((str[i][j] == str[i][j + 1] && (str[i + 1][j] == str[i][j] || str[i + 1][j + 1] == str[i][j])) || (str[i + 1][j] == str[i + 1][j + 1] && (str[i][j] == str[i + 1][j] || str[i][j + 1] == str[i + 1][j]))) {
                yes = 1;
                printf("YES\n");
                break;
            }
        }
        
        if (yes == 1) {
            break;
        }
    }
    
    if (yes == 0) {
        printf("NO\n");
    }
    
    return 0;
}

