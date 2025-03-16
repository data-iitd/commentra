
import java.util.Scanner;

public class s326049239{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a, c, k, b; // Declare variables: a for input, c for counting, k for groups of three, b for temporary storage

        // Continuously read integers from standard input until EOF
        while (scanner.hasNextInt()) {
            a = scanner.nextInt();
            c = 0; // Initialize count of individual items
            k = 0; // Initialize count of groups of three

            // Check if the input number is less than 3
            if (a < 3)
                System.out.println(0); // If less than 3, print 0 (no groups can be formed)
            else {
                b = a; // Store the original value of a in b for later use

                // Loop to count down from a to 0
                while (a-- > 0) {
                    b--; // Decrement b
                    c++; // Increment the count of items

                    // Check if we have counted three items
                    if (c == 3) {
                        k++; // Increment the count of groups of three
                        c = 0; // Reset the count of items for the next group
                    }
                }
                // Print the total number of groups of three formed
                System.out.println(k);
            }
        }
    }
}
