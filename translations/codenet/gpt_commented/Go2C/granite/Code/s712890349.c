
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char value;
    int len;
} Block;

int max(int a, int b) {
    return (a > b)? a : b;
}

Block* run_length(char* s) {
    int n = strlen(s);
    Block* blocks = (Block*)malloc(n * sizeof(Block));
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || s[i]!= s[i-1]) {
            blocks[count].value = s[i];
            blocks[count].len = 1;
            count++;
        } else {
            blocks[count-1].len++;
        }
    }
    return blocks;
}

int main() {
    int n, k, ans = 0;
    scanf("%d %d", &n, &k);
    char s[n];
    fgets(s, n, stdin);
    s[n-1] = '\0'; // Remove trailing newline character
    Block* blocks = run_length(s);
    int sum = 0, zero = 0, l = 0;
    for (int r = 0; r < n; r++) {
        sum += blocks[r].len;
        if (blocks[r].value == '0') {
            zero++;
        }
        while (zero > k) {
            sum -= blocks[l].len;
            if (blocks[l].value == '0') {
                zero--;
            }
            l++;
        }
        ans = max(ans, sum);
    }
    printf("%d\n", ans);
    free(blocks);
    return 0;
}

