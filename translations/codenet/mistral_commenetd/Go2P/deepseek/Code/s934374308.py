def main():
    # Read input from standard input
    N, K, R, S, P = map(int, input().split())
    T = input()

    # Initialize dictionary to store the count of each character
    dict = {"r": 0, "s": 0, "p": 0}

    # Initialize boolean arrays to represent the state of each character
    s = [True] * N
    r = [True] * N
    p = [True] * N

    # Iterate through each character in the input string
    for i in range(len(T)):
        char = T[i]

        # Check if we have reached the window size
        if i >= K:
            # If the current character is a substring of the previous K characters, toggle the state of the character
            if char == T[i - K:i + 1 - K]:
                if char == "s" and s[i % K]:
                    s[i % K] = False
                elif char == "s":
                    s[i % K] = True
                elif char == "r" and r[i % K]:
                    r[i % K] = False
                elif char == "r":
                    r[i % K] = True
                elif char == "p" and p[i % K]:
                    p[i % K] = False
                elif char == "p":
                    p[i % K] = True

            # If the current character is not a substring of the previous K characters, update the state of the characters accordingly
            else:
                if char == "s":
                    s[i % K] = True
                elif char == "r":
                    r[i % K] = True
                elif char == "p":
                    p[i % K] = True

        # Update the dictionary with the count of the current character
        dict[char] += 1

    # Calculate and print the result
    res = P * dict["r"] + S * dict["p"] + R * dict["s"]
    print(res)

main()
