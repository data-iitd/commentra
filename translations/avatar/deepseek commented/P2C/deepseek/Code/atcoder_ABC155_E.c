#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

// Function to read input from clipboard if running on iOS
char* input_clipboard() {
    // This function is not implemented in C, so we'll assume it returns a string
    // You would need to implement this function based on your platform's clipboard API
    return "example input";
}

// Main function for base case
void main_b() {
    char s[1000];
    int pp = 0;
    int na = 0;
    scanf("%s", s);
    int len = strlen(s);
    for (int i = len - 1; i >= 0; i--) {
        int cc = na + (s[i] - '0');
        na = 0;
        if (cc <= 4) {
            pp += cc;
        } else {
            na = 1;
            if (i == 0) {
                pp += 1;
            } else {
                pp += 10 - cc;
            }
        }
    }
    printf("%d\n", pp);
}

// Main function for general case
int main() {
    char s[1000];
    int pmin = 1000;
    int mmin = 0;
    scanf("%s", s);
    int len = strlen(s);
    char new_s[len + 2];
    new_s[0] = '0';
    strcpy(new_s + 1, s);
    for (int i = len; i >= 0; i--) {
        int v = new_s[i] - '0';
        int npmin = (pmin + 10 - (v + 1) < mmin + 10 - v) ? pmin + 10 - (v + 1) : mmin + 10 - v;
        int nmmin = (pmin + v + 1 < mmin + v) ? pmin + v + 1 : mmin + v;
        pmin = npmin;
        mmin = nmmin;
    }
    int result = (pmin < mmin) ? pmin : mmin;
    printf("%d\n", result);
    return 0;
}

// Main execution block
int main_ios() {
    char* input_text;
    if (strcmp(input_method, "clipboard") == 0) {
        input_text = input_clipboard();
        // For demonstration, we'll just use a hardcoded input
        strcpy(s, "123");
    } else if (strcmp(input_method, "file") == 0) {
        FILE* file = fopen("inputFile.txt", "r");
        fscanf(file, "%s", s);
        fclose(file);
    } else {
        // No input method specified, so we'll use stdin
        scanf("%s", s);
    }
    main_b();
    main();
    return 0;
}

int main() {
    main_ios();
    return 0;
}
