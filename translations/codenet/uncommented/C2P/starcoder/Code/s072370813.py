
#include <stdio.h>

def main():
    N = int(raw_input())
    A = [int(raw_input()) for i in range(N)]
    sum = 0
    wa = 0
    for i in range(N):
        sum += A[i]
        wa += i+1
    if sum % wa:
        print "NO"
    else:
        shou = sum/wa
        sa = [0 for i in range(N)]
        for i in range(N):
            sa[i] = A[(i+1)%N] - A[i] - shou
        for i in range(N-1):
            if sa[i] <= 0 and not sa[i] % N:
                print "YES"
                return
        print "NO"

main()

