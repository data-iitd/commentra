
import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        // Step 1: Read the input values for n and k
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); // Read the size of the array
        int k = sc.nextInt(); // Read the number of queries

        // Step 2: Read the array elements
        int arr[] = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt(); // Read each element of the array
        }

        // Step 3: Initialize two counters, o and e, to count the number of 1s and 0s in the array, respectively
        StringBuffer res = new StringBuffer(); // To store the result
        int o = 0, e = 0; // Counters for 1s and 0s

        // Step 4: Iterate through the array to count the number of 1s and 0s
        for (int i = 0; i < n; i++) {
            if (arr[i] == 1) {
                ++o; // Increment the counter for 1s
            } else {
                ++e; // Increment the counter for 0s
            }
        }

        // Step 5: For each query, determine if the length of the subarray is odd
        for (int i = 0; i < k; i++) {
            int l = sc.nextInt(); // Read the left index of the subarray
            int r = sc.nextInt(); // Read the right index of the subarray

            if ((r - l + 1) % 2 == 1) {
                res.append("0\n"); // Append "0" if the length is odd
            } else {
                // Step 6: If the length of the subarray is even, check if the number of 1s and 0s is sufficient
                if ((r - l + 1) / 2 <= o && (r - l + 1) / 2 <= e) {
                    res.append("1\n"); // Append "1" if the condition is satisfied
                } else {
                    res.append("0\n"); // Append "0" if the condition is not satisfied
                }
            }
        }

        // Step 7: Print the result
        System.out.print(res);
        sc.close(); // Close the scanner
    }
}

