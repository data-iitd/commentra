
import java.util.Scanner;

public class s033933040{
    public static void main(String[] args) {
        // Declare variables to hold the dimensions and calculated values
        int a, b, mawari, menseki;
        
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);
        
        // Read two integer inputs from the user representing the dimensions
        a = scanner.nextInt();
        b = scanner.nextInt();
        
        // Calculate the perimeter (mawari) of the rectangle
        mawari = a + a + b + b; // Perimeter formula: 2 * (length + width)
        
        // Calculate the area (menseki) of the rectangle
        menseki = a * b; // Area formula: length * width
        
        // Print the area and perimeter to the console
        System.out.println(menseki + " " + mawari);
        
        // Close the Scanner object to release system resources
        scanner.close();
    }
}
