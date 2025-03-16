
import java.util.*;
public class TicTacToe {
    static String[] board;
    static String turn;
    static String checkWinner() {
        for (int a = 0; a < 8; a++) {
            String line = null;
            switch (a) {
                case 0:
                    line = board[0] + board[1] + board[2];
                    break;
                case 1:
                    line = board[3] + board[4] + board[5];
                    break;
                case 2:
                    line = board[6] + board[7] + board[8];
                    break;
                case 3:
                    line = board[0] + board[3] + board[6];
                    break;
                case 4:
                    line = board[1] + board[4] + board[7];
                    break;
                case 5:
                    line = board[2] + board[5] + board[8];
                    break;
                case 6:
                    line = board[0] + board[4] + board[8];
                    break;
                case 7:
                    line = board[2] + board[4] + board[6];
                    break;
            }
            if (line.equals("XXX")) return "X";
            if (line.equals("OOO")) return "O";
        }
        for (String value : board) {
            if (value.matches("\\d")) return null; 
        }
        return "draw";
    }
    static void printBoard() {
        System.out.println("|---|---|---|");
        System.out.println("| " + board[0] + " | " + board[1] + " | " + board[2] + " |");
        System.out.println("|-----------|");
        System.out.println("| " + board[3] + " | " + board[4] + " | " + board[5] + " |");
        System.out.println("|-----------|");
        System.out.println("| " + board[6] + " | " + board[7] + " | " + board[8] + " |");
        System.out.println("|---|---|---|");
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        board = new String[9];
        turn = "X";
        String winner = null;
        for (int a = 0; a < 9; a++) {
            board[a] = String.valueOf(a + 1);
        }
        int moveCount = 0; 
        while (winner == null) {
            if (moveCount < 9) {
                int move = in.nextInt();
                if (move < 1 || move > 9 || !board[move - 1].matches("\\d")) {
                    System.out.println("Invalid move! Try again.");
                    continue;
                }
                board[move - 1] = turn;
                printBoard();
                winner = checkWinner();
                turn = turn.equals("X") ? "O" : "X";
                moveCount++;
            } else {
                break;
            }
        }
        if (winner.equals("draw")) {
            System.out.println("It's a draw! Thanks for playing.");
        } else {
            System.out.println("Congratulations! Player " + winner + " wins!");
        }
        in.close();
    }
}
