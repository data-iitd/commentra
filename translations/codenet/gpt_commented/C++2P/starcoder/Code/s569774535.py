
# Read the number of elements
n = int(input())

# Initialize a vector to store the elements
a = []

# Input the elements into the vector
for i in range(n):
    a.append(int(input()))

# Initialize the answer counter and a flag for the loop
ans = 0
ok = True

# Loop until an odd number is found in the vector
while ok:
    # Check each element in the vector
    for i in range(n):
        # If the current element is odd, print the answer and exit
        if a[i] % 2 == 1:
            print(ans)
            exit()
        # If the current element is even, divide it by 2
        else:
            a[i] /= 2
    # Increment the answer counter for each complete iteration
    ans += 1

# Output the final count of divisions by 2 before encountering an odd number
print(ans)

