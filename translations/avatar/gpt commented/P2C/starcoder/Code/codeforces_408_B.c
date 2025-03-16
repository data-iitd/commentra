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
#include <stdint.h>
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
#include <stdint.h>

int main() {
    // Read the first line of input which represents the colors bought
    char line[100000];
    scanf("%s", line);
    // Count the occurrences of each color bought using Counter
    int bought_count[26] = {0};
    for (int i = 0; i < strlen(line); i++) {
        bought_count[line[i] - 'A']++;
    }
    
    // Read the second line of input which represents the colors made
    scanf("%s", line);
    // Count the occurrences of each color made using Counter
    int made_count[26] = {0};
    for (int i = 0; i < strlen(line); i++) {
        made_count[line[i] - 'A']++;
    }
    
    // Initialize the result variable to store the total count of matched colors
    int res = 0;
    
    // Iterate through each color in the made_count
    for (int i = 0; i < 26; i++) {
        // If a color made is not found in the bought colors, return -1
        if (made_count[i] > 0 && bought_count[i] == 0) {
            printf("-1\n");
            return 0;
        }
        // Add the minimum of the bought and made counts for each color to the result
        res += min(bought_count[i], made_count[i]);
    }
    
    // Print the total count of matched colors
    printf("%d\n", res);
    return 0;
}

