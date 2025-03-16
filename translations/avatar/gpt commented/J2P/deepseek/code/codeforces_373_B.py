import sys

# Variable to store the maximum answer found during the binary search
ans = 0

# Function to calculate the number of integers with digits less than or equal to 'a'
def get(a):
    ret = 0
    now = 1
    t = 1
    
    # Infinite loop to calculate the count of numbers
    while True:
        # If the next base exceeds 'a', calculate the remaining numbers
        if now * 10 > a:
            ret += (a - now + 1) * t
            break
        # Add the count of numbers for the current base
        ret += now * 9 * t
        now *= 10
        t += 1
    return ret

# Function to perform binary search to find the maximum value of 'mid' 
# such that k * mid <= x
def binary_search(k, l, r, x):
    global ans
    # Check if the search range is valid
    if r >= l:
        mid = l + (r - l) // 2
        
        # Update the answer if mid is a valid candidate
        if mid > ans and mid * k <= x:
            ans = mid

        # If mid is the exact solution, return it
        if k * mid == x:
            return mid

        # If mid * k is greater than x, search in the left half
        if k * mid > x:
            return binary_search(k, l, mid - 1, x)

        # Otherwise, search in the right half
        return binary_search(k, mid + 1, r, x)

    return -1

# Read the input values
gen, st, tim = map(int, sys.stdin.readline().split())

# Calculate the effective generation count per time unit
gen //= tim

# Initialize the binary search range
beg = st - 1
end = int(10**18)

# Perform binary search to find the maximum valid number
while True:
    med = (beg + end) // 2 + 1
    
    # Check if the count of numbers from st to med exceeds gen
    if get(med) - get(st - 1) > gen:
        end = med - 1
    else:
        beg = med
    
    # If the search range converges, print the result
    if beg == end:
        print(beg - st + 1)
        break
