import java.io.BufferedReader; // Import BufferedReader class for reading input from console
import java.io.IOException; // Import IOException exception for reading input
import java.io.InputStreamReader; // Import InputStreamReader class for reading input stream

public class Main {
    public static void main(String[] args) throws IOException {
        // Initialize BufferedReader object to read input from console
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // Read a line of input from the console
        String line = br.readLine();

        // Split the line into an array of strings using space character as delimiter
        String[] list = line.split(" ");

        // Parse the first three elements of the array as integers x, a, and y
        int x = Integer.parseInt(list[0]);
        int a = Integer.parseInt(list[1]);
        int y = Integer.parseInt(list[2]);

        // Initialize a string variable h with the value "NO"
        String h = "NO";

        // Check if any of the numbers x, a, or y are equal to 5 or 7
        if (x == 5 || x == 7 || a == 5 || a == 7 || y == 5 || y == 7) {
            // If any of the numbers satisfy the condition, check if their sum is equal to 17
            if (x + y + a == 17) {
                // If the sum is equal to 17, set the value of h to "YES"
                h = "YES";
            }
        }

        // Print the value of h to the console
        System.out.println(h);
    }
}
