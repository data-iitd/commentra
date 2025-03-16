import java.util.Scanner;

public class PowerOfTwo {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object for input
        int n = scanner.nextInt();  // Take an integer input from the user
        while (n % 2 == 0) {  // Check if the number is even and keep dividing by 2 until odd
            n /= 2;
        }
        if (n == 1) {  // Check if the number has been reduced to 1
            System.out.println("YES");  // Print 'YES' if the original number was a power of 2
        } else {
            System.out.println("NO");  // Print 'NO' if the original number was not a power of 2
        }
        scanner.close();  // Close the scanner
    }
}  // <END-OF-CODE>
