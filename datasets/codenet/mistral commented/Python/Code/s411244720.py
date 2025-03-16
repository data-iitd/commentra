# Read the input: N and K
N, K = [int(_) for _ in input().split()]

# Initialize an empty set S
S = set()

# Iterate through K datasets
for i in range(K):
    # Read the size of the current dataset
    d = int(input())
    
    # Read d integers and store them in a list A
    A = [int(_) for _ in input().split()]
    
    # Add the elements of the current dataset to the set S
    S = S | set(A)

# Print the result: N - size of the set S
print(N - len(S))
