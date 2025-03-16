import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Read an integer value from standard input
        int n = scanner.nextInt();
        
        // Check if n is a multiple of 1000
        if (n % 1000 == 0) 
            // If true, print 0 since no additional amount is needed to reach the next multiple of 1000
            System.out.println(0);
        else 
            // If false, calculate and print the difference to the next multiple of 1000
            System.out.println((n / 1000 + 1) * 1000 - n);
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
