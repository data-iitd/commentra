import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String t = sc.next();
        int yay = 0, whoops = 0;
        HashMap<Character, Integer> freqs = new HashMap<Character, Integer>();
        HashMap<Character, Integer> freqt = new HashMap<Character, Integer>();

        // Populating the frequency dictionaries
        for (int i = 0; i < s.length(); i++) {
            char letra = s.charAt(i);
            if (freqs.containsKey(letra)) {
                freqs.put(letra, freqs.get(letra) + 1);
            } else {
                freqs.put(letra, 1);
            }
        }

        for (int i = 0; i < t.length(); i++) {
            char letra = t.charAt(i);
            if (freqt.containsKey(letra)) {
                freqt.put(letra, freqt.get(letra) + 1);
            } else {
                freqt.put(letra, 1);
            }
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
                if (Character.isLowerCase(letra) && freqt.containsKey(Character.toUpperCase(letra)) && freqt.get(Character.toUpperCase(letra)) > 0) {
                    whoops++;
                    freqs.put(letra, freqs.get(letra) - 1);
                    freqt.put(Character.toUpperCase(letra), freqt.get(Character.toUpperCase(letra)) - 1);
                } else if (Character.isUpperCase(letra) && freqt.containsKey(Character.toLowerCase(letra)) && freqt.get(Character.toLowerCase(letra)) > 0) {
                    whoops++;
                    freqs.put(letra, freqs.get(letra) - 1);
                    freqt.put(Character.toLowerCase(letra), freqt.get(Character.toLowerCase(letra)) - 1);
                } else {
                    break;
                }
            }
        }

        System.out.println(yay + " " + whoops);
    }
}

