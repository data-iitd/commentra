import sys
import bisect

# Function to read an array of 4 integers from the standard input
def get_int4():
    return list(map(int, sys.stdin.readline().strip().split()))

# Function to read an array of 64-bit integers from the standard input
def fget_array(size):
    return list(map(int, sys.stdin.readline().strip().split()))

NUM_MAX = 1000
NUM2_MAX = NUM_MAX * NUM_MAX
RANK_MAX = 3000

# Function to find the index of the first element greater than or equal to the given key in the sorted array arr, within the given range
def lower_bound(arr, r, key):
    low = r[0]
    high = r[1]
    while low + 1 < high:
        mid = (low + high) // 2
        if arr[mid] < key:
            low = mid
        else:
            high = mid
    return low + 1

def main():
    x, y, z, rank = get_int4()  # Read 4 integers x, y, z, and rank
    xrr = fget_array(x)  # Read the first array of 64-bit integers
    yrr = fget_array(y)  # Read the second array of 64-bit integers
    zrr = fget_array(z)  # Read the third array of 64-bit integers

    min_sum = float('inf')  # Initialize min_sum with a value larger than any possible sum
    max_sum = 0  # Initialize max_sum with an initial value of 0

    # Iterate through the third array zrr and update min_sum and max_sum accordingly
    for value in zrr:
        min_sum = min(min_sum, value)
        max_sum += value

    pair = []  # Declare a list to store the sum of each pair of elements from the first and second arrays
    # Iterate through the first array xrr and the second array yrr, and compute the sum of each pair
    for i in range(x):
        for j in range(y):
            pair.append(xrr[i] + yrr[j])

    pair.sort()  # Sort the array pair in ascending order
    min_sum += pair[0]
    max_sum += pair[-1]

    cache = [0] * NUM_MAX  # Array to store the index of the last element less than or equal to the current pivot
    cnt_map = [0] * NUM_MAX  # Array to store the number of elements in the sorted array pair less than or equal to the current pivot
    ans = [0] * RANK_MAX  # Array to store the answer for each rank
    size = len(pair)  # Compute the size of the array pair
    prev = min_sum  # Initialize prev with the initial value of min_sum

    # Iterate through the ranks from rank down to 1
    for r in range(rank, 0, -1):
        low = prev - 1  # Initialize the lower bound of the binary search
        high = max_sum + 1  # Initialize the upper bound of the binary search

        # Binary search to find the index of the first element greater than or equal to the current rank
        while low + 1 < high:
            mid = (low + high) // 2
            for i in range(z):
                pivot = zrr[i]
                r_range = (cache[i] - 1, size)  # Define the range for the current pivot
                tmp = lower_bound(pair, r_range, mid - pivot)  # Find the index of the first element greater than or equal to mid-pivot
                cnt_map[i] = tmp  # Store the number of elements in the sorted array pair less than or equal to the current pivot

            if sum(cnt_map[:z]) >= size - r:  # Check if the total number of elements is greater than or equal to size - current rank
                low = mid  # Update low
            else:
                high = mid  # Update high

        ans[r - 1] = low  # Store the index found
        if low == max_sum:  # If the index found is equal to max_sum, break the loop
            break
        prev = low  # Update prev

    # Print the answer for each rank
    for i in range(rank):
        print(max_sum if ans[i] == 0 else ans[i])

if __name__ == "__main__":
    main()

# <END-OF-CODE>
