import java.util.Scanner; // Import the Scanner class for input

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a Scanner object to read input
        int x = sc.nextInt(); // Read an integer value from the user and store it in x

        // Check if the input value x is greater than or equal to 1200
        if (x >= 1200) 
            System.out.println("ARC"); // If true, output "ARC"
        else 
            System.out.println("ABC"); // If false, output "ABC"
    }
}
