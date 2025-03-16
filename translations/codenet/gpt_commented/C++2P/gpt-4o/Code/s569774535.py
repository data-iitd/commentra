# Read the number of elements
n = int(input())

# Initialize a list to store the elements
a = list(map(int, input().split()))

# Initialize the answer counter
ans = 0

# Loop until an odd number is found in the list
while True:
    # Check each element in the list
    for i in range(n):
        # If the current element is odd, print the answer and exit
        if a[i] % 2 == 1:
            print(ans)
            exit()
        # If the current element is even, divide it by 2
        else:
            a[i] //= 2
    # Increment the answer counter for each complete iteration
    ans += 1

# Output the final count of divisions by 2 before encountering an odd number
print(ans)

# <END-OF-CODE>
