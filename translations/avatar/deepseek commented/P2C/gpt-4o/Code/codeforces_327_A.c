#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

// Function to find indices of a character in a string
void find_indices(const char *s, char ch, int *indices, int *count) {
    *count = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == ch) {
            indices[(*count)++] = i;
        }
    }
}

// Function to calculate the maximum distance between two indices of '0'
int calculate_maximum_distance(int *indices, int count) {
    int maximum = 0;
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            int distance = 2 + 2 * (j - i - 1) - (indices[j] - indices[i] - 1);
            if (distance > maximum) {
                maximum = distance;
            }
        }
    }
    return maximum;
}

int main() {
    int n;
    char s[MAX_LENGTH];
    
    // Read the integer input
    scanf("%d", &n);
    // Read the string input and remove spaces
    scanf(" %[^\n]", s);
    
    // Remove spaces from the string
    char temp[MAX_LENGTH];
    int j = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != ' ') {
            temp[j++] = s[i];
        }
    }
    temp[j] = '\0';
    strcpy(s, temp);
    
    // If the string does not contain '0', print n - 1
    if (strchr(s, '0') == NULL) {
        printf("%d\n", n - 1);
    } else {
        // Find all indices of '0' in the string
        int indices[MAX_LENGTH];
        int count;
        find_indices(s, '0', indices, &count);
        
        // If there is only one '0', print n
        if (count == 1) {
            printf("%d\n", n);
        } else {
            // Calculate the maximum distance
            int maximum = calculate_maximum_distance(indices, count);
            // Print the count of '1's plus the maximum distance
            int count_of_ones = 0;
            for (int i = 0; s[i] != '\0'; i++) {
                if (s[i] == '1') {
                    count_of_ones++;
                }
            }
            printf("%d\n", count_of_ones + maximum);
        }
    }
    
    return 0;
}

// <END-OF-CODE>
