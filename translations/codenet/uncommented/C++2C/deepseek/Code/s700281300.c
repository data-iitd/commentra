#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

typedef long long ll;

int main() {
    int n;
    scanf("%d", &n);

    rep(i,n) {
        char s[1000];
        scanf("%s", s);

        // Initialize a set to store unique strings
        // Note: In C, we don't have a built-in set, so we use a simple array with a fixed size
        char *st[100000];
        int st_size = 0;

        // Insert the original string into the set
        st[st_size++] = strdup(s);

        REP(j,1,strlen(s)){ 
            char res[1000], res2[1000];
            int k;
            for(k=0; k<j; k++) {
                res[k] = s[k];
            }
            res[k] = '\0';

            for(k=j; k<strlen(s); k++) {
                res2[k-j] = s[k];
            }
            res2[k-j] = '\0';

            // Reverse the strings
            int len = strlen(res);
            for(int k=0; k<len/2; k++) {
                char temp = res[k];
                res[k] = res[len-k-1];
                res[len-k-1] = temp;
            }

            len = strlen(res2);
            for(int k=0; k<len/2; k++) {
                char temp = res2[k];
                res2[k] = res2[len-k-1];
                res2[len-k-1] = temp;
            }

            // Concatenate and insert the reversed strings
            char t[1000];
            strcpy(t, res);
            strcat(t, res2);
            if (strstr(t, "\0") == NULL) {
                st[st_size++] = strdup(t);
            }

            strcpy(t, res2);
            strcat(t, res);
            if (strstr(t, "\0") == NULL) {
                st[st_size++] = strdup(t);
            }

            strcpy(t, res);
            strcat(t, res2);
            if (strstr(t, "\0") == NULL) {
                st[st_size++] = strdup(t);
            }

            strcpy(t, res2);
            strcat(t, res);
            if (strstr(t, "\0") == NULL) {
                st[st_size++] = strdup(t);
            }

            strcpy(t, res);
            strcat(t, res2);
            if (strstr(t, "\0") == NULL) {
                st[st_size++] = strdup(t);
            }

            strcpy(t, res2);
            strcat(t, res);
            if (strstr(t, "\0") == NULL) {
                st[st_size++] = strdup(t);
            }

            strcpy(t, res);
            strcat(t, res2);
            if (strstr(t, "\0") == NULL) {
                st[st_size++] = strdup(t);
            }

            strcpy(t, res2);
            strcat(t, res);
            if (strstr(t, "\0") == NULL) {
                st[st_size++] = strdup(t);
            }
        }

        printf("%d\n", st_size);
    }

    return 0;
}
