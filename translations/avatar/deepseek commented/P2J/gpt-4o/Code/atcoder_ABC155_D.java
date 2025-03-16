import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Reading N and K
        int N = scanner.nextInt();
        long K = scanner.nextLong();
        
        // Reading list A
        long[] A = new long[N];
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextLong();
        }
        
        // Sorting the list A
        Arrays.sort(A);
        
        // Binary search setup
        long ll = -10_000_000_000_000_000L - 1; // Lower limit initialized to a very small number
        long rr = 10_000_000_000_000_000L + 1; // Upper limit initialized to a very large number
        
        // Binary search execution
        while (ll + 1 < rr) {
            long x = (ll + rr) / 2; // Calculating the midpoint of the current range
            long tot = 0; // Initializing the total count of valid pairs
            
            // Counting valid pairs for each element in A
            for (int i = 0; i < N; i++) {
                if (A[i] < 0) {
                    int l = -1;
                    int r = N;
                    while (l + 1 < r) {
                        int c = (l + r) / 2;
                        if (A[i] * A[c] < x) {
                            r = c;
                        } else {
                            l = c;
                        }
                    }
                    tot += N - r; // Updating the total count for negative A[i]
                } else {
                    int l = -1;
                    int r = N;
                    while (l + 1 < r) {
                        int c = (l + r) / 2;
                        if (A[i] * A[c] < x) {
                            l = c;
                        } else {
                            r = c;
                        }
                    }
                    tot += r; // Updating the total count for non-negative A[i]
                }
                
                if (A[i] * A[i] < x) {
                    tot -= 1; // Adjusting for the pair (i, i) if necessary
                }
            }
            
            tot /= 2; // Dividing by 2 to correct for double-counting pairs
            
            // Adjusting the search range based on the total count
            if (tot < K) {
                ll = x;
            } else {
                rr = x;
            }
        }
        
        System.out.println(ll); // Output the result
        scanner.close();
    }
}
// <END-OF-CODE>
