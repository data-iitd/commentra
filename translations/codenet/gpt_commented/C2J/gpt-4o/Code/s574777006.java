import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables
        int n, q, sum = 0;
        int[] x = new int[10000];
        int[] y = new int[500];
        
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements in array x
        n = scanner.nextInt();
        
        // Read n elements into array x
        for (int i = 0; i < n; i++) {
            x[i] = scanner.nextInt();
        }
        
        // Read the number of queries
        q = scanner.nextInt();
        
        // Read q elements into array y
        for (int i = 0; i < q; i++) {
            y[i] = scanner.nextInt();
        }
        
        // Initialize sum to count how many elements in y are found in x
        for (int i = 0; i < q; i++) {
            // Check each element in y against all elements in x
            for (int j = 0; j < n; j++) {
                // If a match is found, increment sum and break the inner loop
                if (y[i] == x[j]) {
                    sum++;
                    break;
                }
            }
        }
        
        // Output the total count of matches found
        System.out.println(sum);
        
        scanner.close();
    }
}

// <END-OF-CODE>
