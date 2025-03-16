import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read input variables
        int n = scanner.nextInt();
        int k = scanner.nextInt();

        // Read the string
        String s = scanner.next();

        // Initialize an array to store the count of each character
        int[] count = new int[26];

        // Iterate through each character in the string s
        for (char c : s.toCharArray()) {
            // Increment the count of the character in the array count
            count[c - 'A']++;
        }

        // Sort the count array in descending order
        java.util.Arrays.sort(count);

        // Initialize result variable
        int res = 0;

        // Iterate through each character count in the array count
        for (int i = 25; i >= 0; i--) {
            // Check if the count of the current character is greater than or equal to k
            if (count[i] >= k) {
                // Calculate the result and print it
                res += k * k;
                System.out.println(res);
                // Exit the loop as we have found the required characters
                return;
            }
            // Update the value of k by subtracting the count of the current character
            k -= count[i];
            // Add the square of the count of the current character to the result
            res += count[i] * count[i];
        }

        // Print the final result if no character is found with the required count
        System.out.println(res);
    }
}

