#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** read(int len) {
    char** strList = (char**)malloc(len * sizeof(char*));
    for (int i = 0; i < len; i++) {
        strList[i] = (char*)malloc(100 * sizeof(char));
        scanf("%s", strList[i]);
    }
    return strList;
}

void close(char** strList, int len) {
    for (int i = 0; i < len; i++) {
        free(strList[i]);
    }
    free(strList);
}

int main() {
    int n;
    scanf("%d", &n);

    if (n == 1) {
        printf("Hello World\n");
    } else {
        char** strs = read(2);
        int sum = atoi(strs[0]) + atoi(strs[1]);
        printf("%d\n", sum);
        close(strs, 2);
    }

    return 0;
}

