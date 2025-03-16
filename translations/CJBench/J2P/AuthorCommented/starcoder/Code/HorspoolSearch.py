import java.util.HashMap;
import java.util.Scanner;

class Main:
    def __init__(self):
        pass

    def findFirst(self, pattern, text):
        shiftValues = self.calcShiftValues(pattern)
        comparisons = 0

        if pattern == "":
            return -1

        textIndex = pattern.length() - 1

        while textIndex < text.length():
            i = pattern.length() - 1
            while i >= 0:
                comparisons += 1
                patternChar = pattern[i]
                textChar = text[(textIndex + i) - (pattern.length() - 1)]
                if not self.charEquals(patternChar, textChar):
                    textIndex += self.getShiftValue(text[textIndex])
                    break
                i -= 1

            if i == -1:
                return textIndex - pattern.length() + 1

        return -1

    def calcShiftValues(self, pattern):
        table = HashMap()
        patternLength = pattern.length()

        for i in range(pattern.length() - 2, -1, -1):
            c = pattern[i]
            finalI = i
            table.computeIfAbsent(c, lambda k: pattern.length() - 1 - finalI)

        return table

    def getShiftValue(self, c):
        return shiftValues.getOrDefault(c, patternLength)

    def charEquals(self, c1, c2):
        return c1 == c2

    def main(self):
        scanner = Scanner(System.in)

        # Prompt for text
        text = scanner.nextLine()

        # Prompt for pattern
        pattern = scanner.nextLine()

        # Perform search
        position = self.findFirst(pattern, text)

        # Display results
        if position!= -1:
            print("Pattern found at index: " + str(position))
        else:
            print("Pattern not found.")

        scanner.close()

