import sys

# Reading the input
N = int ( sys.stdin.readline ( ) )

# Creating an empty HashMap to store the index of each unique element
map = { }

# Creating an empty PriorityQueue to store the elements in ascending order
nums = [ ]

# Reading the elements one by one and adding them to the PriorityQueue and HashMap
for i in range ( N ) :
    tmp = int ( sys.stdin.readline ( ) )
    nums.append ( tmp )
    map [ tmp ] = i

# Sorting the elements in the PriorityQueue
nums.sort ( )

# Initializing a binary index variable
bin = 0

# Initializing a variable to store the difference in parity between elements
diff = 0

# Processing the elements in the PriorityQueue
for num in nums :
    # Getting the index of the element from the HashMap
    idx = map [ num ]

    # Checking if the binary index and the index of the current element have opposite parity
    if ( bin % 2 ) != ( idx % 2 ) :
        diff += 1

    # Incrementing the binary index
    bin += 1

    # Setting the binary index to 0 or 1 based on the current parity
    bin %= 2

# Calculating and printing the answer
ans = diff // 2
print ( ans )

