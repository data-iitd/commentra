import java.util.Arrays;
import java.util.Scanner;

public class Main {
    // Defining a constant for modulo operation
    static final int MOD = 1000000007;

    // Function to read a list of integers from input
    public static int[] readInts(Scanner scanner) {
        String[] input = scanner.nextLine().split(" ");
        int[] result = new int[input.length];
        for (int i = 0; i < input.length; i++) {
            result[i] = Integer.parseInt(input[i]);
        }
        return result;
    }

    // Main function to execute the logic
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());  // Reading an integer input for 'n'
        int[] A = readInts(scanner);  // Reading a list of integers
        Arrays.sort(A);  // Sorting the list of integers in ascending order
        long ans = 0;  // Initializing the answer variable to accumulate the result

        // Looping through the last 2*n elements of the sorted list in reverse order
        for (int i = A.length - 2; i >= A.length - 2 * n; i -= 2) {
            ans += A[i];  // Adding the current element to the answer
        }

        System.out.println(ans);  // Printing the final accumulated answer
        scanner.close();  // Closing the scanner
    }
}
// <END-OF-CODE>
