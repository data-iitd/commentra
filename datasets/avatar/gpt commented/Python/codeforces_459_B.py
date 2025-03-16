# Read an integer input for the number of elements
n = int(input())

# Read a line of input, split it into individual strings, convert them to integers, and store them in a list
l1 = list(map(int, input().split()))

# Sort the list of integers in ascending order
l1.sort()

# Assign the maximum value in the list to variable 'a'
a = l1[-1]

# Assign the minimum value in the list to variable 'b'
b = l1[0]

# Check if the maximum and minimum values are the same
if a == b:
    # If they are the same, the difference is zero and the number of pairs is n choose 2
    print(a - b, (n) * (n - 1) // 2)
else:
    # Count occurrences of the maximum value 'a' in the list
    ac = l1.count(a)
    
    # Count occurrences of the minimum value 'b' in the list
    bc = l1.count(b)
    
    # Calculate the difference between the maximum and minimum values, and the product of their counts
    print(a - b, ac * bc)
