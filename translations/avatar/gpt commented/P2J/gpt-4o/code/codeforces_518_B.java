import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class StringMatch {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read two strings from input
        String s = scanner.nextLine();
        String t = scanner.nextLine();
        
        // Initialize maps to store frequency counts of characters in both strings
        Map<Character, Integer> freqs = new HashMap<>();
        Map<Character, Integer> freqt = new HashMap<>();
        
        // Initialize counters for matching characters
        int yay = 0, whoops = 0;

        // Count the frequency of each character in the first string 's'
        for (char letra : s.toCharArray()) {
            freqs.put(letra, freqs.getOrDefault(letra, 0) + 1);
        }

        // Count the frequency of each character in the second string 't'
        for (char letra : t.toCharArray()) {
            freqt.put(letra, freqt.getOrDefault(letra, 0) + 1);
        }

        // Compare character frequencies from both strings to count exact matches
        for (char letra : freqs.keySet()) {
            while (freqs.get(letra) > 0 && freqt.containsKey(letra) && freqt.get(letra) > 0) {
                yay++;  // Increment the count of exact matches
                freqs.put(letra, freqs.get(letra) - 1);  // Decrease the count in the first string
                freqt.put(letra, freqt.get(letra) - 1);  // Decrease the count in the second string
            }
        }

        // Compare remaining characters for case-insensitive matches
        for (char letra : freqs.keySet()) {
            while (freqs.get(letra) > 0) {
                // Check for a lowercase letter in 's' and its uppercase counterpart in 't'
                if (Character.isLowerCase(letra) && freqt.containsKey(Character.toUpperCase(letra)) && freqt.get(Character.toUpperCase(letra)) > 0) {
                    whoops++;  // Increment the count of case-insensitive matches
                    freqs.put(letra, freqs.get(letra) - 1);  // Decrease the count in the first string
                    freqt.put(Character.toUpperCase(letra), freqt.get(Character.toUpperCase(letra)) - 1);  // Decrease the count in the second string
                }
                // Check for an uppercase letter in 's' and its lowercase counterpart in 't'
                else if (Character.isUpperCase(letra) && freqt.containsKey(Character.toLowerCase(letra)) && freqt.get(Character.toLowerCase(letra)) > 0) {
                    whoops++;  // Increment the count of case-insensitive matches
                    freqs.put(letra, freqs.get(letra) - 1);  // Decrease the count in the first string
                    freqt.put(Character.toLowerCase(letra), freqt.get(Character.toLowerCase(letra)) - 1);  // Decrease the count in the second string
                } else {
                    break;  // Exit the loop if no more matches can be found
                }
            }
        }

        // Print the results: number of exact matches and case-insensitive matches
        System.out.println(yay + " " + whoops);
        
        scanner.close();
    }
}
// <END-OF-CODE>
