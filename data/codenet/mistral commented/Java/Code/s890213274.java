
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a new Scanner object to read input from the standard input stream
        Scanner sc = new Scanner(System.in);

        // Declare and initialize three integer variables A1, A2, and A3 by reading their values from the user input using the Scanner object
        int A1 = sc.nextInt();
        int A2 = sc.nextInt();
        int A3 = sc.nextInt();

        // Define the main method, which is the entry point of the Java application
        public static void main(String[] args) {
            // Inside the main method, create a new Scanner object sc to read input from the standard input stream

            // Read the first integer value A1 from the user input using the nextInt() method of the Scanner object and assign it to the variable A1
            int A1 = sc.nextInt();

            // Read the second integer value A2 from the user input using the nextInt() method of the Scanner object and assign it to the variable A2
            int A2 = sc.nextInt();

            // Read the third integer value A3 from the user input using the nextInt() method of the Scanner object and assign it to the variable A3
            int A3 = sc.nextInt();

            // Define an if statement to check if the sum of the three integers is greater than or equal to 22
            if ((A1+A2+A3) >= 22) {
                // If the condition is true, print the string "bust" to the standard output stream
                System.out.println("bust");
            } else {
                // If the condition is false, print the string "win" to the standard output stream
                System.out.println("win");
            }
        }
    }
}