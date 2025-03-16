import sys

# Constants
CHARS = 256

# Private constructor to prevent instantiation
def __init__(self):
    pass

# Searches for the pattern in the given text using finite automata.
def searchPattern(text, pattern):
    stateTransitionTable = computeStateTransitionTable(pattern)
    finiteAutomata = FiniteAutomata(stateTransitionTable)

    indexFound = set()
    for i in range(len(text)):
        finiteAutomata.consume(text[i])
        if finiteAutomata.getState() == len(pattern):
            indexFound.add(i - len(pattern) + 1)

    return indexFound

# Computes the finite automata table for the given pattern.
def computeStateTransitionTable(pattern):
    patternLength = len(pattern)
    stateTransitionTable = [[0 for x in range(CHARS)] for y in range(patternLength + 1)]

    for state in range(patternLength + 1):
        for x in range(CHARS):
            stateTransitionTable[state][x] = getNextState(pattern, patternLength, state, x)

    return stateTransitionTable

# Gets the next state for the finite automata.
def getNextState(pattern, patternLength, state, x):
    # If the current state is less than the length of the pattern
    # and the character matches the pattern character, go to the next state
    if state < patternLength and x == pattern[state]:
        return state + 1

    # Check for the highest prefix which is also a suffix
    for ns in range(state, 0, -1):
        if pattern[ns - 1] == x:
            match = True
            for i in range(ns - 1):
                if pattern[i]!= pattern[state - ns + i + 1]:
                    match = False
                    break
            if match:
                return ns

    # If no prefix which is also a suffix is found, return 0
    return 0

# A class representing the finite automata for pattern matching.
class FiniteAutomata:
    def __init__(self, stateTransitionTable):
        self.state = 0
        self.stateTransitionTable = stateTransitionTable

    # Consumes an input character and transitions to the next state.
    def consume(self, input):
        self.state = self.stateTransitionTable[self.state][ord(input)]

    # Gets the current state of the finite automata.
    def getState(self):
        return self.state

if __name__ == "__main__":
    # Input the text
    text = sys.stdin.readline().strip()

    # Input the pattern
    pattern = sys.stdin.readline().strip()

    # Perform pattern matching
    matches = searchPattern(text, pattern)

    # Output the results
    if len(matches) == 0:
        print("No match found.")
    else:
        print("Pattern found at indices: " + str(matches))

