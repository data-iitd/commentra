#include <stdio.h>
#include <string.h>

int main() {
    char a[100], b[100];
    scanf("%s %s", a, b);
    
    int x = (strlen(a) > strlen(b))? strlen(a) : strlen(b);
    
    strcpy(a, (x - strlen(a))? strcat(strcat(a, "0"), "0") : a);
    strcpy(b, (x - strlen(b))? strcat(strcat(b, "0"), "0") : b);
    
    char s[100] = "";
    int c = 0;
    
    for (int i = 0; i < x; i++) {
        int d = (int)b[i] + (int)a[x - i - 1] + c;
        if (d > 9) {
            strcat(s, (char[]){d % 10 + '0', '\0'});
            c = 1;
        } else {
            strcat(s, (char[]){d + '0', '\0'});
            c = 0;
        }
    }
    
    if (c == 1) {
        strcat(s, (char[]){'1', '\0'});
    }
    
    printf("%d\n", atoi(s));
    
    return 0;
}

