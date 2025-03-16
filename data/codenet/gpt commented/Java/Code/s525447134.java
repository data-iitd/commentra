import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read the next input string from the user
        String s = sc.next();
        
        // Check if the input string is "Sunny"
        if(s.equals("Sunny")) {
            // If it is "Sunny", print "Cloudy"
            System.out.println("Cloudy");
        } 
        // Check if the input string is "Cloudy"
        else if(s.equals("Cloudy")) {
            // If it is "Cloudy", print "Rainy"
            System.out.println("Rainy");
        } 
        // If the input string is neither "Sunny" nor "Cloudy"
        else {
            // Print "Sunny" as the default case
            System.out.println("Sunny");
        }
        
        // Close the scanner to prevent resource leaks
        sc.close();
    }

}
