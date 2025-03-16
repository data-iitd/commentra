
import java.util.Scanner; // Import the Scanner class from the java.util package

public class s854821134{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input from the user
        int a = scanner.nextInt(); // Read an integer input from the user and store it in the variable a
        int b = scanner.nextInt(); // Read another integer input from the user and store it in the variable b

        // Check if both a and b are less than or equal to 8
        if (a <= 8 && b <= 8) 
            System.out.println("Yay!"); // If true, print "Yay!"
        else 
            System.out.println(":("); // If false, print ":("

        scanner.close(); // Close the Scanner object to release system resources
    }
}
