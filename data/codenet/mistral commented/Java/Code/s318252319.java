import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Create a new Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);

        // Read a single string input from the user
        String input = sc.next();

        // Extract the last character from the string and convert it to an integer
        int n = Integer.parseInt(input.substring(input.length()-1, input.length()));

        // Check the value of n and print out the corresponding message
        if (n == 3) {
            System.out.println("bon");
        } else if (n == 0 || n == 1 || n == 6 || n == 8) {
            System.out.println("pon");
        } else {
            System.out.println("hon");
        }

        // Close the Scanner object to free up system resources
        sc.close();
    }
}