
package main

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // Read the number of 'S' and 'c'
        int N = sc.nextInt();
        int M = sc.nextInt();
        int tmp = Math.min(N, M/2); // Calculate the minimum of N and half of M
        int ans = 0;
        ans += tmp; // Add the temporary value to the answer
        N -= tmp; // Decrease N by the temporary value
        M -= tmp * 2; // Decrease M by twice the temporary value
        // Output the final answer, which includes the remaining M divided by 4
        System.out.println(ans + M/4);
    }
}

