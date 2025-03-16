#######
# Code
#######

# Define input variables N and M as integers
N, M = map(int, input().split())

# Comments: Get the dimensions N and M of the matrices S and T from user input

# Initialize variables S and T as strings
S = input()
T = input()

# Convert strings S and T into lists
list_S = list(S)
list_T = list(T)

# Initialize a list Number_i containing numbers from 0 to N-1
Number_i = list(range(N))

# Initialize an empty list Number_iMN to store the results of the division i*M/N
Number_iMN = []

# Iterate through each number i in the list Number_i
for i in Number_i:
    # Append the result of the division i*M/N to the list Number_iMN
    Number_iMN.append(int(i * M / N))

# Initialize a list Number_j containing numbers from 0 to M-1
Number_j = list(range(M))

# Find the common elements between Number_iMN and Number_j using set intersection
Kaburi_j = list(set(Number_iMN) & set(Number_j))

# Initialize an empty list Kaburi_i to store the integer representations of the common elements
Kaburi_i = []

# Iterate through each common element j in Kaburi_j
for j in Kaburi_j:
    # Append the integer representation of j to the list Kaburi_i
    Kaburi_i.append(int(j * N / M))

# Initialize a counter variable to keep track of the current index in Kaburi_i
counter = 0

# Initialize a flag variable to indicate whether there is a mismatch between S and T
Flag = 0

# Determine the size of Kaburi_i
Kaburi_Size = len(Kaburi_i)

# Iterate through each index in Kaburi_i until the end of the list
while counter <= Kaburi_Size - 1:
    # Check if the corresponding elements in S and T match
    if list_S[Kaburi_i[counter]] != list_T[Kaburi_j[counter]]:
        # Set the flag variable to 1 if there is a mismatch
        Flag = 1
        # Break out of the loop
        break
    # Increment the counter variable
    counter += 1

# Define a function gcd(a, b) to calculate the greatest common divisor of two integers
def gcd(a, b):
    # While b is not equal to 0, keep updating a and b using the modulo operator
    while b > 0:
        a, b = b, a % b
    # Return the final value of a as the greatest common divisor
    return a

# Check if there is a mismatch between S and T
if Flag == 1:
    # Print -1 if there is a mismatch
    print(-1)
else:
    # Calculate and print the product of N and M divided by their greatest common divisor
    print(int(N * M / gcd(N, M)))
