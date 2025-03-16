

import java.util.Scanner;
import java.util.Arrays;

public class codeforces_653_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();  // Take an integer input for the number of elements
        int[] l = new int[n];  // Create an array of size n to store the integers
        for (int i = 0; i < n; i++) {
            l[i] = scanner.nextInt();  // Take n integers as input and store them in the array
        }
        Arrays.sort(l);  // Sort the array of integers

        // Check if there exists any integer i in the array such that i + 1 and i + 2 are also in the array
        for (int i = 0; i < n - 2; i++) {
            if (l[i + 1] - l[i] == 1 && l[i + 2] - l[i + 1] == 1) {  // Check if i + 1 and i + 2 are in the array
                System.out.println("YES");  // If found, print 'YES' and break the loop
                return;
            }
        }
        System.out.println("NO");  // If no such integer is found, print 'NO'
    }
}
