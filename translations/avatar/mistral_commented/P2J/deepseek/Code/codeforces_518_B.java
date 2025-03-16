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

        for (char letra : s.toCharArray()) {
            freqs.put(letra, freqs.getOrDefault(letra, 0) + 1);
        }

        for (char letra : t.toCharArray()) {
            freqt.put(letra, freqt.getOrDefault(letra, 0) + 1);
        }

        int yay = 0, whoops = 0;

        for (char letra : freqs.keySet()) {
            if (freqs.get(letra) > 0 && freqt.containsKey(letra) && freqt.get(letra) > 0) {
                int min = Math.min(freqs.get(letra), freqt.get(letra));
                yay += min;
                freqs.put(letra, freqs.get(letra) - min);
                freqt.put(letra, freqt.get(letra) - min);
            }
        }

        for (char letra : freqs.keySet()) {
            if (freqs.get(letra) > 0) {
                char lowerLetra = Character.toLowerCase(letra);
                char upperLetra = Character.toUpperCase(letra);
                if (freqt.containsKey(lowerLetra) && freqt.get(lowerLetra) > 0) {
                    whoops += 1;
                    freqs.put(letra, freqs.get(letra) - 1);
                    freqt.put(lowerLetra, freqt.get(lowerLetra) - 1);
                } else if (freqt.containsKey(upperLetra) && freqt.get(upperLetra) > 0) {
                    whoops += 1;
                    freqs.put(letra, freqs.get(letra) - 1);
                    freqt.put(upperLetra, freqt.get(upperLetra) - 1);
                }
            }
        }

        System.out.println(yay + " " + whoops);
    }
}
