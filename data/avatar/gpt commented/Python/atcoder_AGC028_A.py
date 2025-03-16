# Read the values of N and M from input
N, M = map(int, input().split())

# Read the strings S and T from input
S = input()
T = input()

# Convert strings S and T into lists for easier indexing
list_S = list(S)
list_T = list(T)

# Create a list of indices from 0 to N-1
Number_i = [i for i in range(N)]

# Initialize an empty list to store calculated indices
Number_iMN = []

# Calculate the scaled indices based on the ratio of M to N
for i in Number_i:
    Number_iMN.append(i * M / N)

# Create a list of indices from 0 to M-1
Number_j = [j for j in range(M)]

# Find the common indices between the scaled Number_iMN and Number_j
Kaburi_j = list(set(Number_iMN) & set(Number_j))

# Initialize an empty list to store the corresponding indices in the original range
Kaburi_i = []

# Calculate the corresponding indices in the original range based on Kaburi_j
for j in Kaburi_j:
    Kaburi_i.append(int(j * N / M))

# Initialize a counter for iteration and a flag for mismatch detection
counter = 0
Flag = 0

# Get the size of the Kaburi_i list
Kaburi_Size = len(Kaburi_i)

# Check if the characters at the calculated indices in S and T match
while counter <= Kaburi_Size - 1:
    if list_S[int(Kaburi_i[counter])] == list_T[int(Kaburi_j[counter])]:
        pass  # Characters match, continue checking
    else:
        Flag = 1  # Set flag if a mismatch is found
        break  # Exit the loop on mismatch
    counter += 1  # Move to the next index

# Function to calculate the greatest common divisor (GCD) of two numbers
def gcd(a, b):
    while b > 0:
        a, b = b, a % b
    return a

# Output the result based on the flag indicating if a mismatch was found
if Flag == 1:
    print(-1)  # Print -1 if there was a mismatch
else:
    # Print the least common multiple (LCM) of N and M
    print(int(N * M / gcd(N, M)))
