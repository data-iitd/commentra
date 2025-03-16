
import java.util.Scanner ;

// Create a Scanner object to read input from the console
public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in); // Initialize Scanner object

        // Read four integers from the console
        int x, y, a, b;
        x = in.nextInt();
        y = in.nextInt();
        a = in.nextInt();
        b = in.nextInt();

        // Initialize a counter variable
        int count = 0;

        // Find the number of pairs (i, j) that satisfy the condition i < j
        for (int i = a; i <= x; i++) {
            for (int j = b; j <= y; ++j) {
                // If i is less than j, continue to the next iteration of the inner loop
                if (i <= j) continue;

                // Increment the counter if the condition is satisfied
                count++;
            }
        }

        // Print the result
        System.out.println(count);

        // Print all pairs (i, j) that satisfy the condition i < j
        for (int i = a; i <= x; i++) {
            for (int j = b; j <= y; ++j) {
                // If i is less than j, print the pair
                if (i <= j) {
                    System.out.println(i + " " + j);
                }
            }
        }

        // Close the Scanner object to free system resources
        in.close();
    }
}