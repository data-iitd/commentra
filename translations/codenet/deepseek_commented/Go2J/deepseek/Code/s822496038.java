import java.util.Scanner;

public class Main {
    // This is the global scanner used to read input from the standard input.
    private static Scanner scanner = new Scanner(System.in);

    // nextInt reads a single word from the standard input, converts it to an integer, and returns it.
    // It throws an exception if the conversion fails.
    public static int nextInt() {
        return scanner.nextInt();
    }

    // The main function is the entry point of the program.
    public static void main(String[] args) {
        // Set the scanner to read words instead of lines.
        scanner.useDelimiter("\\s+");
        
        // Read the number of apples.
        int appleNum = nextInt();
        
        // Read the number of pieces.
        int pieceNum = nextInt();
        
        // Calculate the total pieces that can be made from the apples.
        int pieceNumMadeFromApples = appleNum * 3;
        
        // Add the given pieces to the pieces made from apples.
        int totalPiece = pieceNumMadeFromApples + pieceNum;
        
        // Print half of the total pieces.
        System.out.println(totalPiece / 2);
    }
}
