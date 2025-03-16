# Initialize a list of strings called divide
divide = ["dream", "dreamer", "erase", "eraser"]

# Read a string from the standard input
S = input().strip()

# Reverse the string S and also reverse each string in the divide list
S = S[::-1]
divide = [d[::-1] for d in divide]

# Initialize a boolean variable called can to True
can = True

# Iterate through each character in the string S
i = 0
while i < len(S):
    # Initialize a boolean variable called can2 to False
    can2 = False

    # Iterate through each string in the divide list
    for d in divide:
        # Check if the substring of S starting from the current index i and having the same size as d is equal to d
        if S[i:i + len(d)] == d:
            # If the substring is equal to d, set can2 to True and move the index i to the end of the matched substring
            can2 = True
            i += len(d)
            break  # Break the loop since we found a match

    # If can2 is False, it means the current substring of S cannot be divided by any string in the divide list
    if not can2:
        can = False
        break

# Output "YES" if can is True, otherwise output "NO"
if can:
    print("YES")
else:
    print("NO")
# <END-OF-CODE>
