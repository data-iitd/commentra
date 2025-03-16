import java.util.Scanner;
import java.util.Vector;

public class Solution {
    public static void main(String[] args) {
        // Initialize minA to a value larger than any possible element in A
        int minA = (int) Math.pow(10, 9) + 1;
        int num = 0; // Counter for the number of valid pairs

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); // Read the size of the array and the threshold value
        int t = sc.nextInt();
        Vector<Integer> A = new Vector<Integer>(); // Create a vector to store the elements of the array

        // Input the elements of the array A
        for (int i = 0; i < n; i++) {
            A.add(sc.nextInt());
        }

        // Iterate through the array to find the minimum value and count valid pairs
        for (int i = 0; i < n; i++) {
            // Update minA if the current element is smaller
            if (minA > A.get(i)) {
                minA = A.get(i);
            } else {
                // Check the difference between the current element and minA
                if (f == A.get(i) - minA) {
                    num++; // Increment the count if the difference matches the previous one
                } else if (f < A.get(i) - minA) {
                    num = 1; // Reset count if a larger difference is found
                    f = A.get(i) - minA; // Update the frequency to the new difference
                }
            }
        }

        // Output the total count of valid pairs
        System.out.println(num);

        sc.close(); // Close the scanner
    }
}

