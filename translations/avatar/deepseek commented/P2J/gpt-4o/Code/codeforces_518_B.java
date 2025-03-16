import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class CharacterFrequency {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        String s = scanner.nextLine(); // Taking first input string
        String t = scanner.nextLine(); // Taking second input string
        
        Map<Character, Integer> freqs = new HashMap<>(); // Map to store frequency of characters in s
        Map<Character, Integer> freqt = new HashMap<>(); // Map to store frequency of characters in t
        int yay = 0, whoops = 0; // Initializing counters for yay and whoops

        // Populating the frequency maps
        for (char letra : s.toCharArray()) {
            freqs.put(letra, freqs.getOrDefault(letra, 0) + 1); // Incrementing the count
        }

        for (char letra : t.toCharArray()) {
            freqt.put(letra, freqt.getOrDefault(letra, 0) + 1); // Incrementing the count
        }

        // Counting yay by matching characters in freqs and freqt
        for (char letra : freqs.keySet()) {
            while (freqs.get(letra) > 0 && freqt.containsKey(letra) && freqt.get(letra) > 0) {
                yay++; // Incrementing yay if characters match
                freqs.put(letra, freqs.get(letra) - 1); // Decrementing the count in freqs
                freqt.put(letra, freqt.get(letra) - 1); // Decrementing the count in freqt
            }
        }

        // Counting whoops by transforming characters to match
        for (char letra : freqs.keySet()) {
            while (freqs.get(letra) > 0) {
                if (Character.isLowerCase(letra) && freqt.containsKey(Character.toUpperCase(letra)) && freqt.get(Character.toUpperCase(letra)) > 0) {
                    whoops++; // Incrementing whoops if transformation is possible
                    freqs.put(letra, freqs.get(letra) - 1); // Decrementing the count in freqs
                    freqt.put(Character.toUpperCase(letra), freqt.get(Character.toUpperCase(letra)) - 1); // Decrementing the count in freqt
                } else if (Character.isUpperCase(letra) && freqt.containsKey(Character.toLowerCase(letra)) && freqt.get(Character.toLowerCase(letra)) > 0) {
                    whoops++; // Incrementing whoops if transformation is possible
                    freqs.put(letra, freqs.get(letra) - 1); // Decrementing the count in freqs
                    freqt.put(Character.toLowerCase(letra), freqt.get(Character.toLowerCase(letra)) - 1); // Decrementing the count in freqt
                } else {
                    break; // Breaking the loop if no more transformations are possible
                }
            }
        }

        System.out.println(yay + " " + whoops); // Printing the final counts of yay and whoops
        scanner.close();
    }
}
// <END-OF-CODE>
