import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the number of characters
        long[] cnt = new long[26]; // Initialize an array to count occurrences of each letter
        for (int i = 0; i < 26; i++) {
            cnt[i] = 1; // Start with 1 for each letter
        }
        
        char[] s = new char[n]; // Array to store the characters
        for (int i = 0; i < n; i++) {
            s[i] = scanner.next().charAt(0); // Read each character
            cnt[s[i] - 'a']++; // Increment the count for the corresponding letter
        }

        long ans = cnt[0]; // Initialize the answer with the count of the first letter
        for (int i = 1; i < 26; i++) { // Loop through the counts of other letters
            ans *= cnt[i]; // Multiply the answer by the count of the current letter
            ans %= 1000000007; // Take the modulo to prevent overflow
        }

        System.out.println(ans - 1); // Output the result, subtracting 1 because we don't count the empty set
        scanner.close();
    }
}

// <END-OF-CODE>
