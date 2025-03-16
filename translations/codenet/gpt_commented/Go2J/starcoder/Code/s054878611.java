package main;

import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] a = new int[n];
        for(int a_i=0; a_i < n; a_i++){
            a[a_i] = in.nextInt();
        }
        System.out.println(solution(n, a));
    }

    public static int solution(int n, int[] a) {
        // Create a memoization array to count occurrences of numbers and their successors.
        int[] memo = new int[100002];
        
        // Iterate through each number in the input array.
        for (int i = 0; i < n; i++) {
                // Increment the count for the current number and its two successors.
                memo[a[i]]++;
                memo[a[i] + 1]++;
                memo[a[i] + 2]++;
        }
        
        // Initialize the output variable to track the maximum frequency found.
        int out = 0;
        
        // Iterate through the memoization array to find the maximum frequency.
        for (int i = 0; i < memo.length; i++) {
                // Update the output if the current count is greater than the current maximum.
                if (memo[i] > 0) {
                        out = Math.max(out, memo[i]);
                }
        }
        
        // Return the maximum frequency found.
        return out;
    }
}

