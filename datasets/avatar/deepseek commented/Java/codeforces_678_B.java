
import java.sql.Timestamp; // Importing Timestamp for SQL operations or time-related tasks
import java.util.*; // Importing all utility classes from java.util package

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in); // Initializing Scanner to read input from the user
        int y = in.nextInt(); // Reading the year from the user input
        boolean leap = check_leap(y); // Checking if the year is a leap year
        int sum = 0; // Initializing sum to accumulate days
        int mod = 0; // Declaring mod for some modulo operation

        // Starting a loop from the next year after 'y' to find the first year where the sum of days is a multiple of 7
        for (int i = y + 1; ; i++) {
            if (check_leap(i)) { // Checking if the current year is a leap year
                sum += 366; // Adding 366 days for leap years
            } else {
                sum += 365; // Adding 365 days for non-leap years
            }
            if (sum % 7 == 0) { // Checking if the sum of days is a multiple of 7
                if ((check_leap(i) && leap) || (!check_leap(i) && !leap)) { // Checking if the current year's leap status matches the initial leap status
                    System.out.println(i); // Printing the year if it matches
                    return; // Exiting the program after printing the year
                } else {
                    continue; // Continuing the loop if the leap status does not match
                }
            }
        }
    }

    // Method to check if a year is a leap year
    static boolean check_leap(int y) {
        return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0); // Returning true if the year is a leap year
    }
}

