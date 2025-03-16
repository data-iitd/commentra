import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Create a new Scanner object to read user input
        Scanner sc = new Scanner(System.in);

        String s; // Declare a String variable to store user input

        // Read a string from the user's input
        s = sc.next();

        // Check if the string is equal to "Sunny"
        if (s.equals("Sunny")) {
            System.out.println("Cloudy"); // Print "Cloudy" to the console if it is
        }

        // Check if the string is equal to "Cloudy"
        else if (s.equals("Cloudy")) {
            System.out.println("Rainy"); // Print "Rainy" to the console if it is
        }

        // If the string is not equal to "Sunny" or "Cloudy", print "Sunny" to the console
        else {
            System.out.println("Sunny");
        }

        // Close the Scanner object to free up system resources
        sc.close();
    }
}