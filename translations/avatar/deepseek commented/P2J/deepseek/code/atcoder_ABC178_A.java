import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int tcs = 1; // Number of test cases
        int tc = 1; // Current test case number

        while (tc <= tcs) {
            int a = scanner.nextInt(); // Read an integer input from standard input
            System.out.println(a == 0 ? 1 : 0); // Print 1 if the input is 0, otherwise print 0
            tc++; // Increment the current test case number
        }
    }
}
