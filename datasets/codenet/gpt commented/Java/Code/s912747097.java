import java.util.Scanner; // Import the Scanner class for user input

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read an integer input from the user, representing the radius
        int r = sc.nextInt();
        
        // Calculate the area of a circle using the formula (3 * r * r) and print the result
        System.out.println(3 * r * r);
        
        // Close the scanner to prevent resource leaks
        sc.close();
    }
}
