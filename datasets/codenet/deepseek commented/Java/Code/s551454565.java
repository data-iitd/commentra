
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Initialize Scanner to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read a string input from the user
        String s = sc.next();
        
        // Determine the next weather condition based on the input
        if (s.equals("Sunny")) {
            // If the input is "Sunny", print "Cloudy"
            System.out.println("Cloudy");
        } else if (s.equals("Cloudy")) {
            // If the input is "Cloudy", print "Rainy"
            System.out.println("Rainy");
        } else {
            // If the input is neither "Sunny" nor "Cloudy", print "Sunny"
            System.out.println("Sunny");
        }
        
        // Close the Scanner to free up resources
        sc.close();
    }
}

