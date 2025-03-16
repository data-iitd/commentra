import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(true) {
            int m = sc.nextInt();
            int n = sc.nextInt();
            if(m == 0)
                break;
            int l = 0;
            int r = 1500000;
            int ans = 0;
            while(l < r) {
                int mid = (l + r) / 2;
                if(check(m, mid, n, sc)) {
                    ans = mid;
                    if(r == mid)
                        break;
                    r = mid;
                } else {
                    if(l == mid)
                        break;
                    l = mid;
                }
            }
            System.out.println(ans);
        }
    }

    // Function to check if it is possible to distribute weights
    public static boolean check(int m, int wei, int n, Scanner sc) {
        int tmp = wei; // Temporary variable to hold the remaining weight
        n--; // Decrease the number of available books by one
        for(int i = 0; i < n; i++) {
            // If the current weight exceeds the available weight
            if(tmp < sc.nextInt()) {
                // If there are still books left to use
                if(n > 0) {
                    n--; // Use one book
                    tmp = wei; // Reset the temporary weight to the original weight
                    // Check again if the current weight exceeds the available weight
                    if(tmp < sc.nextInt())
                        return false; // Not possible to distribute
                } else {
                    return false; // No books left to use
                }
            }
            // Deduct the current book's weight from the temporary weight
            tmp -= sc.nextInt();
        }
        return true; // Successfully distributed the weights
    }
}

