import java.util.Scanner;  // Import the Scanner class for input

public class Main {  // Define the main class
    public static void main(String[] args) {  // Start of the main method
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object for input
        int N = scanner.nextInt();  // Read the number of movements from the standard input
        int nx = 0, ny = 0, nt = 0;  // Initialize the current positions and time

        for (int i = 0; i < N; i++) {  // Start a loop that runs N times
            int t = scanner.nextInt();  // Read the time for each movement
            int x = scanner.nextInt();  // Read the x-coordinate for each movement
            int y = scanner.nextInt();  // Read the y-coordinate for each movement
            int tmp = t - nt - (Math.abs(x - nx) + Math.abs(y - ny));  // Calculate the time difference

            if (tmp < 0 || tmp % 2 != 0) {  // Check if the difference is less than 0 or if it is odd
                System.out.println("No");  // Output "No" and terminate the program
                return;  // Exit the main method
            }

            nx = x;  // Update the current x-coordinate
            ny = y;  // Update the current y-coordinate
            nt = t;  // Update the current time
        }

        System.out.println("Yes");  // If the loop completes without issues, output "Yes"
    }
}  // End of the main class
// <END-OF-CODE>
