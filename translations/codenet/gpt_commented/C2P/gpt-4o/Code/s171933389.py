import sys
import bisect

# Constants defining maximum sizes for arrays and ranks
NUM_MAX = 1000
NUM2_MAX = NUM_MAX * NUM_MAX
RANK_MAX = 3000

# Constants defining maximum values for calculations
VAL_MAX = int(1e+10)
SUM_MAX = VAL_MAX * 3

# Function to read four integers from standard input
def get_int4():
    return map(int, sys.stdin.readline().strip().split())

# Function to read an array of int64 from standard input
def fget_array(size):
    return list(map(int, sys.stdin.readline().strip().split()))

# Main function
def main():
    # Read the dimensions and rank
    x, y, z, rank = get_int4()

    # Read the arrays from input
    xrr = fget_array(x)
    yrr = fget_array(y)
    zrr = fget_array(z)

    # Initialize min and max sums
    min_sum = VAL_MAX + 1
    max_sum = 0

    # Calculate minimum and maximum values from zrr
    min_sum = min(min_sum, *zrr)
    max_sum = max(max_sum, *zrr)

    # Create an array to hold the sums of pairs from xrr and yrr
    pair = []
    
    # Calculate all possible sums of pairs from xrr and yrr
    for xi in xrr:
        for yi in yrr:
            pair.append(xi + yi)

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
    size = x * y * z
    prev = min_sum

    # Iterate to find the rank-th largest sum
    for r in range(rank, 0, -1):
        low = prev - 1
        high = max_sum + 1

        # Binary search to find the appropriate sum
        while low + 1 < high:
            mid = (low + high) // 2
            cnt = 0

            # Count how many sums are less than or equal to mid
            for i in range(z):
                pivot = zrr[i]
                r_start = cache[i] - 1
                tmp = bisect.bisect_right(pair, mid - pivot, r_start, len(pair))
                cnt_map[i] = tmp
                cnt += tmp

            # Adjust the search range based on the count
            if cnt <= size - r:
                cache[:] = cnt_map[:]
                low = mid
            else:
                high = mid

        # Store the found sum in the answer array
        ans[r - 1] = low
        if low == max_sum:
            break  # Stop if we reach the maximum sum
        prev = low  # Update previous sum for the next iteration

    # Print the results for each rank
    for i in range(rank):
        print(ans[i] if ans[i] != 0 else max_sum)

if __name__ == "__main__":
    main()  # Execute the main function

# <END-OF-CODE>
