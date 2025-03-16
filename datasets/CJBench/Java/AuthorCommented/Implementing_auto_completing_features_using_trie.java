
import java.util.*;

// Java Program to implement Auto-Complete Feature using Trie
class Trieac {

    // Alphabet size (# of symbols)
    public static final int ALPHABET_SIZE = 26;

    // Trie node
    static class TrieNode {

        TrieNode[] children = new TrieNode[ALPHABET_SIZE];

        // isWordEnd is true if the node represents end of a word
        boolean isWordEnd;
    }

    // Returns new trie node (initialized to NULLs)
    static TrieNode getNode() {
        TrieNode pNode = new TrieNode();
        pNode.isWordEnd = false;

        for (int i = 0; i < ALPHABET_SIZE; i++) {
            pNode.children[i] = null;
        }

        return pNode;
    }

    // If not present, inserts key into trie. If the key is prefix of trie node, just marks leaf node
    static void insert(TrieNode root, final String key) {
        TrieNode pCrawl = root;

        for (int level = 0; level < key.length(); level++) {
            int index = (key.charAt(level) - 'a');
            if (pCrawl.children[index] == null) {
                pCrawl.children[index] = getNode();
            }
            pCrawl = pCrawl.children[index];
        }

        // Mark last node as leaf
        pCrawl.isWordEnd = true;
    }

    // Returns true if key presents in trie, else false
    boolean search(TrieNode root, final String key) {
        int length = key.length();
        TrieNode pCrawl = root;

        for (int level = 0; level < length; level++) {
            int index = (key.charAt(level) - 'a');

            if (pCrawl.children[index] == null) {
                pCrawl = pCrawl.children[index];
            }
        }

        return (pCrawl != null && pCrawl.isWordEnd);
    }

    // Returns 0 if current node has a child. If all children are NULL, return 1.
    static boolean isLastNode(TrieNode root) {
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (root.children[i] != null) {
                return false;
            }
        }
        return true;
    }

    // Recursive function to print auto-suggestions for given node.
    static void suggestionsRec(TrieNode root, String currPrefix) {
        // Found a string in Trie with the given prefix
        if (root.isWordEnd) {
            System.out.println(currPrefix);
        }

        // All children struct node pointers are NULL
        if (isLastNode(root)) {
            return;
        }

        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (root.children[i] != null) {
                // Append current character to currPrefix string
                suggestionsRec(root.children[i], currPrefix + (char) (97 + i));
            }
        }
    }

    // Function to print suggestions for given query prefix.
    static int printAutoSuggestions(TrieNode root, final String query) {
        TrieNode pCrawl = root;

        // Check if prefix is present and find the node (of last level) with last character of given string.
        int level;
        int n = query.length();

        for (level = 0; level < n; level++) {
            int index = (query.charAt(level) - 'a');

            // No string in the Trie has this prefix
            if (pCrawl.children[index] == null) {
                return 0;
            }

            pCrawl = pCrawl.children[index];
        }

        // If prefix is present as a word.
        boolean isWord = (pCrawl.isWordEnd);

        // If prefix is last node of tree (has no children)
        boolean isLast = isLastNode(pCrawl);

        // If prefix is present as a word, but there is no subtree below the last matching node.
        if (isWord && isLast) {
            System.out.println(query);
            return -1;
        }

        // If there are nodes below the last matching character.
        if (!isLast) {
            suggestionsRec(pCrawl, query);
            return 1;
        }

        return 0;
    }

    // Driver code
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        sc.nextLine(); // Consume newline

        TrieNode root = getNode();

        for (int i = 0; i < n; i++) {
            insert(root, sc.nextLine());
        }

        String prefix = sc.nextLine();

        int comp = printAutoSuggestions(root, prefix);

        if (comp == -1) {
            System.out.println("No other strings found with this prefix\n");
        } else if (comp == 0) {
            System.out.println("No string found with this prefix\n");
        }

        sc.close();
    }
}
