import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Input the number of strings and the maximum number of occurrences of a character allowed
        long n = scanner.nextLong();
        long k = scanner.nextLong();
        
        // Read the string from the standard input
        String s = scanner.next();
        
        // Initialize the length of the first character and the counter for the current character
        char L = s.charAt(0);
        long ans = 0;
        long ans2 = 0;
        long cnt = 0;

        // Iterate through the string starting from the second character
        for (int i = 1; i < n; i++) {
            // If the current character is the same as the previous character, increment the counter
            if (L == s.charAt(i)) {
                cnt++;
            } else {
                // Update the answer with the sum of the count of the previous character and the number of times the previous character appeared in the string
                ans += cnt;
                ans2++;
                // Reset the counter for the new character
                cnt = 0;
                // Update the length of the current character
                L = s.charAt(i);
            }
        }

        // Update the answer with the count of the last character and the number of times it appeared in the string
        ans += cnt;
        ans2++;

        // Output the answer with the minimum of twice the number of allowed occurrences and the number of unique characters in the string minus one
        System.out.println(ans + Math.min(2 * k, ans2 - 1));
        
        scanner.close();
    }
}
// <END-OF-CODE>
