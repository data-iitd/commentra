
import java.util.HashMap;
import java.util.Scanner;

class Main:
    shiftValues = None
    patternLength = None
    comparisons = 0

    # Method to find the first occurrence of a pattern in a text
    def findFirst(self, pattern, text):
        return self.firstOccurrence(pattern, text, True)

    # Recursive method to find the first occurrence of a pattern in a text
    def firstOccurrence(self, pattern, text, caseSensitive):
        self.shiftValues = self.calcShiftValues(pattern) # Calculate shift values for the pattern
        self.comparisons = 0

        if pattern == "": # Base case: if the pattern is empty, return -1
            return -1

        textIndex = len(pattern) - 1 # Initialize textIndex to the last character of the pattern

        while textIndex < len(text): # While textIndex is less than the length of the text
            i = len(pattern) - 1 # Initialize i to the last character of the pattern

            # Loop through each character of the pattern from the last to the first
            while i >= 0:
                self.comparisons += 1 # Increment comparisons for each character comparison

                patternChar = pattern[i] # Get the character of the pattern at index i
                textChar = text[(textIndex + i) - (len(pattern) - 1)] # Get the character of the text at the corresponding index

                # Compare the characters of the pattern and text, considering case sensitivity
                if not self.charEquals(patternChar, textChar, caseSensitive):
                    textIndex += self.getShiftValue(text[textIndex]) # Shift textIndex based on the shift value of the character at textIndex
                    break # Exit the inner loop if the characters don't match

                i -= 1 # Decrement i to compare the next character of the pattern with the text

            # If all characters of the pattern match the corresponding characters in the text, return the index of the first match
            if i == -1:
                return textIndex - len(pattern) + 1

            textIndex += 1 # Increment textIndex to compare the next possible match in the text

        # If no match is found, return -1
        return -1

    # Method to compare two characters, considering case sensitivity
    def charEquals(self, c1, c2, caseSensitive):
        return caseSensitive and c1 == c2 or not caseSensitive and c1.lower() == c2.lower()

    # Method to calculate shift values for a pattern
    def calcShiftValues(self, pattern):
        self.patternLength = len(pattern)
        table = HashMap()

        # Calculate shift values for each character in the pattern, from the last to the first
        for i in range(len(pattern) - 2, -1, -1):
            c = pattern[i]
            table.putIfAbsent(c, len(pattern) - 1 - i)

        return table

    # Method to get the shift value for a character
    def getShiftValue(self, c):
        return self.shiftValues.getOrDefault(c, self.patternLength)

    # Main method to read input from the user and call findFirst method
    def main(self):
        scanner = Scanner(System.in)
        text = scanner.nextLine() # Read the text from the user
        pattern = scanner.nextLine() # Read the pattern from the user
        position = self.findFirst(pattern, text) # Find the first occurrence of the pattern in the text

        if position!= -1: # If the pattern is found, print the index of the first occurrence
            print("Pattern found at index: " + str(position))
        else: # If the pattern is not found, print a message indicating that
            print("Pattern not found.")

        scanner.close() # Close the scanner after reading the input

if __name__ == "__main__":
    Main().main()

