
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char str[4][1000];
    int i = -1;
    while(i!= 3) {
        i++;
        scanf("%s", str[i]);
    }
    int u = -1;
    while(u!= 2) {
        u++;
        int yes = 0;
        int i = -1;
        while(i!= 2) {
            i++;
            if((str[u][i] == str[u][i+1] && (str[u+1][i] == str[u][i] || str[u+1][i+1] == str[u][i])) || (str[u+1][i] == str[u+1][i+1] && (str[u][i] == str[u+1][i] || str[u][i+1] == str[u+1][i]))) {
                yes = 1;
                printf("YES\n");
                break;
            }
        }
        if(yes == 1) {
            break;
        }
        if(yes == 0) {
            printf("NO\n");
        }
    }
    return 0;
}

