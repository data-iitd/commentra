import sys
from typing import List

INF = float('inf')
MAXN = 2 * 10**5 + 10  # maximum size of the array

a = [0] * MAXN  # array 'a' of size MAXN
L = [0] * (MAXN // 2)  # auxiliary array 'L'
R = [0] * (MAXN // 2)  # auxiliary array 'R'

def merge(left: int, mid: int, right: int) -> int:
    global a, L, R
    cnt = 0  # counter to store the number of inversions
    n1 = mid - left  # size of the first subarray
    n2 = right - mid  # size of the second subarray

    # copy the elements of the first subarray to 'L' array
    for i in range(n1):
        L[i] = a[left + i]

    # copy the elements of the second subarray to 'R' array
    for i in range(n2):
        R[i] = a[mid + i]

    # set the last elements of 'L' and 'R' arrays as INF
    L[n1] = R[n2] = INF

    # merge the two sorted subarrays and update the array 'a' accordingly
    i = j = 0
    for k in range(left, right):
        if L[i] <= R[j]:
            a[k] = L[i]
            i += 1  # increment index for L
        else:
            a[k] = R[j]
            j += 1  # increment index for R
            cnt += n1 - i  # update the counter 'cnt' with the number of inversions caused by this swap

    return cnt  # return the number of inversions caused by merging the two subarrays

def mergesort(left: int, right: int) -> int:
    if left + 1 < right:  # if the size of the subarray is greater than 1
        mid = (left + right) // 2  # find the middle index
        v1 = mergesort(left, mid)  # recursively sort the left subarray and calculate the number of inversions
        v2 = mergesort(mid, right)  # recursively sort the right subarray and calculate the number of inversions
        v3 = merge(left, mid, right)  # merge the two sorted subarrays and calculate the number of inversions
        return v1 + v2 + v3  # return the total number of inversions caused by sorting the subarrays
    return 0  # if the size of the subarray is 1, the array is already sorted and there are no inversions

def main():
    global a
    input = sys.stdin.read
    data = input().split()
    n = int(data[0])  # read the size of the array
    for i in range(n):
        a[i] = int(data[i + 1])  # read the elements of the array
    ans = mergesort(0, n)  # call the mergesort function to sort the array and calculate the number of inversions
    print(ans)  # print the number of inversions

if __name__ == "__main__":
    main()

# <END-OF-CODE>
