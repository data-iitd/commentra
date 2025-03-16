import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();

        int max_tmp = 0;
        int max = 0;
        for (int i = 0; i < s.length(); i++) {
            switch (s.charAt(i)) {
                case 'A':
                case 'C':
                case 'T':
                case 'G':
                    max_tmp++;
                    break;
                default:
                    break;
            }

            if (i == s.length() - 1) {
                break;
            }
            if (s.charAt(i + 1) == 'A' || s.charAt(i + 1) == 'C' || s.charAt(i + 1) == 'T' || s.charAt(i + 1) == 'G') {
                continue;
            }
            if (max < max_tmp) {
                max = max_tmp;
            }
            max_tmp = 0;
        }
        System.out.println(max);
    }
}

