
# Initializing scanner for reading input from stdin
sc = input().split()

# Function to read next integer from input
def nextInt():
    # Reading next token as a string
    sc = input().split()
    # Converting the string to integer
    i = int(sc[0])
    return i

# Function to split input into words
def sc.split(split):
    # Reading the whole line
    data = input().split()
    # Splitting the line into words
    split(data)

# Function to sort the array in ascending order
def sort(ar):
    # Sorting the array in ascending order
    ar.sort()

# Function to calculate the sum of elements at index 3n-2i-1 in the sorted array
def sum(ar):
    # Calculating the sum of elements at index 3n-2i-1 in the sorted array
    sum = 0
    for i in range(n):
        # Adding the element at index 3n-2i-1 to the sum
        sum += ar[3*n-(i+1)*2]
    return sum

# Main function
n = nextInt()

# Allocating memory for the array
ar = [0] * (3*n)

# Reading elements of the array
for i in range(len(ar)):
    # Reading next integer and storing it in the array
    ar[i] = nextInt()

# Sorting the array in ascending order
sort(ar)

# Calculating the sum of elements at index 3n-2i-1 in the sorted array
sum = sum(ar)

# Printing the result
print(sum)

