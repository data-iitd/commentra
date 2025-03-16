# Read the number of elements N from user input
N = int(input())

# Initialize a list to store two lists of integers
A = []
# Loop to read two lines of input, each containing a list of integers
for _ in range(2):
    s = list(map(int, input().split()))
    A.append(s)

# Initialize a list to store the results for each possible drop point
ans = []

# Iterate through each possible drop point from 0 to N-1
for i in range(N):
    # Assign the first and second lists from A to baselis and groundlis respectively
    baselis = A[0]
    groundlis = A[1]
    
    # Initialize count to zero for the current drop point
    count = 0
    
    # Calculate the total sum of elements from baselis up to the current index i
    # and the sum of elements from groundlis starting from index i to N
    count = count + sum(baselis[0:i+1]) + sum(groundlis[i:N+1])
    
    # Append the calculated count to the ans list
    ans.append(count)

# Print the maximum value from the ans list, which represents the best drop point
print(max(ans))
