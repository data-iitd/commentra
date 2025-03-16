#include <stdio.h>
#include <string.h>

int main() {
    char ip[100]; // Assuming the input will not exceed 99 characters
    char st[100] = "";
    
    scanf("%s", ip);
    
    if (strlen(ip) != 1) {
        if (ip[0] == '9') {
            strcat(st, "9");
            // Shift the string to remove the first character
            memmove(ip, ip + 1, strlen(ip)); 
        }
        
        for (int i = 0; i < strlen(ip); i++) {
            if (ip[i] > '4') {
                int n = 9 - (ip[i] - '0');
                char temp[2];
                sprintf(temp, "%d", n);
                strcat(st, temp);
            } else {
                char temp[2] = {ip[i], '\0'};
                strcat(st, temp);
            }
        }
    } else {
        strcpy(st, ip);
    }
    
    printf("%d\n", atoi(st));
    
    return 0;
}

// <END-OF-CODE>
