
# Initialize variables
N, K, R, S, P = map(int, input().split())
T = input()

# Initialize dictionary to store the count of each character
dict = {"r": 0, "s": 0, "p": 0}

# Initialize boolean arrays to represent the state of each character
char = ""
s = [True] * N
r = [True] * N
p = [True] * N

# Initialize all characters to be in the 'on' state
for i in range(N):
    s[i] = True

# Iterate through each character in the input string
for i in range(len(T)):
    # Assign the current character to a variable
    char = T[i]

    # Check if we have reached the window size
    if i >= K:
        # If the current character is a substring of the previous K characters, toggle the state of the character
        if char == T[i-K:i+1-K]:
            switch char:
                case "s":
                    # Toggle the state of the character at index i%K
                    if s[i%K]:
                        s[i%K] = False
                        continue
                    else:
                        s[i%K] = True

                case "r":
                    # Toggle the state of the character at index i%K
                    if r[i%K]:
                        r[i%K] = False
                        continue
                    else:
                        r[i%K] = True

                case "p":
                    # Toggle the state of the character at index i%K
                    if p[i%K]:
                        p[i%K] = False
                        continue
                    else:
                        p[i%K] = True

        # If the current character is not a substring of the previous K characters, update the state of the characters accordingly
        else:
            switch char:
                case "s":
                    # Set the state of the character at index i%K to 'on'
                    s[i%K] = True
                case "r":
                    # Set the state of the character at index i%K to 'on'
                    r[i%K] = True
                case "p":
                    # Set the state of the character at index i%K to 'on'
                    p[i%K] = True

    # Update the dictionary with the count of the current character
    switch char:
        case "s":
            dict["s"] = dict["s"] + 1
        case "r":
            dict["r"] = dict["r"] + 1
        case "p":
            dict["p"] = dict["p"] + 1

# Calculate and print the result
res = P*dict["r"] + S*dict["p"] + R*dict["s"]
print(res)

