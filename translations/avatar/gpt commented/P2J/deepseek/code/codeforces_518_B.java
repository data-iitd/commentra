import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
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
                yay++;
                freqs.put(letra, freqs.get(letra) - 1);
                freqt.put(letra, freqt.get(letra) - 1);
            }
        }
        
        // Compare remaining characters for case-insensitive matches
        for (char letra : freqs.keySet()) {
            while (freqs.get(letra) > 0) {
                if (Character.isLowerCase(letra) && Character.isUpperCase(letra) != Character.isUpperCase(letra)) {
                    char upperLetra = Character.toUpperCase(letra);
                    if (freqt.containsKey(upperLetra) && freqt.get(upperLetra) > 0) {
                        whoops++;
                        freqs.put(letra, freqs.get(letra) - 1);
                        freqt.put(upperLetra, freqt.get(upperLetra) - 1);
                    } else {
                        break;
                    }
                } else if (Character.isUpperCase(letra) && Character.isLowerCase(letra) != Character.isLowerCase(letra)) {
                    char lowerLetra = Character.toLowerCase(letra);
                    if (freqt.containsKey(lowerLetra) && freqt.get(lowerLetra) > 0) {
                        whoops++;
                        freqs.put(letra, freqs.get(letra) - 1);
                        freqt.put(lowerLetra, freqt.get(lowerLetra) - 1);
                    } else {
                        break;
                    }
                } else {
                    break;
                }
            }
        }
        
        // Print the results: number of exact matches and case-insensitive matches
        System.out.println(yay + " " + whoops);
    }
}
