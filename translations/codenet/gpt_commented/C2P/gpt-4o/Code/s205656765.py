# Declare variables for the number of coins of each type and the target value
A = int(input())  # Number of 10 yen coins
B = int(input())  # Number of 2 yen coins
C = int(input())  # Number of 1 yen coins
X = int(input())  # Target value in yen

# Convert the target value from yen to the number of 50 yen coins
X = X // 50

# Counter for the number of combinations that meet the target value
kosu = 0

# Iterate through all possible combinations of coins
for i in range(A + 1):  # Loop through the number of 10 yen coins
    for j in range(B + 1):  # Loop through the number of 2 yen coins
        for k in range(C + 1):  # Loop through the number of 1 yen coins
            # Check if the current combination of coins equals the target value
            if X == (10 * i) + (2 * j) + k:
                kosu += 1  # Increment the counter if the combination matches

# Output the total number of combinations that meet the target value
print(kosu)

# <END-OF-CODE>
