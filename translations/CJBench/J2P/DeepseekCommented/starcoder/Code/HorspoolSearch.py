import java.util.HashMap;
import java.util.Scanner;

class Main:
    # Stores shift values for each character in the pattern
    shiftValues = {}

    # Stores the length of the pattern
    patternLength = 0

    # Counter for the number of character comparisons
    comparisons = 0

    # Finds the first occurrence of the pattern in the text
    def findFirst(self, pattern, text):
        return self.firstOccurrence(pattern, text, True)

    # Implements the Boyer-Moore algorithm to find the first occurrence
    def firstOccurrence(self, pattern, text, caseSensitive):
        self.shiftValues = self.calcShiftValues(pattern)
        self.comparisons = 0

        # If the pattern is empty, return -1
        if pattern == "":
            return -1

        textIndex = pattern.length() - 1
        while textIndex < len(text):
            i = pattern.length() - 1
            while i >= 0:
                self.comparisons += 1
                patternChar = pattern[i]
                textChar = text[(textIndex + i) - (pattern.length() - 1)]
                if not self.charEquals(patternChar, textChar, caseSensitive):
                    textIndex += self.getShiftValue(text[textIndex])
                    break
                i -= 1
            if i == -1:
                return textIndex - pattern.length() + 1
        return -1

    # Compares characters, optionally ignoring case sensitivity
    def charEquals(self, c1, c2, caseSensitive):
        if caseSensitive:
            return c1 == c2
        else:
            return c1.lower() == c2.lower()

    # Calculates the shift values for each character in the pattern
    def calcShiftValues(self, pattern):
        self.patternLength = len(pattern)
        table = {}
        for i in range(len(pattern) - 2, -1, -1):
            c = pattern[i]
            table[c] = len(pattern) - 1 - i
        return table

    # Retrieves the shift value for a given character
    def getShiftValue(self, c):
        return self.shiftValues.get(c, self.patternLength)

    # Main method to read input and find the pattern
    def main(self):
        scanner = Scanner(System.in)
        text = scanner.nextLine()
        pattern = scanner.nextLine()
        position = self.findFirst(pattern, text)
        if position!= -1:
            print("Pattern found at index: " + str(position))
        else:
            print("Pattern not found.")
        scanner.close()

# 