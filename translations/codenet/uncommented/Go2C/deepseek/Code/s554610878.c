#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MOD 1000000007

char* getString() {
    char buffer[10000];
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline character
    char* result = (char*)malloc(strlen(buffer) + 1);
    strcpy(result, buffer);
    return result;
}

int main() {
    char* week[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    char* s = getString();
    int index = -1;
    for (int i = 0; i < 7; i++) {
        if (strcmp(s, week[i]) == 0) {
            index = i;
            break;
        }
    }

    printf("%d\n", 7 - index);
    free(s);
    return 0;
}

