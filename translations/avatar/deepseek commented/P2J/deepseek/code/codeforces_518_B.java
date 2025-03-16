import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        String t = scanner.nextLine();

        Map<Character, Integer> freqs = new HashMap<>();
        Map<Character, Integer> freqt = new HashMap<>();
        int yay = 0, whoops = 0;

        // Populating the frequency dictionaries
        for (char letra : s.toCharArray()) {
            freqs.put(letra, freqs.getOrDefault(letra, 0) + 1);
        }

        for (char letra : t.toCharArray()) {
            freqt.put(letra, freqt.getOrDefault(letra, 0) + 1);
        }

        // Counting yay by matching characters in freqs and freqt
        for (char letra : freqs.keySet()) {
            while (freqs.get(letra) > 0 && freqt.containsKey(letra) && freqt.get(letra) > 0) {
                yay++;
                freqs.put(letra, freqs.get(letra) - 1);
                freqt.put(letra, freqt.get(letra) - 1);
            }
        }

        // Counting whoops by transforming characters to match
        for (char letra : freqs.keySet()) {
            while (freqs.get(letra) > 0) {
                if (Character.isLowerCase(letra) && Character.isUpperCase(letra) != Character.isUpperCase(letra)) {
                    if (freqt.containsKey(Character.toUpperCase(letra)) && freqt.get(Character.toUpperCase(letra)) > 0) {
                        whoops++;
                        freqs.put(letra, freqs.get(letra) - 1);
                        freqt.put(Character.toUpperCase(letra), freqt.get(Character.toUpperCase(letra)) - 1);
                    } else {
                        break;
                    }
                } else if (Character.isUpperCase(letra) && Character.isLowerCase(letra) != Character.isLowerCase(letra)) {
                    if (freqt.containsKey(Character.toLowerCase(letra)) && freqt.get(Character.toLowerCase(letra)) > 0) {
                        whoops++;
                        freqs.put(letra, freqs.get(letra) - 1);
                        freqt.put(Character.toLowerCase(letra), freqt.get(Character.toLowerCase(letra)) - 1);
                    } else {
                        break;
                    }
                } else {
                    break;
                }
            }
        }

        System.out.println(yay + " " + whoops);
    }
}
