#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

def main():
    # Step 1: Reading Input
    i_min = 0
    min = 1000
    X = 0
    N = 0
    scanf("%d %d", &X, &N)
    
    # If no values are excluded, print X and exit
    if N == 0:
        printf("%d\n", X)
        exit(0)
    
    # Step 2: Initializing Arrays
    plus = [0] * 256
    minus = [0] * 256
    for i in range(256):
        plus[i] = i
        minus[i] = -i
    
    # Step 3: Marking Excluded Values
    for i in range(N):
        j = 0
        scanf("%d", &j)
        plus[j] = 0
    
    # Step 4: Finding the Nearest Non-Zero Value
    i_min = 0
    min = 1000
    for i in range(255, -1, -1):
        if plus[i] == 0 and i > 0:
            continue
        k = X - plus[i]
        if k < 0:
            k *= -1
        if k <= min:
            min = k
            i_min = i
    
    # Step 5: Outputting the Result
    printf("%d\n", i_min)
    
    return 0

