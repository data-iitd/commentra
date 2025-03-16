
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>

int main() {
    // Create a FastScanner object to read input efficiently
    typedef struct {
        char buffer[1000000];
        int index;
    } FastScanner;
    FastScanner input;
    input.index = 0;

    // Read the number of integers to be processed
    int n = 0;
    sscanf(input.buffer + input.index, "%d", &n);
    input.index += strlen(input.buffer + input.index) + 1;

    // Initialize a HashMap to store the frequency of each integer
    typedef struct {
        int key;
        int value;
    } Entry;
    Entry* map = (Entry*)malloc(n * sizeof(Entry));
    int mapSize = 0;

    // Loop through the input integers and populate the frequency map
    for (int i = 0; i < n; i++) {
        int val = 0;
        sscanf(input.buffer + input.index, "%d", &val);
        input.index += strlen(input.buffer + input.index) + 1;
        int found = 0;
        for (int j = 0; j < mapSize; j++) {
            if (map[j].key == val) {
                map[j].value++;
                found = 1;
                break;
            }
        }
        if (!found) {
            map[mapSize].key = val;
            map[mapSize].value = 1;
            mapSize++;
        }
    }

    // Initialize a variable to track the maximum frequency found
    int max = INT_MIN;

    // Iterate through the entries in the frequency map to find the maximum frequency
    for (int i = 0; i < mapSize; i++) {
        int value = map[i].value;
        // Update max if the current frequency is greater than the current max
        max = fmax(max, value);
    }

    // Print the maximum frequency and the number of unique integers
    printf("%d %d\n", max, mapSize);

    return 0;
}
