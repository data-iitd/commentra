
import java.util.Scanner; // Import the Scanner class for input operations

public class s844285682{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input from the user
        
        int a = scanner.nextInt(); // Read an integer input from the user, which represents time in seconds
        
        // Calculate and display the time in hours, minutes, and seconds
        // a/(60*60) calculates the number of hours
        // a%(60*60)/60 calculates the number of minutes
        // a%(60*60)%60 calculates the remaining seconds
        System.out.println(a/(60*60) + ":" + a%(60*60)/60 + ":" + a%(60*60)%60);
        
        scanner.close(); // Close the Scanner object to release system resources
    }
}
