
import java.util.Scanner; // Step 1: Import the Scanner class for input

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Step 4: Create a Scanner object to read input
        int t = sc.nextInt(); // Step 5: Read the number of test cases
        int count = 0; // Step 6: Initialize a counter to keep track of the number of times the condition is met

        // Step 7: Use a while loop to iterate through each test case
        while (t-- > 0) {
            int a = sc.nextInt(); // Step 8: Read the value of a for each test case
            int b = sc.nextInt(); // Step 8: Read the value of b for each test case
            int c = sc.nextInt(); // Step 8: Read the value of c for each test case

            // Step 9: Check if any of the values are 1 or if all three values are 1
            if ((a == 1 && b == 1) || (a == 1 && c == 1) || (b == 1 && c == 1) || (a == 1 && b == 1 && c == 1)) {
                count++; // Step 10: Increment the counter if the condition is met
            }
        }

        // Step 11: Print the counter value after the loop
        System.out.println(count);
    }
}
