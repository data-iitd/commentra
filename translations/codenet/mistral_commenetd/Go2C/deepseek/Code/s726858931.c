#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACITY 1000 * 1024

char buffer[CAPACITY];
int bufferIndex = 0;

void scanInit() {
    setvbuf(stdin, buffer, _IOFBF, CAPACITY);
}

int nextInt() {
    int num;
    scanf("%d", &num);
    return num;
}

char nextChar() {
    char ch;
    scanf(" %c", &ch);
    return ch;
}

char* nextStr() {
    char* str = (char*)malloc(CAPACITY * sizeof(char));
    scanf("%s", str);
    return str;
}

int main() {
    scanInit();

    char* s = nextStr();

    char c = 'a';

    for (int j = 0; j < 26; j++) {
        int found = 0;

        for (int i = 0; i < strlen(s); i++) {
            if (s[i] == c) {
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("%c\n", c);
            return 0;
        }

        c++;
    }

    printf("None\n");
    return 0;
}
