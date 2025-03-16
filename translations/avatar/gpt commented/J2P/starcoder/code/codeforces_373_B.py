import sys

# Variable to store the maximum answer found during the binary search
ans = 0

# Function to calculate the number of integers with digits less than or equal to 'a'
def get(a):
    ret = 0 # Variable to accumulate the result
    now = 1 # Current base (1, 10, 100,...)
    t = 1   # Digit count (1 for single digits, 2 for double digits, etc.)
    
    # Infinite loop to calculate the count of numbers
    while True:
        # If the next base exceeds 'a', calculate the remaining numbers
        if now * 10 > a:
            ret += (a - now + 1) * t # Add the count of remaining numbers
            break # Exit the loop
        # Add the count of numbers for the current base
        ret += now * 9 * t # 9 options for each digit place
        now *= 10 # Move to the next base (10, 100,...)
        t += 1 # Increment the digit count
    return ret # Return the total count

# Function to perform binary search to find the maximum value of'mid' 
# such that k * mid <= x
def binarySearch(k, l, r, x):
    # Check if the search range is valid
    if r >= l:
        mid = l + (r - l) / 2 # Calculate the mid-point
        
        # Update the answer if mid is a valid candidate
        if mid > ans and mid * k <= x: ans = mid

        # If mid is the exact solution, return it
        if k * mid == x: return mid

        # If mid * k is greater than x, search in the left half
        if k * mid > x: return binarySearch(k, l, mid - 1, x)

        # Otherwise, search in the right half
        return binarySearch(k, mid + 1, r, x)

    return -1 # Return -1 if no valid mid is found

# BufferedReader for fast input and PrintWriter for fast output
br = sys.stdin
pw = sys.stdout

# Read the input values
gen, st, tim = map(int, br.readline().split())

# Calculate the effective generation count per time unit
gen /= tim

# Initialize the binary search range
beg = st - 1
end = 10 ** 18

# Perform binary search to find the maximum valid number
while True:
    med = (beg + end) / 2 + 1 # Calculate the midpoint
    
    # Check if the count of numbers from st to med exceeds gen
    if get(med) - get(st - 1) > gen:
        end = med - 1 # Adjust the end of the search range
    else:
        beg = med # Adjust the beginning of the search range

    # If the search range converges, print the result
    if beg == end:
        pw.write(str(beg - st + 1)) # Output the count of valid numbers
        break # Exit the loop

# 