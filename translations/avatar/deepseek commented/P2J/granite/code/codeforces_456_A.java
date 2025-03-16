

import java.util.Scanner;

public class codeforces_456_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();  // Take an integer input representing the number of elements in the list `m`
        int[][] m = new int[n][2];  // Create a 2D array `m` where each row contains two integers
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                m[i][j] = scanner.nextInt();  // Read two integers from the input and assign them to the corresponding position in the 2D array `m`
            }
        }
        scanner.close();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (m[i][1] < m[j][1]) {  // Check if the second element of the current element `m[i]` is less than the second element of the current element `m[j]`
                    int[] temp = m[i];  // Swap the elements at positions `i` and `j` in the 2D array `m`
                    m[i] = m[j];
                    m[j] = temp;
                }
            }
        }

        int[] a = m[0];  // Assign the first element of the sorted 2D array `m` to the variable `a`
        for (int i = 1; i < n; i++) {
            if (m[i][1] > a[1]) {  // Check if the second element of the current element `m[i]` is greater than the second element of the variable `a`
                System.out.println("Happy Alex");  // If true, print "Happy Alex" and break out of the loop
                break;
            }
            a = m[i];  // If false, assign the current element `m[i]` to the variable `a`
        }
        if (a == m[n - 1]) {  // If the loop completes without breaking
            System.out.println("Poor Alex");  // Print "Poor Alex"
        }
    }
}
