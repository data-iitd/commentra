
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Global variable to store the answer
    long ans = 0;

    // Helper function to calculate the sum of numbers based on a specific pattern
    long get(long a) {
        long ret = 0;
        long now = 1;
        long t = 1;
        for (; ; ) {
            if (now * 10 > a) {
                ret += (a - now + 1) * t;
                break;
            }
            ret += now * 9 * t;
            now *= 10;
            t++;
        }
        return ret;
    }

    // Binary search function to find the desired value
    long binarySearch(long k, long l, long r, long x) {
        if (r >= l) {
            long mid = l + (r - l) / 2;
            if (mid > ans && mid * k <= x) ans = mid;

            if (k * mid == x) return mid;

            if (k * mid > x) return binarySearch(k, l, mid - 1, x);

            return binarySearch(k, mid + 1, r, x);
        }

        return -1;
    }

    // Setup for input and output using BufferedReader and PrintWriter
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    line = (char *) malloc(1024 * sizeof(char));
    while ((read = getline(&line, &len, stdin))!= -1) {
        if (read == 0) break;
        char *token = NULL;
        char *saveptr = NULL;
        token = strtok_r(line, " ", &saveptr);
        long gen = atol(token);
        token = strtok_r(NULL, " ", &saveptr);
        long st = atol(token);
        token = strtok_r(NULL, " ", &saveptr);
        long tim = atol(token);
        gen /= tim;
        long beg = st - 1, end = (long) pow(10, 18);
        while (true) {
            long med = (beg + end) / 2 + 1;
            if (get(med) - get(st - 1) > gen) {
                end = med - 1;
            } else {
                beg = med;
            }
            if (beg == end) {
                printf("%ld\n", beg - st + 1);
                break;
            }
        }
    }
    free(line);
    return 0;
}

