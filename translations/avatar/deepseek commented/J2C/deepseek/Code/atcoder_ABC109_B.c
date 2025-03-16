#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);
    
    char** map = (char**)malloc(N * sizeof(char*));
    for (int i = 0; i < N; i++) {
        map[i] = (char*)malloc(100 * sizeof(char));
    }
    
    for (int i = 0; i < N; i++) {
        scanf("%s", map[i]);
    }
    
    int ans = 1;
    char** past = (char**)malloc(N * sizeof(char*));
    for (int i = 0; i < N; i++) {
        past[i] = (char*)malloc(100 * sizeof(char));
    }
    char next[2] = "";
    
    for (int i = 0; i < N; i++) {
        int found = 0;
        for (int j = 0; j < i; j++) {
            if (strcmp(past[j], map[i]) == 0) {
                ans = 0;
                found = 1;
                break;
            }
        }
        if (found) break;
        
        strcpy(past[i], map[i]);
        
        if (i != 0) {
            if (next[0] != map[i][0]) {
                ans = 0;
                break;
            }
        }
        strcpy(next, map[i] + strlen(map[i]) - 1);
    }
    
    if (ans) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    
    for (int i = 0; i < N; i++) {
        free(map[i]);
        free(past[i]);
    }
    free(map);
    free(past);
    
    return 0;
}
