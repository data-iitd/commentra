
#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char s[100];
    
    scanf("%d", &n);
    scanf("%s", s);
    
    printf("%d\n", (int)strstr(s, "ABC")!= NULL);
    
    return 0;
}
// 