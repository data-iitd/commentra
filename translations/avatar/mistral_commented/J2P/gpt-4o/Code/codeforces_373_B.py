import sys
import math

# Initialize answer variable to 0
ans = 0

# Function to calculate the sum of digits from position 'a' to the end
def get(a):
    ret = 0  # Initialize result to 0
    now = 1  # Initialize current position to 1
    t = 1    # Initialize multiplier to 1
    while True:
        # Calculate the sum of digits from current position to the end
        if now * 10 > a:
            ret += (a - now + 1) * t  # Add the sum of digits from current position to the end
            break
        ret += now * 9 * t  # Add the sum of digits from current position to the next position
        now *= 10  # Move to the next position
        t += 1  # Increment the multiplier
    return ret  # Return the sum of digits

# Binary search function to find the position of the number that satisfies the condition
def binary_search(k, l, r, x):
    global ans
    # Base case: if the search range is empty, return -1
    if r >= l:
        mid = l + (r - l) // 2  # Calculate the middle index
        # Check if the middle index is the answer and if it satisfies the condition
        if mid > ans and mid * k <= x:
            ans = mid  # Update the answer if it satisfies the condition

        # Check if the middle index is the answer
        if k * mid == x:
            return mid  # Return the answer if it is the answer

        # Recursively search in the left subtree if the condition is not satisfied
        if k * mid > x:
            return binary_search(k, l, mid - 1, x)

        # Recursively search in the right subtree if the condition is not satisfied
        return binary_search(k, mid + 1, r, x)

    # Base case: if the search range is empty, return -1
    return -1

# Main function to read input and calculate the answer
def main():
    global ans
    input = sys.stdin.read
    data = input().split()
    gen = int(data[0])  # Read the number of generations
    st = int(data[1])   # Read the starting time
    tim = int(data[2])  # Read the time difference between generations
    gen //= tim  # Calculate the number of generations per second
    beg = st - 1
    end = 10**18  # Initialize the search range

    # Binary search to find the position of the number that satisfies the condition
    while True:
        med = (beg + end) // 2 + 1  # Calculate the middle index
        if get(med) - get(st - 1) > gen:  # Check if the middle index generates more digits than the given limit
            end = med - 1  # Narrow the search range to the left if it generates more digits
        else:
            beg = med  # Narrow the search range to the right if it generates less digits
        if beg == end:  # Check if the search range is empty
            print(beg - st + 1)  # Print the answer if the search range is empty
            break

if __name__ == "__main__":
    main()

# <END-OF-CODE>
