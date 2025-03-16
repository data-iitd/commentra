import java.util.HashMap;
import java.util.Scanner;

class Main:
    # Private constructor to prevent instantiation
    def __init__(self):
        pass

    # HashMap to store shift values for characters in the pattern
    shiftValues = None
    # Length of the pattern
    patternLength = None
    # Counter for the number of comparisons made
    comparisons = 0

    # Public method to find the first occurrence of a pattern in a text
    def findFirst(self, pattern, text):
        return self.firstOccurrence(pattern, text, True)

    # Private method to find the first occurrence of a pattern in a text
    def firstOccurrence(self, pattern, text, caseSensitive):
        # Calculate shift values for the pattern
        self.shiftValues = self.calcShiftValues(pattern)
        self.comparisons = 0 # Reset comparisons count
        # If the pattern is empty, return -1 (not found)
        if pattern == "":
            return -1
        # Start searching from the end of the pattern in the text
        textIndex = pattern.length() - 1
        while textIndex < text.length():
            i = pattern.length() - 1 # Index for the pattern
            while i >= 0:
                self.comparisons += 1 # Increment comparison count
                patternChar = pattern[i]
                textChar = text[(textIndex + i) - (pattern.length() - 1)]
                # Check if characters match based on case sensitivity
                if not self.charEquals(patternChar, textChar, caseSensitive):
                    # If not a match, shift the text index based on the character
                    textIndex += self.getShiftValue(text[textIndex])
                    break # Exit inner loop to continue with the next text index
                i -= 1 # Move to the next character in the pattern
            # If all characters matched, return the starting index of the match
            if i == -1:
                return textIndex - pattern.length() + 1
        # If no match is found, return -1
        return -1

    # Method to compare two characters based on case sensitivity
    def charEquals(self, c1, c2, caseSensitive):
        return caseSensitive and c1 == c2 or not caseSensitive and Character.toLowerCase(c1) == Character.toLowerCase(c2)

    # Method to calculate shift values for each character in the pattern
    def calcShiftValues(self, pattern):
        self.patternLength = pattern.length() # Store the length of the pattern
        table = HashMap() # Initialize shift values table
        # Populate the shift values for each character in the pattern
        for i in range(pattern.length() - 2, -1, -1):
            c = pattern[i]
            finalI = i # Final index for lambda expression
            table.computeIfAbsent(c, lambda k: pattern.length() - 1 - finalI)
        return table # Return the shift values table

    # Method to get the shift value for a character
    def getShiftValue(self, c):
        return self.shiftValues.getOrDefault(c, self.patternLength) # Default to pattern length if not found

    # Main method to execute the program
    def main(self):
        scanner = Scanner(System.in) # Create a scanner for input
        text = scanner.nextLine() # Read the text input
        pattern = scanner.nextLine() # Read the pattern input
        position = self.findFirst(pattern, text) # Find the first occurrence of the pattern
        # Output the result based on the position found
        if position!= -1:
            print("Pattern found at index: " + str(position))
        else:
            print("Pattern not found.")
        scanner.close() # Close the scanner

# 