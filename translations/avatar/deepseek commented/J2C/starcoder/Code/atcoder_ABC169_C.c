
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    long a;
    char b[100000];
    scanf("%ld", &a);
    scanf("%s", b);
    
    int length = strlen(b);
    char bStr[100000];
    int bInt = 0;
    for (int i = 0; i < length; i++) {
        if (b[i]!= '.') {
            bStr[i] = b[i];
        }
    }
    bInt = atoi(bStr);
    
    long result = (a * bInt) / 100;
    printf("%ld\n", result);
    return 0;
}

