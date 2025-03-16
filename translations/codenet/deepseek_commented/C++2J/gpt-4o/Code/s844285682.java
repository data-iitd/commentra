import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int a; // Declare an integer variable a
        
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        a = scanner.nextInt(); // Take an integer input from the user and store it in variable a
        
        // Calculate and output the hours, minutes, and seconds
        System.out.println(a / (60 * 60) + ":" + (a % (60 * 60)) / 60 + ":" + (a % (60 * 60)) % 60);
        
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
