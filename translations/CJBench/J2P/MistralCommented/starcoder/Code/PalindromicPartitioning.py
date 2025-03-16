
import sys

def minimalPartitions(word):
    len = len(word) # length of the given word
    minCuts = [0] * len # array to store the minimum number of cuts required for each substring

    isPalindrome = [[True] * len for i in range(len)] # 2D boolean array to check if a substring is a palindrome or not

    # Initialize the first row and column of the isPalindrome matrix with true values
    for i in range(len):
        isPalindrome[i][i] = True

    # Fill the rest of the isPalindrome matrix
    for subLen in range(2, len + 1):
        for i in range(len - subLen + 1):
            j = i + subLen - 1

            # Base case for substring of length 2
            if subLen == 2:
                isPalindrome[i][j] = (word[i] == word[j])

            # Recursive case for substrings of length greater than 2
            else:
                isPalindrome[i][j] = (word[i] == word[j]) and isPalindrome[i + 1][j - 1]

    # Calculate the minimum number of cuts required for each substring
    for i in range(len):
        if isPalindrome[0][i]:
            minCuts[i] = 0 # If the substring is a palindrome, no cuts are required
        else:
            minCuts[i] = sys.maxsize # If the substring is not a palindrome, initialize the minimum number of cuts as maximum value
            for j in range(0, i):
                if isPalindrome[j + 1][i] and 1 + minCuts[j] < minCuts[i]:
                    minCuts[i] = 1 + minCuts[j] # Update the minimum number of cuts if a palindrome substring is found before the current substring

    # Return the minimum number of cuts required for the entire word
    return minCuts[len - 1]

if __name__ == "__main__":
    inputString = input() # Read a line of input from the console
    result = minimalPartitions(inputString) # Calculate the minimum number of partitions required for the input string
    print("Minimum number of partitions required: " + str(result)) # Print the result to the console

