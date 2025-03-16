import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String t = sc.next();
        int yay = 0;
        int whoops = 0;
        int[] freqs = new int[26];
        int[] freqt = new int[26];
        for (int i = 0; i < s.length(); i++) {
            freqs[s.charAt(i) - 'a']++;
        }
        for (int i = 0; i < t.length(); i++) {
            freqt[t.charAt(i) - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            while (freqs[i] > 0 && freqt[i] > 0) {
                yay++;
                freqs[i]--;
                freqt[i]--;
            }
        }
        for (int i = 0; i < 26; i++) {
            while (freqs[i] > 0) {
                if (i >= 0 && i < 26 && freqt[i] > 0) {
                    whoops++;
                    freqs[i]--;
                    freqt[i]--;
                } else {
                    break;
                }
            }
        }
        System.out.println(yay + " " + whoops);
    }
}

