

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>

typedef struct {
    int color;
    int count;
} Color;

int compareColors(const void *a, const void *b) {
    Color *c1 = (Color *)a;
    Color *c2 = (Color *)b;
    return c1->color - c2->color;
}

int main() {
    // Read the first line of input and create a Color array for the bought colors
    char line[1000];
    fgets(line, sizeof(line), stdin);
    int n = strlen(line);
    line[n-1] = '\0';
    Color *boughtColors = (Color *)malloc(n * sizeof(Color));
    int boughtCount = 0;
    char *token = strtok(line, " ");
    while (token!= NULL) {
        boughtColors[boughtCount].color = atoi(token);
        boughtColors[boughtCount].count = 1;
        boughtCount++;
        token = strtok(NULL, " ");
    }
    qsort(boughtColors, boughtCount, sizeof(Color), compareColors);

    // Read the second line of input and create a Color array for the colors to be made
    fgets(line, sizeof(line), stdin);
    n = strlen(line);
    line[n-1] = '\0';
    Color *madeColors = (Color *)malloc(n * sizeof(Color));
    int madeCount = 0;
    token = strtok(line, " ");
    while (token!= NULL) {
        madeColors[madeCount].color = atoi(token);
        madeColors[madeCount].count = 1;
        madeCount++;
        token = strtok(NULL, " ");
    }
    qsort(madeColors, madeCount, sizeof(Color), compareColors);

    // Initialize the result variable to store the total number of colors that can be made
    int res = 0;

    // Iterate over each color in the'madeColors' array
    int i = 0, j = 0;
    while (i < madeCount && j < boughtCount) {
        // Check if the current color in'madeColors' is the same as the current color in 'boughtColors'
        if (madeColors[i].color == boughtColors[j].color) {
            // If the colors are the same, add the minimum of the counts to the result
            res += min(madeColors[i].count, boughtColors[j].count);
            i++;
            j++;
        } else if (madeColors[i].color < boughtColors[j].color) {
            // If the color in'madeColors' is smaller, skip it
            i++;
        } else {
            // If the color in 'boughtColors' is smaller, skip it
            j++;
        }
    }

    // Print the final result
    printf("%d\n", res);

    // Free the memory allocated for the Color arrays
    free(boughtColors);
    free(madeColors);

    return 0;
}

