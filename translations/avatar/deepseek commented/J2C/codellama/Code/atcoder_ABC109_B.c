#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);
    
    char **map = (char **)malloc(N * sizeof(char *));
    for (int i = 0; i < N; i++) {
        map[i] = (char *)malloc(100 * sizeof(char));
        scanf("%s", map[i]);
    }
    
    int i, j;
    int ans = 1;
    char *past = (char *)malloc(100 * sizeof(char));
    char next[100];
    
    for (i = 0; i < N; i++) {
        for (j = 0; j < i; j++) {
            if (strcmp(map[i], map[j]) == 0) {
                ans = 0;
                break;
            }
        }
        if (ans == 0) {
            break;
        }
        strcpy(past, map[i]);
        
        if (i != 0) {
            if (strcmp(next, map[i]) != 0) {
                ans = 0;
                break;
            }
        }
        strcpy(next, map[i]);
    }
    
    if (ans == 1) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    
    return 0;
}

