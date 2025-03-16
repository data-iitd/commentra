import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare an array to hold 10 integers
        int[] v = new int[10];
        
        // Initialize a variable to hold the sum of the integers
        int sum = 0;
        
        // Create a Scanner object for user input
        Scanner scanner = new Scanner(System.in);
        
        // Prompt the user to enter 10 integers and store them in the array
        for (int i = 0; i < 10; i++) {
            v[i] = scanner.nextInt();
        }
        
        // Calculate the sum of the integers stored in the array
        for (int i = 0; i < 10; i++) {
            sum += v[i];
        }
        
        // Output the calculated sum to the console
        System.out.println(sum);
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
