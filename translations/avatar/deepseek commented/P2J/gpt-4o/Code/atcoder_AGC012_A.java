import java.util.Arrays;
import java.util.Scanner;

public class Main {
    // Function to read integers from input
    public static int[] readInts(Scanner scanner) {
        String[] input = scanner.nextLine().split(" ");
        int[] result = new int[input.length];
        for (int i = 0; i < input.length; i++) {
            result[i] = Integer.parseInt(input[i]);
        }
        return result;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = Integer.parseInt(scanner.nextLine());  // Read integer n
        int[] A = readInts(scanner);  // Read list A
        Arrays.sort(A);  // Sort the list A
        long ans = 0;  // Initialize answer variable
        
        // Calculate the sum of every second element from the end
        for (int i = A.length - 2; i >= A.length - 2 * n; i -= 2) {
            ans += A[i];
        }
        
        System.out.println(ans);  // Print the calculated sum
        scanner.close();
    }
}

// <END-OF-CODE>
