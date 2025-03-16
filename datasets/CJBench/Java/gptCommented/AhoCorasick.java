import java.util.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;

public class Main {
    // Node class representing each node in the Trie
    private static class Node {
        // Map to hold child nodes for each character
        private final Map<Character, Node> child = new HashMap<>();
        // Suffix link to facilitate pattern matching
        private Node suffixLink;
        // Output link for patterns that end at this node
        private Node outputLink;
        // Index of the pattern if this node represents the end of a pattern
        private int patternInd;

        // Constructor to initialize a new node
        Node() {
            this.suffixLink = null;
            this.outputLink = null;
            this.patternInd = -1;
        }
    }

    // Trie class for storing patterns and searching them in a given text
    public static class Trie {
        // Root node of the Trie
        private final Node root = new Node();
        // Array of patterns to be searched
        private final String[] patterns;

        // Constructor to initialize the Trie with patterns
        public Trie(final String[] patterns) {
            this.patterns = patterns;
            buildTrie(); // Build the Trie structure
            buildSuffixAndOutputLinks(); // Build suffix and output links for efficient searching
        }

        // Method to build the Trie from the given patterns
        private void buildTrie() {
            for (int i = 0; i < patterns.length; i++) {
                Node curr = root; // Start from the root for each pattern
                for (char c : patterns[i].toCharArray()) {
                    // Create child nodes for each character in the pattern
                    curr = curr.child.computeIfAbsent(c, k -> new Node());
                }
                // Mark the end of the pattern with its index
                curr.patternInd = i;
            }
        }

        // Method to build suffix and output links for the Trie
        private void buildSuffixAndOutputLinks() {
            root.suffixLink = root; // Root's suffix link points to itself
            Queue<Node> queue = new LinkedList<>(); // Queue for BFS

            // Initialize suffix links for the direct children of the root
            for (Node child : root.child.values()) {
                child.suffixLink = root; // Direct children point to root
                queue.add(child); // Add to queue for processing
            }

            // Process nodes in the queue to establish suffix and output links
            while (!queue.isEmpty()) {
                Node current = queue.poll(); // Get the current node from the queue
                for (Map.Entry<Character, Node> entry : current.child.entrySet()) {
                    char ch = entry.getKey(); // Character for the current child
                    Node child = entry.getValue(); // Current child node
                    Node suffix = current.suffixLink; // Start with the current node's suffix link

                    // Follow suffix links until a matching child is found or root is reached
                    while (suffix != root && !suffix.child.containsKey(ch)) {
                        suffix = suffix.suffixLink;
                    }

                    // If a matching child is found, update the suffix link
                    if (suffix.child.containsKey(ch)) {
                        suffix = suffix.child.get(ch);
                    }
                    child.suffixLink = suffix; // Set the suffix link for the child

                    // Set the output link based on the suffix node
                    if (suffix.patternInd != -1) {
                        child.outputLink = suffix; // If suffix is a pattern end, set output link
                    } else {
                        child.outputLink = suffix.outputLink; // Otherwise, inherit output link
                    }
                    queue.add(child); // Add child to the queue for further processing
                }
            }
        }

        // Method to search for patterns in the given text
        public Map<String, List<Integer>> search(String text) {
            // Map to store matches for each pattern
            Map<String, List<Integer>> matches = new LinkedHashMap<>();
            for (String pattern : patterns) {
                matches.put(pattern, new ArrayList<>()); // Initialize list for each pattern
            }
            Node current = root; // Start from the root of the Trie

            // Iterate through each character in the text
            for (int i = 0; i < text.length(); i++) {
                char ch = text.charAt(i); // Current character in the text
                // Follow suffix links if the character is not found in the current node's children
                while (current != root && !current.child.containsKey(ch)) {
                    current = current.suffixLink;
                }
                // If the character is found, move to the corresponding child node
                if (current.child.containsKey(ch)) {
                    current = current.child.get(ch);
                }
                Node temp = current; // Temporary node for output link traversal

                // Traverse through output links to find all patterns that end at this position
                while (temp != null) {
                    if (temp.patternInd != -1) {
                        // Add the starting index of the found pattern to the matches
                        matches.get(patterns[temp.patternInd]).add(i - patterns[temp.patternInd].length() + 1);
                    }
                    temp = temp.outputLink; // Move to the next output link
                }
            }
            return matches; // Return the map of matches
        }
    }

    // Main method to run the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner for input
        String text = scanner.nextLine(); // Read the text to search patterns in
        int patternCount = scanner.nextInt(); // Read the number of patterns
        scanner.nextLine(); // Consume the newline character

        // Array to hold the patterns
        String[] patterns = new String[patternCount];
        for (int i = 0; i < patternCount; i++) {
            patterns[i] = scanner.nextLine(); // Read each pattern
        }

        // Create a Trie with the given patterns
        Trie trie = new Trie(patterns);
        // Search for patterns in the text
        Map<String, List<Integer>> result = trie.search(text);
        
        // Print the results of the pattern matches
        System.out.println("Pattern matches:");
        for (String pattern : patterns) {
            System.out.println(pattern + ": " + result.get(pattern)); // Display each pattern and its matches
        }
        scanner.close(); // Close the scanner
    }
}
