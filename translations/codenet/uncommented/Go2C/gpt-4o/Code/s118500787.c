#include <stdio.h>
#include <string.h>

int main() {
    char S[100001], T[100001];
    scanf("%s %s", S, T);
    
    int max = 0;
    int lenS = strlen(S);
    int lenT = strlen(T);
    
    for (int i = 0; i <= lenS - lenT; i++) {
        int c = 0;
        for (int j = 0; j < lenT; j++) {
            if (S[i + j] == T[j]) {
                c++;
            }
        }
        if (max < c) {
            max = c;
        }
    }
    
    printf("%d\n", lenT - max);
    return 0;
}

// <END-OF-CODE>
