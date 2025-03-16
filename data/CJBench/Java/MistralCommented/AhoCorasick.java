
import java.util.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;

public class Main {
    
    // Define a private inner class Node for the Trie data structure
    private static class Node {
        // Initialize an empty HashMap for child nodes
        private final Map<Character, Node> child = new HashMap<>();
        
        // Initialize a null suffixLink and outputLink
        private Node suffixLink;
        private Node outputLink;
        
        // Initialize a -1 for pattern index
        private int patternInd;
        
        // Constructor for Node
        Node() {
            this.suffixLink = null;
            this.outputLink = null;
            this.patternInd = -1;
        }
    }
    
    // Define a public class Trie for the Trie data structure
    public static class Trie {
        // Initialize the root Node
        private final Node root = new Node();
        
        // Initialize the patterns array
        private String[] patterns;
        
        // Constructor for Trie
        public Trie(final String[] patterns) {
            this.patterns = patterns;
            buildTrie(); // Build the Trie data structure
            buildSuffixAndOutputLinks(); // Build suffix and output links
        }
        
        // Method to build the Trie data structure
        private void buildTrie() {
            for (int i = 0; i < patterns.length; i++) {
                Node curr = root; // Initialize current Node as root
                for (char c : patterns[i].toCharArray()) { // Iterate through each character in the pattern
                    curr = curr.child.computeIfAbsent(c, k -> new Node()); // If child Node doesn't exist, create a new one
                    curr = curr; // Update current Node to the newly created child Node
                }
                // Set the pattern index when reaching the end of the pattern
                curr.patternInd = i;
            }
        }
        
        // Method to build suffix and output links
        private void buildSuffixAndOutputLinks() {
            root.suffixLink = root; // Initialize the suffixLink of the root Node as itself
            Queue<Node> queue = new LinkedList<>(); // Initialize a Queue for BFS traversal
            for (Node child : root.child.values()) { // Add all children to the Queue
                child.suffixLink = root; // Initialize the suffixLink of each child as the root
                queue.add(child);
            }
            while (!queue.isEmpty()) { // Perform BFS traversal
                Node current = queue.poll(); // Dequeue a Node
                for (Map.Entry<Character, Node> entry : current.child.entrySet()) { // Iterate through each child
                    char ch = entry.getKey();
                    Node child = entry.getValue();
                    Node suffix = current.suffixLink; // Initialize suffix as the suffixLink of the current Node
                    while (suffix != root && !suffix.child.containsKey(ch)) { // Find the common suffixNode
                        suffix = suffix.suffixLink;
                    }
                    if (suffix.child.containsKey(ch)) { // If a suffixNode is found
                        suffix = suffix.child.get(ch); // Update suffix to the found suffixNode
                    }
                    child.suffixLink = suffix; // Set the suffixLink of the current child Node
                    if (suffix.patternInd != -1) { // If the suffixNode has a pattern index
                        child.outputLink = suffix; // Set the outputLink of the current child Node to the suffixNode
                    } else { // Otherwise, set the outputLink to the outputLink of the suffixNode
                        child.outputLink = suffix.outputLink;
                    }
                    queue.add(child); // Add the current child Node to the Queue for further traversal
                }
            }
        }
        
        // Method to search for pattern matches in a given text
        public Map<String, List<Integer>> search(String text) {
            Map<String, List<Integer>> matches = new LinkedHashMap<>(); // Initialize an empty HashMap to store the results
            for (String pattern : patterns) { // Iterate through each pattern
                matches.put(pattern, new ArrayList<>()); // Initialize an empty ArrayList to store the matches for the current pattern
            }
            Node current = root; // Initialize the current Node as the root
            for (int i = 0; i < text.length(); i++) { // Iterate through each character in the text
                char ch = text.charAt(i); // Get the current character
                while (current != root && !current.child.containsKey(ch)) { // Find the common prefixNode
                    current = current.suffixLink;
                }
                if (current.child.containsKey(ch)) { // If a child Node is found
                    current = current.child.get(ch); // Update the current Node to the found child Node
                }
                Node temp = current; // Initialize a temporary Node to traverse the output links
                while (temp != null) { // Traverse the output links
                    if (temp.patternInd != -1) { // If a pattern Node is found
                        matches.get(patterns[temp.patternInd]).add(i - patterns[temp.patternInd].length() + 1); // Add the match index to the ArrayList for the current pattern
                    }
                    temp = temp.outputLink; // Update the temporary Node to the next outputNode
                }
            }
            return matches; // Return the HashMap containing the pattern matches
        }
    }
    
    // Main method to read input and call the Trie search method
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Initialize a Scanner for reading input
        String text = scanner.nextLine(); // Read the text from input
        int patternCount = scanner.nextInt(); // Read the number of patterns from input
        scanner.nextLine(); // Read the newline character from input
        String[] patterns = new String[patternCount]; // Initialize an empty String array to store the patterns
        for (int i = 0; i < patternCount; i++) { // Read each pattern from input and store it in the String array
            patterns[i] = scanner.nextLine();
        }
        Trie trie = new Trie(patterns); // Create a new Trie object with the given patterns
        Map<String, List<Integer>> result = trie.search(text); // Call the search method to find the pattern matches in the text
        System.out.println("Pattern matches:"); // Print the header for the output
        for (String pattern : patterns) { // Iterate through each pattern
            System.out.println(pattern + ": " + result.get(pattern)); // Print the pattern and its matches
        }
        scanner.close(); // Close the Scanner
    }
}

