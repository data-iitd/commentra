
import sys

# Function to check if it is possible to distribute weights
def check(n, wei, book):
    tmp = wei # Temporary variable to hold the remaining weight
    n -= 1 # Decrease the number of available books by one
    for i in range(len(book)):
        # If the current weight exceeds the available weight
        if tmp < book[i]:
            # If there are still books left to use
            if n > 0:
                n -= 1 # Use one book
                tmp = wei # Reset the temporary weight to the original weight
                # Check again if the current weight exceeds the available weight
                if tmp < book[i]:
                    return False # Not possible to distribute
            else:
                return False # No books left to use
        # Deduct the current book's weight from the temporary weight
        tmp -= book[i]
    return True # Successfully distributed the weights

# Read input until m is zero
while True:
    m, n = map(int, input().split()) # Read m and n
    if m == 0:
        break
    book = [] # List to store the weights of the books
    # Read the weights of the books
    for i in range(n):
        book.append(int(input())) # Read each book's weight
    # Uncomment this block to check for multiple weight distributions
    # while True:
    #     tmp = int(input()) # Read weight to check
    #     if check(m, tmp, book):
    #         print("YES") # Possible distribution
    #     else:
    #         print("NO") # Not possible distribution
    l = 0 # Lower bound for binary search
    r = 1500000 # Upper bound for binary search
    ans = 0 # Variable to store the answer
    # Perform binary search to find the maximum weight that can be distributed
    while l < r:
        # Check if the middle weight can be distributed
        if check(m, (l + r) // 2, book):
            ans = (l + r) // 2 # Update answer
            # If the upper bound equals the middle, break the loop
            if r == (l + r) // 2:
                break
            r = (l + r) // 2 # Move the upper bound down
        else:
            # If the lower bound equals the middle, break the loop
            if l == (l + r) // 2:
                break
            l = (l + r) // 2 # Move the lower bound up
    print(ans) # Output the maximum weight that can be distributed

