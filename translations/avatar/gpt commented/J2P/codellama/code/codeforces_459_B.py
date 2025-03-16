import sys 

# Read from stdin, the input stream
input = sys.stdin.read()

# Split the input by whitespace
input_list = input.split()

# Read the number of elements from input
N = int(input_list[0])

# Initialize an array to hold the input integers
A = []

# Read N integers from input and store them in the array A
for i in range(1, N+1):
    A.append(int(input_list[i]))

# Sort the array A to easily find the minimum and maximum values
A.sort()

# Identify the minimum and maximum values in the sorted array
min = A[0]
max = A[N-1]

# Initialize counters for occurrences of min and max values
mins = 0
maxs = 0

# Count how many times the minimum and maximum values occur in the array
for value in A:
    if value == min:
        mins += 1
    if value == max:
        maxs += 1

# If all elements are the same (min equals max)
if min == max:
    # Calculate the difference (which is 0) and the number of ways to choose 2 from mins
    print((max - min) + " " + mins * (mins - 1) / 2)
else:
    # Calculate the difference and the product of occurrences of min and max
    print((max - min) + " " + mins * maxs)

# 