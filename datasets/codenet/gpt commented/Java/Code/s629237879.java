import java.io.*;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException { 
        // Create a BufferedReader to read input from the console
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        // Read the first line of input which indicates the number of cards
        String sc = br.readLine();
        int n = Integer.parseInt(sc);
        
        // Initialize an array to store the cards that are already present
        String[] str = new String[n];
        
        // Read the existing cards from the input
        for (int i = 0; i < n; i++) {
            str[i] = br.readLine();
        }
        
        // Define the four suits of cards
        String[] mark = {"S", "H", "C", "D"};
        
        // Iterate over each suit
        for (String ma : mark) {
            // Iterate over card numbers from 1 to 13
            for (int i = 1; i <= 13; i++) {
                // Convert the card number to a string
                String s = Integer.toString(i);
                
                // Create the full card representation (e.g., "S 1", "H 2")
                String st = ma + " " + s;
                
                // Check if the card is already present in the input
                if (Arrays.asList(str).contains(st)) {
                    // If the card is present, skip to the next iteration
                    continue;
                } else {
                    // If the card is not present, print it
                    System.out.println(st);
                }
            }
        }
    }
}
