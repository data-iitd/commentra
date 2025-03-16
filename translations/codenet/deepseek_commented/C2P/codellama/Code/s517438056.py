#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(void) {
    # Step 1: Reading Input
    N, D = map(int, input().split())
    matrix = [[0] * D for _ in range(N)]
    
    # Step 2: Inputting Points
    for i in range(N):
        for j in range(D):
            matrix[i][j] = int(input())
    
    # Step 3: Calculating Distances
    k = 0
    for i in range(N - 1):
        for j in range(i + 1, N):
            m = 0
            for n in range(D):
                m = (matrix[i][n] - matrix[j][n]) ** 2 + m
            l = sqrt(m)
            if l.is_integer():
                k += 1
    
    # Step 4: Outputting the Result
    print(k)
    
    # Free allocated memory
    del matrix
    return 0
}

