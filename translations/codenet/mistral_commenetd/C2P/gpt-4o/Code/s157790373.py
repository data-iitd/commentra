LEN = 300
TRUE = 1
FALSE = -1

def solve(i, m):  # Function to check if there is a subsequence of given length 'm' in the array 'A' starting from index 'i'
    global flag
    # Base case: If index 'i' goes beyond the size of the array 'A', return false as no subsequence can start from this index
    if i > n:
        return FALSE

    # Base case: If length 'm' is negative, return false
    elif m < 0:
        return FALSE

    # Base case: If length 'm' is zero, any empty subsequence of length zero can be formed from any index in the array 'A'
    elif m == 0:
        flag = TRUE  # Setting the flag to true as a subsequence of length 'm' is found
        return TRUE  # Returning true to indicate that a subsequence of length 'm' is found

    # Recursive case: If length 'm' cannot be formed from the element at index 'i', check if it can be formed from the elements starting from index 'i+1'
    else:
        # Not using the element at index 'i' to form the subsequence of length 'm'
        solve(i + 1, m)

        # Using the element at index 'i' to form the subsequence of length 'm'
        solve(i + 1, m - A[i])

# Main function
if __name__ == "__main__":
    n = int(input())  # Reading the size of the array 'A'
    A = list(map(int, input().split()))  # Reading the elements of the array 'A'

    q = int(input())  # Reading the number of queries
    for _ in range(q):  # Loop through all the queries
        M = int(input())  # Reading the length of subsequence to be checked in the current query
        flag = FALSE  # Initializing the flag to false

        solve(0, M)  # Calling the function 'solve' to check if there is a subsequence of given length 'M' in the array 'A'

        if flag == TRUE:
            print("yes")  # If a subsequence of given length 'M' is found, print 'yes'
        else:
            print("no")  # If no subsequence of given length 'M' is found, print 'no'

# <END-OF-CODE>
