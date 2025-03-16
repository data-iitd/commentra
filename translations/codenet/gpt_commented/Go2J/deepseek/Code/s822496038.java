import java.util.Scanner;

public class ApplePieces {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of apples and pieces from input
        int appleNum = scanner.nextInt();
        int pieceNum = scanner.nextInt();
        
        // Calculate the number of pieces made from apples (3 pieces per apple)
        int pieceNumMadeFromApples = appleNum * 3;
        
        // Calculate the total number of pieces (pieces from apples + existing pieces)
        int totalPiece = pieceNumMadeFromApples + pieceNum;
        
        // Output the total number of complete sets of 2 pieces
        System.out.println(totalPiece / 2);
    }
}
