
# Package declaration for the main Python program
import sys

# Read the input from the command line arguments
n = int(sys.argv[1])

# Read 'n' float values from the command line arguments and store them in a list 'a'
a = [float(x) for x in sys.argv[2:]]

# Iterate through the list 'a' 'n-1' times and sort it using the'sorted' function
for i in range(n-1):
	a = sorted(a)

# Initialize an empty list 'na'
na = []

# Iterate through the list 'a' starting from index 2 and append its elements to the list 'na'
for j in range(2, len(a)):
	na.append(a[j])

# Reassign the value of the list 'a' with the list 'na' and the first two elements being the average of the first two elements of the original list 'a'
na.append((a[0]+a[1])/2)
a = na

# Print the first element of the sorted list 'a' to the standard output
print(a[0])

