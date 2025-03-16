import java.util.*;

public class Main {
    // Define the modulus
    static final int MOD = 1000000007;

    // Function to read integers from the standard input
    public static int[] readInts() {
        Scanner scanner = new Scanner(System.in);
        String[] input = scanner.nextLine().split(" ");
        int[] result = new int[input.length];
        for (int i = 0; i < input.length; i++) {
            result[i] = Integer.parseInt(input[i]);
        }
        return result;
    }

    // Main function
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());
        int[] A = readInts();
        
        // Sort the array A in ascending order
        Arrays.sort(A);
        
        long ans = 0;
        // Calculate the answer by summing up the elements of A at indices which are not multiples of 2n + 1
        for (int i = A.length - 2; i >= A.length - 2 * n; i -= 2) {
            ans += A[i];
        }
        
        // Print the answer
        System.out.println(ans);
    }
}

// <END-OF-CODE>
