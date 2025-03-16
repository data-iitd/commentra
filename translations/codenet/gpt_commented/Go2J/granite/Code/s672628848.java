
import java.util.Scanner;

public class s672628848{
    public static void main(String[] args) {
        // Declare five integer variables to hold input values
        int a, b, c, d, e;

        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Read five integers from standard input
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();
        d = scanner.nextInt();
        e = scanner.nextInt();

        // Create an array containing the input integers
        int[] al = {a, b, c, d, e};

        // Iterate over the array to find the first occurrence of zero
        for (int n = 0; n < al.length; n++) {
            // Check if the current element is zero
            if (al[n] == 0) {
                // Print the index (1-based) of the first zero found and exit the loop
                System.out.println(n + 1);
                break;
            }
        }
    }
}
