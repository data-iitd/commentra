def main():
    # Initialize variables
    N, K, R, S, P = map(int, input().split())
    T = input().strip()

    # Initialize dictionary to store the count of each character
    dict_count = {"r": 0, "s": 0, "p": 0}

    # Initialize boolean arrays to represent the state of each character
    s = [True] * N
    r = [True] * N
    p = [True] * N

    # Iterate through each character in the input string
    for i in range(len(T)):
        char = T[i]

        # Check if we have reached the window size
        if i >= K:
            # If the current character is the same as the character K positions back
            if char == T[i - K]:
                if char == "s":
                    s[i % K] = not s[i % K]
                elif char == "r":
                    r[i % K] = not r[i % K]
                elif char == "p":
                    p[i % K] = not p[i % K]
            else:
                # If the current character is not the same, set the state of the character to 'on'
                if char == "s":
                    s[i % K] = True
                elif char == "r":
                    r[i % K] = True
                elif char == "p":
                    p[i % K] = True

        # Update the dictionary with the count of the current character
        dict_count[char] += 1

    # Calculate and print the result
    res = P * dict_count["r"] + S * dict_count["p"] + R * dict_count["s"]
    print(res)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
