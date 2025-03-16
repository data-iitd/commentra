import sys

# Function to calculate the minimal number of partitions for a given string
def minimalPartitions(word):
    len = len(word) # Get the length of the input string
    minCuts = [0] * len # Array to store the minimum cuts for each substring
    isPalindrome = [[False] * len for i in range(len)] # 2D array to check if substrings are palindromes

    # Initialize the isPalindrome array for single character substrings
    for i in range(len):
        isPalindrome[i][i] = True # A single character is always a palindrome

    # Fill the isPalindrome table for substrings of length 2 and greater
    for subLen in range(2, len + 1):
        for i in range(len - subLen + 1):
            j = i + subLen - 1 # Ending index of the substring
            # Check if the substring from i to j is a palindrome
            if subLen == 2:
                isPalindrome[i][j] = (word[i] == word[j]) # Two characters case
            else:
                isPalindrome[i][j] = (word[i] == word[j]) and isPalindrome[i + 1][j - 1] # General case

    # Calculate the minimum cuts required for each substring
    for i in range(len):
        if isPalindrome[0][i]:
            minCuts[i] = 0 # No cuts needed if the whole substring is a palindrome
        else:
            minCuts[i] = sys.maxint # Initialize to maximum value
            # Check for possible cuts
            for j in range(0, i):
                # If the substring from j+1 to i is a palindrome
                if isPalindrome[j + 1][i] and 1 + minCuts[j] < minCuts[i]:
                    minCuts[i] = 1 + minCuts[j] # Update the minimum cuts
    return minCuts[len - 1] # Return the minimum cuts for the entire string

# Main method to execute the program
def main():
    inputString = sys.stdin.readline().strip() # Read the input string
    result = minimalPartitions(inputString) # Calculate the minimum partitions
    print "Minimum number of partitions required: " + str(result) # Output the result

if __name__ == "__main__":
    main()

