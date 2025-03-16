#######
# Code
#######

# Initialize the number of floors N
N = int(input())

# Initialize an empty list A to store the base and ground floor lists
A = []

# Read the base and ground floor lists from the input
for _ in range(2):
    # Read a line of input and convert it to a list of integers
    s = list(map(int, input().split()))
    # Append the list to A
    A.append(s)

# Initialize an empty list ans to store the answer for each floor
ans = []

# Iterate through each floor from 0 to N-1
for i in range(N):
    # Get the base and ground floor lists for the current floor
    baselis = A[0]
    groundlis = A[1]
    
    # Initialize a variable count to store the total number of stairs climbed up to the current floor
    count = 0
    
    # Calculate the total number of stairs climbed up to the current floor
    # by summing up the number of stairs climbed from the base to the current floor
    # and the number of stairs climbed from the current floor to the ground floor
    count = count + sum(baselis[0:i+1]) + sum(groundlis[i:N+1])
    
    # Append the answer to the list ans
    ans.append(count)

# Print the maximum number of stairs climbed in the entire building
print(max(ans))
