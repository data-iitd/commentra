
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Initialize a new scanner for reading input from stdin
        Scanner sc = new Scanner(System.in);
        // Read the number of apples from the standard input
        int appleNum = sc.nextInt();
        // Read the number of pieces to be made from apples from the standard input
        int pieceNum = sc.nextInt();
        // Calculate the number of pieces made from apples
        int pieceNumMadeFromApples = appleNum * 3;
        // Calculate the total number of pieces
        int totalPiece = pieceNumMadeFromApples + pieceNum;
        // Print the total number of pieces divided by 2
        System.out.println(totalPiece / 2);
        // End of the code
    }
}

