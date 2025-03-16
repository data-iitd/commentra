#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the occurrences of each string
typedef struct {
    char *str;
    int count;
} String;

// Function to read the input from standard input
void readInput(String *s, int n) {
    int i;
    char *str = (char *)malloc(sizeof(char) * 100);
    for (i = 0; i < n; i++) {
        scanf("%s", str);
        s[i].str = str;
        s[i].count = 1;
    }
}

// Function to find the longest string
void findLongest(String *s, int n) {
    int i, j, max = 0, index = -1;
    for (i = 0; i < n; i++) {
        if (s[i].count > max) {
            max = s[i].count;
            index = i;
        }
    }
    printf("%s\n", s[index].str);
}

int main() {
    int n;
    scanf("%d", &n);
    String *s = (String *)malloc(sizeof(String) * n);
    readInput(s, n);
    findLongest(s, n);
    return 0;
}

