import java.util.*;

class Main {

    public static void main(String[] args) throws java.lang.Exception {

        // Create a Scanner object to read input from the standard input stream.
        Scanner sc = new Scanner(System.in);
        // Read the number of test cases.
        int count = sc.nextInt();

        // Loop through each test case.
        for (int i = 0; count > i; i++) {
            // Read the year, month, and day for the current test case.
            int y = sc.nextInt();
            int m = sc.nextInt();
            int d = sc.nextInt();

            // Call the Answer method with the current year, month, and day, and print the result.
            System.out.println(Answer(y, m, d));
        }
    }

    // The Answer method calculates a result based on the given year, month, and day.
    public static int Answer(int y, int m, int d) {
        // Initialize the result to 1.
        int result = 1;

        // Check if the year is divisible by 3.
        if (y % 3 == 0) {
            // Add 20 minus the day to the result if the year is divisible by 3.
            result += 20 - d;
        } else if (m % 2 == 0) {
            // Add 19 minus the day to the result if the month is even.
            result += 19 - d;
        } else {
            // Add 20 minus the day to the result otherwise.
            result += 20 - d;
        }

        // Loop through the remaining months from the next month to October (10).
        for (m+=1; m <= 10; m++) {
            if (y % 3 == 0) {
                // Add 20 to the result if the year is divisible by 3.
                result += 20;
            } else {
                if (m % 2 == 0) {
                    // Add 19 to the result if the month is even.
                    result += 19;
                } else {
                    // Add 20 to the result otherwise.
                    result += 20;
                }
            }
        }

        // Loop through the future years from the next year to 1000.
        for (y += 1; y < 1000; y++) {
            if (y % 3 == 0) {
                // Add 200 to the result if the year is divisible by 3.
                result += 200;
            } else {
                // Add 195 to the result otherwise.
                result += 195;
            }
        }
        // Return the calculated result.
        return result;
    }
}
