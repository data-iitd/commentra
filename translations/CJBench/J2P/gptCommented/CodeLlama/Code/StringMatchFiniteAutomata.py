
import sys

# Constant representing the maximum number of characters
CHARS = sys.maxunicode + 1

# Method to search for a pattern in a given text using finite automata
def search_pattern(text, pattern):
    # Compute the state transition table for the given pattern
    state_transition_table = compute_state_transition_table(pattern)
    # Create a finite automata instance with the state transition table
    finite_automata = FiniteAutomata(state_transition_table)
    # Set to store the indices where the pattern is found
    index_found = set()

    # Iterate through each character in the text
    for i in range(len(text)):
        # Consume the current character in the finite automata
        finite_automata.consume(text[i])
        # Check if the current state indicates a complete match of the pattern
        if finite_automata.get_state() == len(pattern):
            # Add the starting index of the match to the set
            index_found.add(i - len(pattern) + 1)

    # Return the set of indices where the pattern was found
    return index_found

# Method to compute the state transition table for the given pattern
def compute_state_transition_table(pattern):
    pattern_length = len(pattern)
    # Initialize the state transition table
    state_transition_table = [[0] * CHARS for _ in range(pattern_length + 1)]

    # Populate the state transition table
    for state in range(pattern_length + 1):
        for x in range(CHARS):
            # Determine the next state for each character
            state_transition_table[state][x] = get_next_state(pattern, pattern_length, state, x)

    # Return the completed state transition table
    return state_transition_table

# Method to determine the next state based on the current state and input character
def get_next_state(pattern, pattern_length, state, x):
    # If the current state matches the character in the pattern, move to the next state
    if state < pattern_length and x == ord(pattern[state]):
        return state + 1
    # Check for partial matches in the pattern
    for ns in range(state, 0, -1):
        if ord(pattern[ns - 1]) == x:
            match = True
            # Verify if the characters match the prefix of the pattern
            for i in range(ns - 1):
                if pattern[i] != pattern[state - ns + i + 1]:
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
    state_transition_table = None

    # Constructor to initialize the finite automata with the state transition table
    def __init__(self, state_transition_table):
        self.state_transition_table = state_transition_table

    # Method to consume an input character and transition to the next state
    def consume(self, input):
        self.state = self.state_transition_table[self.state][ord(input)]

    # Method to get the current state of the finite automata
    def get_state(self):
        return self.state

# Main method to execute the program
def main():
    # Read the text and pattern from the user
    text = input()
    pattern = input()
    # Search for the pattern in the text
    matches = search_pattern(text, pattern)
    # Output the results based on whether matches were found
    if not matches:
        print("No match found.")
    else:
        print("Pattern found at indices:", matches)

if __name__ == "__main__":
    main()

