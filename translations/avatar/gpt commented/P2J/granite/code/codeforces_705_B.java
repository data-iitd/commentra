
import java.util.Scanner;

public class codeforces_705_B{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements
        int n = scanner.nextInt();

        // Read the list of integers from input
        int[] w = new int[n];
        for (int i = 0; i < n; i++) {
            w[i] = scanner.nextInt();
        }

        // Initialize a variable 'c' to track the output state
        int c = 2;

        // Iterate through each element in the list 'w'
        for (int i = 0; i < n; i++) {
            // If the current element is 1, print the current value of 'c'
            if (w[i] == 1) {
                System.out.println(c);
            }
            // If the current element is even, toggle 'c' between 2 and 3
            else if (w[i] % 2 == 0) {
                c = 3 - c;  // This will switch c between 2 and 3
                System.out.println(c);
            }
            // If the current element is odd (and not 1), print the current value of 'c'
            else {
                System.out.println(c);
            }
        }
    }
}
