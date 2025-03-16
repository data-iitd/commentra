#include<stdio.h>

def bubbleSort(A):
    count = 0
    for i in range(len(A)):
        for j in range(len(A) - 1):
            if A[j] > A[j + 1]:
                A[j], A[j + 1] = A[j + 1], A[j]
                count += 1
    return count

def main():
    N = int(input())
    A = [int(x) for x in input().split()]
    count = bubbleSort(A)
    for i in range(len(A)):
        print(A[i], end = " ")
    print()
    print(count)

if __name__ == "__main__":
    main()

