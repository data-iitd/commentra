import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public final class Main {
    // Constant representing the maximum number of characters
    private static final int CHARS = Character.MAX_VALUE + 1;

    // Private constructor to prevent instantiation of the class
    private Main() {
    }

    // Method to search for a pattern in a given text using finite automata
    public static Set<Integer> searchPattern(final String text, final String pattern) {
        // Compute the state transition table for the given pattern
        final var stateTransitionTable = computeStateTransitionTable(pattern);
        // Create a finite automata instance with the state transition table
        FiniteAutomata finiteAutomata = new FiniteAutomata(stateTransitionTable);
        // Set to store the indices where the pattern is found
        Set<Integer> indexFound = new TreeSet<>();

        // Iterate through each character in the text
        for (int i = 0; i < text.length(); i++) {
            // Consume the current character in the finite automata
            finiteAutomata.consume(text.charAt(i));
            // Check if the current state indicates a complete match of the pattern
            if (finiteAutomata.getState() == pattern.length()) {
                // Add the starting index of the match to the set
                indexFound.add(i - pattern.length() + 1);
            }
        }
        // Return the set of indices where the pattern was found
        return indexFound;
    }

    // Method to compute the state transition table for the given pattern
    private static int[][] computeStateTransitionTable(final String pattern) {
        final int patternLength = pattern.length();
        // Initialize the state transition table
        int[][] stateTransitionTable = new int[patternLength + 1][CHARS];

        // Populate the state transition table
        for (int state = 0; state <= patternLength; ++state) {
            for (int x = 0; x < CHARS; ++x) {
                // Determine the next state for each character
                stateTransitionTable[state][x] = getNextState(pattern, patternLength, state, x);
            }
        }
        // Return the completed state transition table
        return stateTransitionTable;
    }

    // Method to determine the next state based on the current state and input character
    private static int getNextState(final String pattern, final int patternLength, final int state, final int x) {
        // If the current state matches the character in the pattern, move to the next state
        if (state < patternLength && x == pattern.charAt(state)) {
            return state + 1;
        }
        // Check for partial matches in the pattern
        for (int ns = state; ns > 0; ns--) {
            if (pattern.charAt(ns - 1) == x) {
                boolean match = true;
                // Verify if the characters match the prefix of the pattern
                for (int i = 0; i < ns - 1; i++) {
                    if (pattern.charAt(i) != pattern.charAt(state - ns + i + 1)) {
                        match = false;
                        break;
                    }
                }
                // If a match is found, return the new state
                if (match) {
                    return ns;
                }
            }
        }
        // If no match is found, return the initial state
        return 0;
    }

    // Inner class representing the finite automata
    private static final class FiniteAutomata {
        // Current state of the finite automata
        private int state = 0;
        // State transition table for the finite automata
        private final int[][] stateTransitionTable;

        // Constructor to initialize the finite automata with the state transition table
        private FiniteAutomata(int[][] stateTransitionTable) {
            this.stateTransitionTable = stateTransitionTable;
        }

        // Method to consume an input character and transition to the next state
        private void consume(final char input) {
            state = stateTransitionTable[state][input];
        }

        // Method to get the current state of the finite automata
        private int getState() {
            return state;
        }
    }

    // Main method to execute the program
    public static void main(String[] args) {
        // Create a scanner to read input from the user
        Scanner scanner = new Scanner(System.in);
        // Read the text and pattern from the user
        String text = scanner.nextLine();
        String pattern = scanner.nextLine();
        // Search for the pattern in the text
        Set<Integer> matches = searchPattern(text, pattern);
        // Output the results based on whether matches were found
        if (matches.isEmpty()) {
            System.out.println("No match found.");
        } else {
            System.out.println("Pattern found at indices: " + matches);
        }
        // Close the scanner to free resources
        scanner.close();
    }
}
