
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the global variables
int N, ss, ans, A, B, C;

// Define the helper functions
char* nextLine();
int min(int a, int b);
int max(int64_t a, int64_t b);
int com(int a, int b);
int abs(int a);
int sum(int a[]);

int main() {
    // Read the first line which contains the number of tests and the number of elements in the array
    char* X = nextLine();
    char* Y = strchr(X,'');
    *Y = '\0';
    N = atoi(X);
    A = atoi(Y + 1);
    Y = strchr(Y + 1,'');
    *Y = '\0';
    B = atoi(Y + 1);
    Y = strchr(Y + 1,'');
    *Y = '\0';
    C = atoi(Y + 1);
    ss = A + B + C;

    // Initialize the array and the dp array
    int arr[N];
    int dp[N];

    // Initialize the answer variable
    ans = 10000;

    // Read the next N lines which contain the elements of the array
    for (int i = 0; i < N; i++) {
        char* Z = nextLine();
        arr[i] = atoi(Z);
    }

    // Call the dfs function to find the minimum cost
    dfs(dp, 0, arr);

    // Print the answer
    printf("%d\n", ans);

    // Free the memory allocated for the arrays
    free(X);
    free(Y);
    free(Z);

    return 0;
}

void dfs(int dp[], int times, int arr[]) {
    // Base case: if the number of elements processed is equal to N, calculate the cost and update the answer if necessary
    if (times >= N) {
        ans = min(ans, calc(dp, arr));
        return;
    }

    // Recursive case: try all possible values for the current element
    for (int i = 0; i < 4; i++) {
        dp[times] = i;
        dfs(dp, times + 1, arr);
    }
}

int calc(int dp[], int arr[]) {
    // Initialize the cost and the variables to store the sum of elements with each value in dp
    int cost = 0;
    int AA = 0;
    int BB = 0;
    int CC = 0;

    // Initialize the memo array to store the number of elements with each value in dp
    int memo[4] = {0};

    // Iterate through the dp array and update the variables
    for (int i = 0; i < N; i++) {
        // Update the variables based on the current value in dp
        int a = dp[i];
        memo[a]++;
        if (a == 1) {
            AA += arr[i];
        } else if (a == 2) {
            BB += arr[i];
        } else if (a == 3) {
            CC += arr[i];
        }
    }

    // Calculate the cost based on the variables
    cost += abs(A - AA);
    cost += abs(B - BB);
    cost += abs(C - CC);

    // Update the cost based on the number of elements with each value in dp
    for (int i = 1; i < 4; i++) {
        int a = memo[i];
        if (a < 1) {
            cost += 10000;
        } else {
            cost += (a - 1) * 10;
        }
    }

    // Return the cost
    return cost;
}

// Helper functions
char* nextLine() {
    int bufSize = 256;
    char* buf = (char*)malloc(sizeof(char) * bufSize);
    gets(buf);
    char* ret = (char*)malloc(sizeof(char) * strlen(buf) + 1);
    strcpy(ret, buf);
    free(buf);
    return ret;
}

int min(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

int max(int64_t a, int64_t b) {
    if (a > b) {
        return a;
    }
    return b;
}

int com(int a, int b) {
    if (a > b) {
        return 0;
    }
    return 0; //abs(a - b)
}

int abs(int a) {
    if (a < 0) {
        return a * -1;
    }
    return a;
}

int sum(int a[]) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += a[i];
    }
    return sum;
}

