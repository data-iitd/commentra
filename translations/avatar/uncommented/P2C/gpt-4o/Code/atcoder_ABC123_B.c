#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int value;
    int e;
} MenuItem;

int compare(const void *a, const void *b) {
    MenuItem *itemA = (MenuItem *)a;
    MenuItem *itemB = (MenuItem *)b;
    return itemA->e - itemB->e;
}

int main() {
    MenuItem menu[5];
    for (int i = 0; i < 5; i++) {
        char m[11]; // Assuming the input number will not exceed 10 digits
        scanf("%s", m);
        int len = strlen(m);
        int e = m[len - 1] - '0'; // Get the last character and convert to int
        if (e == 0) {
            e = 10;
        }
        menu[i].value = atoi(m);
        menu[i].e = e;
    }

    qsort(menu, 5, sizeof(MenuItem), compare);

    int ans = 0;
    for (int i = 1; i < 5; i++) {
        ans += ceil(menu[i].value / 10.0) * 10;
    }
    printf("%d\n", ans + menu[0].value);

    return 0;
}

// <END-OF-CODE>
