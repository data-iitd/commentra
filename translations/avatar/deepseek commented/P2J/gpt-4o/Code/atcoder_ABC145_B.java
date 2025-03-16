import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Take an integer input from the user
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character
        
        // Take a string input from the user
        String s = scanner.nextLine();
        
        // Check if n is odd
        if (n % 2 != 0) {
            // Print 'No' if n is odd
            System.out.println("No");
        } else {
            // Compare the first half of the string with the second half
            String firstHalf = s.substring(0, n / 2);
            String secondHalf = s.substring(n / 2);
            if (firstHalf.equals(secondHalf)) {
                // Print 'Yes' if the first half is equal to the second half
                System.out.println("Yes");
            } else {
                // Print 'No' if the first half is not equal to the second half
                System.out.println("No");
            }
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>
