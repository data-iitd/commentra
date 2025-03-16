n, r = 0, 0

while True:
    # Read the values of n and r
    n, r = map(int, input().split())
    # Break the loop if both n and r are zero
    if n == 0 and r == 0:
        break
    
    # Initialize list a with values from n down to 1
    a = list(range(n, 0, -1))
    
    # For each round of r
    for _ in range(r):
        # Copy list a to list b
        b = a[:]
        # Read the values of p and c
        p, c = map(int, input().split())

        # Perform the shift operation on list a
        for j in range(c):
            a[j] = b[p - 1 + j]
        
        # Fill the remaining positions in list a
        for j in range(c, c + p - 1):
            a[j] = b[j - c]
    
    # Print the first element of list a
    print(a[0])

# <END-OF-CODE>
