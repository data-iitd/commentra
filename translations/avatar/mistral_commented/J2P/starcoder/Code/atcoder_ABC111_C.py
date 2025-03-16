
import sys

# Reading the number of elements 'n' from the standard input stream
n = int(sys.stdin.readline())

v = [] # Declaring an integer array 'v' to store the input elements

# Reading the elements of the array 'v' from the standard input stream
for i in range(n):
    v.append(int(sys.stdin.readline()))

vo = [0] * 100010 # Declaring an integer array 'vo' of size 100010 to store the count of occurrences of each unique value in the odd indexed elements of the array 'v'
ve = [0] * 100010 # Declaring an integer array've' of size 100010 to store the count of occurrences of each unique value in the even indexed elements of the array 'v'
vt = [0] * 100010 # Declaring an integer array 'vt' of size 100010 to store the total count of occurrences of each unique value in the array 'v'

# Initializing all the elements of the arrays 'vo','ve', and 'vt' to zero
for i in range(100010):
    vo[i] = 0
    ve[i] = 0
    vt[i] = 0

# Counting the occurrences of each unique value in the odd indexed elements of the array 'v' and updating the 'vo' array accordingly
for i in range(0, n, 2):
    currentElement = v[i]
    vo[currentElement] += 1

# Counting the occurrences of each unique value in the even indexed elements of the array 'v' and updating the've' array accordingly
for i in range(1, n, 2):
    currentElement = v[i]
    ve[currentElement] += 1

# Sorting the arrays 'vo','ve', and 'vt' in descending order
vo.sort(reverse=True)
ve.sort(reverse=True)
vt.sort(reverse=True)

ans = 0 # Declaring an integer variable 'ans' to store the answer

# Checking if the sum of the first elements of the arrays 'vo' and've' is equal to the first element of the array 'vt'
if vo[0] + ve[0] == vt[0]:
    # Calculating the answer as the minimum of the difference between the total number of elements and the sum of the counts of the first elements of the arrays 'vo' and've'
    ans = min(n - vo[0] - ve[1], n - vo[1] - ve[0])
else:
    # Calculating the answer as the difference between the count of the first element of the array 'vo' and the count of the first element of the array've'
    ans = n - vo[0] - ve[0]

# Printing the answer to the standard output stream
print(ans)

