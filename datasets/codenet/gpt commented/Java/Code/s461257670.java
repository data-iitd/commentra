import java.util.*;

class Main {

    public static void main(String[] args) throws java.lang.Exception {
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read the number of test cases from the user
        int count = sc.nextInt();

        // Loop through each test case
        for (int i = 0; count > i; i++) {
            // Read the year, month, and day from the user
            int y = sc.nextInt();
            int m = sc.nextInt();
            int d = sc.nextInt();

            // Call the Answer method and print the result
            System.out.println(Answer(y, m, d));
        }
    }

    public static int Answer(int y, int m, int d) {
        // Initialize the result variable with a base value of 1
        int result = 1;

        // Calculate the initial result based on the year and month
        if (y % 3 == 0) {
            // If the year is divisible by 3, adjust result based on the day
            result += 20 - d;
        } else if (m % 2 == 0) {
            // If the month is even, adjust result based on the day
            result += 19 - d;
        } else {
            // If the month is odd, adjust result based on the day
            result += 20 - d;
        }

        // Loop through the months from the next month to October
        for (m += 1; m <= 10; m++) {
            // If the year is divisible by 3, add 20 to the result
            if (y % 3 == 0) {
                result += 20;
            } else {
                // If the month is even, add 19; otherwise, add 20
                if (m % 2 == 0) {
                    result += 19;
                } else {
                    result += 20;
                }
            }
        }

        // Loop through the years from the next year to 999
        for (y += 1; y < 1000; y++) {
            // If the year is divisible by 3, add 200; otherwise, add 195
            if (y % 3 == 0) {
                result += 200;
            } else {
                result += 195;
            }
        }
        
        // Return the final calculated result
        return result;
    }
}
