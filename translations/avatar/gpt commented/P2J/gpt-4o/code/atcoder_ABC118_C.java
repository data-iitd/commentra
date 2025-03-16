import java.util.Scanner;
import java.util.Arrays;
import java.util.stream.IntStream;

public class GCDCalculator {
    public static void main(String[] args) {
        // Read an integer input N, which represents the number of elements in the list
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        
        // Read a line of input, split it into individual string elements, convert them to integers,
        // and store them in an array A
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt();
        }
        
        // Calculate the GCD of all elements in the array A
        int gcd = Arrays.stream(A).reduce(A[0], GCDCalculator::gcd);
        
        // Print the calculated GCD
        System.out.println(gcd);
        
        scanner.close();
    }

    // Method to calculate the GCD of two numbers
    private static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}
// <END-OF-CODE>
