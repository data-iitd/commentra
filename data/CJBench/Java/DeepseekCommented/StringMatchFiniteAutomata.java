import java.util.Scanner; // Importing Scanner for input
import java.util.Set; // Importing Set for storing indices of matches
import java.util.TreeSet; // Importing TreeSet for storing and sorting indices

// Final class Main to prevent instantiation
public final class Main {
    // Constant representing the number of characters in the Unicode character set
    private static final int CHARS = Character.MAX_VALUE + 1;

    // Private constructor to prevent instantiation
    private Main() {
    }

    // Method to search for pattern in text using finite automaton approach
    public static Set<Integer> searchPattern(final String text, final String pattern) {
        // Compute the state transition table for the pattern
        final var stateTransitionTable = computeStateTransitionTable(pattern);
        // Initialize the finite automaton with the state transition table
        FiniteAutomata finiteAutomata = new FiniteAutomata(stateTransitionTable);
        // Set to store the indices where the pattern is found
        Set<Integer> indexFound = new TreeSet<>();
        // Iterate through the text to find matches
        for (int i = 0; i < text.length(); i++) {
            // Consume the current character
            finiteAutomata.consume(text.charAt(i));
            // If the current state matches the pattern length, a match is found
            if (finiteAutomata.getState() == pattern.length()) {
                indexFound.add(i - pattern.length() + 1); // Add the starting index of the match
            }
        }
        return indexFound; // Return the set of indices where the pattern is found
    }

    // Method to compute the state transition table for the pattern
    private static int[][] computeStateTransitionTable(final String pattern) {
        final int patternLength = pattern.length();
        // Create a 2D array to store the state transitions
        int[][] stateTransitionTable = new int[patternLength + 1][CHARS];
        // Fill the table by computing the next state for each state and character
        for (int state = 0; state <= patternLength; ++state) {
            for (int x = 0; x < CHARS; ++x) {
                stateTransitionTable[state][x] = getNextState(pattern, patternLength, state, x);
            }
        }
        return stateTransitionTable; // Return the state transition table
    }

    // Method to get the next state based on the current state and input character
    private static int getNextState(final String pattern, final int patternLength, final int state, final int x) {
        if (state < patternLength && x == pattern.charAt(state)) {
            return state + 1; // Increment state if characters match
        }
        // Backtrack to find the longest prefix which is also a suffix
        for (int ns = state; ns > 0; ns--) {
            if (pattern.charAt(ns - 1) == x) {
                boolean match = true;
                for (int i = 0; i < ns - 1; i++) {
                    if (pattern.charAt(i) != pattern.charAt(state - ns + i + 1)) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    return ns; // Return the next state
                }
            }
        }
        return 0; // Default state if no match is found
    }

    // Inner class to manage the finite state automaton for pattern matching
    private static final class FiniteAutomata {
        private int state = 0; // Initial state
        private final int[][] stateTransitionTable;

        // Constructor to initialize the finite automaton with the state transition table
        private FiniteAutomata(int[][] stateTransitionTable) {
            this.stateTransitionTable = stateTransitionTable;
        }

        // Method to consume an input character and update the state
        private void consume(final char input) {
            state = stateTransitionTable[state][input];
        }

        // Method to get the current state of the finite automaton
        private int getState() {
            return state;
        }
    }

    // Main method to read input, search for the pattern, and print the results
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Initialize Scanner for input
        String text = scanner.nextLine(); // Read the text input
        String pattern = scanner.nextLine(); // Read the pattern input
        Set<Integer> matches = searchPattern(text, pattern); // Find all matches
        if (matches.isEmpty()) {
            System.out.println("No match found."); // Print no match message if no matches found
        } else {
            System.out.println("Pattern found at indices: " + matches); // Print the indices of matches
        }
        scanner.close(); // Close the scanner
    }
}
