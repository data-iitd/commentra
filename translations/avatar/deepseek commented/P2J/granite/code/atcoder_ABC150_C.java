

import java.util.Scanner;  // Import the Scanner class

public class atcoder_ABC150_C{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object
        int n = scanner.nextInt();  // Take an integer input `n`
        int[] orig = new int[n];  // Create an array to store all permutations of numbers from 1 to `n`
        for (int i = 0; i < n; i++) {
            orig[i] = i + 1;  // Initialize the array with numbers from 1 to `n`
        }
        int[] p = new int[n];  // Create an array to store the first permutation `p`
        for (int i = 0; i < n; i++) {
            p[i] = scanner.nextInt();  // Take the elements of permutation `p`
        }
        int[] q = new int[n];  // Create an array to store the second permutation `q`
        for (int i = 0; i < n; i++) {
            q[i] = scanner.nextInt();  // Take the elements of permutation `q`
        }
        int pn = 0, qn = 0;  // Initialize the indices of permutation `p` and `q`
        for (int i = 0; i < n; i++) {
            if (Arrays.equals(orig, p)) {  // Check if the current array is equal to permutation `p`
                pn = i;  // Set the index of permutation `p` to the current index
            }
            if (Arrays.equals(orig, q)) {  // Check if the current array is equal to permutation `q`
                qn = i;  // Set the index of permutation `q` to the current index
            }
            int temp = orig[n - 1];  // Swap the last two elements of the array
            for (int j = n - 1; j > 0; j--) {
                orig[j] = orig[j - 1];  // Shift the elements to the right
            }
            orig[0] = temp;  // Set the first element to the swapped element
        }
        System.out.println(Math.abs(pn - qn));  // Calculate the absolute difference between the indices and print the result
    }
}
