
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        // Set the scanner to read words instead of lines.
        Scanner sc = new Scanner(System.in);
        sc.useDelimiter("\\s");
        
        // Read the number of apples.
        int appleNum = sc.nextInt();
        
        // Read the number of pieces.
        int pieceNum = sc.nextInt();
        
        // Calculate the total pieces that can be made from the apples.
        int pieceNumMadeFromApples = appleNum * 3;
        
        // Add the given pieces to the pieces made from apples.
        int totalPiece = pieceNumMadeFromApples + pieceNum;
        
        // Print half of the total pieces.
        System.out.println(totalPiece / 2);
    }
}

