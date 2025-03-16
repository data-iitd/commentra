
N, K, R, S, P = map(int, input().split())
T = input()

# Initialize the dictionary to keep track of the counts of 'r','s', and 'p'
dict = {"r": 0, "s": 0, "p": 0}
# Initialize a string to store the current character
char = ""
# Initialize a boolean slice to keep track of the availability of each choice for each player
s = [True] * N
# Create copies of the slice for 'r', 'p'
r = s[:]
p = s[:]

# Iterate over each character in the string T
for i in range(len(T)):
    char = T[i:i+1]
    # Check if the current index is greater than or equal to K
    if i >= K:
        # Check if the last K characters are the same as the current character
        if char == T[i-K:i+1-K]:
            # Update the availability of the choice based on the current character
            if char == "s":
                s[i%K] = False
            elif char == "r":
                r[i%K] = False
            elif char == "p":
                p[i%K] = False
    else:
        # Set the availability of the choice based on the current character
        if char == "s":
            s[i%K] = True
        elif char == "r":
            r[i%K] = True
        elif char == "p":
            p[i%K] = True

    # Update the counts in the dictionary based on the current character
    if char == "s":
        dict["s"] += 1
    elif char == "r":
        dict["r"] += 1
    elif char == "p":
        dict["p"] += 1

# Calculate the result by multiplying the counts of 'r','s', and 'p' with their respective values (P, S, R)
res = P*dict["r"] + S*dict["p"] + R*dict["s"]
# Print the result
print(res)

