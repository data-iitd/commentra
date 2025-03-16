
#include <stdio.h>
#include <string.h>

int main() {
    // Set up input and output streams
    FILE *inputStream = stdin;
    FILE *outputStream = stdout;

    // Create an instance of TaskC to solve the problem
    // Call the solve method with test number 1
    // Close the output stream
    // Output the result
    return 0;
}

static void solve(int testNumber, FILE *in, FILE *out) {
    // Read the number of strings
    int n;
    fscanf(in, "%d", &n);

    // Initialize an array to count occurrences of specific starting letters
    int cnt[5] = {0};

    // Process each string input
    char str[10];
    for (int i = 0; i < n; ++i) {
        fgets(str, 10, in);
        // Increment the count based on the first character of the string
        if (str[0] == 'M') {
            cnt[0]++;
        } else if (str[0] == 'A') {
            cnt[1]++;
        } else if (str[0] == 'R') {
            cnt[2]++;
        } else if (str[0] == 'C') {
            cnt[3]++;
        } else if (str[0] == 'H') {
            cnt[4]++;
        }
    }

    // Calculate the result based on combinations of counts
    long res = (long)cnt[0] * cnt[1] * cnt[2] +
                (long)cnt[0] * cnt[1] * cnt[3] +
                (long)cnt[0] * cnt[1] * cnt[4] +
                (long)cnt[0] * cnt[2] * cnt[3] +
                (long)cnt[0] * cnt[2] * cnt[4] +
                (long)cnt[0] * cnt[3] * cnt[4] +
                (long)cnt[1] * cnt[2] * cnt[3] +
                (long)cnt[1] * cnt[2] * cnt[4] +
                (long)cnt[1] * cnt[3] * cnt[4] +
                (long)cnt[2] * cnt[3] * cnt[4];

    // Output the result
    fprintf(out, "%ld\n", res);
}
