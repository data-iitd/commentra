
// Importing the Scanner class for reading input from the standard input
import java.util.Scanner;

public class Main {
    // Initializing the variables N, m, f, a, b, and c with zeros
    static int N = 368, m[] = new int[N], f[] = new int[N], a = 0, b = 0, c = 0;

    public static void main(String[] args) {
        // Reading the number of operations from the standard input
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        // Processing each operation
        for (int i = 0; i < n; i++) {
            // Reading an operation line and splitting it into components
            String x = sc.next();
            int a = sc.nextInt();
            int b = sc.nextInt();
            // If the operation is 'M', updating the m array accordingly
            if (x.equals("M")) {
                m[a] += 2;
                m[b] -= 2;
            }
            // If the operation is 'F', updating the f array accordingly
            else {
                f[a] += 2;
                f[b] -= 2;
            }
        }
        // Calculating the prefix sums of m and f arrays
        for (int i = 0; i < N; i++) {
            // Updating the variables a and b with the sum of m and f arrays respectively
            a += m[i];
            b += f[i];
            // Finding the minimum of a and b and updating the variable c if the minimum is greater than the current value of c
            if (Math.min(a, b) > c) {
                c = Math.min(a, b);
            }
        }
        // Printing the result, which is the minimum of the prefix sums of m and f arrays
        System.out.println(c);
    }
}

