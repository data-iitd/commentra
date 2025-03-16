
# <START-OF-CODE>

# Create a Scanner object to read input from the console
sc = Scanner(sys.stdin)

# Read the number of elements to be processed
n = sc.nextInt()

# Initialize variables to hold the sums of three different sets of integers
a = 0
b = 0
c = 0

# Read n integers and calculate their sum (a)
for i in range(n):
    a += sc.nextInt()

# Read n-1 integers and calculate their sum (b)
for i in range(n-1):
    b += sc.nextInt()

# Read n-2 integers and calculate their sum (c)
for i in range(n-2):
    c += sc.nextInt()

# Calculate the difference between the sums: x = sum of first set - sum of second set
x = a - b

# Calculate the difference between the sums: y = sum of second set - sum of third set
y = b - c

# Print the results of the differences
print(x)
print(y)

# 