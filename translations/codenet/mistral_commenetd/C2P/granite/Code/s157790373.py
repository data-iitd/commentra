

# Python code to check if there is a subsequence of given length'm' in the array 'A' starting from index 'i'

def solve(i, m): # Function to check if there is a subsequence of given length'm' in the array 'A' starting from index 'i'
    # Base case: If index 'i' goes beyond the size of the array 'A', return false as no subsequence can start from this index
    if i > n:
        return False

    # Base case: If length'm' is zero, any empty subsequence of length zero can be formed from any index in the array 'A'
    elif m < 0:
        return False

    # Base case: If length'm' is equal to zero or the difference between the elements at index 'i+1' and 'i' is equal to'm', a subsequence of length'm' can be formed starting from index 'i'
    elif m == 0 or m - A[i+1] == 0:
        global flag # Global variable 'flag' to check if a subsequence of given length'm' is found
        flag = True # Setting the flag to true as a subsequence of length'm' is found
        return True # Returning true to indicate that a subsequence of length'm' is found

    # Recursive case: If length'm' cannot be formed from the element at index 'i', check if it can be formed from the elements starting from index 'i+1'
    else:
        # Not using the element at index 'i' to form the subsequence of length'm'
        solve(i+1, m)

        # Using the element at index 'i' to form the subsequence of length'm'
        solve(i+1, m-A[i])

n = int(input()) # Reading the size of the array 'A'
A = list(map(int, input().split())) # Reading the elements of the array 'A'

q = int(input()) # Reading the number of queries
for i in range(q): # Loop through all the queries
    m = int(input()) # Reading the length of subsequence to be checked in the current query
    global flag # Global variable 'flag' to check if a subsequence of given length'm' is found
    flag = False # Initializing the flag to false

    solve(0, m) # Calling the function'solve' to check if there is a subsequence of given length'm' in the array 'A'

    if flag == True: # If a subsequence of given length'm' is found, print 'yes'
        print("yes")
    else: # If no subsequence of given length'm' is found, print 'no'
        print("no")

