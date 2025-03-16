import java.util.Scanner; // Import the Scanner class for input

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Read the values of N and A from the standard input
        int N = scanner.nextInt();
        int A = scanner.nextInt();
        
        // Use the conditional operator to check if the remainder of N divided by 500 is less than or equal to A
        System.out.println((N % 500 <= A) ? "Yes" : "No");
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
