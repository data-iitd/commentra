
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);
    char** map = (char**)malloc(sizeof(char*) * N);
    for (int i = 0; i < N; i++) {
        map[i] = (char*)malloc(sizeof(char) * 100);
        scanf("%s", map[i]);
    }
    int ans = 1;
    char** past = (char**)malloc(sizeof(char*) * N);
    char* next = "";
    for (int i = 0; i < N; i++) {
        int found = 0;
        for (int j = 0; j < i; j++) {
            if (strcmp(past[j], map[i]) == 0) {
                found = 1;
                break;
            }
        }
        if (found) {
            ans = 0;
            break;
        }
        past[i] = (char*)malloc(sizeof(char) * 100);
        strcpy(past[i], map[i]);
        if (i!= 0) {
            if (map[i][0]!= next[0]) {
                ans = 0;
                break;
            }
        }
        char* temp = (char*)malloc(sizeof(char) * 100);
        strcpy(temp, map[i]);
        temp[strlen(temp) - 1] = '\0';
        next = temp;
    }
    if (ans) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}
//END-OF-CODE