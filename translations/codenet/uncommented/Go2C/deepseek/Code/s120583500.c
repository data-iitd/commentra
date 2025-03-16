#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    int count = 0;
    int counter[1000] = {0};
    int counterIndex = 0;

    scanf("%s", s);

    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        if (s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T') {
            count++;
        } else {
            counter[counterIndex++] = count;
            count = 0;
        }
    }

    counter[counterIndex++] = count;

    for (int i = 0; i < counterIndex; i++) {
        for (int j = i + 1; j < counterIndex; j++) {
            if (counter[i] < counter[j]) {
                int temp = counter[i];
                counter[i] = counter[j];
                counter[j] = temp;
            }
        }
    }

    printf("%d\n", counter[0]);

    return 0;
}
