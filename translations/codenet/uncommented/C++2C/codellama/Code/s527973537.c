#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    char N[100];
    scanf("%s", N);
    int S = 0;
    for (int i=0;i<strlen(N);i++){
        S += N[i]-'0';
    }
    if (atoi(N)%S==0) printf("Yes\n");
    else printf("No\n");
    return 0;
}
