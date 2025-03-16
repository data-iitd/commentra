
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <float.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <float.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_COLORS 26

int main() {
    // Read the first line and count the number of occurrences of each color
    char line[1000];
    scanf("%s", line);
    int bought_count[MAX_COLORS] = {0};
    for (int i = 0; i < strlen(line); i++) {
        bought_count[line[i] - 'a']++;
    }

    // Read the second line and count the number of occurrences of each color
    scanf("%s", line);
    int made_cout[MAX_COLORS] = {0};
    for (int i = 0; i < strlen(line); i++) {
        made_cout[line[i] - 'a']++;
    }

    // Initialize result to 0
    int res = 0;

    // Iterate through each color in made_cout
    for (int i = 0; i < MAX_COLORS; i++) {
        // Check if the color is present in bought_count
        if (made_cout[i] > 0 && bought_count[i] == 0) {
            // If not, print -1 and exit the function
            printf("-1\n");
            return 0;
        }

        // Update the result by adding the minimum of bought and made counts
        res += (bought_count[i] < made_cout[i])? bought_count[i] : made_cout[i];
    }

    // Print the result
    printf("%d\n", res);

    return 0;
}

