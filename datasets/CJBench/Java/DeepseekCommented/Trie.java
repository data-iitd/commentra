import java.util.HashMap;
import java.util.Scanner;

class MainNode {
    char value;
    HashMap<Character, MainNode> child;
    boolean end;

    // Constructor to initialize the node with a given character value.
    MainNode(char value) {
        this.value = value;
        this.child = new HashMap<>();
        this.end = false;
    }
}

public class Main {
    private static final char ROOT_NODE_VALUE = '*';
    private final MainNode root;

    // Constructor to initialize the Trie with a root node.
    public Main() {
        root = new MainNode(ROOT_NODE_VALUE);
    }

    // Inserts a word into the Trie.
    public void insert(String word) {
        MainNode currentNode = root;
        for (int i = 0; i < word.length(); i++) {
            MainNode node = currentNode.child.getOrDefault(word.charAt(i), null);
            if (node == null) {
                node = new MainNode(word.charAt(i));
                currentNode.child.put(word.charAt(i), node);
            }
            currentNode = node;
        }
        currentNode.end = true;
    }

    // Searches for a word in the Trie.
    public boolean search(String word) {
        MainNode currentNode = root;
        for (int i = 0; i < word.length(); i++) {
            MainNode node = currentNode.child.getOrDefault(word.charAt(i), null);
            if (node == null) {
                return false;
            }
            currentNode = node;
        }
        return currentNode.end;
    }

    // Deletes a word from the Trie.
    public boolean delete(String word) {
        MainNode currentNode = root;
        for (int i = 0; i < word.length(); i++) {
            MainNode node = currentNode.child.getOrDefault(word.charAt(i), null);
            if (node == null) {
                return false;
            }
            currentNode = node;
        }
        if (currentNode.end) {
            currentNode.end = false;
            return true;
        }
        return false;
    }

    // Counts the total number of words in the Trie.
    public int countWords() {
        return countWords(root);
    }

    // Helper method to recursively count words in the Trie.
    private int countWords(MainNode node) {
        if (node == null) {
            return 0;
        }
        int count = 0;
        if (node.end) {
            count++;
        }
        for (MainNode child : node.child.values()) {
            count += countWords(child);
        }
        return count;
    }

    // Checks if there are any words in the Trie that start with the given prefix.
    public boolean startsWithPrefix(String prefix) {
        MainNode currentNode = root;
        for (int i = 0; i < prefix.length(); i++) {
            MainNode node = currentNode.child.getOrDefault(prefix.charAt(i), null);
            if (node == null) {
                return false;
            }
            currentNode = node;
        }
        return true;
    }

    // Counts the number of words in the Trie that start with the given prefix.
    public int countWordsWithPrefix(String prefix) {
        MainNode currentNode = root;
        for (int i = 0; i < prefix.length(); i++) {
            MainNode node = currentNode.child.getOrDefault(prefix.charAt(i), null);
            if (node == null) {
                return 0;
            }
            currentNode = node;
        }
        return countWords(currentNode);
    }

    // Main method to take user input and perform operations on the Trie.
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Main trie = new Main();
        int n = scanner.nextInt();
        scanner.nextLine(); 
        for (int i = 0; i < n; i++) {
            String operation = scanner.next();
            if (operation.equals("insert")) {
                String word = scanner.next();
                trie.insert(word);
            } else if (operation.equals("search")) {
                String word = scanner.next();
                System.out.println(trie.search(word));
            } else if (operation.equals("delete")) {
                String word = scanner.next();
                System.out.println(trie.delete(word));
            } else if (operation.equals("countWords")) {
                System.out.println(trie.countWords());
            } else if (operation.equals("startsWith")) {
                String prefix = scanner.next();
                System.out.println(trie.startsWithPrefix(prefix));
            } else if (operation.equals("countWithPrefix")) {
                String prefix = scanner.next();
                System.out.println(trie.countWordsWithPrefix(prefix));
            }
        }
        scanner.close();
    }
}
