import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the number of strings

        // Declare an array to store the count of each character
        int[] cnt = new int[26];
        // Initialize the count array with 1
        for (int i = 0; i < 26; i++) {
            cnt[i] = 1;
        }

        // Read the strings from the standard input and update the count array accordingly
        for (int i = 0; i < n; i++) {
            char c = scanner.next().charAt(0); // Read a character from the standard input
            cnt[c - 'a']++; // Increment the count of the character in the count array
        }

        // Calculate the answer using the count array
        long ans = 1; // Initialize the answer to 1
        for (int i = 0; i < 26; i++) { // Iterate through all the characters from 'a' to 'z'
            ans *= cnt[i]; // Multiply the answer with the count of the current character
        }

        // Calculate the final answer by subtracting 1 from the initial answer
        ans--;

        // Print the final answer to the standard output
        System.out.println(ans);
    }
}

