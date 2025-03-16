def compute_state_transition_table(pattern):
    pattern_length = len(pattern)
    state_transition_table = [[0] * (1 << 16) for _ in range(pattern_length + 1)]

    for state in range(pattern_length + 1):
        for x in range(1 << 16):
            state_transition_table[state][x] = get_next_state(pattern, pattern_length, state, x)

    return state_transition_table


def get_next_state(pattern, pattern_length, state, x):
    if state < pattern_length and pattern[state] == chr(x):
        return state + 1

    for ns in range(state, 0, -1):
        if pattern[ns - 1] == chr(x):
            match = True
            for i in range(ns - 1):
                if pattern[i] != pattern[state - ns + i + 1]:
                    match = False
                    break
            if match:
                return ns

    return 0


class FiniteAutomata:
    def __init__(self, state_transition_table):
        self.state = 0
        self.state_transition_table = state_transition_table

    def consume(self, input_char):
        self.state = self.state_transition_table[self.state][input_char]

    def get_state(self):
        return self.state


def search_pattern(text, pattern):
    state_transition_table = compute_state_transition_table(pattern)
    finite_automata = FiniteAutomata(state_transition_table)
    index_found = set()

    for i in range(len(text)):
        finite_automata.consume(ord(text[i]))
        if finite_automata.get_state() == len(pattern):
            index_found.add(i - len(pattern) + 1)

    return index_found


def main():
    text = input()
    pattern = input()
    matches = search_pattern(text, pattern)
    if not matches:
        print("No match found.")
    else:
        print("Pattern found at indices: " + " ".join(map(str, matches)))


main()
