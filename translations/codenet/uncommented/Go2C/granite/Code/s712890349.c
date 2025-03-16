
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char value;
    int len;
} Block;

int max(int a, int b) {
    return (a > b)? a : b;
}

Block* run_length(char* s) {
    int len = 0;
    while (s[len]!= '\0') {
        len++;
    }
    Block* blocks = (Block*)malloc(sizeof(Block) * len);
    int i = 0;
    int j = 0;
    while (s[j]!= '\0') {
        char value = s[j];
        int count = 1;
        while (s[j+1] == value && s[j+1]!= '\0') {
            count++;
            j++;
        }
        blocks[i].value = value;
        blocks[i].len = count;
        i++;
        j++;
    }
    return blocks;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    char s[N];
    scanf("%s", s);
    Block* blocks = run_length(s);
    int sum = 0;
    int zero = 0;
    int l = 0;
    int ans = 0;
    for (int r = 0; r < N; r++) {
        sum += blocks[r].len;
        if (blocks[r].value == '0') {
            zero++;
        }
        while (K < zero) {
            sum -= blocks[l].len;
            if (blocks[l].value == '0') {
                zero--;
            }
            l++;
        }
        ans = max(ans, sum);
    }
    printf("%d\n", ans);
    return 0;
}

