
import sys

# Class to represent a finite automata
class FiniteAutomata:
    def __init__(self, stateTransitionTable):
        self.state = 0
        self.stateTransitionTable = stateTransitionTable

    # Method to consume a character and move to the next state
    def consume(self, input):
        self.state = self.stateTransitionTable[self.state][input]

    # Method to get the current state of the finite automata
    def getState(self):
        return self.state

# Method to search for a pattern in a given text using Finite Automata
def searchPattern(text, pattern):
    stateTransitionTable = computeStateTransitionTable(pattern) # Compute state transition table for the given pattern
    finiteAutomata = FiniteAutomata(stateTransitionTable) # Create a finite automata object with the state transition table
    indexFound = set() # Initialize an empty set to store the indices of the matches

    # Iterate through each character in the text and check if the pattern matches
    for i in range(len(text)):
        finiteAutomata.consume(text[i]) # Consume the current character in the text
        if finiteAutomata.getState() == len(pattern): # If we have reached the end state of the pattern
            indexFound.add(i - len(pattern) + 1) # Add the index of the match to the set
    return indexFound

# Method to compute the state transition table for a given pattern
def computeStateTransitionTable(pattern):
    patternLength = len(pattern) # Get the length of the pattern
    stateTransitionTable = [[0 for x in range(CHARS)] for y in range(patternLength + 1)] # Initialize a 2D array to store the state transition table

    # Initialize the state transition table with all zeros
    for state in range(patternLength + 1):
        for x in range(CHARS):
            stateTransitionTable[state][x] = getNextState(pattern, patternLength, state, x) # Set the next state based on the current state and character
    return stateTransitionTable

# Method to get the next state based on the current state and character
def getNextState(pattern, patternLength, state, x):
    if state < patternLength and x == pattern[state]: # If the current character matches the character in the pattern at the current state
        return state + 1 # Move to the next state

    # If the current character does not match the character in the pattern at the current state, try to find a previous state that matches the current character
    for ns in range(state, 0, -1):
        if pattern[ns - 1] == x:
            match = True
            for i in range(ns - 1):
                if pattern[i]!= pattern[state - ns + i + 1]:
                    match = False
                    break
            if match:
                return ns # If a previous state is found that matches the current character, return that state
    return 0 # If no state is found, return 0

# Main method to read input from the user and call the searchPattern method
def main():
    text = sys.stdin.readline().strip() # Read the text from the user
    pattern = sys.stdin.readline().strip() # Read the pattern from the user
    matches = searchPattern(text, pattern) # Call the searchPattern method to find the matches
    if len(matches) == 0: # If no matches are found, print a message
        print("No match found.")
    else: # If matches are found, print the indices of the matches
        print("Pattern found at indices: " + str(matches))

# Constant to store the maximum value of a character code
CHARS = 256

if __name__ == '__main__':
    main()

# 