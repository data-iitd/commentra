
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

        // Populating the frequency arrays
        for (int i = 0; i < s.length(); i++) {
            freqs[s.charAt(i) - 'a']++;
        }
        for (int i = 0; i < t.length(); i++) {
            freqt[t.charAt(i) - 'a']++;
        }

        // Counting yay by matching characters in freqs and freqt
        for (int i = 0; i < 26; i++) {
            while (freqs[i] > 0 && freqt[i] > 0) {
                yay++;
                freqs[i]--;
                freqt[i]--;
            }
        }

        // Counting whoops by transforming characters to match
        for (int i = 0; i < 26; i++) {
            while (freqs[i] > 0) {
                if ((i >= 0 && i <= 25 && freqt[i - 32] > 0) || (i >= 65 && i <= 90 && freqt[i + 32] > 0)) {
                    whoops++;
                    freqs[i]--;
                    if (i >= 0 && i <= 25) {
                        freqt[i - 32]--;
                    } else {
                        freqt[i + 32]--;
                    }
                } else {
                    break;
                }
            }
        }

        System.out.println(yay + " " + whoops);  // Printing the final counts of yay and whoops
    }
}
