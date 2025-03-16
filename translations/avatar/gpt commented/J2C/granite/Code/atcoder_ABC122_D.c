
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>

#define MOD 1000000007

typedef struct {
    char *s;
    int len;
} String;

typedef struct {
    String *arr;
    int size;
} Array;

typedef struct {
    String key;
    long value;
} Entry;

typedef struct {
    Entry *entries;
    int size;
} Map;

Array *TOKENS;
Map **memo;
int N;

void init() {
    TOKENS = (Array *)malloc(sizeof(Array));
    TOKENS->arr = (String *)malloc(sizeof(String) * 4);
    TOKENS->arr[0] = (String){"A", 1};
    TOKENS->arr[1] = (String){"C", 1};
    TOKENS->arr[2] = (String){"G", 1};
    TOKENS->arr[3] = (String){"T", 1};
    TOKENS->size = 4;

    memo = (Map **)malloc(sizeof(Map *) * (N + 1));
    for (int i = 0; i <= N; i++) {
        memo[i] = (Map *)malloc(sizeof(Map));
        memo[i]->entries = (Entry *)malloc(sizeof(Entry) * 100);
        memo[i]->size = 0;
    }
}

int isOK(String last4) {
    char *s = last4.s;
    if (strstr(s, "AGC")!= NULL) {
        return 0;
    }
    for (int i = 0; i < 3; i++) {
        char temp = s[i];
        s[i] = s[i + 1];
        s[i + 1] = temp;
        if (strstr(s, "AGC")!= NULL) {
            return 0;
        }
        temp = s[i];
        s[i] = s[i + 1];
        s[i + 1] = temp;
    }
    return 1;
}

long dfs(int current, String last3) {
    if (memo[current]->size > 0) {
        for (int i = 0; i < memo[current]->size; i++) {
            if (strcmp(memo[current]->entries[i].key.s, last3.s) == 0) {
                return memo[current]->entries[i].value;
            }
        }
    }
    if (current == N) {
        return 1;
    }
    long result = 0;
    for (int i = 0; i < TOKENS->size; i++) {
        String c = TOKENS->arr[i];
        if (isOK((String){last3.s + 1, 3}) == 1) {
            result = (result + dfs(current + 1, (String){last3.s + 1, 3})) % MOD;
        }
    }
    Entry entry = (Entry){last3, result};
    memo[current]->entries[memo[current]->size] = entry;
    memo[current]->size++;
    return result;
}

int main() {
    init();
    scanf("%d", &N);
    printf("%ld\n", dfs(0, (String){"TTT", 3}));
    return 0;
}

