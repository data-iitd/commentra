import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Read input values: the number of initial candles (candeleIntere) and the number of candles needed to create a new one (b)
        Scanner scanner = new Scanner(System.in);
        int candeleIntere = scanner.nextInt();
        int b = scanner.nextInt();
        
        // Initialize total candles burned (s) and remaining loose candles (restoSciolte)
        int s = 0;
        int restoSciolte = 0;
        
        // Loop until there are no more candles to burn or we have enough loose candles to create a new one
        while (candeleIntere > 0 || restoSciolte >= b) {
            // Calculate how many new candles can be created from the remaining loose candles
            candeleIntere += restoSciolte / b;
            
            // Update the number of loose candles after creating new candles
            restoSciolte %= b;
            
            // Add the current number of candles to the total burned count
            s += candeleIntere;
            
            // Update the number of loose candles with the remainder from the current candles
            restoSciolte += candeleIntere % b;
            
            // Reduce the number of candles by the number of new candles created
            candeleIntere /= b;
        }
        
        // Print the total number of candles burned
        System.out.println(s);
    }
}

