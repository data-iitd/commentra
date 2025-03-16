
import java.util.HashMap;
import java.util.Scanner;

class MainNode {
    // Initialize a MainNode with a given value, an empty HashMap for children, and a boolean flag indicating if it's an end node
    char value;
    HashMap<Character, MainNode> child;
    boolean end;

    MainNode(char value) {
        this.value = value;
        this.child = new HashMap<>();
        this.end = false;
    }
}

public class Main {
    // Initialize a private final root node with the value '*'
    private static final char ROOT_NODE_VALUE = '*';
    private final MainNode root;

    public Main() {
        // Initialize the root node
        root = new MainNode(ROOT_NODE_VALUE);
    }

    // Method to insert a word into the Trie
    public void insert(String word) {
        MainNode currentNode = root; // Initialize currentNode as the root

        for (int i = 0; i < word.length(); i++) {
            MainNode node = currentNode.child.getOrDefault(word.charAt(i), null);
            // If the node for the current character doesn't exist, create a new node and add it as a child to the current node
            if (node == null) {
                node = new MainNode(word.charAt(i));
                currentNode.child.put(word.charAt(i), node);
            }
            currentNode = node; // Move to the next node
        }
        // Set the end flag for the last node
        currentNode.end = true;
    }

    // Method to search for a word in the Trie
    public boolean search(String word) {
        MainNode currentNode = root; // Initialize currentNode as the root

        for (int i = 0; i < word.length(); i++) {
            MainNode node = currentNode.child.getOrDefault(word.charAt(i), null);
            // If the node for the current character doesn't exist, return false
            if (node == null) {
                return false;
            }
            currentNode = node; // Move to the next node
        }
        // Return true if the last node is an end node
        return currentNode.end;
    }

    // Method to delete a word from the Trie
    public boolean delete(String word) {
        MainNode currentNode = root; // Initialize currentNode as the root

        for (int i = 0; i < word.length(); i++) {
            MainNode node = currentNode.child.getOrDefault(word.charAt(i), null);
            // If the node for the current character doesn't exist, return false
            if (node == null) {
                return false;
            }
            currentNode = node; // Move to the next node
        }
        // If the last node is not an end node, return false
        if (!currentNode.end) {
            return false;
        }
        // If the last node has no children, set its parent's child reference to null and return true
        if (currentNode.child.isEmpty()) {
            currentNode.parent.child.remove(currentNode.value);
            return true;
        }
        // Find the node with the smallest character value among the children of the last node
        MainNode smallestNode = currentNode;
        for (MainNode child : currentNode.child.values()) {
            if (child.value < smallestNode.value) {
                smallestNode = child;
            }
        }
        // Merge the children of the last node into the smallest node
        smallestNode.child.putAll(currentNode.child);
        // Set the end flag for the smallest node
        smallestNode.end = currentNode.end;
        // Remove the last node
        currentNode.parent.child.remove(currentNode.value);
        return true;
    }

    // Method to count the number of words in the Trie
    public int countWords() {
        return countWords(root);
    }

    // Recursive method to count the number of words in the Trie
    private int countWords(MainNode node) {
        int count = 0;
        // If the node is an end node, increment the count
        if (node.end) {
            count++;
        }
        // Recursively count the number of words in the children of the node
        for (MainNode child : node.child.values()) {
            count += countWords(child);
        }
        return count;
    }

    // Method to check if a word starts with a given prefix in the Trie
    public boolean startsWithPrefix(String prefix) {
        MainNode currentNode = root; // Initialize currentNode as the root

        for (int i = 0; i < prefix.length(); i++) {
            MainNode node = currentNode.child.getOrDefault(prefix.charAt(i), null);
            // If the node for the current character doesn't exist, return false
            if (node == null) {
                return false;
            }
            currentNode = node; // Move to the next node
        }
        // Return true if the last node is an end node
        return currentNode.end;
    }

    // Method to count the number of words in the Trie that start with a given prefix
    public int countWordsWithPrefix(String prefix) {
        MainNode currentNode = root; // Initialize currentNode as the root

        for (int i = 0; i < prefix.length(); i++) {
            MainNode node = currentNode.child.getOrDefault(prefix.charAt(i), null);
            // If the node for the current character doesn't exist, return 0
            if (node == null) {
                return 0;
            }
            currentNode = node; // Move to the next node
        }
        // Return the number of words in the sub-Trie rooted at the last node
        return countWords(currentNode);
    }

    // Main method to read input and perform operations on the Trie
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Initialize a Scanner to read input

        Main trie = new Main(); // Initialize a new Main object to represent the Trie

        int n = scanner.nextInt(); // Read the number of operations
        scanner.nextLine(); // Read the newline character

        for (int i = 0; i < n; i++) {
            String operation = scanner.next(); // Read the operation

            if (operation.equals("insert")) {
                String word = scanner.next(); // Read the word to be inserted
                trie.insert(word); // Perform the insertion
            } else if (operation.equals("search")) {
                String word = scanner.next(); // Read the word to be searched
                System.out.println(trie.search(word)); // Print the search result
            } else if (operation.equals("delete")) {
                String word = scanner.next(); // Read the word to be deleted
                System.out.println(trie.delete(word)); // Print the deletion result
            } else if (operation.equals("countWords")) {
                System.out.println(trie.countWords()); // Print the number of words in the Trie
            } else if (operation.equals("startsWith")) {
                String prefix = scanner.next(); // Read the prefix
                System.out.println(trie.startsWithPrefix(prefix)); // Print whether the Trie starts with the prefix
            } else if (operation.equals("countWithPrefix")) {
                String prefix = scanner.next(); // Read the prefix
                System.out.println(trie.countWordsWithPrefix(prefix)); // Print the number of words in the Trie that start with the prefix
            }
        }

        scanner.close(); // Close the Scanner
    }
}