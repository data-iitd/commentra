# Import necessary libraries and modules
import java.util.*;
import java.lang.*;
import java.io.*;

// Define helper functions
public static void main(String[] args) {
    // Read input
    Scanner sc = new Scanner(System.in);
    int q = sc.nextInt();
    int h = sc.nextInt();
    int s = sc.nextInt();
    int d = sc.nextInt();
    int n = sc.nextInt();

    // Calculate the length of the longest segment that can be formed
    // using the given resources
    int best1L = Math.min(q*4, h*2, s);
    int best2L = Math.min(d, best1L*2);

    // Check if n is even
    if (n % 2 == 0) {
        // If it is, print the length of the longest segment that can be formed
        // by dividing n into pairs and using the best2L length for each pair
        System.out.println(best2L * (n/2));
    } else {
        // If n is odd, print the length of the longest segment that can be formed
        // by dividing n-1 into pairs and using the best2L length for each pair,
        // and adding the best1L length at the end
        System.out.println(best2L * (n/2) + best1L);
    }
}
