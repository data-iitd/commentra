import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int tcs = 1; // Number of test cases
        int tc = 1; // Test case counter

        while (tc <= tcs) {
            int a = scanner.nextInt(); // Read the next test case and store it in a variable 'a'
            System.out.println(a == 0 ? 1 : 0); // Print the solution for the current test case
            tc++; // Increment the test case counter
        }
    }
}
