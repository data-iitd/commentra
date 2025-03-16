
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String s = sc.next();
        s = s.replace(" ", "");
        if (s.indexOf('0') == -1) {
            System.out.println(n - 1);
        } else {
            int[] indices = new int[s.length()];
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == '0') {
                    indices[i] = 1;
                } else {
                    indices[i] = 0;
                }
            }
            int maximum = 0;
            for (int i = 0; i < indices.length - 1; i++) {
                for (int j = i + 1; j < indices.length; j++) {
                    if (indices[i] == 1 && indices[j] == 1) {
                        maximum = Math.max(maximum, 2 + 2 * (Math.abs(i - j) - 1) - (Math.abs(indices[i] - indices[j]) - 1));
                    }
                }
            }
            System.out.println(s.replace("0", "").length() + maximum);
        }
    }
}

