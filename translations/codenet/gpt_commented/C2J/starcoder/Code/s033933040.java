
// Import the Scanner class to read input from the console
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner input = new Scanner(System.in);
        
        // Read two integer inputs from the user representing the dimensions
        int a = input.nextInt();
        int b = input.nextInt();
        
        // Calculate the perimeter (mawari) of the rectangle
        int mawari = 2 * (a + b); // Perimeter formula: 2 * (length + width)
        
        // Calculate the area (menseki) of the rectangle
        int menseki = a * b; // Area formula: length * width
        
        // Print the area and perimeter to the console
        System.out.println(menseki + " " + mawari);
    }
}

