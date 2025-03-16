
#include <stdio.h>
#include <string.h>

int main() {
    char ip[100];
    scanf("%s", ip);
    char st[100] = "";
    int len = strlen(ip);
    if (len!= 1) {
        if (ip[0] == '9') {
            st[0] = '9';
            strcpy(ip, ip + 1);
        }
        for (int i = 0; i < len; i++) {
            if (ip[i] - '0' > 4) {
                st[i] = '9' - (ip[i] - '0');
            } else {
                st[i] = ip[i];
            }
        }
    } else {
        st[0] = ip[0];
    }
    printf("%d\n", atoi(st));
    return 0;
}
//END-OF-CODE