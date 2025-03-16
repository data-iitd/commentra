# Including necessary header files
import sys
import math

# Macros for iteration
ll = long long
For = lambda i,x,y: [i for i in range(x,y+1)]
FOr = lambda i,x,y: [i for i in range(x,y-1,-1)]

# Function prototypes and necessary definitions
def read():
	return int(sys.stdin.readline())

def write(x):
	sys.stdout.write(str(x)+'\n')

def writeln(x):
	sys.stdout.write(str(x)+'\n')

# Main function
n = read()
a = [0]*(n+1)
q = [0]*(n+1)
tot = 0

# Reading array 'a'
For(i,1,n)	a[i] = read()

# Sorting array 'a' in ascending order
a.sort()

# Finding duplicate elements and storing them in 'q'
For(i,1,n)	# Iterating through array 'a'
	if a[i]==a[i+1]:	# Checking if current element is same as next element
		q[tot] = a[i]	# If yes, storing it in 'q'
		i += 1		# Incrementing index 'i'
		tot += 1

# Outputting the result
writeln(q[tot]*q[tot-1])

# End of main function
# 