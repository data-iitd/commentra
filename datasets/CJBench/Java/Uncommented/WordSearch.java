
import java.util.Scanner;
public class WordSearch {
    private final int[] dx = {0, 0, 1, -1};
    private final int[] dy = {1, -1, 0, 0};
    private boolean[][] visited;
    private char[][] board;
    private String word;
    private boolean isValid(int x, int y) {
        return x >= 0 && x < board.length && y >= 0 && y < board[0].length;
    }
    private boolean doDFS(int x, int y, int nextIdx) {
        visited[x][y] = true;
        if (nextIdx == word.length()) {
            return true;
        }
        for (int i = 0; i < 4; ++i) {
            int xi = x + dx[i];
            int yi = y + dy[i];
            if (isValid(xi, yi) && board[xi][yi] == word.charAt(nextIdx) && !visited[xi][yi]) {
                boolean exists = doDFS(xi, yi, nextIdx + 1);
                if (exists) {
                    return true;
                }
            }
        }
        visited[x][y] = false; 
        return false;
    }
    public boolean exist(char[][] board, String word) {
        this.board = board;
        this.word = word;
        for (int i = 0; i < board.length; ++i) {
            for (int j = 0; j < board[0].length; ++j) {
                if (board[i][j] == word.charAt(0)) {
                    visited = new boolean[board.length][board[0].length];
                    boolean exists = doDFS(i, j, 1);
                    if (exists) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int rows = scanner.nextInt();
        int cols = scanner.nextInt();
        char[][] board = new char[rows][cols];
        for (int i = 0; i < rows; i++) {
            String row = scanner.next();
            board[i] = row.toCharArray();
        }
        String word = scanner.next();
        WordSearch wordSearch = new WordSearch();
        boolean result = wordSearch.exist(board, word);
        if (result) {
            System.out.println("The word exists in the board.");
        } else {
            System.out.println("The word does not exist in the board.");
        }
        scanner.close();
    }
}
