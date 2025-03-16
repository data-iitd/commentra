import java.util.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;

public class Main {
    // Represents a node in the trie
    private static class Node {
        // Map to store child nodes
        private final Map<Character, Node> child = new HashMap<>();
        // Suffix link for the node
        private Node suffixLink;
        // Output link for the node
        private Node outputLink;
        // Index to indicate which pattern the node represents
        private int patternInd;

        // Constructor to initialize the node
        Node() {
            this.suffixLink = null;
            this.outputLink = null;
            this.patternInd = -1;
        }
    }

    // Trie class to represent the trie data structure
    public static class Trie {
        // Root of the trie
        private final Node root = new Node();
        // Array to store the patterns
        private final String[] patterns;

        // Constructor to initialize the trie with patterns
        public Trie(final String[] patterns) {
            this.patterns = patterns;
            // Build the trie
            buildTrie();
            // Build suffix and output links
            buildSuffixAndOutputLinks();
        }

        // Method to build the trie by adding each pattern
        private void buildTrie() {
            for (int i = 0; i < patterns.length; i++) {
                Node curr = root;
                for (char c : patterns[i].toCharArray()) {
                    curr = curr.child.computeIfAbsent(c, k -> new Node());
                }
                curr.patternInd = i;
            }
        }

        // Method to build suffix and output links for each node
        private void buildSuffixAndOutputLinks() {
            root.suffixLink = root;
            Queue<Node> queue = new LinkedList<>();
            for (Node child : root.child.values()) {
                child.suffixLink = root;
                queue.add(child);
            }
            while (!queue.isEmpty()) {
                Node current = queue.poll();
                for (Map.Entry<Character, Node> entry : current.child.entrySet()) {
                    char ch = entry.getKey();
                    Node child = entry.getValue();
                    Node suffix = current.suffixLink;
                    while (suffix != root && !suffix.child.containsKey(ch)) {
                        suffix = suffix.suffixLink;
                    }
                    if (suffix.child.containsKey(ch)) {
                        suffix = suffix.child.get(ch);
                    }
                    child.suffixLink = suffix;
                    if (suffix.patternInd != -1) {
                        child.outputLink = suffix;
                    } else {
                        child.outputLink = suffix.outputLink;
                    }
                    queue.add(child);
                }
            }
        }

        // Method to search for all occurrences of patterns in the given text
        public Map<String, List<Integer>> search(String text) {
            Map<String, List<Integer>> matches = new LinkedHashMap<>();
            for (String pattern : patterns) {
                matches.put(pattern, new ArrayList<>());
            }
            Node current = root;
            for (int i = 0; i < text.length(); i++) {
                char ch = text.charAt(i);
                while (current != root && !current.child.containsKey(ch)) {
                    current = current.suffixLink;
                }
                if (current.child.containsKey(ch)) {
                    current = current.child.get(ch);
                }
                Node temp = current;
                while (temp != null) {
                    if (temp.patternInd != -1) {
                        matches.get(patterns[temp.patternInd]).add(i - patterns[temp.patternInd].length() + 1);
                    }
                    temp = temp.outputLink;
                }
            }
            return matches;
        }
    }

    // Main method to read input, construct the trie, and print matches
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String text = scanner.nextLine();
        int patternCount = scanner.nextInt();
        scanner.nextLine(); 
        String[] patterns = new String[patternCount];
        for (int i = 0; i < patternCount; i++) {
            patterns[i] = scanner.nextLine();
        }
        Trie trie = new Trie(patterns);
        Map<String, List<Integer>> result = trie.search(text);
        System.out.println("Pattern matches:");
        for (String pattern : patterns) {
            System.out.println(pattern + ": " + result.get(pattern));
        }
        scanner.close();
    }
}
