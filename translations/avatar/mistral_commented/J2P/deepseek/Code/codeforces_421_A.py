# Import necessary classes
import sys

# Read the number of test cases
n = int(sys.stdin.readline().strip())

# Read the number of elements in the first list and the second list
a, b = map(int, sys.stdin.readline().strip().split())

# Read and store the elements of the first and second lists
list1 = list(map(int, sys.stdin.readline().strip().split()))
list2 = list(map(int, sys.stdin.readline().strip().split()))

# Iterate through the input array and print the corresponding number based on the presence of the element in list1
for i in range(1, n + 1):
    if i in list1:  # Check if the current input element is present in list1
        print(1, end=" ")  # If present, print 1
    else:
        print(2, end=" ")  # If not present, print 2

# End-of-code comment
