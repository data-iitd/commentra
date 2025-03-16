
import java.util.Scanner;  // Import the Scanner class from the java.util package.

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object.
        int N = scanner.nextInt();  // Read an integer input N, representing the number of elements in the list A.
        int[] A = new int[N];  // Create a list A of size N.
        for (int i = 0; i < N; i++) {  // For each integer i in the range [0, N),
            A[i] = scanner.nextInt();  // read an integer input and assign it to the i-th element of the list A.
        }
        int gcd = 0;  // Initialize the GCD to 0.
        for (int i = 0; i < N; i++) {  // For each integer i in the range [0, N),
            gcd = gcd(gcd, A[i]);  // compute the GCD of the current GCD and the i-th element of the list A, and assign the result to the variable gcd.
        }
        System.out.println(gcd);  // Print the computed GCD.
    }

    public static int gcd(int a, int b) {  // Compute the greatest common divisor (GCD) of two integers.
        if (b == 0) {  // If b is 0,
            return a;  // return a.
        } else {  // Otherwise,
            return gcd(b, a % b);  // compute the GCD of b and the remainder of a divided by b, and return the result.
        }
    }
}

