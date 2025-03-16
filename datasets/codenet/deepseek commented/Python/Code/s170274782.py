
N = int(input())  # Read the number of stations N
A = []
for _ in range(2):
    s = list(map(int, input().split()))  # Read two lists of integers of length N
    A.append(s)

# Initialize an empty list to store the sums of elements up to each station
ans = []

# Initialize a counter to keep track of the sum of elements up to each station
count = 0

# Loop through each station index i from 0 to N-1
for i in range(N):
    baselis = A[0]  # Get the first list representing the base line
    groundlis = A[1]  # Get the second list representing the ground line
    count = 0  # Reset the counter for each station
    count = count + sum(baselis[0:i+1]) + sum(groundlis[i:N+1])  # Calculate the sum of elements up to station i
    ans.append(count)  # Append the sum to the ans list

print(max(ans))  # Print the maximum value in the ans list

