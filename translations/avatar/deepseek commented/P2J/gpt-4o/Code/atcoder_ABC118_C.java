import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

public class GCDExample {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object for input.
        int N = scanner.nextInt();  // Take an integer input N, representing the number of elements in the list A.
        List<Integer> A = new ArrayList<>();  // Create a list to store the integers.

        for (int i = 0; i < N; i++) {
            A.add(scanner.nextInt());  // Take space-separated integers and add them to the list A.
        }

        int gcd = A.get(0);  // Initialize gcd with the first element of the list.
        for (int i = 1; i < A.size(); i++) {
            gcd = gcd(gcd, A.get(i));  // Compute the GCD of the current gcd and the next element.
        }

        System.out.println(gcd);  // Print the computed GCD.
        scanner.close();  // Close the scanner.
    }

    // Method to compute GCD of two numbers.
    public static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;  // Return the GCD.
    }
}
// <END-OF-CODE>
