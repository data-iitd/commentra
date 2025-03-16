
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

#define NUM_MAX 1000
#define NUM2_MAX (NUM_MAX*NUM_MAX)
#define RANK_MAX 3000

#define VAL_MAX (int64_t)(1e+10)
#define SUM_MAX (VAL_MAX*3)

def get_int4(a1, a2, a3, a4):
    # Read 4 integers from the standard input and store them in the given pointers
    a1, a2, a3, a4 = map(int, input().split())
    # Return 0 to indicate successful execution
    return 0

def fget_array(arr, size):
    # Iterate through the given size and read each 64-bit integer from the standard input and store it in the given array
    for i in range(size):
        arr[i] = int(input())
    # Return 0 to indicate successful execution
    return 0

def asc(a1, a2):
    # Compare two 64-bit integers and return 1 if aa1 is greater than aa2, 0 if they are equal, and -1 if aa1 is less than aa2
    if a1 > a2:
        return 1
    if a1 == a2:
        return 0
    return -1

def desc(a1, a2):
    # Compare two 64-bit integers and return -1 if aa1 is less than aa2, 0 if they are equal, and 1 if aa1 is greater than aa2
    if a1 > a2:
        return -1
    if a1 == a2:
        return 0
    return 1

def lower_bound(arr, r, key):
    low = r.start
    high = r.end
    # Binary search to find the index of the first element greater than or equal to the given key in the sorted array arr, within the given range r
    while low + 1 < high:
        mid = (low + high) // 2
        if arr[mid] < key:
            low = mid
        else:
            high = mid
    # Return the index of the first element greater than or equal to the given key, or the size of the array if no such element exists
    return low + 1

def sum(arr, size):
    # Iterate through the given array and return the sum of all its elements
    return sum(arr[:size])

def main():
    x, y, z, rank = map(int, input().split())
    xrr = [0] * NUM_MAX
    yrr = [0] * NUM_MAX
    zrr = [0] * NUM_MAX
    # Read the three arrays of 64-bit integers from the standard input using the function fget_array()
    fget_array(xrr, x)
    fget_array(yrr, y)
    fget_array(zrr, z)
    min_sum = VAL_MAX+1
    max_sum = 0
    for i in range(z):
        min_sum = min(min_sum, zrr[i])
        max_sum += zrr[i]

    pair = [0] * NUM2_MAX
    idx = 0
    for i in range(x):
        for j in range(y):
            pair[idx] = xrr[i] + yrr[j]
            idx += 1

    # Sort the array pair in ascending order using the qsort() function and the asc() comparator function
    pair.sort(key=asc)
    # Update min_sum and max_sum with the sum of the first and last elements in the sorted array pair, respectively
    min_sum += pair[0]
    max_sum += pair[idx-1]

    cache = [0] * NUM_MAX
    cnt_map = [0] * NUM_MAX
    ans = [0] * RANK_MAX
    size = x*y*z
    prev = min_sum
    for r in range(rank, 0, -1):
        low = prev-1
        high = max_sum+1
        while low + 1 < high:
            mid = (low + high) // 2
            for i in range(z):
                pivot = zrr[i]
                r = struct(cache[i]-1, idx)
                cnt_map[i] = lower_bound(pair, r, mid-pivot)
            if sum(cnt_map, z) >= size-r:
                low = mid
            else:
                high = mid
        ans[r-1] = low
        if low == max_sum:
            break
        prev = low

    for i in range(rank):
        print(ans[i])

if __name__ == "__main__":
    main()

