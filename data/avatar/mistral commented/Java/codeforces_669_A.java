
import java.io.BufferedReader; // BufferedReader to read input from the console
import java.io.IOException; // IOException for handling input/output exceptions
import java.io.InputStreamReader; // InputStreamReader to read input from the console

public class Main {
    // Main method is the entry point of the Java application
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); // Create a BufferedReader object to read input from the console
        int n; // Declare an integer variable 'n' to store the input number

        // Read the input number from the console and store it in the 'n' variable
        System.out.print("Enter a number: ");
        n = Integer.parseInt(br.readLine());

        // Call the 'solve' method to calculate and print the result
        solve(n);

        // Close the BufferedReader object to release the system resources
        br.close();
    }

    // 'solve' method to calculate and print the result
    public static void solve(int n) {
        // Calculate the result and print it to the console
        System.out.println((n / 3) * 2 + (n % 3 == 0 ? 0 : 1));
    }
}