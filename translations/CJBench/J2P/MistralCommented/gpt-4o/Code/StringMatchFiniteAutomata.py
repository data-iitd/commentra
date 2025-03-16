class FiniteAutomata:
    def __init__(self, state_transition_table):
        self.state = 0  # Current state of the finite automata
        self.state_transition_table = state_transition_table  # State transition table

    def consume(self, input_char):
        self.state = self.state_transition_table[self.state][ord(input_char)]  # Move to the next state based on input character

    def get_state(self):
        return self.state  # Get the current state


def compute_state_transition_table(pattern):
    pattern_length = len(pattern)  # Get the length of the pattern
    chars = 256  # Maximum value of a character code (ASCII)
    state_transition_table = [[0] * chars for _ in range(pattern_length + 1)]  # Initialize state transition table

    for state in range(pattern_length + 1):
        for x in range(chars):
            state_transition_table[state][x] = get_next_state(pattern, pattern_length, state, x)  # Set the next state

    return state_transition_table


def get_next_state(pattern, pattern_length, state, x):
    if state < pattern_length and x == ord(pattern[state]):  # If the current character matches the pattern
        return state + 1  # Move to the next state

    for ns in range(state, 0, -1):  # Try to find a previous state that matches the current character
        if pattern[ns - 1] == chr(x):
            match = True
            for i in range(ns - 1):
                if pattern[i] != pattern[state - ns + i + 1]:
                    match = False
                    break
            if match:
                return ns  # Return the matching state
    return 0  # If no state is found, return 0


def search_pattern(text, pattern):
    state_transition_table = compute_state_transition_table(pattern)  # Compute state transition table
    finite_automata = FiniteAutomata(state_transition_table)  # Create finite automata object
    index_found = set()  # Initialize an empty set to store indices of matches

    for i in range(len(text)):
        finite_automata.consume(text[i])  # Consume the current character
        if finite_automata.get_state() == len(pattern):  # If we reached the end state of the pattern
            index_found.add(i - len(pattern) + 1)  # Add the index of the match

    return index_found  # Return the set of indices


def main():
    text = input()  # Read the text from the user
    pattern = input()  # Read the pattern from the user
    matches = search_pattern(text, pattern)  # Call the search_pattern function

    if not matches:  # If no matches are found
        print("No match found.")
    else:  # If matches are found
        print("Pattern found at indices:", sorted(matches))  # Print the indices of the matches


if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
