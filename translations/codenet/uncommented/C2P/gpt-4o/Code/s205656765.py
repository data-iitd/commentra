# Read integers A, B, C, and X from input
A = int(input())
B = int(input())
C = int(input())
X = int(input())

X = X // 50  # Integer division by 50

kosu = 0  # Initialize the count

# Iterate through all combinations of i, j, and k
for i in range(A + 1):
    for j in range(B + 1):
        for k in range(C + 1):
            if X == (10 * i) + (2 * j) + k:
                kosu += 1  # Increment the count if the condition is met

# Print the result
print(kosu)

# <END-OF-CODE>
