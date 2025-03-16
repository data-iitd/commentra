import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

class Main:
    # Constant representing the maximum number of characters
    CHARS = Character.MAX_VALUE + 1

    # Private constructor to prevent instantiation of the class
    def __init__(self):
        pass

    # Method to search for a pattern in a given text using finite automata
    def searchPattern(self, text, pattern):
        # Compute the state transition table for the given pattern
        stateTransitionTable = self.computeStateTransitionTable(pattern)
        # Create a finite automata instance with the state transition table
        finiteAutomata = FiniteAutomata(stateTransitionTable)
        # Set to store the indices where the pattern is found
        indexFound = TreeSet()

        # Iterate through each character in the text
        for i in range(0, len(text)):
            # Consume the current character in the finite automata
            finiteAutomata.consume(text[i])
            # Check if the current state indicates a complete match of the pattern
            if finiteAutomata.getState() == pattern.length():
                # Add the starting index of the match to the set
                indexFound.add(i - pattern.length() + 1)

        # Return the set of indices where the pattern was found
        return indexFound

    # Method to compute the state transition table for the given pattern
    def computeStateTransitionTable(self, pattern):
        patternLength = pattern.length()
        # Initialize the state transition table
        stateTransitionTable = [[0 for x in range(CHARS)] for y in range(patternLength + 1)]

        # Populate the state transition table
        for state in range(0, patternLength + 1):
            for x in range(0, CHARS):
                # Determine the next state for each character
                stateTransitionTable[state][x] = self.getNextState(pattern, patternLength, state, x)

        # Return the completed state transition table
        return stateTransitionTable

    # Method to determine the next state based on the current state and input character
    def getNextState(self, pattern, patternLength, state, x):
        # If the current state matches the character in the pattern, move to the next state
        if state < patternLength and x == pattern.charAt(state):
            return state + 1
        # Check for partial matches in the pattern
        for ns in range(state, 0, -1):
            if pattern.charAt(ns - 1) == x:
                match = True
                # Verify if the characters match the prefix of the pattern
                for i in range(0, ns - 1):
                    if pattern.charAt(i)!= pattern.charAt(state - ns + i + 1):
                        match = False
                        break
                # If a match is found, return the new state
                if match:
                    return ns
        # If no match is found, return the initial state
        return 0

    # Inner class representing the finite automata
    class FiniteAutomata:
        # Current state of the finite automata
        state = 0
        # State transition table for the finite automata
        stateTransitionTable = None

        # Constructor to initialize the finite automata with the state transition table
        def __init__(self, stateTransitionTable):
            self.stateTransitionTable = stateTransitionTable

        # Method to consume an input character and transition to the next state
        def consume(self, input):
            self.state = self.stateTransitionTable[self.state][input]

        # Method to get the current state of the finite automata
        def getState(self):
            return self.state


# Main method to execute the program
if __name__ == '__main__':
    # Create a scanner to read input from the user
    scanner = Scanner(System.in)
    # Read the text and pattern from the user
    text = scanner.nextLine()
    pattern = scanner.nextLine()
    # Search for the pattern in the text
    matches = Main().searchPattern(text, pattern)
    # Output the results based on whether matches were found
    if matches.isEmpty():
        print("No match found.")
    else:
        print("Pattern found at indices: " + matches)
    # Close the scanner to free resources
    scanner.close()

