
import sys

# Constants
CHARS = 256

# Private constructor to prevent instantiation
class Main:
    def __init__(self):
        pass

# Searches for the pattern in the given text using finite automata.
def search_pattern(text, pattern):
    state_transition_table = compute_state_transition_table(pattern)
    finite_automata = FiniteAutomata(state_transition_table)

    index_found = set()
    for i in range(len(text)):
        finite_automata.consume(text[i])
        if finite_automata.get_state() == len(pattern):
            index_found.add(i - len(pattern) + 1)

    return index_found

# Computes the finite automata table for the given pattern.
def compute_state_transition_table(pattern):
    pattern_length = len(pattern)
    state_transition_table = [[0] * CHARS for _ in range(pattern_length + 1)]

    for state in range(pattern_length + 1):
        for x in range(CHARS):
            state_transition_table[state][x] = get_next_state(pattern, pattern_length, state, x)

    return state_transition_table

# Gets the next state for the finite automata.
def get_next_state(pattern, pattern_length, state, x):
    # If the current state is less than the length of the pattern
    # and the character matches the pattern character, go to the next state
    if state < pattern_length and x == pattern[state]:
        return state + 1

    # Check for the highest prefix which is also a suffix
    for ns in range(state, 0, -1):
        if pattern[ns - 1] == x:
            match = True
            for i in range(0, ns - 1):
                if pattern[i] != pattern[state - ns + i + 1]:
                    match = False
                    break
            if match:
                return ns

    # If no prefix which is also a suffix is found, return 0
    return 0

# A class representing the finite automata for pattern matching.
class FiniteAutomata:
    def __init__(self, state_transition_table):
        self.state = 0
        self.state_transition_table = state_transition_table

    # Consumes an input character and transitions to the next state.
    def consume(self, input):
        self.state = self.state_transition_table[self.state][input]

    # Gets the current state of the finite automata.
    def get_state(self):
        return self.state

# Input the text
text = sys.stdin.readline().strip()

# Input the pattern
pattern = sys.stdin.readline().strip()

# Perform pattern matching
matches = search_pattern(text, pattern)

# Output the results
if len(matches) == 0:
    print("No match found.")
else:
    print("Pattern found at indices: " + str(matches))

# END-OF-CODE
