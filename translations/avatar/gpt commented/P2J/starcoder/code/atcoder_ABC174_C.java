import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        // Read the integer k from input
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        sc.close();

        // Initialize a variable to hold the current value of t
        int t = 0;

        // Loop through numbers from 1 to k
        for (int i = 1; i <= k; i++) {
            // Update t by appending a '7' at the end and taking modulo k
            t = (t % k) * 10 + 7;

            // Check if the current value of t is divisible by k
            if (t % k == 0) {
                System.out.println(i);  // Print the current index if divisible
                break;
            }
        } else {
            // If no index was found, print -1
            System.out.println(-1);
        }
    }
}

