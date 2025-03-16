import java.util.Scanner;

public class Main {
    // Main function
    public static void main(String[] args) {
        // Initialize a scanner for reading input from stdin
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of apples from the standard input
        int appleNum = scanner.nextInt();
        // Read the number of pieces to be made from apples from the standard input
        int pieceNum = scanner.nextInt();
        
        // Calculate the number of pieces made from apples
        int pieceNumMadeFromApples = appleNum * 3;
        // Calculate the total number of pieces
        int totalPiece = pieceNumMadeFromApples + pieceNum;
        
        // Print the total number of pieces divided by 2
        System.out.println(totalPiece / 2);
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
