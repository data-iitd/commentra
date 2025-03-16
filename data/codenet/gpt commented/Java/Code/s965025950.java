import java.util.Scanner; // Import the Scanner class for user input

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in);
        
        // Read three integers from the user
        int x = sc.nextInt(); // Read the first integer
        int y = sc.nextInt(); // Read the second integer
        int z = sc.nextInt(); // Read the third integer
        
        // Print the integers in the order: z, x, y
        System.out.println(z + " " + x + " " + y);
        
        // Close the Scanner to free up resources
        sc.close();
    }
}
