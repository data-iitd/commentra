

import java.util.Scanner;

public class codeforces_612_B{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();  // Take an integer input representing the length of the list `a`
        int[] a = new int[n];  // Initialize an array `a` of length `n`
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();  // Take an integer input and assign it to the corresponding position in `a`
        }
        int[] b = new int[n];  // Initialize an array `b` of length `n`
        for (int i = 0; i < n; i++) {
            b[a[i] - 1] = i;  // Assign the index of each element in `a` to the corresponding position in `b`, adjusting for zero-based indexing
        }
        int res = 0;  // Initialize the result variable `res` to 0
        for (int i = 1; i < n; i++) {
            res += Math.abs(b[i] - b[i - 1]);  // Calculate the sum of absolute differences between the positions of consecutive elements in `b`
        }
        System.out.println(res);  // Print the result
    }
}
