#include <stdio.h>
#include <string.h>

int main() {
    char ip[100];
    char st[100];
    int len, i;

    scanf("%s", ip);
    len = strlen(ip);
    if (len != 1) {
        if (ip[0] == '9') {
            st[0] = '9';
            for (i = 1; i < len; i++) {
                if (ip[i] > '4') {
                    st[i] = '9' - ip[i] + '0';
                } else {
                    st[i] = ip[i];
                }
            }
            st[len] = '\0';
        } else {
            for (i = 0; i < len; i++) {
                if (ip[i] > '4') {
                    st[i] = '9' - ip[i] + '0';
                } else {
                    st[i] = ip[i];
                }
            }
            st[len] = '\0';
        }
    } else {
        strcpy(st, ip);
    }
    printf("%d\n", atoi(st));
    return 0;
}
