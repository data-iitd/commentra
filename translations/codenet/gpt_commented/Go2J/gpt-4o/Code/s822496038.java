import java.util.Scanner; // Importing Scanner for input

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Initialize a new scanner to read from standard input
        
        // Read the number of apples and pieces from input
        int appleNum = sc.nextInt(); 
        int pieceNum = sc.nextInt(); 
        
        // Calculate the number of pieces made from apples (3 pieces per apple)
        int pieceNumMadeFromApples = appleNum * 3;
        
        // Calculate the total number of pieces (pieces from apples + existing pieces)
        int totalPiece = pieceNumMadeFromApples + pieceNum;
        
        // Output the total number of complete sets of 2 pieces
        System.out.println(totalPiece / 2);
        
        sc.close(); // Close the scanner
    }
}

// <END-OF-CODE>
