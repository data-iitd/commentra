import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    static final int SIZE = (int)(1e5 * 2) + 13; // Define the size of the count array

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt(); // Read the number of elements
        int k = scanner.nextInt(); // Read the threshold k
        
        int[] cnt = new int[SIZE]; // Array to count occurrences of each integer
        ArrayList<Integer> a = new ArrayList<>(); // List to store non-zero counts
        
        // Count occurrences of each integer
        for (int i = 0; i < n; i++) {
            int x = scanner.nextInt();
            cnt[x]++;
        }
        
        // Filter non-zero counts and store them in list a
        for (int i = 0; i < cnt.length; i++) {
            if (cnt[i] > 0) {
                a.add(cnt[i]);
            }
        }
        
        // Sort the list a in ascending order
        Collections.sort(a);
        
        // Calculate the sum of the smallest k counts in list a
        int ans = 0;
        int m = a.size() - k;
        for (int i = 0; i < m; i++) {
            ans += a.get(i);
        }
        
        // Output the result
        System.out.println(ans);
        
        scanner.close();
    }
}

// <END-OF-CODE>
