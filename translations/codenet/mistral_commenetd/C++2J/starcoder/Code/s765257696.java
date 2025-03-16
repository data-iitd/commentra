
import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) {
        // Read an integer n from the standard input
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        // Allocate an array p of size n to store the input integers
        int[] p = new int[n];

        // Initialize the variable ans to 0
        int ans = 0;

        // Iterate through the array p from index 0 to n-3
        for (int i = 0; i < n - 2; i++) {
            // Check if the current element p[i] is smaller than the next two elements p[i+1] and p[i+2]
            if (p[i] < p[i+1] && p[i+1] < p[i+2]) {
                // Increment the ans variable if both conditions are true
                ans++;
            }

            // Check if the current element p[i] is greater than the next two elements p[i+1] and p[i+2]
            if (p[i] > p[i+1] && p[i+1] > p[i+2]) {
                // Increment the ans variable if both conditions are true
                ans++;
            }
        }

        // Print the value of ans to the standard output
        System.out.println(ans);
    }
}

