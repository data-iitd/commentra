
# Initialize an array of strings called divide
divide = ["dream", "dreamer", "erase", "eraser"]

# Read a string from the standard input and store it in a variable called S
S = input()

# Reverse the string S and also reverse each string in the divide array
S = S[::-1]
for i in range(4): divide[i] = divide[i][::-1]

# Initialize a boolean variable called can to true
can = True

# Iterate through each character in the string S
for i in range(len(S)):
    # Initialize a boolean variable called can2 to false
    can2 = False

    # Iterate through each string in the divide array
    for d in divide:
        # Check if the substring of S starting from the current index i and having the same size as d is equal to d
        if S[i:i+len(d)] == d:
            # If the substring is equal to d, set can2 to true and move the index i to the end of the matched substring
            can2 = True
            i += len(d)
            break

    # If can2 is false, it means the current substring of S cannot be divided by any string in the divide array, so set can to false and break the loop
    if not can2:
        can = False
        break

# Output "YES" if can is true, otherwise output "NO"
if can: print("YES")
else: print("NO")
