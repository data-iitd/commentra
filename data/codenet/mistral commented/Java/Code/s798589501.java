
import java.util.*; // Import Java Util Scanner library

public class Main {
    public static void main(String[] args) throws Exception {
        
        // Create a new Scanner object to read input from the console
        Scanner s = new Scanner(System.in);
        
        // Read two integers, E and Y, from the console
        int E = s.nextInt();
        int Y = s.nextInt();
        
        // Check the value of E using an if statement
        if (E == 0) {
            // If E is equal to 0, check the value of Y using nested if statements
            // to determine which generation the person belongs to
            if (Y <= 1911) {
                // If Y is less than or equal to 1911, print the corresponding generation label
                // and the number of years since the birth year
                System.out.print("M");
                System.out.println(Y - 1867);
            } else if (Y <= 1925) {
                // If Y is less than or equal to 1925, print the corresponding generation label
                // and the number of years since the birth year
                System.out.print("T");
                System.out.println(Y - 1911);
            } else if (Y <= 1988) {
                // If Y is less than or equal to 1988, print the corresponding generation label
                // and the number of years since the birth year
                System.out.print("S");
                System.out.println(Y - 1925);
            } else {
                // If Y is greater than 1988, print the corresponding generation label
                // and the number of years since the birth year
                System.out.print("H");
                System.out.println(Y - 1988);
            }
        } else if (E == 1) {
            // If E is not equal to 0, print the sum of the birth year and the given year
            System.out.println(1867 + Y);
        } else if (E == 2) {
            // If E is not equal to 0, print the sum of the birth year and the given year
            System.out.println(1911 + Y);
        } else if (E == 3) {
            // If E is not equal to 0, print the sum of the birth year and the given year
            System.out.println(1925 + Y);
        } else {
            // If E is not equal to 0, print the sum of the birth year and the given year
            System.out.println(1988 + Y);
        }
        
        // Close the Scanner object to free up system resources
        s.close();
    }
}