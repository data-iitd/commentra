
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public final class Main {
    private static final int CHARS = Character.MAX_VALUE + 1; // Maximum value of a character code

    private Main() {
    }

    // Method to search for a pattern in a given text using Finite Automata
    public static Set<Integer> searchPattern(final String text, final String pattern) {
        final var stateTransitionTable = computeStateTransitionTable(pattern); // Compute state transition table for the given pattern
        FiniteAutomata finiteAutomata = new FiniteAutomata(stateTransitionTable); // Create a finite automata object with the state transition table
        Set<Integer> indexFound = new TreeSet<>(); // Initialize an empty set to store the indices of the matches

        // Iterate through each character in the text and check if the pattern matches
        for (int i = 0; i < text.length(); i++) {
            finiteAutomata.consume(text.charAt(i)); // Consume the current character in the text
            if (finiteAutomata.getState() == pattern.length()) { // If we have reached the end state of the pattern
                indexFound.add(i - pattern.length() + 1); // Add the index of the match to the set
            }
        }
        return indexFound;
    }

    // Method to compute the state transition table for a given pattern
    private static int[][] computeStateTransitionTable(final String pattern) {
        final int patternLength = pattern.length(); // Get the length of the pattern
        int[][] stateTransitionTable = new int[patternLength + 1][CHARS]; // Initialize a 2D array to store the state transition table

        // Initialize the state transition table with all zeros
        for (int state = 0; state <= patternLength; ++state) {
            for (int x = 0; x < CHARS; ++x) {
                stateTransitionTable[state][x] = getNextState(pattern, patternLength, state, x); // Set the next state based on the current state and character
            }
        }
        return stateTransitionTable;
    }

    // Method to get the next state based on the current state and character
    private static int getNextState(final String pattern, final int patternLength, final int state, final int x) {
        if (state < patternLength && x == pattern.charAt(state)) { // If the current character matches the character in the pattern at the current state
            return state + 1; // Move to the next state
        }

        // If the current character does not match the character in the pattern at the current state, try to find a previous state that matches the current character
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
                    return ns; // If a previous state is found that matches the current character, return that state
                }
            }
        }
        return 0; // If no state is found, return 0
    }

    // Class to represent a finite automata
    private static final class FiniteAutomata {
        private int state = 0; // Current state of the finite automata
        private final int[][] stateTransitionTable; // State transition table to move from one state to another based on the input character

        // Constructor to initialize the finite automata with the given state transition table
        private FiniteAutomata(int[][] stateTransitionTable) {
            this.stateTransitionTable = stateTransitionTable;
        }

        // Method to consume a character and move to the next state
        private void consume(final char input) {
            state = stateTransitionTable[state][input];
        }

        // Method to get the current state of the finite automata
        private int getState() {
            return state;
        }
    }

    // Main method to read input from the user and call the searchPattern method
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner object to read input from the user
        String text = scanner.nextLine(); // Read the text from the user
        String pattern = scanner.nextLine(); // Read the pattern from the user
        Set<Integer> matches = searchPattern(text, pattern); // Call the searchPattern method to find the matches
        if (matches.isEmpty()) { // If no matches are found, print a message
            System.out.println("No match found.");
        } else { // If matches are found, print the indices of the matches
            System.out.println("Pattern found at indices: " + matches);
        }
        scanner.close(); // Close the scanner object
    }
}