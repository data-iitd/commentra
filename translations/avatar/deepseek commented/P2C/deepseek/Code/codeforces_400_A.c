#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read a single value from input
int* value() {
    int* arr = (int*)malloc(10 * sizeof(int));
    int index = 0;
    char ch;
    while ((ch = getchar()) != ' ' && ch != '\n') {
        if (ch == 'O') {
            arr[index++] = 0;
        } else {
            arr[index++] = 1;
        }
    }
    return arr;
}

// Function to read multiple values from input
int* values() {
    int* arr = (int*)malloc(10 * sizeof(int));
    int index = 0;
    char ch;
    while ((ch = getchar()) != ' ' && ch != '\n') {
        if (ch == 'O') {
            arr[index++] = 0;
        } else {
            arr[index++] = 1;
        }
    }
    return arr;
}

// Function to read a list of integers from input
int* inlst() {
    int* arr = (int*)malloc(10 * sizeof(int));
    int index = 0;
    char ch;
    while ((ch = getchar()) != ' ' && ch != '\n') {
        if (ch == 'O') {
            arr[index++] = 0;
        } else {
            arr[index++] = 1;
        }
    }
    return arr;
}

// Function to read a list of integers from stdin
int* inlsts() {
    int* arr = (int*)malloc(10 * sizeof(int));
    int index = 0;
    char ch;
    while ((ch = getchar()) != ' ' && ch != '\n') {
        if (ch == 'O') {
            arr[index++] = 0;
        } else {
            arr[index++] = 1;
        }
    }
    return arr;
}

// Function to read a single integer from input
int inp() {
    int num;
    scanf("%d", &num);
    return num;
}

// Function to read a single integer from stdin
int inps() {
    int num;
    scanf("%d", &num);
    return num;
}

// Function to read a single string from input
char* instr() {
    char* str = (char*)malloc(100 * sizeof(char));
    scanf("%s", str);
    return str;
}

// Function to read a list of strings from input
char** stlst() {
    char** strs = (char**)malloc(10 * sizeof(char*));
    for (int i = 0; i < 10; i++) {
        strs[i] = (char*)malloc(100 * sizeof(char));
        scanf("%s", strs[i]);
    }
    return strs;
}

// Helper function to check if a grid of given dimensions can be formed
int help(int a, int b, int* l) {
    int tot[b][a];
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < a; j++) {
            tot[i][j] = l[i * a + j];
        }
    }
    for (int i = 0; i < a; i++) {
        int sum = 0;
        for (int j = 0; j < b; j++) {
            sum += tot[j][i];
        }
        if (sum == b) {
            return 1;
        }
    }
    return 0;
}

// Main solving function
void solve() {
    char* x = instr();
    int s[12];
    for (int i = 0; i < 12; i++) {
        if (x[i] == 'O') {
            s[i] = 0;
        } else {
            s[i] = 1;
        }
    }
    int tot[2][2];
    int count = 0;
    for (int i = 1; i <= 12; i++) {
        if (12 % i == 0) {
            if (help(i, 12 / i, s)) {
                tot[count][0] = 12 / i;
                tot[count][1] = i;
                count++;
            }
        }
    }
    printf("%d ", count);
    for (int i = 0; i < count; i++) {
        printf("%dx%d ", tot[i][0], tot[i][1]);
    }
    printf("\n");
}

// Main execution block
int main() {
    int t = inp();
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}
