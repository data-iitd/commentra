import java.util.*;

class Main {

    public static void main(String[] args) throws java.lang.Exception {
        // Initialize a Scanner object to read input from the standard input
        Scanner sc = new Scanner(System.in);

        // Read the number of test cases from the standard input
        int count = sc.nextInt();

        // Iterate through each test case
        for (int i = 0; count > i; i++) {
            // Read the year, month, and day from the standard input
            int y = sc.nextInt();
            int m = sc.nextInt();
            int d = sc.nextInt();

            // Call the Answer method with the given arguments and print the result to the standard output
            System.out.println(Answer(y, m, d));
        }
    }

    // The Answer method takes three integer arguments: year y, month m, and day d
    public static int Answer(int y, int m, int d) {
        int result = 1; // Initialize the result variable with the value 1

        // Check if the year is divisible by 3
        if (y % 3 == 0) {
            result += 20 - d; // Add the difference between 20 and the day to the result
        }

        // Check if the month is even
        if (m % 2 == 0) {
            result += 19 - d; // Add the difference between 19 and the day to the result
        } else {
            result += 20 - d; // Add the difference between 20 and the day to the result
        }

        // Iterate through each month from 1 to 10
        for (m+=1; m <= 10; m++) {
            // Check if the year is divisible by 3
            if (y % 3 == 0) {
                result += 20; // Add 20 to the result
            } else {
                // Check if the month is even
                if (m % 2 == 0) {
                    result += 19; // Add 19 to the result
                } else {
                    result += 20; // Add 20 to the result
                }
            }
        }

        // Iterate through each year from y+1 to 1000
        for (y += 1; y < 1000; y++) {
            // Check if the year is divisible by 3
            if (y % 3 == 0) {
                result += 200; // Add 200 to the result
            } else {
                result += 195; // Add 195 to the result
            }
        }

        // Return the result
        return result;
    }
}
