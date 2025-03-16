
import re

# Initializes the method to check if the given word pattern matches the input string
def matchWordPattern(pattern, inputString):
    patternMap = {} # Initialize an empty HashMap to store the mapping of characters to strings
    strMap = {} # Initialize an empty HashMap to store the mapping of strings to characters

    # Recursive method to check if the pattern matches the input string
    return backtrack(pattern, inputString, 0, 0, patternMap, strMap)

# Recursive method to check if the pattern matches the input string
def backtrack(pattern, inputString, patternIndex, strIndex, patternMap, strMap):
    # Base case: if we have checked all characters in the pattern and all characters in the input string, then the pattern matches the input string
    if patternIndex == len(pattern) and strIndex == len(inputString):
        return True

    # Base case: if we have checked all characters in the pattern or all characters in the input string, then the pattern does not match the input string
    if patternIndex == len(pattern) or strIndex == len(inputString):
        return False

    currentChar = pattern[patternIndex] # Get the current character in the pattern

    # If the current character in the pattern is already mapped to a string, check if the input string starts with that string
    if currentChar in patternMap:
        mappedStr = patternMap[currentChar]
        if inputString.startswith(mappedStr, strIndex):
            # Recursively call the backtrack method with the updated pattern index and string index
            return backtrack(pattern, inputString, patternIndex + 1, strIndex + len(mappedStr), patternMap, strMap)
        else:
            # If the input string does not start with the mapped string, then the pattern does not match the input string
            return False
    else:
        # If the current character in the pattern is not yet mapped to a string, try mapping it to different substrings in the input string
        for end in range(strIndex + 1, len(inputString) + 1):
            substring = inputString[strIndex:end] # Get the substring starting from the current string index to the end of the input string

            # If the substring is already mapped to a character, skip it and try the next substring
            if substring in strMap:
                continue

            # Map the current character in the pattern to the substring in the input string
            patternMap[currentChar] = substring
            strMap[substring] = currentChar

            # Recursively call the backtrack method with the updated pattern index and string index
            result = backtrack(pattern, inputString, patternIndex + 1, end, patternMap, strMap)

            # If the pattern matches the input string, return true
            if result:
                return True

            # If the pattern does not match the input string, unmap the current character and substring and try the next substring
            del patternMap[currentChar]
            del strMap[substring]

        # If none of the substrings in the input string match the current character in the pattern, then the pattern does not match the input string
        return False

# Main method to read the pattern and input string from the user and print the result
def main():
    pattern = input() # Read the pattern from the user
    inputString = input() # Read the input string from the user

    result = matchWordPattern(pattern, inputString) # Call the matchWordPattern method with the pattern and input string

    print(result) # Print the result to the console

if __name__ == '__main__':
    main()

