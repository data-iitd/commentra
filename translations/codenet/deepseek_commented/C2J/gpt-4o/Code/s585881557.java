import java.util.Scanner;  // Import the Scanner class for input

public class Main {  // Define the Main class
    public static void main(String[] args) {  // Define the main method
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object for input
        int h = scanner.nextInt();  // Read the first integer and store it in h
        int r = scanner.nextInt();  // Read the second integer and store it in r
        
        if (r > -h) {  // Check if r is greater than -h
            System.out.println("1");  // If true, print 1
        } else if (r == -h) {  // If the condition in the if statement is false, check if r is equal to -h
            System.out.println("0");  // If true, print 0
        } else {  // If neither of the above conditions is true
            System.out.println("-1");  // Print -1
        }
        
        scanner.close();  // Close the scanner
    }
}

// <END-OF-CODE>
