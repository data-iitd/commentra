#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    // Assuming a TreeMap-like structure in C is not straightforward, we'll use a 2D array to simulate it.
    // This is a simplified version and may not handle all edge cases perfectly.
    int map[1000][2] = {0}; // Array to simulate TreeMap, where map[i][0] is the key and map[i][1] is the value.
    int index = 0; // Index to keep track of the last used slot in the map array.

    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        int found = 0;

        // Check if the lower key exists.
        for (int j = 0; j < index; j++) {
            if (map[j][0] < num) {
                if (map[j][1] == 1) {
                    // Remove the key if the value is 1.
                    for (int k = j; k < index - 1; k++) {
                        map[k][0] = map[k + 1][0];
                        map[k][1] = map[k + 1][1];
                    }
                    index--;
                } else {
                    // Decrease the value if it's greater than 1.
                    map[j][1]--;
                }
                found = 1;
                break;
            }
        }

        // If no lower key exists, add the new key.
        if (!found) {
            map[index][0] = num;
            map[index][1] = 1;
            index++;
        } else {
            // Add the new key or increase the value if it already exists.
            int j;
            for (j = 0; j < index; j++) {
                if (map[j][0] == num) {
                    map[j][1]++;
                    break;
                }
            }
            if (j == index) {
                map[index][0] = num;
                map[index][1] = 1;
                index++;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < index; i++) {
        ans += map[i][1];
    }
    printf("%d\n", ans);

    return 0;
}
