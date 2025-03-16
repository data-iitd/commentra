# Read two integers N and K from input, where N is the total number of elements 
# and K is the number of sets to be processed.
N, K = [int(_) for _ in input().split()]

# Initialize an empty set S to store unique elements from the input sets.
S = set()

# Loop K times to read K sets of integers.
for i in range(K):
    # Read an integer d which represents the number of elements in the current set (not used further).
    d = int(input())
    
    # Read the next line of input and convert it into a list of integers A.
    A = [int(_) for _ in input().split()]
    
    # Update the set S with the elements from the current set A, ensuring uniqueness.
    S = S | set(A)

# Calculate and print the number of elements from 1 to N that are not in the set S.
print(N - len(S))
