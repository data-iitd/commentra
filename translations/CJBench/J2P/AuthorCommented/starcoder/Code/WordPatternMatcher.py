import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

class Main:

    def __init__(self):
        pass

    def matchWordPattern(self, pattern, inputString):
        patternMap = HashMap()
        strMap = HashMap()
        return self.backtrack(pattern, inputString, 0, 0, patternMap, strMap)

    def backtrack(self, pattern, inputString, patternIndex, strIndex, patternMap, strMap):
        if patternIndex == pattern.length() and strIndex == inputString.length():
            return True
        if patternIndex == pattern.length() or strIndex == inputString.length():
            return False

        currentChar = pattern.charAt(patternIndex)
        if patternMap.containsKey(currentChar):
            mappedStr = patternMap.get(currentChar)
            if inputString.startsWith(mappedStr, strIndex):
                return self.backtrack(pattern, inputString, patternIndex + 1, strIndex + mappedStr.length(), patternMap, strMap)
            else:
                return False

        for end in range(strIndex + 1, inputString.length() + 1):
            substring = inputString.substring(strIndex, end)
            if strMap.containsKey(substring):
                continue

            patternMap.put(currentChar, substring)
            strMap.put(substring, currentChar)
            if self.backtrack(pattern, inputString, patternIndex + 1, end, patternMap, strMap):
                return True

            patternMap.remove(currentChar)
            strMap.remove(substring)

        return False

    def main(self):
        sc = Scanner(System.in)

        pattern = sc.nextLine()

        inputString = sc.nextLine()

        result = self.matchWordPattern(pattern, inputString)
        print(result)

        sc.close()

# 