import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter an integer: ");  // Prompt the user for input
        int n = scanner.nextInt();  // Read an integer from the user

        while (n % 2 == 0) {  // While n is even
            n /= 2;  // Divide n by 2 to remove the last even factor
        }

        if (n == 1) {  // If n is now 1
            System.out.println("YES");  // Print 'YES'
        } else {  // Otherwise
            System.out.println("NO");  // Print 'NO'
        }

        scanner.close();  // Close the scanner
    }
}

// <END-OF-CODE>
