import re

def matchWordPattern(pattern, inputString):
    # Maps to store the relationship between pattern characters and substrings
    patternMap = {}
    strMap = {}
    # Start the backtracking process
    return backtrack(pattern, inputString, 0, 0, patternMap, strMap)

# Backtracking method to find a valid mapping of pattern to input string
def backtrack(pattern, inputString, patternIndex, strIndex, patternMap, strMap):
    # Check if both pattern and input string have been fully matched
    if patternIndex == len(pattern) and strIndex == len(inputString):
        return True
    # If one of them is fully matched but the other is not, return false
    if patternIndex == len(pattern) or strIndex == len(inputString):
        return False

    # Get the current character from the pattern
    currentChar = pattern[patternIndex]
    
    # If the current character is already mapped to a substring
    if currentChar in patternMap:
        mappedStr = patternMap[currentChar]
        # Check if the input string starts with the mapped substring at the current index
        if inputString.startswith(mappedStr, strIndex):
            # Continue to backtrack with the next character in the pattern and the updated index in the input string
            return backtrack(pattern, inputString, patternIndex + 1, strIndex + len(mappedStr), patternMap, strMap)
        else:
            return False # Mapped substring does not match
    # Try to map the current pattern character to different substrings of the input string
    for end in range(strIndex + 1, len(inputString) + 1):
        substring = inputString[strIndex:end]
        # If the substring is already mapped to a different pattern character, skip it
        if substring in strMap:
            continue
        # Map the current character to the substring and vice versa
        patternMap[currentChar] = substring
        strMap[substring] = currentChar
        # Recursively backtrack with the new mappings
        if backtrack(pattern, inputString, patternIndex + 1, end, patternMap, strMap):
            return True # Found a valid mapping
        # If not successful, remove the mappings and try the next substring
        del patternMap[currentChar]
        del strMap[substring]
    return False # No valid mapping found

# Main method to execute the program
def main():
    # Read the pattern and input string from user input
    pattern = input()
    inputString = input()
    # Check if the pattern matches the input string
    result = matchWordPattern(pattern, inputString)
    # Output the result
    print(result)

if __name__ == '__main__':
    main()

