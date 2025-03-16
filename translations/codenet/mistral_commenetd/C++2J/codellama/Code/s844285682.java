
import java.util.Scanner; // Import the Scanner class

public class TimeConversion {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a Scanner object to read input from the command line
        
        System.out.print("Enter the number of seconds: "); // Print a message to ask the user for the number of seconds
        int a = sc.nextInt(); // Read an integer value from the command line and assign it to the variable a
        
        int hours = a / (60 * 60); // Extract the hours from the number of seconds
        int minutes = (a % (60 * 60)) / 60; // Extract the minutes from the remaining seconds
        int seconds = (a % (60 * 60)) % 60; // Extract the seconds from the remaining seconds
        
        System.out.println(hours + ":" + minutes + ":" + seconds); // Print the time representation of the number of seconds
    }
}

