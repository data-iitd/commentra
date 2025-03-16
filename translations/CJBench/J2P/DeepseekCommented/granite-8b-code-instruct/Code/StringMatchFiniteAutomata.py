
import sys

# Final class Main to prevent instantiation
class Main:
    # Constant representing the number of characters in the Unicode character set
    CHARS = 65536

    # Private constructor to prevent instantiation
    def __init__(self):
        pass

    # Method to search for pattern in text using finite automaton approach
    @staticmethod
    def search_pattern(text, pattern):
        # Compute the state transition table for the pattern
        state_transition_table = Main.compute_state_transition_table(pattern)
        # Initialize the finite automaton with the state transition table
        finite_automata = Main.FiniteAutomata(state_transition_table)
        # Set to store the indices where the pattern is found
        matches = set()
        # Iterate through the text to find matches
        for i in range(len(text)):
            # Consume the current character
            finite_automata.consume(text[i])
            # If the current state matches the pattern length, a match is found
            if finite_automata.get_state() == len(pattern):
                matches.add(i - len(pattern) + 1)  # Add the starting index of the match
        return matches  # Return the set of indices where the pattern is found

    # Method to compute the state transition table for the pattern
    @staticmethod
    def compute_state_transition_table(pattern):
        pattern_length = len(pattern)
        # Create a 2D array to store the state transitions
        state_transition_table = [[0] * Main.CHARS for _ in range(pattern_length + 1)]
        # Fill the table by computing the next state for each state and character
        for state in range(pattern_length + 1):
            for x in range(Main.CHARS):
                state_transition_table[state][x] = Main.get_next_state(pattern, pattern_length, state, x)
        return state_transition_table  # Return the state transition table

    # Method to get the next state based on the current state and input character
    @staticmethod
    def get_next_state(pattern, pattern_length, state, x):
        if state < pattern_length and x == ord(pattern[state]):
            return state + 1  # Increment state if characters match
        # Backtrack to find the longest prefix which is also a suffix
        for ns in range(state, 0, -1):
            if ord(pattern[ns - 1]) == x:
                match = True
                for i in range(0, ns - 1):
                    if pattern[i]!= pattern[state - ns + i + 1]:
                        match = False
                        break
                if match:
                    return ns  # Return the next state
        return 0  # Default state if no match is found

    # Inner class to manage the finite state automaton for pattern matching
    class FiniteAutomata:
        def __init__(self, state_transition_table):
            self.state = 0  # Initial state
            self.state_transition_table = state_transition_table

        # Method to consume an input character and update the state
        def consume(self, input):
            self.state = self.state_transition_table[self.state][ord(input)]

        # Method to get the current state of the finite automaton
        def get_state(self):
            return self.state

# Main method to read input, search for the pattern, and print the results
if __name__ == "__main__":
    text = sys.stdin.readline().strip()  # Read the text input
    pattern = sys.stdin.readline().strip()  # Read the pattern input
    matches = Main.search_pattern(text, pattern)  # Find all matches
    if not matches:
        print("No match found.")  # Print no match message if no matches found
    else:
        print("Pattern found at indices: ", matches)  # Print the indices of matches

