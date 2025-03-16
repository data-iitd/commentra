def main():
    # Read input values: N (length of string), K (window size), R, S, P (points for each move)
    N, K, R, S, P = map(int, input().split())
    T = input().strip()

    # Initialize a dictionary to count occurrences of each move
    dict_moves = {"r": 0, "s": 0, "p": 0}
    
    # Create lists to track the state of each move within the last K moves
    s = [True] * N  # For 's'
    r = [True] * N  # For 'r'
    p = [True] * N  # For 'p'
    
    # Iterate through each character in the input string T
    for i in range(len(T)):
        char = T[i]  # Get the current character

        # Check if we are within the bounds of K
        if i >= K:
            # If the current character is the same as the character K positions back
            if char == T[i - K]:
                # Toggle the availability of the move based on the current character
                if char == "s":
                    if s[i % K]:
                        s[i % K] = False  # Mark 's' as used
                        continue
                    else:
                        s[i % K] = True  # Mark 's' as available again

                elif char == "r":
                    if r[i % K]:
                        r[i % K] = False  # Mark 'r' as used
                        continue
                    else:
                        r[i % K] = True  # Mark 'r' as available again

                elif char == "p":
                    if p[i % K]:
                        p[i % K] = False  # Mark 'p' as used
                        continue
                    else:
                        p[i % K] = True  # Mark 'p' as available again
            else:
                # If the current character is different from the character K positions back
                if char == "s":
                    s[i % K] = True  # Mark 's' as available
                elif char == "r":
                    r[i % K] = True  # Mark 'r' as available
                elif char == "p":
                    p[i % K] = True  # Mark 'p' as available

        # Count the occurrences of each move
        dict_moves[char] += 1  # Increment count for the current move

    # Calculate the total score based on the counts and respective points
    res = P * dict_moves["r"] + S * dict_moves["p"] + R * dict_moves["s"]
    
    # Print the final result
    print(res)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
