import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();  // Take an integer input N, representing the number of elements in the list A.
        int[] A = new int[N];  // Create an array A to store the elements.
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt();  // Take space-separated integers as input and store them in the array A.
        }
        int gcd = A[0];  // Initialize gcd with the first element of the array A.
        for (int i = 1; i < N; i++) {
            gcd = gcd(gcd, A[i]);  // Compute the GCD of the current gcd and the next element in the array A.
        }
        System.out.println(gcd);  // Print the computed GCD.
    }

    // Helper function to compute the GCD of two numbers using the Euclidean algorithm.
    public static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}
