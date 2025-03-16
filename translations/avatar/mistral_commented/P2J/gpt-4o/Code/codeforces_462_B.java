import java.util.Arrays;
import java.util.Scanner;

public class CharacterCount {
    public static void main(String[] args) {
        // Define input variables
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // n: number of characters in the string s
        int k = scanner.nextInt(); // k: number of occurrences of a character we want to find
        scanner.nextLine(); // Consume the newline character
        String s = scanner.nextLine(); // s: string to be processed

        // Initialize an array to store the count of each character
        int[] count = new int[26];

        // Iterate through each character in the string s
        for (char c : s.toCharArray()) {
            // Increment the count of the character in the array count
            count[c - 'A']++;
        }

        // Sort the count array in descending order
        Arrays.sort(count);
        int[] sortedCount = new int[26];
        for (int i = 0; i < 26; i++) {
            sortedCount[i] = count[25 - i]; // Reverse the order
        }

        // Initialize result variable
        int res = 0;

        // Iterate through each character count in the sorted array
        for (int i = 0; i < 26; i++) {
            // Check if the count of the current character is greater than or equal to k
            if (sortedCount[i] >= k) {
                // Calculate the result and print it
                res += k * k;
                System.out.println(res);
                // Exit the loop as we have found the required characters
                return;
            }
            // Update the value of k by subtracting the count of the current character
            k -= sortedCount[i];
            // Add the square of the count of the current character to the result
            res += sortedCount[i] * sortedCount[i];
        }

        // Print the final result if no character is found with the required count
        System.out.println(res);
    }
}
// <END-OF-CODE>
