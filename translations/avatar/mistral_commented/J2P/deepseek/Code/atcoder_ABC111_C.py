import sys
from collections import Counter

# Reading the number of elements 'n' from the standard input stream
n = int(input().strip())

# Reading the elements of the array 'v' from the standard input stream
v = list(map(int, input().strip().split()))

# Counting the occurrences of each unique value in the odd indexed elements of the array 'v'
vo = Counter(v[i] for i in range(0, n, 2))

# Counting the occurrences of each unique value in the even indexed elements of the array 'v'
ve = Counter(v[i] for i in range(1, n, 2))

# Sorting the counters 'vo' and 've' in descending order
vo_sorted = sorted(vo.items(), key=lambda x: x[1], reverse=True)
ve_sorted = sorted(ve.items(), key=lambda x: x[1], reverse=True)

# Initializing the answer variable
ans = 0

# Checking if the sum of the first elements of the counters 'vo' and 've' is equal to the first element of the sorted counters
if vo_sorted[0][0] == ve_sorted[0][0]:
    # Calculating the answer as the minimum of the difference between the total number of elements and the sum of the counts of the first elements of the counters 'vo' and 've'
    ans = min(n - vo_sorted[0][1] - ve_sorted[1][1], n - vo_sorted[1][1] - ve_sorted[0][1])
else:
    # Calculating the answer as the difference between the count of the first element of the counter 'vo' and the count of the first element of the counter 've'
    ans = n - vo_sorted[0][1] - ve_sorted[0][1]

# Printing the answer to the standard output stream
print(ans)
