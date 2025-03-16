import java.util.Scanner; // Import the Scanner class for input operations

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a Scanner object to read input from the command line
        int a, b; // Declare two integer variables a and b
        
        // Read an integer input from the user, which represents time in seconds
        a = sc.nextInt();
        
        // Calculate and display the time in hours, minutes, and seconds
        // a/(60*60) calculates the number of hours
        // a%(60*60)/60 calculates the number of minutes
        // a%(60*60)%60 calculates the remaining seconds
        System.out.println(a/(60*60) + ":" + a%(60*60)/60 + ":" + a%(60*60)%60);
        
        sc.close(); // Close the Scanner object
    }
}
