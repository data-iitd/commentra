import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int max = 0, max_tmp = 0;
        for (int i = 0; i < s.length(); i++) {
            switch (s.charAt(i)) {
                case 'A':
                case 'C':
                case 'T':
                case 'G':
                    max_tmp++;
                    break;
                default:
                    if (max < max_tmp) {
                        max = max_tmp;
                    }
                    max_tmp = 0;
                    break;
            }
            if (i == s.length() - 1) {
                if (max < max_tmp) {
                    max = max_tmp;
                }
                max_tmp = 0;
            }
        }
        System.out.println(max);
    }
}

