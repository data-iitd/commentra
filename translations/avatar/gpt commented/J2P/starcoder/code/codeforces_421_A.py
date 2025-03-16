
# Create a Scanner object to read input from the console
sc = Scanner(System.in)

# Declare variables for the number of elements and sizes of the two lists
n, a, b = 0, 0, 0

# Read the values for n, a, and b from the input
n = sc.nextInt()
a = sc.nextInt()
b = sc.nextInt()

# Initialize two lists to store the elements of the two lists
list1 = []
list2 = []

# Read 'a' integers into list1
for i in range(a):
    list1.append(sc.nextInt())

# Read 'b' integers into list2
for i in range(b):
    list2.append(sc.nextInt())

# Iterate from 0 to n-1 to check the presence of each index in list1
for i in range(n):
    # If the current index + 1 is in list1, print 1
    if i + 1 in list1:
        print(1, end=" ")
    # Otherwise, print 2
    else:
        print(2, end=" ")

# 