import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Taking input from the user and splitting it into two integers
        String[] input = scanner.nextLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int k = Integer.parseInt(input[1]);
        
        // Taking another input from the user, which is supposed to be a list of integers
        int[] M = new int[n];
        String[] mInput = scanner.nextLine().split(" ");
        for (int i = 0; i < n; i++) {
            M[i] = Integer.parseInt(mInput[i]);
        }
        
        // Initializing a variable `m` to 0
        int m = 0;

        // Starting a loop that will iterate `n` times
        for (int j = 0; j < n; j++) {
            // Starting another loop that will iterate `n` times
            for (int p = 0; p < n; p++) {
                // Checking if the element at position `p` in the list `M` is 0
                if (M[p] == 0) {
                    // If the condition is true, print the position `p + 1`
                    System.out.print((p + 1) + " ");
                    // Break out of the loop after printing the position
                    break;
                }
            }
            // Decreasing the elements in the list `M` from position 0 to `p - k` by 1
            for (int l = 0; l < p + 1 - k; l++) {
                M[l]--;
            }
            // Decreasing the element at position `p` by 1
            M[p]--;
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
