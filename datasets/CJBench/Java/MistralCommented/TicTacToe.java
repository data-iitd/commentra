
import java.util.*;

public class Main {
    static String[] board; // initialize the board as a String array
    static String turn; // keep track of whose turn it is

    static String checkWinner() {
        // check rows for a win
        for (int a = 0; a < 8; a++) {
            String line = null;
            switch (a) {
                case 0:
                    line = board[0] + board[1] + board[2]; // concatenate the strings of the first row
                    break;
                case 1:
                    line = board[3] + board[4] + board[5]; // concatenate the strings of the second row
                    break;
                case 2:
                    line = board[6] + board[7] + board[8]; // concatenate the strings of the third row
                    break;
                case 3:
                    line = board[0] + board[3] + board[6]; // concatenate the strings of the first and third diagonal
                    break;
                case 4:
                    line = board[1] + board[4] + board[7]; // concatenate the strings of the second diagonal
                    break;
                case 5:
                    line = board[2] + board[5] + board[8]; // concatenate the strings of the third diagonal
                    break;
                case 6:
                    line = board[0] + board[4] + board[8]; // concatenate the strings of the first and third column
                    break;
                case 7:
                    line = board[2] + board[4] + board[6]; // concatenate the strings of the second and third column
                    break;
            }
            // check if the line contains three identical symbols (X or O)
            if (line.equals("XXX")) {
                return "X"; // return X as the winner
            } else if (line.equals("OOO")) {
                return "O"; // return O as the winner
            }
        }
        // check if all the board positions are filled (draw)
        for (String value : board) {
            if (value.matches("\\d")) continue; // skip empty positions
            return null; // if all positions are filled, return null
        }
        return "draw"; // if all positions are filled and no winner was found, return draw
    }

    static void printBoard() {
        // print the board header
        System.out.println("|---|---|---|");
        // print the board rows
        System.out.println("| " + board[0] + " | " + board[1] + " | " + board[2] + " |");
        System.out.println("|-----------|");
        System.out.println("| " + board[3] + " | " + board[4] + " | " + board[5] + " |");
        System.out.println("|-----------|");
        System.out.println("| " + board[6] + " | " + board[7] + " | " + board[8] + " |");
        // print the board footer
        System.out.println("|---|---|---|");
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in); // initialize the Scanner for user input
        board = new String[9]; // initialize the board as a String array of size 9
        turn = "X"; // set the initial turn to X

        // initialize the board with numbers 1 to 9
        for (int a = 0; a < 9; a++) {
            board[a] = String.valueOf(a + 1);
        }

        String winner = null;
        int moveCount = 0; // initialize move counter

        // game loop
        while (winner == null) {
            if (moveCount < 9) { // check if there are still moves to be made
                int move; // variable to store the user's move

                // get the user's move
                System.out.println("Player " + turn + ", enter your move (1-9):");
                move = in.nextInt();

                // validate the user's move
                if (move < 1 || move > 9 || !board[move - 1].matches("\\d")) {
                    System.out.println("Invalid move! Try again.");
                    continue;
                }

                // make the move
                board[move - 1] = turn;

                // print the updated board
                printBoard();

                // check for a winner or a draw
                winner = checkWinner();

                // change the turn
                turn = turn.equals("X") ? "O" : "X";

                moveCount++; // increment the move counter
            } else { // if all moves have been made
                break;
            }
        }

        // print the game result
        if (winner.equals("draw")) {
            System.out.println("It's a draw! Thanks for playing.");
        } else {
            System.out.println("Congratulations! Player " + winner + " wins!");
        }

        // close the Scanner
        in.close();
    }
}