import sys

# Macro definitions for maximum and minimum
def max(a, b):
    return a if a > b else b

def min(a, b):
    return a if a < b else b

# Function to read four integers from standard input
def get_int4(a1, a2, a3, a4):
    a1.append(int(input().split()[0]))
    a2.append(int(input().split()[1]))
    a3.append(int(input().split()[2]))
    a4.append(int(input().split()[3]))
    return 0

# Function to read an array of int64_t from standard input
def fget_array(arr, size):
    for i in range(size):
        arr.append(int(input()))
    return 0

# Constants defining maximum sizes for arrays and ranks
NUM_MAX = 1000
NUM2_MAX = NUM_MAX * NUM_MAX
RANK_MAX = 3000

# Comparison function for ascending order used in qsort
def asc(a1, a2):
    aa1 = a1[0]
    aa2 = a2[0]
    return 1 if aa1 > aa2 else 0 if aa1 == aa2 else -1

# Comparison function for descending order used in qsort
def desc(a1, a2):
    aa1 = a1[0]
    aa2 = a2[0]
    return -1 if aa1 > aa2 else 0 if aa1 == aa2 else 1

# Constants defining maximum values for calculations
VAL_MAX = 10**10
SUM_MAX = VAL_MAX * 3

# Structure to represent a range with start and end indices
class Range:
    def __init__(self, start, end):
        self.start = start
        self.end = end

# Function to find the lower bound index of a key in a sorted array
def lower_bound(arr, r, key):
    low = r.start
    high = r.end
    while low + 1 < high:
        mid = (low + high) // 2
        if arr[mid] < key:
            low = mid
        else:
            high = mid
    return low + 1

# Main function
def main():
    # Variables to hold input values and rank
    x, y, z, rank = [], [], [], []
    get_int4(x, y, z, rank)  # Read the dimensions and rank

    # Arrays to hold input values
    xrr = []
    yrr = []
    zrr = []

    # Read the arrays from input
    fget_array(xrr, x[0])
    fget_array(yrr, y[0])
    fget_array(zrr, z[0])

    # Initialize min and max sums
    min_sum = VAL_MAX + 1
    max_sum = 0

    # Calculate minimum and maximum values from zrr
    for i in range(z[0]):
        min_sum = min(min_sum, zrr[i])
        max_sum = max(max_sum, zrr[i])

    # Create an array to hold the sums of pairs from xrr and yrr
    pair = []
    idx = 0

    # Calculate all possible sums of pairs from xrr and yrr
    for i in range(x[0]):
        for j in range(y[0]):
            pair.append(xrr[i] + yrr[j])

    # Sort the pair array in ascending order
    pair.sort()

    # Update min and max sums with the smallest and largest pair sums
    min_sum += pair[0]
    max_sum += pair[-1]

    # Arrays for caching and counting
    cache = [0] * NUM_MAX
    cnt_map = [0] * NUM_MAX
    ans = [0] * RANK_MAX

    # Calculate the size of the combined array
    size = x[0] * y[0] * z[0]
    prev = min_sum

    # Iterate to find the rank-th largest sum
    for r in range(rank[0], 0, -1):
        low = prev - 1
        high = max_sum + 1

        # Binary search to find the appropriate sum
        while low + 1 < high:
            mid = (low + high) // 2
            cnt = 0

            # Count how many sums are less than or equal to mid
            for i in range(z[0]):
                pivot = zrr[i]
                r = Range(cache[i] - 1, len(pair))
                tmp = lower_bound(pair, r, mid - pivot)
                cnt_map[i] = tmp
                cnt += tmp

            # Adjust the search range based on the count
            if cnt <= size - r:
                cache = cnt_map[:]
                low = mid
            else:
                high = mid

        # Store the found sum in the answer array
        ans[r - 1] = low
        if low == max_sum:
            break  # Stop if we reach the maximum sum
        prev = low  # Update previous sum for the next iteration

    # Print the results for each rank
    for i in range(rank[0]):
        print(ans[i] if ans[i] != 0 else max_sum)

if __name__ == "__main__":
    main()
