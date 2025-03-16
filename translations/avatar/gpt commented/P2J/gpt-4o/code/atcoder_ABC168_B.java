import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Read an integer input K from the user
        int K = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character
        
        // Read a string input S from the user
        String S = scanner.nextLine();
        
        // Check if the length of the string S is less than or equal to K
        if (S.length() <= K) {
            // If true, print the original string S
            System.out.println(S);
        } else {
            // If the length of S is greater than K, print the first K characters followed by '...'
            System.out.println(S.substring(0, K) + "...");
        }
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
