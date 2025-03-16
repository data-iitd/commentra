n = int(input())  # Read the integer n from standard input
a, b, c = input().split()  # Read the three strings a, b, and c from standard input

ans = 0  # Initialize ans to 0

# Loop through each character position up to n
for i in range(n):
    # Check if all three characters at position i are the same
    if a[i] == b[i] == c[i]:
        pass  # Do nothing
    # Check if any two characters at position i are the same
    elif a[i] == b[i] or b[i] == c[i] or a[i] == c[i]:
        ans += 1  # Increment ans by 1
    # If all three characters at position i are different
    else:
        ans += 2  # Increment ans by 2

print(ans)  # Print the final value of ans

# <END-OF-CODE>
