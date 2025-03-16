import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Reading the number of elements and number of queries
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        
        // Initializing the output list with zeros
        int[] out = new int[n];
        
        // Initializing the comparison list with values from 2 to n+1
        int[] comp = new int[n];
        for (int i = 0; i < n; i++) {
            comp[i] = i + 2;
        }
        
        // Processing each query
        for (int i = 0; i < m; i++) {
            int l = scanner.nextInt();
            int r = scanner.nextInt();
            int x = scanner.nextInt();
            
            int t = l;
            while (t <= r) {
                int nextVal = comp[t - 1]; // Getting the next value to compare
                if (out[t - 1] == 0 && t != x) { // Checking if the current position should be updated
                    out[t - 1] = x; // Updating the output list
                }
                comp[t - 1] = (t >= x) ? (r + 1) : x; // Updating the comparison list based on the condition
                t = nextVal; // Moving to the next position in the range
            }
        }
        
        // Outputting the final result
        for (int value : out) {
            System.out.print(value + " ");
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
