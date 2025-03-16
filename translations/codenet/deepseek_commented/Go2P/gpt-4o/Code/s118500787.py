def main():
    # Read the two strings S and T from standard input
    S = input().strip()
    T = input().strip()
    
    # Initialize the maximum number of matching characters to 0
    max_matches = 0
    
    # Iterate over the possible starting positions of the substring of S that is the same length as T
    for i in range(len(S) - len(T) + 1):
        # Initialize a counter for the number of matching characters in the current substring
        count = 0
        
        # Check each character in the current substring against the corresponding character in T
        for j in range(len(T)):
            if S[i + j] == T[j]:
                # Increment the counter if the characters match
                count += 1
        
        # Update max_matches if the current count of matching characters is greater than the previous max
        if max_matches < count:
            max_matches = count
    
    # Print the number of characters that need to be changed to make S contain T as a substring
    print(len(T) - max_matches)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
