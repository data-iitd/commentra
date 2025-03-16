import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        // Read the number of elements
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        
        // Initialize a vector to store the elements and read them from input
        int[] a = new int[n];
        REP(i, n) a[i] = in.nextInt();
        
        // Sort the vector to facilitate duplicate checking
        Arrays.sort(a);
        
        // Check for duplicates in the sorted vector
        REP(i, n - 1) {
            if (a[i] == a[i + 1]) {
                // If a duplicate is found, print "NO" and exit
                System.out.println("NO");
                return;
            }
        }
        
        // If no duplicates are found, print "YES"
        System.out.println("YES");
    }
}

