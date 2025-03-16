import java.util.*;
import java.util.HashMap;
public class WordSearch_IIUsingPrefixTree {
    public static class Trie {
        private String value;
        private boolean isKey;
        private final Map<Character, Trie> children = new HashMap<>();
        public boolean hasChild(char ch) {
            return children.containsKey(ch);
        }
        public void addChild(char ch) {
            children.put(ch, new Trie());
        }
        public Trie getChild(char ch) {
            return children.get(ch);
        }
        public void insert(String word) {
            var node = this;
            for (var ch : word.toCharArray()) {
                if (!node.hasChild(ch)) {
                    node.addChild(ch);
                }
                node = node.getChild(ch);
            }
            node.value = word;
            node.isKey = true;
        }
    }
    public List<String> findWords(char[][] board, String[] words) {
        Set<String> uniqueWords = new HashSet<>(Arrays.asList(words));
        Trie trie = new Trie();
        uniqueWords.forEach(trie::insert);
        Set<String> result = new HashSet<>();
        int m = board.length;
        int n = board[0].length;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                boolean[][] visited = new boolean[m][n];
                visited[i][j] = true;
                traverse(board, i, j, trie, visited, result);
            }
        }
        return new ArrayList<>(result);
    }
    private void traverse(char[][] board, int i, int j, Trie trie, boolean[][] visited, Set<String> result) {
        char ch = board[i][j];
        if (trie.hasChild(ch)) {
            Trie child = trie.getChild(ch);
            if (child.isKey) {
                result.add(child.value);
            }
            checkNewPos(board, i - 1, j, child, visited, result);
            checkNewPos(board, i, j - 1, child, visited, result);
            checkNewPos(board, i + 1, j, child, visited, result);
            checkNewPos(board, i, j + 1, child, visited, result);
        }
    }
    private void checkNewPos(char[][] board, int i, int j, Trie trie, boolean[][] visited, Set<String> result) {
        int m = board.length;
        int n = board[0].length;
        if (i < 0 || j < 0 || i >= m || j >= n) {
            return;
        }
        if (!visited[i][j]) {
            visited[i][j] = true;
            traverse(board, i, j, trie, visited, result);
            visited[i][j] = false;
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int rows = scanner.nextInt();
        int cols = scanner.nextInt();
        scanner.nextLine(); 
        char[][] board = new char[rows][cols];
        for (int i = 0; i < rows; i++) {
            board[i] = scanner.nextLine().toCharArray();
        }
        int wordCount = scanner.nextInt();
        scanner.nextLine(); 
        String[] words = new String[wordCount];
        for (int i = 0; i < wordCount; i++) {
            words[i] = scanner.nextLine();
        }
        WordSearch_IIUsingPrefixTree wordSearch = new WordSearch_IIUsingPrefixTree();
        List<String> result = wordSearch.findWords(board, words);
        result.forEach(System.out::println);
        scanner.close();
    }
}
