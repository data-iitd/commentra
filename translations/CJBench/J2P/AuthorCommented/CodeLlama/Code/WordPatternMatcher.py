import sys

def matchWordPattern(pattern, inputString):
    patternMap = {}
    strMap = {}
    return backtrack(pattern, inputString, 0, 0, patternMap, strMap)

def backtrack(pattern, inputString, patternIndex, strIndex, patternMap, strMap):
    if patternIndex == len(pattern) and strIndex == len(inputString):
        return True
    if patternIndex == len(pattern) or strIndex == len(inputString):
        return False

    currentChar = pattern[patternIndex]
    if currentChar in patternMap:
        mappedStr = patternMap[currentChar]
        if inputString[strIndex:].startswith(mappedStr):
            return backtrack(pattern, inputString, patternIndex + 1, strIndex + len(mappedStr), patternMap, strMap)
        else:
            return False

    for end in range(strIndex + 1, len(inputString) + 1):
        substring = inputString[strIndex:end]
        if substring in strMap:
            continue

        patternMap[currentChar] = substring
        strMap[substring] = currentChar
        if backtrack(pattern, inputString, patternIndex + 1, end, patternMap, strMap):
            return True

        del patternMap[currentChar]
        del strMap[substring]

    return False

if __name__ == "__main__":
    pattern = sys.stdin.readline().strip()

    inputString = sys.stdin.readline().strip()

    result = matchWordPattern(pattern, inputString)
    print("True" if result else "False")

