
import java.util.Scanner;

public class codeforces_518_B{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        String t = scanner.nextLine();

        int[] freqs = new int[26];
        int[] freqt = new int[26];

        int yay = 0;
        int whoops = 0;

        // Count the frequency of each character in the first string's'
        for (int i = 0; i < s.length(); i++) {
            char letra = s.charAt(i);
            freqs[letra - 'a']++;
        }

        // Count the frequency of each character in the second string 't'
        for (int i = 0; i < t.length(); i++) {
            char letra = t.charAt(i);
            freqt[letra - 'a']++;
        }

        // Compare character frequencies from both strings to count exact matches
        for (int i = 0; i < 26; i++) {
            while (freqs[i] > 0 && freqt[i] > 0) {
                yay++;  // Increment the count of exact matches
                freqs[i]--;  // Decrease the count in the first string
                freqt[i]--;  // Decrease the count in the second string
            }
        }

        // Compare remaining characters for case-insensitive matches
        for (int i = 0; i < 26; i++) {
            while (freqs[i] > 0) {
                // Check for a lowercase letter in's' and its uppercase counterpart in 't'
                if (Character.isLowerCase(i + 'a') && freqt[Character.toUpperCase(i + 'a') - 'a'] > 0) {
                    whoops++;  // Increment the count of case-insensitive matches
                    freqs[i]--;  // Decrease the count in the first string
                    freqt[Character.toUpperCase(i + 'a') - 'a']--;  // Decrease the count in the second string
                }
                // Check for an uppercase letter in's' and its lowercase counterpart in 't'
                else if (Character.isUpperCase(i + 'a') && freqt[Character.toLowerCase(i + 'a') - 'a'] > 0) {
                    whoops++;  // Increment the count of case-insensitive matches
                    freqs[i]--;  // Decrease the count in the first string
                    freqt[Character.toLowerCase(i + 'a') - 'a']--;  // Decrease the count in the second string
                } else {
                    break;  // Exit the loop if no more matches can be found
                }
            }
        }

        // Print the results: number of exact matches and case-insensitive matches
        System.out.println(yay + " " + whoops);
    }
}
