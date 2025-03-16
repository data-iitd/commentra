def main():
    N, K, R, S, P = map(int, input().split())
    T = input().strip()

    # Initialize the dictionary to keep track of the counts of 'r', 's', and 'p'
    dict_counts = {"r": 0, "s": 0, "p": 0}
    # Initialize a boolean list to keep track of the availability of each choice for each player
    s = [True] * N
    # Create copies of the list for 'r', 'p'
    r = s[:]
    p = s[:]

    # Iterate over each character in the string T
    for i in range(len(T)):
        char = T[i]
        # Check if the current index is greater than or equal to K
        if i >= K:
            # Check if the last K characters are the same as the current character
            if char == T[i-K:i+1-K]:
                # Update the availability of the choice based on the current character
                if char == "s":
                    if s[i % K]:
                        s[i % K] = False
                        continue
                    else:
                        s[i % K] = True
                elif char == "r":
                    if r[i % K]:
                        r[i % K] = False
                        continue
                    else:
                        r[i % K] = True
                elif char == "p":
                    if p[i % K]:
                        p[i % K] = False
                        continue
                    else:
                        p[i % K] = True
            else:
                # Set the availability of the choice based on the current character
                if char == "s":
                    s[i % K] = True
                elif char == "r":
                    r[i % K] = True
                elif char == "p":
                    p[i % K] = True

        # Update the counts in the dictionary based on the current character
        dict_counts[char] += 1

    # Calculate the result by multiplying the counts of 'r', 's', and 'p' with their respective values (P, S, R)
    res = P * dict_counts["r"] + S * dict_counts["p"] + R * dict_counts["s"]
    # Print the result
    print(res)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
