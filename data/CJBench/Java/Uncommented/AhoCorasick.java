import java.util.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
public class AhoCorasick {
    private static class Node {
        private final Map<Character, Node> child = new HashMap<>();
        private Node suffixLink;
        private Node outputLink;
        private int patternInd;
        Node() {
            this.suffixLink = null;
            this.outputLink = null;
            this.patternInd = -1;
        }
    }
    public static class Trie {
        private final Node root = new Node();
        private final String[] patterns;
        public Trie(final String[] patterns) {
            this.patterns = patterns;
            buildTrie();
            buildSuffixAndOutputLinks();
        }
        private void buildTrie() {
            for (int i = 0; i < patterns.length; i++) {
                Node curr = root;
                for (char c : patterns[i].toCharArray()) {
                    curr = curr.child.computeIfAbsent(c, k -> new Node());
                }
                curr.patternInd = i;
            }
        }
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
