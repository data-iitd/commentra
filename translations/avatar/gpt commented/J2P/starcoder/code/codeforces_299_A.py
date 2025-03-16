
# Create a Scanner object to read input from the user
in = Scanner(System.in)

# Read the number of elements in the array
n = in.nextInt()

# Initialize an array of size n to store the input values
a = [0] * n

# Loop to read n integers from the user and store them in the array
for i in range(n):
    a[i] = in.nextInt()

# Sort the array in ascending order
a.sort()

# Store the minimum value from the sorted array
min = a[0]

# Check if all elements in the array are divisible by the minimum value
for value in a:
    if value % min!= 0:
        # If any element is not divisible, print -1 and exit
        print(-1)
        return

# If all elements are divisible, print the minimum value
print(min)

# 