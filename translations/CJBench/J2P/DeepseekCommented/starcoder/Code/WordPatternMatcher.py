
import re

def matchWordPattern(pattern, inputString):
    # Maps to store the pattern-to-string and string-to-pattern mappings
    patternMap = {}
    strMap = {}
    # Start the backtracking process
    return backtrack(pattern, inputString, 0, 0, patternMap, strMap)

# Helper method to perform the backtracking for pattern matching
def backtrack(pattern, inputString, patternIndex, strIndex, patternMap, strMap):
    # If both pattern and input string are fully traversed, return true
    if patternIndex == len(pattern) and strIndex == len(inputString):
        return True
    # If either pattern or input string is fully traversed, return false
    if patternIndex == len(pattern) or strIndex == len(inputString):
        return False
    # Get the current character from the pattern
    currentChar = pattern[patternIndex]
    # Check if the current character is already mapped
    if currentChar in patternMap:
        # Get the mapped string
        mappedStr = patternMap[currentChar]
        # Check if the input string starts with the mapped string
        if inputString.startswith(mappedStr, strIndex):
            # Recursively check the next part of the pattern and input string
            return backtrack(pattern, inputString, patternIndex + 1, strIndex + len(mappedStr), patternMap, strMap)
        else:
            return False
    # Try to map the current character to different substrings in the input string
    for end in range(strIndex + 1, len(inputString) + 1):
        substring = inputString[strIndex:end]
        if substring in strMap:
            continue
        # Map the current character to the substring
        patternMap[currentChar] = substring
        strMap[substring] = currentChar
        # Recursively check the next part of the pattern and input string
        if backtrack(pattern, inputString, patternIndex + 1, end, patternMap, strMap):
            return True
        # Backtrack: remove the current mapping
        del patternMap[currentChar]
        del strMap[substring]
    return False

# Main method to take input and print the result
if __name__ == '__main__':
    pattern = input()
    inputString = input()
    result = matchWordPattern(pattern, inputString)
    print(result)

