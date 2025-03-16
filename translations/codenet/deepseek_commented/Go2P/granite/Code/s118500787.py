

def main():
    # Read the two strings S and T from standard input
    S, T = input(), input()
    
    # Initialize the maximum number of matching characters to 0
    max_count = 0
    
    # Iterate over the possible starting positions of the substring of S that is the same length as T
    for i in range(len(S) - len(T) + 1):
        # Initialize a counter for the number of matching characters in the current substring
        count = 0
        
        # Check each character in the current substring against the corresponding character in T
        for j in range(len(T)):
            if S[i + j] == T[j]:
                # Increment the counter if the characters match
                count += 1
        
        # Update max_count if the current count of matching characters is greater than the previous max_count
        if count > max_count:
            max_count = count
    
    # Print the number of characters that need to be changed to make S contain T as a substring
    print(len(T) - max_count)

if __name__ == "__main__":
    main()

This code snippet now includes detailed comments explaining each step and logical block, making it easier to understand the purpose and functionality of the code.