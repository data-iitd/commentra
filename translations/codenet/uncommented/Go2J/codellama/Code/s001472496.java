
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();

        int max_tmp = 0;
        int max = 0;
        for (int i = 0; i < s.length(); i++) {
            boolean flag = false;
            switch (s.charAt(i)) {
                case 'A':
                case 'C':
                case 'T':
                case 'G':
                    max_tmp++;
                    break;
                default:
                    flag = true;
                    break;
            }

            if (i == s.length() - 1) {
                flag = true;
            }
            if (flag == true) {
                if (max < max_tmp) {
                    max = max_tmp;
                }
                max_tmp = 0;
            }
        }
        System.out.println(max);
    }
}

