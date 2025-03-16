import java.util.*;

public class Main {
    // Array to represent the Tic-Tac-Toe board
    static String[] board;
    // Variable to track the current player's turn
    static String turn;

    // Method to check for a winner or a draw
    static String checkWinner() {
        // Check all possible winning combinations
        for (int a = 0; a < 8; a++) {
            String line = null;
            switch (a) {
                case 0:
                    line = board[0] + board[1] + board[2]; // Top row
                    break;
                case 1:
                    line = board[3] + board[4] + board[5]; // Middle row
                    break;
                case 2:
                    line = board[6] + board[7] + board[8]; // Bottom row
                    break;
                case 3:
                    line = board[0] + board[3] + board[6]; // Left column
                    break;
                case 4:
                    line = board[1] + board[4] + board[7]; // Middle column
                    break;
                case 5:
                    line = board[2] + board[5] + board[8]; // Right column
                    break;
                case 6:
                    line = board[0] + board[4] + board[8]; // Diagonal from top-left to bottom-right
                    break;
                case 7:
                    line = board[2] + board[4] + board[6]; // Diagonal from top-right to bottom-left
                    break;
            }
            // Check if player X has won
            if (line.equals("XXX")) return "X";
            // Check if player O has won
            if (line.equals("OOO")) return "O";
        }
        // Check for any remaining moves on the board
        for (String value : board) {
            if (value.matches("\\d")) return null; // If there's still a number, the game is not over
        }
        // If no moves left and no winner, it's a draw
        return "draw";
    }

    // Method to print the current state of the board
    static void printBoard() {
        System.out.println("|---|---|---|");
        System.out.println("| " + board[0] + " | " + board[1] + " | " + board[2] + " |");
        System.out.println("|-----------|");
        System.out.println("| " + board[3] + " | " + board[4] + " | " + board[5] + " |");
        System.out.println("|-----------|");
        System.out.println("| " + board[6] + " | " + board[7] + " | " + board[8] + " |");
        System.out.println("|---|---|---|");
    }

    // Main method to run the Tic-Tac-Toe game
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        // Initialize the board with numbers 1-9
        board = new String[9];
        turn = "X"; // X starts first
        String winner = null;

        // Fill the board with numbers representing empty spaces
        for (int a = 0; a < 9; a++) {
            board[a] = String.valueOf(a + 1);
        }

        int moveCount = 0; // Counter for the number of moves made
        // Loop until there is a winner or the board is full
        while (winner == null) {
            if (moveCount < 9) {
                // Read the player's move
                int move = in.nextInt();
                // Validate the move
                if (move < 1 || move > 9 || !board[move - 1].matches("\\d")) {
                    System.out.println("Invalid move! Try again.");
                    continue; // Prompt for a new move
                }
                // Update the board with the current player's move
                board[move - 1] = turn;
                // Print the updated board
                printBoard();
                // Check for a winner after the move
                winner = checkWinner();
                // Switch turns between players
                turn = turn.equals("X") ? "O" : "X";
                moveCount++; // Increment the move counter
            } else {
                break; // Exit if the board is full
            }
        }
        // Announce the result of the game
        if (winner.equals("draw")) {
            System.out.println("It's a draw! Thanks for playing.");
        } else {
            System.out.println("Congratulations! Player " + winner + " wins!");
        }
        in.close(); // Close the scanner resource
    }
}
