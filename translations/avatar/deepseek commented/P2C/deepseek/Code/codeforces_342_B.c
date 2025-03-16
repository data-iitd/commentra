#include <stdio.h>

int main() {
    int n, m, s, f;
    scanf("%d %d %d %d", &n, &m, &s, &f);

    char direction, char_to_add;
    int i = 1, j = s, t, l, r;
    int k = 1;

    if (s < f) {
        direction = 'R';
    } else {
        direction = 'L';
    }

    char result[100000]; // Assuming the result won't exceed 100000 characters
    int result_index = 0;

    while (j != f) {
        if (i > k && k < m) {
            scanf("%d %d %d", &t, &l, &r);
            k++;
        }

        if (i == t && (l <= j && j <= r || l <= j + (direction == 'R' ? 1 : -1) && j + (direction == 'R' ? 1 : -1) <= r)) {
            result[result_index++] = 'X';
        } else {
            result[result_index++] = direction;
            j += (direction == 'R' ? 1 : -1);
        }
        i++;
    }

    result[result_index] = '\0'; // Null-terminate the result string
    printf("%s\n", result);

    return 0;
}

