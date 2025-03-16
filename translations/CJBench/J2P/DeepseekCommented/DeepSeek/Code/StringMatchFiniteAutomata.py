import sys

# Constant representing the number of characters in the Unicode character set
CHARS = 2**16

# Method to search for pattern in text using finite automaton approach
def search_pattern(text, pattern):
    # Compute the state transition table for the pattern
    state_transition_table = compute_state_transition_table(pattern)
    # Initialize the finite automaton with the state transition table
    finite_automaton = FiniteAutomaton(state_transition_table)
    # List to store the indices where the pattern is found
    index_found = []
    # Iterate through the text to find matches
    for i in range(len(text)):
        # Consume the current character
        finite_automaton.consume(text[i])
        # If the current state matches the pattern length, a match is found
        if finite_automaton.state == len(pattern):
            index_found.append(i - len(pattern) + 1)  # Add the starting index of the match
    return index_found  # Return the list of indices where the pattern is found

# Method to compute the state transition table for the pattern
def compute_state_transition_table(pattern):
    pattern_length = len(pattern)
    # Create a 2D array to store the state transitions
    state_transition_table = [[0] * CHARS for _ in range(pattern_length + 1)]
    # Fill the table by computing the next state for each state and character
    for state in range(pattern_length + 1):
        for x in range(CHARS):
            state_transition_table[state][x] = get_next_state(pattern, pattern_length, state, x)
    return state_transition_table  # Return the state transition table

# Method to get the next state based on the current state and input character
def get_next_state(pattern, pattern_length, state, x):
    if state < pattern_length and chr(x) == pattern[state]:
        return state + 1  # Increment state if characters match
    # Backtrack to find the longest prefix which is also a suffix
    for ns in range(state, 0, -1):
        if pattern[ns - 1] == chr(x):
            match = True
            for i in range(ns - 1):
                if pattern[i] != pattern[state - ns + i + 1]:
                    match = False
                    break
            if match:
                return ns  # Return the next state
    return 0  # Default state if no match is found

# Inner class to manage the finite state automaton for pattern matching
class FiniteAutomaton:
    def __init__(self, state_transition_table):
        self.state = 0  # Initial state
        self.state_transition_table = state_transition_table

    # Method to consume an input character and update the state
    def consume(self, input_char):
        self.state = self.state_transition_table[self.state][ord(input_char)]

    # Method to get the current state of the finite automaton
    def get_state(self):
        return self.state

# Main method to read input, search for the pattern, and print the results
def main():
    # Read the text input
    text = input()
    # Read the pattern input
    pattern = input()
    # Find all matches
    matches = search_pattern(text, pattern)
    # Print the indices of matches if any
    if not matches:
        print("No match found.")
    else:
        print("Pattern found at indices: " + " ".join(map(str, matches)))

# Run the main method
if __name__ == "__main__":
    main()
