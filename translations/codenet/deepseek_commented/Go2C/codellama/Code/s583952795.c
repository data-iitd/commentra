#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>
#include <stddef.h>

// Go:
// package main

// C:
int main(int argc, char *argv[]) {
    // Go:
    // buf := make([]byte, initialBufSize)
    // scanner.Buffer(buf, maxBufSize)
    // scanner.Split(bufio.ScanWords)

    // Read two integers N and K from standard input
    // Go:
    // N, K := readInt(), readInt()
    int N, K;
    scanf("%d %d", &N, &K);

    // Convert N to base K and print the length of the resulting string
    // Go:
    // s := TenToN(N, K)
    // fmt.Println(len(s))
    char s[100];
    int i = 0;
    while (N > 0) {
        s[i++] = N % K + '0';
        N /= K;
    }
    printf("%d\n", i);

    // Go:
    // 