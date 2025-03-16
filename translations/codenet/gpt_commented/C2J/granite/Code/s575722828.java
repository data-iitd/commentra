
import java.util.Scanner;

public class s575722828{
    public static void main(String[] args) {
        // Declare an integer variable to store the total seconds
        int S;

        // Create a Scanner object to read user input
        Scanner scanner = new Scanner(System.in);

        // Read the total seconds from user input
        S = scanner.nextInt();

        // Calculate hours, minutes, and seconds from the total seconds
        // and print them in the format HH:MM:SS
        System.out.printf("%d:%d:%d\n", 
                S / 3600,                // Calculate hours
                (S % 3600) / 60,        // Calculate minutes
                S % 60);               // Calculate remaining seconds

        // Close the Scanner object to release system resources
        scanner.close();
    }
}
