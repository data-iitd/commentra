import sys # Importing sys for reading input

# Final class Main to prevent instantiation
class Main:
    # Constant representing the number of characters in the Unicode character set
    CHARS = 0x110000

    # Private constructor to prevent instantiation
    def __init__(self):
        pass

    # Method to search for pattern in text using finite automaton approach
    def searchPattern(self, text, pattern):
        # Compute the state transition table for the pattern
        stateTransitionTable = self.computeStateTransitionTable(pattern)
        # Initialize the finite automaton with the state transition table
        finiteAutomata = FiniteAutomata(stateTransitionTable)
        # Set to store the indices where the pattern is found
        indexFound = set()
        # Iterate through the text to find matches
        for i in range(len(text)):
            # Consume the current character
            finiteAutomata.consume(text[i])
            # If the current state matches the pattern length, a match is found
            if finiteAutomata.getState() == len(pattern):
                indexFound.add(i - len(pattern) + 1) # Add the starting index of the match
        return indexFound # Return the set of indices where the pattern is found

    # Method to compute the state transition table for the pattern
    def computeStateTransitionTable(self, pattern):
        patternLength = len(pattern)
        # Create a 2D array to store the state transitions
        stateTransitionTable = [[0 for x in range(self.CHARS)] for y in range(patternLength + 1)]
        # Fill the table by computing the next state for each state and character
        for state in range(patternLength + 1):
            for x in range(self.CHARS):
                stateTransitionTable[state][x] = self.getNextState(pattern, patternLength, state, x)
        return stateTransitionTable # Return the state transition table

    # Method to get the next state based on the current state and input character
    def getNextState(self, pattern, patternLength, state, x):
        if state < patternLength and x == pattern[state]:
            return state + 1 # Increment state if characters match
        # Backtrack to find the longest prefix which is also a suffix
        for ns in range(state, 0, -1):
            if pattern[ns - 1] == x:
                match = True
                for i in range(ns - 1):
                    if pattern[i]!= pattern[state - ns + i + 1]:
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
if __name__ == "__main__":
    text = sys.stdin.readline().strip() # Read the text input
    pattern = sys.stdin.readline().strip() # Read the pattern input
    matches = Main().searchPattern(text, pattern) # Find all matches
    if len(matches) == 0:
        print("No match found.") # Print no match message if no matches found
    else:
        print("Pattern found at indices: " + str(matches)) # Print the indices of matches

