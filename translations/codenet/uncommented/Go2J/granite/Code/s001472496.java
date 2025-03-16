
import java.util.Scanner;

public class s001472496{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();

        int max_tmp = 0;
        int max = 0;
        for (int i = 0; i < s.length(); i++) {
            boolean flag = false;
            switch (String.valueOf(s.charAt(i))) {
                case "A":
                case "C":
                case "T":
                case "G":
                    max_tmp++;
                    break;
                default:
                    flag = true;
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

