#include <stdio.h>
#include <string.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int differences[1000]; // Assuming the maximum number of differences will not exceed 1000
    int count = 0;

    for (int i = 0; i < m; i++) {
        char s[1001]; // Assuming the length of each string will not exceed 1000 characters
        scanf("%s", s);

        int index_S = -1, index_G = -1;

        // Find the indices of 'S' and 'G' in the current string
        for (int j = 0; j < strlen(s); j++) {
            if (s[j] == 'S') {
                index_S = j;
            } else if (s[j] == 'G') {
                index_G = j;
            }
        }

        // Calculate the difference and add it to the array if valid
        if (index_S != -1 && index_G != -1 && index_S > index_G) {
            differences[count++] = index_S - index_G;
        }
    }

    // Check if there is any negative number in the array and print accordingly
    int has_negative = 0;
    for (int i = 0; i < count; i++) {
        if (differences[i] < 0) {
            has_negative = 1;
            break;
        }
    }

    if (has_negative) {
        printf("-1\n");
    } else {
        printf("%d\n", count);
    }

    return 0;
}
