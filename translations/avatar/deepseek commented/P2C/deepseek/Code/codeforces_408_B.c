#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define MAX_COLORS 1000

typedef struct {
    int count[MAX_COLORS];
    int size;
} Counter;

void counter_init(Counter *c) {
    c->size = 0;
    memset(c->count, 0, sizeof(c->count));
}

void counter_add(Counter *c, char color) {
    c->count[color - 'a']++;
    if (c->count[color - 'a'] == 1) {
        c->size++;
    }
}

void counter_subtract(Counter *c, char color) {
    if (c->count[color - 'a'] > 0) {
        c->count[color - 'a']--;
        if (c->count[color - 'a'] == 0) {
            c->size--;
        }
    }
}

int counter_get(Counter *c, char color) {
    return c->count[color - 'a'];
}

void solution() {
    // Read the first line of input and create a Counter object for the bought colors
    char line[MAX_COLORS + 1];
    scanf("%s", line);
    Counter bought_count;
    counter_init(&bought_count);
    for (int i = 0; line[i] != '\0'; i++) {
        counter_add(&bought_count, line[i]);
    }

    // Read the second line of input and create a Counter object for the colors to be made
    scanf("%s", line);
    Counter made_count;
    counter_init(&made_count);
    for (int i = 0; line[i] != '\0'; i++) {
        counter_add(&made_count, line[i]);
    }

    // Initialize the result variable to store the total number of colors that can be made
    int res = 0;

    // Iterate over each color in the 'made_count' Counter
    for (int i = 0; i < 26; i++) {
        char color = 'a' + i;
        // Check if the color is not in the 'bought_count' Counter
        if (counter_get(&made_count, color) > 0 && counter_get(&bought_count, color) == 0) {
            // If a color is not bought, print -1 and exit
            printf("-1\n");
            return;
        }
        // Calculate the minimum of the counts of the current color in both 'bought_count' and 'made_count'
        // and add this to the result
        res += (counter_get(&bought_count, color) < counter_get(&made_count, color)) ? counter_get(&bought_count, color) : counter_get(&made_count, color);
    }

    // Print the final result
    printf("%d\n", res);
}

int main() {
    // Set the number of test cases to 1
    int t = 1;
    // Run the solution function for one test case
    for (int i = 0; i < t; i++) {
        solution();
    }
    return 0;
}

