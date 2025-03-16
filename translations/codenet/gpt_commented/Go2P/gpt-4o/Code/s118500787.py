def read_string():
    return input().strip()

def main():
    # Read two strings S and T from standard input
    S = read_string()
    T = read_string()
    
    # Initialize a variable to keep track of the maximum number of matching characters
    max_matches = 0
    
    # Iterate over each possible starting index in S where T can fit
    for i in range(len(S) - len(T) + 1):
        # Initialize a counter for matching characters
        count = 0
        
        # Compare characters of T with the corresponding characters in S
        for j in range(len(T)):
            if S[i + j] == T[j]:
                count += 1  # Increment the counter for each matching character
        
        # Update the maximum count of matching characters if the current count is greater
        if max_matches < count:
            max_matches = count
    
    # Output the number of characters in T that do not match with S
    print(len(T) - max_matches)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
