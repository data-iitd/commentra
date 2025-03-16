
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.next();
        int count = 0;
        int[] counter = new int[s.length()];

        if (s.length() == 0) {
            return;
        }

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'A' || s.charAt(i) == 'C' || s.charAt(i) == 'G' || s.charAt(i) == 'T') {
                count++;
            } else {
                counter[i] = count;
                count = 0;
            }
        }

        counter[s.length()] = count;
        Arrays.sort(counter);
        System.out.println(counter[counter.length - 1]);
    }
}

