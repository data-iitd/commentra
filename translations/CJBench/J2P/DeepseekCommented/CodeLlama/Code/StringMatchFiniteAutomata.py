
# Importing Scanner for input
from java.util import Scanner
# Importing Set for storing indices of matches
from java.util import Set
# Importing TreeSet for storing and sorting indices
from java.util import TreeSet

# Final class Main to prevent instantiation
class Main:
    # Constant representing the number of characters in the Unicode character set
    CHARS = Character.MAX_VALUE + 1

    # Private constructor to prevent instantiation
    def __init__(self):
        pass

    # Method to search for pattern in text using finite automaton approach
    @staticmethod
    def searchPattern(text, pattern):
        # Compute the state transition table for the pattern
        stateTransitionTable = Main.computeStateTransitionTable(pattern)
        # Initialize the finite automaton with the state transition table
        finiteAutomata = FiniteAutomata(stateTransitionTable)
        # Set to store the indices where the pattern is found
        indexFound = TreeSet()
        # Iterate through the text to find matches
        for i in range(len(text)):
            # Consume the current character
            finiteAutomata.consume(text[i])
            # If the current state matches the pattern length, a match is found
            if finiteAutomata.getState() == len(pattern):
                indexFound.add(i - len(pattern) + 1) # Add the starting index of the match
        return indexFound # Return the set of indices where the pattern is found

    # Method to compute the state transition table for the pattern
    @staticmethod
    def computeStateTransitionTable(pattern):
        patternLength = len(pattern)
        # Create a 2D array to store the state transitions
        stateTransitionTable = [[0] * Main.CHARS for _ in range(patternLength + 1)]
        # Fill the table by computing the next state for each state and character
        for state in range(patternLength + 1):
            for x in range(Main.CHARS):
                stateTransitionTable[state][x] = Main.getNextState(pattern, patternLength, state, x)
        return stateTransitionTable # Return the state transition table

    # Method to get the next state based on the current state and input character
    @staticmethod
    def getNextState(pattern, patternLength, state, x):
        if state < patternLength and x == pattern[state]:
            return state + 1 # Increment state if characters match
        # Backtrack to find the longest prefix which is also a suffix
        for ns in range(state, 0, -1):
            if pattern[ns - 1] == x:
                match = True
                for i in range(ns - 1):
                    if pattern[i] != pattern[state - ns + i + 1]:
                        match = False
                        break
                if match:
                    return ns # Return the next state
        return 0 # Default state if no match is found

    # Inner class to manage the finite state automaton for pattern matching
    class FiniteAutomata:
        def __init__(self, stateTransitionTable):
            self.state = 0 # Initial state
            self.stateTransitionTable = stateTransitionTable

        # Method to consume an input character and update the state
        def consume(self, input):
            self.state = self.stateTransitionTable[self.state][input]

        # Method to get the current state of the finite automaton
        def getState(self):
            return self.state

# Main method to read input, search for the pattern, and print the results
def main(args):
    scanner = Scanner(System.in) # Initialize Scanner for input
    text = scanner.nextLine() # Read the text input
    pattern = scanner.nextLine() # Read the pattern input
    matches = Main.searchPattern(text, pattern) # Find all matches
    if len(matches) == 0:
        print("No match found.") # Print no match message if no matches found
    else:
        print("Pattern found at indices: " + matches) # Print the indices of matches
    scanner.close() # Close the scanner

# End of code
