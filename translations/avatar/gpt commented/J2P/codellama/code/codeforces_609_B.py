
# Import the Scanner class from the java.util package
from java.util import Scanner

# Create a Scanner object to read input from the console
in = Scanner(System.in)

# Read the number of elements (n) and the maximum value (m)
n = in.nextInt()
m = in.nextInt()

# Initialize an array to store the input values
arr = [None] * n

# Initialize a frequency array to count occurrences of each number from 1 to 10
gen = [0] * 11

# Read n integers from input and populate the arr and gen arrays
for i in range(n):
    arr[i] = in.nextInt()
    gen[arr[i]] += 1

# Initialize a variable to hold the final answer
ans = 0

# Calculate the number of valid pairs (i, k) where i != k
for i in range(1, m + 1):
    for k in range(1, m + 1):
        if i != k:
            # Add the product of the counts of i and k to the answer
            ans += gen[i] * gen[k]

# Since each pair (i, k) is counted twice, divide the result by 2
print(ans / 2)

# END-OF-CODE
