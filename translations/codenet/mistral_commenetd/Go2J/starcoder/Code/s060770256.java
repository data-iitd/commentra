
package main;

import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        System.out.println(solution(n, m));
    }

    // Function to find the product of two numbers after subtracting 2 from each
    public static int solution(int n, int m) {
        // Set n and m to be the input numbers after subtracting 2 from each
        n = n - 2;
        m = m - 2;

        // Check if n is less than 0, if so set it to 1
        if (n < 0) {
            n = 1;
        }

        // Check if m is less than 0, if so set it to 1
        if (m < 0) {
            m = 1;
        }

        // Multiply n and m and return the result
        return n * m;
    }
}

