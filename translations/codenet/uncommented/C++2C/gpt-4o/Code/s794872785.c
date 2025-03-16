#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRINGS 1000
#define MAX_STRING_LENGTH 100

int solve() {
    int maxsize = 0;
    int maxcnt = 0;
    int ans_num;
    int ans_num2;
    char str_v[MAX_STRINGS][MAX_STRING_LENGTH];
    int str_count = 0;

    char in[MAX_STRING_LENGTH];
    while (scanf("%s", in) != EOF) {
        strcpy(str_v[str_count], in);
        if (maxsize < strlen(in)) {
            maxsize = strlen(in);
            ans_num = str_count;
        }
        str_count++;
    }

    for (int i = 0; i < str_count; i++) {
        int cnt = 0;
        for (int j = 0; j < str_count; j++) {
            if (strcmp(str_v[i], str_v[j]) == 0) cnt++;
        }
        if (maxcnt < cnt) {
            maxcnt = cnt;
            ans_num2 = i;
        }
    }

    printf("%s %s\n", str_v[ans_num2], str_v[ans_num]);
<<<<<<< HEAD

=======
    
>>>>>>> 98c87cb78a (data updated)
    return 1;
}

int main() {
    solve();
    return 0;
}

// <END-OF-CODE>
