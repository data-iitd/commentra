
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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
FILE *br = fopen("input.txt", "r");
FILE *pw = fopen("output.txt", "w");

// Main function where the execution starts
int main() {
    long gen, st, tim;
    fscanf(br, "%ld", &gen);
    fscanf(br, "%ld", &st);
    fscanf(br, "%ld", &tim);
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
            fprintf(pw, "%ld\n", beg - st + 1);
            break;
        }
    }
    fclose(br);
    fclose(pw);
    return 0;
}

